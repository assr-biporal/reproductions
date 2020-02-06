import brian2
import collections

def parse_namespace(namespace_dict):
    return {name : eval(quantity, brian2.core.namespace.DEFAULT_UNITS) for name, quantity in namespace_dict.items()}


def load_neurongroups(neuron_model: str, neuron_params_dict: dict):
    group_dict = dict()
    for neuron_name, neuron_params in neuron_params_dict.items():
        if 'namespace' in neuron_params:
            neuron_namespace = parse_namespace(neuron_params.pop('namespace'))
        else:
            neuron_namespace = dict()

        group_dict[neuron_name] = brian2.NeuronGroup(
            neuron_params.pop('N'),
            neuron_model,
            name=neuron_name,
            namespace=neuron_namespace,
            **neuron_params
        )
    return group_dict


if __name__ == '__main__':
    import yaml
    with open('neuron_model.txt', 'r') as model_f, open('neuron_parameters.yaml', 'r') as params_f:
        neurongroup_dict = load_neurongroups(
            model_f.read(),
            yaml.safe_load(params_f)
        )
    print(neurongroup_dict)
    print(neurongroup_dict['Interneurons'].namespace)