'''
Sample-specific persistent activity
-----------------------------------

Five subpopulations with three selective and one reset stimuli example.
Analog to figure 6b in the paper.

BRUNEL, Nicolas et WANG, Xiao-Jing. Effects of neuromodulation in a cortical network model of object working memory 
dominated by recurrent inhibition. Journal of computational neuroscience, 2001, vol. 11, no 1, p. 63-85.

copy from https://github.com/brian-team/brian2/blob/master/examples/frompapers/Brunel_Wang_2001.py
'''

import brian2
from brian2 import Hz, ms
import numpy


import yaml
import load_models
with open('neuron_model.txt', 'r') as model_f, open('neuron_parameters.yaml', 'r') as params_f:
    neurongroup_dict = load_models.load_neurongroups(
        model_f.read(),
        yaml.safe_load(params_f)
    )

P_E = neurongroup_dict['Pyramidal_Cells']
#P_E.v = V_L
P_I = neurongroup_dict['Interneurons']
#P_I.v = V_L

with open('synapse_models.yaml', 'r') as models_f, open('synapse_parameters.yaml', 'r') as params_f:
    synapse_dict = load_models.load_synapses(
        neurongroup_dict,
        yaml.safe_load(models_f),
        yaml.safe_load(params_f)
    )

# external stimuli
rate = 3 * Hz
C_ext = 800

# subpopulations
f = 0.1
p = 5
N_sub = int(P_E._N * f)
N_non = int(P_E._N * (1. - f * p))
w_plus = 2.1
w_minus = 1. - f * (w_plus - 1.) / (1. - f)


# E to E
C_E_E = synapse_dict['AMPA_NMDA_rec']['Pyramidal_Cells']['Pyramidal_Cells']
C_E_E.w[:] = 1

for pi in range(N_non, N_non + p * N_sub, N_sub):

    # internal other subpopulation to current nonselective
    C_E_E.w[C_E_E.indices[:, pi:pi + N_sub]] = w_minus

    # internal current subpopulation to current subpopulation
    C_E_E.w[C_E_E.indices[pi:pi + N_sub, pi:pi + N_sub]] = w_plus

#plot C_E_E.w
import matplotlib.pyplot as plt

W = numpy.full((P_E._N, P_E._N), 0.)
W[C_E_E.i[:], C_E_E.j[:]] = C_E_E.w[:]
plt.imshow(W)
plt.colorbar()
plt.show()

# external noise
C_P_E = brian2.PoissonInput(P_E, 's_AMPA_ext', C_ext, rate, '1')
C_P_I = brian2.PoissonInput(P_I, 's_AMPA_ext', C_ext, rate, '1')

# at 1s, select population 1
C_selection = int(f * C_ext)
rate_selection = 25 * Hz
stimuli1 = brian2.TimedArray(numpy.r_[numpy.zeros(40), numpy.ones(2), numpy.zeros(100)], dt=25 * ms)
input1 = brian2.PoissonInput(P_E[N_non:N_non + N_sub], 's_AMPA_ext', C_selection, rate_selection, 'stimuli1(t)')

# at 2s, select population 2
stimuli2 = brian2.TimedArray(numpy.r_[numpy.zeros(80), numpy.ones(2), numpy.zeros(100)], dt=25 * ms)
input2 = brian2.PoissonInput(P_E[N_non + N_sub:N_non + 2 * N_sub], 's_AMPA_ext', C_selection, rate_selection, 'stimuli2(t)')

# at 3s, reset selection
stimuli_reset = brian2.TimedArray(numpy.r_[numpy.zeros(120), numpy.ones(2), numpy.zeros(100)], dt=25 * ms)
input_reset_I = brian2.PoissonInput(P_E, 's_AMPA_ext', C_ext, rate_selection, 'stimuli_reset(t)')
input_reset_E = brian2.PoissonInput(P_I, 's_AMPA_ext', C_ext, rate_selection, 'stimuli_reset(t)')

# monitors
N_activity_plot = 15
sp_E_sels = [brian2.SpikeMonitor(P_E[pi:pi + N_activity_plot]) for pi in range(N_non, N_non + p * N_sub, N_sub)]
sp_E = brian2.SpikeMonitor(P_E[:N_activity_plot])
sp_I = brian2.SpikeMonitor(P_I[:N_activity_plot])

r_E_sels = [brian2.PopulationRateMonitor(P_E[pi:pi + N_sub]) for pi in range(N_non, N_non + p * N_sub, N_sub)]
r_E = brian2.PopulationRateMonitor(P_E[:N_non])
r_I = brian2.PopulationRateMonitor(P_I)

# simulate, can be long >120s
net = brian2.Network(brian2.collect())
net.add(sp_E_sels)
net.add(r_E_sels)
net.run(4 * brian2.second, report='stdout')

# plotting
import matplotlib.pyplot as plt
plt.title('Population rates')
plt.xlabel('ms')
plt.ylabel('Hz')

plt.plot(r_E.t / ms, r_E.smooth_rate(width=25 * ms) / Hz, label='nonselective')
plt.plot(r_I.t / ms, r_I.smooth_rate(width=25 * ms) / Hz, label='inhibitory')

for i, r_E_sel in enumerate(r_E_sels[::-1]):
    plt.plot(r_E_sel.t / ms, r_E_sel.smooth_rate(width=25 * ms) / Hz, label='selective {}'.format(p - i))

plt.legend()
plt.figure()

plt.title('Population activities ({} neurons/pop)'.format(N_activity_plot))
plt.xlabel('ms')
plt.yticks([])

plt.plot(sp_E.t / ms, sp_E.i + (p + 1) * N_activity_plot, '.', markersize=2, label='nonselective')
plt.plot(sp_I.t / ms, sp_I.i + p * N_activity_plot, '.', markersize=2, label='inhibitory')

for i, sp_E_sel in enumerate(sp_E_sels[::-1]):
    plt.plot(sp_E_sel.t / ms, sp_E_sel.i + (p - i - 1) * N_activity_plot, '.', markersize=2, label='selective {}'.format(p - i))

plt.legend()
plt.show()