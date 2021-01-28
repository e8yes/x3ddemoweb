from typing import List
from typing import Tuple
import math
import tensorflow as tf
import numpy as np

INPUT_SIZE = 11
NUM_RES_BLOCKS = 4

class ResidualTowerHeadLayer(tf.Module):
    def __init__(self, 
                 num_input_channels: int,
                 num_filters: int):
        super(ResidualTowerHeadLayer, self).__init__()

        kernel_size = 5
        self.conv_kernel = tf.Variable(
            name="res_tower_head_kernel",
            initial_value=tf.random.truncated_normal( # pylint: disable=unexpected-keyword-arg
                shape=[kernel_size, kernel_size, 
                       num_input_channels, 
                       num_filters],
                stddev=1/math.sqrt(kernel_size*kernel_size*num_input_channels),
                dtype=tf.float32))
        self.biases = tf.Variable(
            name="res_tower_head_bias",
            initial_value=tf.zeros(shape=[num_filters], dtype=tf.float32))
        
    def Variables(self) -> List[tf.Tensor]:
        return [self.conv_kernel, self.biases]

class ResidualBlock(tf.Module):
    def __init__(self,
                 block_num: int,
                 num_filters: int):
        super(ResidualBlock, self).__init__()

        num_input_channels = num_filters
        kernel_size = 5
        num_output_channels = num_filters
        self.conv_kernel1 = tf.Variable(
            name="res_b{0}_kernel1".format(block_num),
            initial_value=tf.random.truncated_normal( # pylint: disable=unexpected-keyword-arg
                shape=[kernel_size, kernel_size, 
                       num_input_channels, 
                       num_output_channels],
                stddev=1/math.sqrt(kernel_size*kernel_size*num_input_channels),
                dtype=tf.float32))
        self.biases1 = tf.Variable(
            name="res_b{0}_bias1".format(block_num),
            initial_value=tf.zeros(shape=[num_output_channels], dtype=tf.float32))

        self.conv_kernel2 = tf.Variable(
            name="res_b{0}_kernel2".format(block_num),
            initial_value=tf.random.truncated_normal( # pylint: disable=unexpected-keyword-arg
                shape=[kernel_size, kernel_size, 
                       num_input_channels, 
                       num_output_channels],
                stddev=1/math.sqrt(kernel_size*kernel_size*num_input_channels),
                dtype=tf.float32))
        self.biases2 = tf.Variable(
            name="res_b{0}_bias2".format(block_num),
            initial_value=tf.zeros(shape=[num_output_channels], dtype=tf.float32))
    
    def Variables(self) -> List[tf.Tensor]:
        return [self.conv_kernel1, self.biases1, self.conv_kernel2, self.biases2]

class PolicyLayer(tf.Module):
    def __init__(self, num_input_channels: int):
        super(PolicyLayer, self).__init__()

        kernel_size = 1
        num_output_channels = 2
        self.conv_kernel = tf.Variable(
            name="policy_conv_kernel",
            initial_value=tf.random.truncated_normal( # pylint: disable=unexpected-keyword-arg
                shape=[kernel_size, kernel_size, 
                       num_input_channels, 
                       num_output_channels],
                stddev=1/math.sqrt(kernel_size*kernel_size*num_input_channels),
                dtype=tf.float32))
        self.conv_biases = tf.Variable(
            name="policy_conv_biases",
            initial_value=tf.zeros(shape=[num_output_channels], dtype=tf.float32))

        num_inputs = INPUT_SIZE*INPUT_SIZE*2
        num_outputs = INPUT_SIZE*INPUT_SIZE + 3 + 2
        self.weights = tf.Variable(
            name="policy_fc_weights",
            initial_value=tf.random.truncated_normal(shape=[num_inputs, num_outputs], # pylint: disable=unexpected-keyword-arg
                                                     stddev=1/math.sqrt(num_inputs),
                                                     dtype=tf.float32))
        self.biases = tf.Variable(
            name="policy_fc_biases",
            initial_value=tf.zeros(shape=[num_outputs], dtype=tf.float32))
    
    def Variables(self) -> List[tf.Tensor]:
        return [self.conv_kernel, self.conv_biases, self.weights, self.biases]

class ValueLayer(tf.Module):
    def __init__(self, num_input_channels: int):
        super(ValueLayer, self).__init__()

        kernel_size = 1
        num_output_channels = 1
        self.conv_kernel = tf.Variable(
            name="value_conv_kernel",
            initial_value=tf.random.truncated_normal( # pylint: disable=unexpected-keyword-arg
                shape=[kernel_size, kernel_size, 
                       num_input_channels, 
                       num_output_channels],
                stddev=1/math.sqrt(kernel_size*kernel_size*num_input_channels),
                dtype=tf.float32))
        self.conv_biases = tf.Variable(
            name="value_conv_biases",
            initial_value=tf.zeros(shape=[num_output_channels], dtype=tf.float32))

        num_inputs = INPUT_SIZE*INPUT_SIZE
        num_outputs = num_input_channels
        self.weights1 = tf.Variable(
            name="value_fc1_weights",
            initial_value=tf.random.truncated_normal(shape=[num_inputs, num_outputs], # pylint: disable=unexpected-keyword-arg
                                                     stddev=1/math.sqrt(num_inputs),
                                                     dtype=tf.float32))
        self.biases1 = tf.Variable(
            name="value_fc1_biases",
            initial_value=tf.zeros(shape=[num_outputs], dtype=tf.float32))

        num_inputs = num_input_channels
        num_outputs = 1
        self.weights2 = tf.Variable(
            name="value_fc2_weights",
            initial_value=tf.random.truncated_normal(shape=[num_inputs, num_outputs], # pylint: disable=unexpected-keyword-arg
                                                     stddev=1/math.sqrt(num_inputs),
                                                     dtype=tf.float32))
        self.biases2 = tf.Variable(
            name="value_fc2_biases",
            initial_value=tf.zeros(shape=[num_outputs], dtype=tf.float32))
    
    def Variables(self) -> List[tf.Tensor]:
        return [self.conv_kernel, self.conv_biases,
                self.weights1, self.biases1,
                self.weights2, self.biases2]

class GomokuCnnResNetSharedTower(tf.Module):
    def __init__(self):
        super(GomokuCnnResNetSharedTower, self).__init__()
        self.res_tower_head_layer_ = ResidualTowerHeadLayer(
            num_input_channels=2 + 5 + 1, num_filters=32)

        self.res_blocks_ = list()
        for i in range(NUM_RES_BLOCKS):
            self.res_blocks_.append(ResidualBlock(block_num=i, num_filters=32))
        
        self.policy_layer_ = PolicyLayer(num_input_channels=32)
        self.value_layer_ = ValueLayer(num_input_channels=32)
    
    def Variables(self) -> List[tf.Tensor]:
        variables = list()

        variables += self.res_tower_head_layer_.Variables()

        for block in self.res_blocks_:
            variables += block.Variables()

        variables += self.policy_layer_.Variables()
        variables += self.value_layer_.Variables()

        return variables

    def Name(self)-> str:
        return "gomoku_cnn_shared_tower_{0}_{0}_b{1}" \
            .format(INPUT_SIZE, NUM_RES_BLOCKS)

    @tf.function(
        input_signature=[
            tf.TensorSpec(shape=[None, INPUT_SIZE, INPUT_SIZE], dtype=tf.float32),
            tf.TensorSpec(shape=[None], dtype=tf.float32),
            tf.TensorSpec(shape=[None], dtype=tf.float32),
            tf.TensorSpec(shape=[None], dtype=tf.float32),
            tf.TensorSpec(shape=[None], dtype=tf.float32),
            tf.TensorSpec(shape=[None], dtype=tf.float32),
            tf.TensorSpec(shape=[None], dtype=tf.float32)
        ])
    def __call__(self,
                 board_features: np.ndarray,
                 game_phase_place_3_stones: np.ndarray,
                 game_phase_swap2_decision: np.ndarray,
                 game_phase_place2_more_stones: np.ndarray,
                 game_phase_stone_type_decision: np.ndarray,
                 game_phase_standard_gomoku: np.ndarray,
                 next_move_stone_type) -> Tuple[tf.Tensor, tf.Tensor, tf.Tensor]:
        # Places the game states into feature planes.
        black_stones = -tf.minimum(x=board_features, y=0.0) # pylint: disable=invalid-unary-operand-type
        black_stones = tf.reshape(tensor=black_stones,
                                  shape=[-1, INPUT_SIZE, INPUT_SIZE, 1])

        white_stones = tf.maximum(x=board_features, y=0.0)
        white_stones = tf.reshape(tensor=white_stones,
                                  shape=[-1, INPUT_SIZE, INPUT_SIZE, 1])

        game_phase_place_3_stones = \
            tf.reshape(tensor=game_phase_place_3_stones, shape=[-1, 1, 1, 1])
        game_phase_place_3_stones = \
            tf.repeat(input=game_phase_place_3_stones, repeats=[INPUT_SIZE], axis=2)
        game_phase_place_3_stones = \
            tf.repeat(input=game_phase_place_3_stones, repeats=[INPUT_SIZE], axis=1)

        game_phase_swap2_decision = \
            tf.reshape(tensor=game_phase_swap2_decision, shape=[-1, 1, 1, 1])
        game_phase_swap2_decision = \
            tf.repeat(input=game_phase_swap2_decision, repeats=[INPUT_SIZE], axis=2)
        game_phase_swap2_decision = \
            tf.repeat(input=game_phase_swap2_decision, repeats=[INPUT_SIZE], axis=1)

        game_phase_place2_more_stones = \
            tf.reshape(tensor=game_phase_place2_more_stones, shape=[-1, 1, 1, 1])
        game_phase_place2_more_stones = \
            tf.repeat(input=game_phase_place2_more_stones, repeats=[INPUT_SIZE], axis=2)
        game_phase_place2_more_stones = \
            tf.repeat(input=game_phase_place2_more_stones, repeats=[INPUT_SIZE], axis=1)

        game_phase_stone_type_decision = \
            tf.reshape(tensor=game_phase_stone_type_decision, shape=[-1, 1, 1, 1])
        game_phase_stone_type_decision = \
            tf.repeat(input=game_phase_stone_type_decision, repeats=[INPUT_SIZE], axis=2)
        game_phase_stone_type_decision = \
            tf.repeat(input=game_phase_stone_type_decision, repeats=[INPUT_SIZE], axis=1)

        game_phase_standard_gomoku = \
            tf.reshape(tensor=game_phase_standard_gomoku, shape=[-1, 1, 1, 1])
        game_phase_standard_gomoku = \
            tf.repeat(input=game_phase_standard_gomoku, repeats=[INPUT_SIZE], axis=2)
        game_phase_standard_gomoku = \
            tf.repeat(input=game_phase_standard_gomoku, repeats=[INPUT_SIZE], axis=1)

        next_move_stone_type = \
            tf.reshape(tensor=next_move_stone_type, shape=[-1, 1, 1, 1])
        next_move_stone_type = \
            tf.repeat(input=next_move_stone_type, repeats=[INPUT_SIZE], axis=2)
        next_move_stone_type = \
            tf.repeat(input=next_move_stone_type, repeats=[INPUT_SIZE], axis=1)
        
        conv_features = tf.concat(values=[black_stones, # pylint: disable=unexpected-keyword-arg, no-value-for-parameter
                                          white_stones,
                                          game_phase_place_3_stones,
                                          game_phase_swap2_decision,
                                          game_phase_place2_more_stones,
                                          game_phase_stone_type_decision,
                                          game_phase_standard_gomoku,
                                          next_move_stone_type],
                                  axis=3)

        # Residual tower head
        conv_features = tf.nn.conv2d(input=conv_features,
                                     filters=self.res_tower_head_layer_.conv_kernel,
                                     strides=[1, 1, 1, 1],
                                     padding="SAME") + \
                        self.res_tower_head_layer_.biases
        conv_features = tf.nn.leaky_relu(features=conv_features)

        # Constructs the residual tower.
        for res_block in self.res_blocks_:
            conv_output = tf.nn.conv2d(input=conv_features,
                                       filters=res_block.conv_kernel1,
                                       strides=[1, 1, 1, 1],
                                       padding="SAME") + \
                          res_block.biases1
            conv_output = tf.nn.leaky_relu(features=conv_output)

            conv_output = tf.nn.conv2d(input=conv_output,
                                       filters=res_block.conv_kernel2,
                                       strides=[1, 1, 1, 1],
                                       padding="SAME") + \
                          res_block.biases2
            conv_features = conv_features + tf.nn.leaky_relu(features=conv_output)
        
        # Policy output
        policy_hidden_layer = tf.nn.conv2d(input=conv_features,
                                           filters=self.policy_layer_.conv_kernel,
                                           strides=[1, 1, 1, 1],
                                           padding="SAME") + \
                              self.policy_layer_.conv_biases
        policy_hidden_layer = tf.nn.relu(features=policy_hidden_layer)

        policy_hidden_layer = tf.reshape(tensor=policy_hidden_layer,
                                         shape=[-1, INPUT_SIZE*INPUT_SIZE*2])
        policy_logits = tf.matmul(a=policy_hidden_layer,
                                  b=self.policy_layer_.weights) + \
                     self.policy_layer_.biases
        policy = tf.nn.softmax(logits=policy_logits)

        # Value output
        value_hidden_layer = tf.nn.conv2d(input=conv_features,
                                           filters=self.value_layer_.conv_kernel,
                                           strides=[1, 1, 1, 1],
                                           padding="SAME") + \
                              self.value_layer_.conv_biases
        value_hidden_layer = tf.nn.relu(features=value_hidden_layer)

        value_hidden_layer = tf.reshape(tensor=value_hidden_layer,
                                        shape=[-1, INPUT_SIZE*INPUT_SIZE])
        value_hidden_layer2 = tf.matmul(a=value_hidden_layer,
                                        b=self.value_layer_.weights1) + \
                              self.value_layer_.biases1
        value_hidden_layer2 = tf.nn.relu(features=value_hidden_layer2)

        value = tf.matmul(a=value_hidden_layer2,
                          b=self.value_layer_.weights2) + \
                self.value_layer_.biases2
        value = tf.tanh(x=value)
        value = tf.reshape(tensor=value, shape=[-1])

        return policy, value, policy_logits
    
    @tf.function
    def Loss(self,
             boards: np.ndarray, 
             game_phase_place_3_stones: np.ndarray, 
             game_phase_swap2_decision: np.ndarray, 
             game_phase_place2_more_stones: np.ndarray, 
             game_phase_stone_type_decision: np.ndarray, 
             game_phase_standard_gomoku: np.ndarray, 
             next_move_stone_types: np.ndarray, 
             policies: np.ndarray, 
             values: np.ndarray) -> Tuple[tf.Tensor, tf.Tensor, tf.Tensor]:
        _, pred_values, policy_logits = \
            self(boards, 
                 game_phase_place_3_stones,
                 game_phase_swap2_decision,
                 game_phase_place2_more_stones,
                 game_phase_stone_type_decision,
                 game_phase_standard_gomoku,
                 next_move_stone_types)

        policy_losses = tf.nn.softmax_cross_entropy_with_logits(
            labels=policies, logits=policy_logits)
        policy_loss = tf.reduce_mean(input_tensor=policy_losses, axis=0)

        value_loss = \
            tf.losses.mse(y_true=values, y_pred=pred_values)

        loss = policy_loss + value_loss
        
        return loss, policy_loss, value_loss
