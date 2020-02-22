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


def load_synapses(neurongroup_dict: dict, synapse_model_dict: dict, synapse_params_dict_dict_dict: dict):
    synapse_list = list()

    for synapse_type_name, synapse_model in synapse_model_dict.items():
        synapse_model_namespace = synapse_model.pop('namespace') if 'namespace' in synapse_model else dict()

        for from_neuron_name, synapse_params_dict in synapse_params_dict_dict_dict[synapse_type_name].items():
            for to_neuron_name, synapse_params in synapse_params_dict.items():
                synapse_namespace = parse_namespace(dict(
                    synapse_params.pop('namespace') if 'namespace' in synapse_params else dict(),
                    **synapse_model_namespace
                ))
                synapse = brian2.Synapses(
                    neurongroup_dict[from_neuron_name], neurongroup_dict[to_neuron_name],
                    name='{}_from{}to{}*'.format(
                        synapse_type_name,
                        ''.join(filter(str.isupper, from_neuron_name)),
                        ''.join(filter(str.isupper, to_neuron_name))
                        ),
                    namespace=synapse_namespace,
                    **synapse_model
                )
                synapse_list.append(synapse)
                synapse.connect(**synapse_params)
    return synapse_list

if __name__ == '__main__':
    import yaml
    with open('neuron_model.txt', 'r') as model_f, open('neuron_parameters.yaml', 'r') as params_f:
        neurongroup_dict = load_neurongroups(
            model_f.read(),
            yaml.safe_load(params_f)
        )
    print(neurongroup_dict)
    print(neurongroup_dict['Interneurons'].namespace)

    with open('synapse_models.yaml', 'r') as f_models, open('synapse_parameters.yaml', 'r') as f_params:
        synapse_dict = load_synapses(
            neurongroup_dict,
            yaml.safe_load(f_models),
            yaml.safe_load(f_params)
        )
    print(synapse_dict)