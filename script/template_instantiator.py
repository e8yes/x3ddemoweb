from typing import Dict
from typing import List
from script.config import BuildTarget
from script.config import ClusterConfig
from script.config import NodeConfig
from script.run_bash_script import RunSingleCommandInNode

def BuildTargetImageName(deployment_node: NodeConfig,
                         docker_registry_port: int,
                         target: BuildTarget) -> str:
  return "{0}:{1}/{2}".format(
    deployment_node.location, docker_registry_port, target.name)


def BuildVars(cluster_config: ClusterConfig,
              node_configs: Dict[str, NodeConfig],
              build_targets: List[BuildTarget]) -> Dict[str, str]:
  result = dict()
  
  result["{{load_balancer_location}}"] = \
    node_configs[cluster_config.load_balancer].location
  
  result["{{postgres_citus_master_location}}"] = \
    node_configs[cluster_config.postgres_citus_master].location
  result["{{postgres_citus_master_port}}"] = \
    cluster_config.postgres_citus_master_port
  result["{{postgres_citus_master_user}}"] = \
    cluster_config.postgres_citus_master_user
  result["{{postgres_citus_master_password}}"] = \
    cluster_config.postgres_citus_master_password

  result["{{deployment_master_location}}"] = \
    node_configs[cluster_config.deployment_master].location

  for build_target in build_targets:
    if not build_target.pushable:
      continue

    build_target_var_key = "{{" + build_target.name + "_image}}"
    build_target_var_val = BuildTargetImageName(
      deployment_node=node_configs[cluster_config.deployment_master],
      docker_registry_port=cluster_config.deployment_image_registry_port,
      target=build_target)

    result[build_target_var_key] = build_target_var_val

  return result

def ReplaceVarNamesWithValues(content: str, vars: Dict[str, str]) -> str:
  for entry in vars.items():
      content = content.replace(entry[0], entry[1])
  return content

class TemplateInstantiator:
  def __init__(self,
                cluster_config: ClusterConfig,
                node_configs: Dict[str, NodeConfig],
                build_targets: List[BuildTarget]):
    self.vars_ = BuildVars(cluster_config, node_configs, build_targets)
  
  def AddVar(self, name: str, value: str) -> None:
    self.vars_[name] = value

  def __ReadTemplateFile(self, 
                         template_file_path: str, 
                         target_node: NodeConfig):
    if target_node is None:
      with open(template_file_path, "r") as template_file:
        return template_file.read()
      assert(False)
    else:
      content = RunSingleCommandInNode(
        node=target_node, 
        command="cat {0}".format(template_file_path), 
        retrieve_output=True)
      assert(content)
      return content.decode("utf-8")
  
  def __WriteInstantiatedFile(self,
                              content: str,
                              instantiated_file_path: str,
                              target_node):
    if target_node is None:
      with open(instantiated_file_path, "w") as instantiated_file:
        instantiated_file.write(content)
        return
      assert(True)
    else:
      escaped_content = content.replace("\"", "\\\"")
      RunSingleCommandInNode(
        node=target_node, 
        command="echo -e \"{0}\" > {1}"
          .format(escaped_content, instantiated_file_path))

  def Instantiate(self, 
                  template_file_path: str,
                  target_node: NodeConfig) -> str:
    instantiated_file_path = template_file_path.replace(".tmpl", "")
    assert(instantiated_file_path != template_file_path)

    content = self.__ReadTemplateFile(template_file_path=template_file_path, 
                                      target_node=target_node)
    instantiated = ReplaceVarNamesWithValues(content=content, vars=self.vars_)
    self.__WriteInstantiatedFile(content=instantiated, 
                                 instantiated_file_path=instantiated_file_path,
                                 target_node=target_node)

    return instantiated_file_path

