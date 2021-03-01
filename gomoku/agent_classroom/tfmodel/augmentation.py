import numpy as np

def RotationTransform(board: np.ndarray,
                      shl_map: np.ndarray,
                      policy_plane: np.ndarray,
                      k: int):
    board = np.rot90(
        board, k=k, axes=(0, 1))
    shl_map = np.rot90(
        shl_map, k=k, axes=(0, 1))
    policy_plane = np.rot90(
        policy_plane, k=k, axes=(0, 1))
    return board, shl_map, policy_plane

def SwitchStoneType(board: np.ndarray,
                    shl_map: np.ndarray,
                    next_move_stone_type: np.ndarray,
                    policy: np.ndarray,
                    input_size: int):
    new_board = np.copy(a=board)
    new_board[board == 1] = 2
    new_board[board == 2] = 1

    new_next_move_stone_type = np.copy(a=next_move_stone_type)
    new_next_move_stone_type[next_move_stone_type == 1] = 2
    new_next_move_stone_type[next_move_stone_type == 2] = 1

    new_shl_map = np.copy(a=shl_map)
    new_shl_map[:,:,:2], new_shl_map[:,:,2:] = \
        shl_map[:,:,2:], shl_map[:,:,:2]

    new_policy = np.copy(a=policy)
    new_policy[input_size*input_size + 0], \
    new_policy[input_size*input_size + 1] = \
        policy[input_size*input_size + 1], \
        policy[input_size*input_size + 0]

    new_policy[input_size*input_size + 3], \
    new_policy[input_size*input_size + 4] = \
        policy[input_size*input_size + 4], \
        policy[input_size*input_size + 3]

    return new_board, \
           new_shl_map, \
           new_next_move_stone_type, \
           new_policy

def TransformFeatures(board: np.ndarray,
                      game_phase: np.ndarray,
                      next_move_stone_type: np.ndarray,
                      shl_map: np.ndarray,
                      policy: np.ndarray,
                      value: np.ndarray,
                      transform_type: int):
    if transform_type is None:
        transform_type = np.random.choice(
            a=np.arange(start=0, stop=16))

    input_size = board.shape[0]

    if transform_type == 0:
        pass
    elif 1 <= transform_type <= 3:
        policy_plane = np.reshape(
            a=policy[:input_size*input_size], 
            newshape=(input_size, input_size),
            order="F")
        board, shl_map, policy_plane = RotationTransform(
            board=board, shl_map=shl_map, policy_plane=policy_plane,
            k=transform_type)
        policy = np.concatenate(
            (np.reshape(
                a=policy_plane, 
                newshape=(input_size*input_size),
                order="F"),
             policy[input_size*input_size:]), axis=0)
    elif 4 <= transform_type <= 7:
        policy_plane = np.reshape(
            a=policy[:input_size*input_size], 
            newshape=(input_size, input_size),
            order="F")

        board = np.flip(board, axis=0)
        shl_map = np.flip(shl_map, axis=0)
        policy_plane = np.flip(policy_plane, axis=0)

        board, shl_map, policy_plane = RotationTransform(
            board=board, shl_map=shl_map, policy_plane=policy_plane,
            k=transform_type - 4)

        policy = np.concatenate(
            (np.reshape(
                a=policy_plane, 
                newshape=(input_size*input_size),
                order="F"),
             policy[input_size*input_size:]), axis=0)
    elif 8 <= transform_type <= 11:
        board,\
        shl_map,\
        next_move_stone_type,\
        policy = SwitchStoneType(
            board=board,
            shl_map=shl_map,
            next_move_stone_type=next_move_stone_type,
            policy=policy,
            input_size=input_size)

        policy_plane = np.reshape(
            a=policy[:input_size*input_size], 
            newshape=(input_size, input_size),
            order="F")

        board, shl_map, policy_plane = RotationTransform(
            board=board, shl_map=shl_map, policy_plane=policy_plane,
            k=transform_type - 8)

        policy = np.concatenate(
            (np.reshape(
                a=policy_plane, 
                newshape=(input_size*input_size),
                order="F"),
             policy[input_size*input_size:]), axis=0)
    elif 12 <= transform_type <= 15:
        board,\
        shl_map,\
        next_move_stone_type,\
        policy = SwitchStoneType(
            board=board,
            shl_map=shl_map,
            next_move_stone_type=next_move_stone_type,
            policy=policy,
            input_size=input_size)

        policy_plane = np.reshape(
            a=policy[:input_size*input_size], 
            newshape=(input_size, input_size),
            order="F")

        board = np.flip(board, axis=0)
        shl_map = np.flip(shl_map, axis=0)
        policy_plane = np.flip(policy_plane, axis=0)

        board, shl_map, policy_plane = RotationTransform(
            board=board, shl_map=shl_map, policy_plane=policy_plane,
            k=transform_type - 12)

        policy = np.concatenate(
            (np.reshape(
                a=policy_plane, 
                newshape=(input_size*input_size),
                order="F"),
             policy[input_size*input_size:]), axis=0)

    return board,\
           game_phase,\
           next_move_stone_type,\
           shl_map,\
           policy,\
           value

if __name__ == "__main__":
    board = np.array(
        object=[[0, 0, 1],
                [0, 0, 0],
                [0, 0, 2]],
        dtype=np.uint8)
    game_phase = np.array(
        object=[4], dtype=np.uint8)
    next_move_stone_type = np.array(
        object=[1], dtype=np.uint8)
    shl_map = np.array(
        object=[[[0, 0, 0, 0], [2, 0, 0, 0], [0, 0, 0, 0]],
                [[0, 0, 0, 0], [0, 0, 0, 0], [0, 0, 1, 0]],
                [[0, 0, 0, 0], [0, 0, 0, 0], [0, 0, 0, 0]]],
        dtype=np.float32)
    policy = np.array(
        object=[0, 0, 0,
                0.33, 0, 0,
                0, 0, 0,
                0.33, 0, 0, 0.33, 0],
        dtype=np.float32)
    value = np.array(object=[-1], dtype=np.float32)

    for transform_type in range(16):
        board_t,\
        game_phase_t,\
        next_move_stone_type_t,\
        shl_map_t,\
        policy_t,\
        value_t = TransformFeatures(
            board=board,
            game_phase=game_phase,
            next_move_stone_type=next_move_stone_type,
            shl_map=shl_map,
            policy=policy,
            value=value,
            transform_type=transform_type)

        print("=====================================")
        print("transform_type=", transform_type)
        print("board=\n", board_t)
        print("game_phase=\n", game_phase_t)
        print("next_move_stone_type=\n", next_move_stone_type_t)
        print("shl_score=\n", np.sum(a=shl_map_t, axis=2))
        print("policy=\n", policy_t)
        print("value=\n", value_t)
        print("=====================================")
