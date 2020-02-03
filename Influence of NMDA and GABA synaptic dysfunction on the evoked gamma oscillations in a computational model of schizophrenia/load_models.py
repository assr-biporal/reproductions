import brian2
import collections

def parse_namespace(namespace_dict):
    return {name : eval(quantity, brian2.core.namespace.DEFAULT_UNITS) for name, quantity in namespace_dict.items()}


def load_neurongroups(neuron_model_dict: dict, neuron_params_dict: dict):
    group_dict = dict()
    for neuron_name, neuron_params in neuron_params_dict.items():
        if 'namespace' in neuron_params:
            neuron_namespace = parse_namespace(neuron_params.pop('namespace'))
        else:
            neuron_namespace = dict()
        neuron_model = neuron_model_dict[neuron_params.pop('eqs')]['eqs']
        group_dict[neuron_name] = brian2.NeuronGroup(
            neuron_params.pop('N'),
            neuron_model,
            name=neuron_name,
            namespace=neuron_namespace,
            **neuron_params,
        )
    return group_dict


def load_synapses(neurongroup_dict: dict, synapse_model_dict: dict, synapse_params_dict_dict_dict: dict):
    synapse_dict = collections.defaultdict(
        lambda: collections.defaultdict(
            lambda: collections.defaultdict(
                dict
            )
        )
    )
    for synapse_type_name, synapse_model in synapse_model_dict.items():
        synapse_model_namespace = synapse_model.pop('namespace')
        for from_neuron_name, synapse_params_dict in synapse_params_dict_dict_dict[synapse_type_name].items():
            for to_neuron_name, synapse_params in synapse_params_dict.items():
                synapse_namespace = parse_namespace(dict(
                    synapse_model_namespace, **synapse_params.pop('namespace')
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
                synapse_dict[synapse_type_name][from_neuron_name][to_neuron_name] = synapse
                synapse.connect(**synapse_params)
    return synapse_dict

if __name__ == '__main__':
    import yaml
    with open('neuron_models.yaml', 'r') as f_models, open('neuron_parameters.yaml', 'r') as f_params:
        neurongroup_dict = load_neurongroups(
            yaml.safe_load(f_models),
            yaml.safe_load(f_params)
        )
    print(neurongroup_dict)
    with open('synapse_models.yaml', 'r') as f_models, open('synapse_parameters.yaml', 'r') as f_params:
        synapse_dict = load_synapses(
            neurongroup_dict,
            yaml.safe_load(f_models),
            yaml.safe_load(f_params)
        )
    print(synapse_dict)