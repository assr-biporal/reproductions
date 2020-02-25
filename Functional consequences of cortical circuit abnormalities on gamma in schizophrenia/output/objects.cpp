
#include "objects.h"
#include "synapses_classes.h"
#include "brianlib/clocks.h"
#include "brianlib/dynamic_array.h"
#include "brianlib/stdint_compat.h"
#include "network.h"
#include "randomkit.h"
#include<vector>
#include<iostream>
#include<fstream>

namespace brian {

std::vector< rk_state* > _mersenne_twister_states;

//////////////// networks /////////////////
Network magicnetwork;
Network network;

//////////////// arrays ///////////////////
int32_t * _array_AMPA_NMDA_fromPCtoFSI_N;
const int _num__array_AMPA_NMDA_fromPCtoFSI_N = 1;
int32_t * _array_AMPA_NMDA_fromPCtoPC_N;
const int _num__array_AMPA_NMDA_fromPCtoPC_N = 1;
int32_t * _array_AMPA_NMDA_fromPCtoRSI_N;
const int _num__array_AMPA_NMDA_fromPCtoRSI_N = 1;
double * _array_defaultclock_dt;
const int _num__array_defaultclock_dt = 1;
double * _array_defaultclock_t;
const int _num__array_defaultclock_t = 1;
int64_t * _array_defaultclock_timestep;
const int _num__array_defaultclock_timestep = 1;
int32_t * _array_Fast_Spiking_Interneurons__spikespace;
const int _num__array_Fast_Spiking_Interneurons__spikespace = 51;
double * _array_Fast_Spiking_Interneurons_g_AMPA_d;
const int _num__array_Fast_Spiking_Interneurons_g_AMPA_d = 50;
double * _array_Fast_Spiking_Interneurons_g_AMPA_r;
const int _num__array_Fast_Spiking_Interneurons_g_AMPA_r = 50;
double * _array_Fast_Spiking_Interneurons_g_GABA_d;
const int _num__array_Fast_Spiking_Interneurons_g_GABA_d = 50;
double * _array_Fast_Spiking_Interneurons_g_GABA_r;
const int _num__array_Fast_Spiking_Interneurons_g_GABA_r = 50;
double * _array_Fast_Spiking_Interneurons_g_NMDA_d;
const int _num__array_Fast_Spiking_Interneurons_g_NMDA_d = 50;
double * _array_Fast_Spiking_Interneurons_g_NMDA_r;
const int _num__array_Fast_Spiking_Interneurons_g_NMDA_r = 50;
int32_t * _array_Fast_Spiking_Interneurons_i;
const int _num__array_Fast_Spiking_Interneurons_i = 50;
double * _array_Fast_Spiking_Interneurons_v;
const int _num__array_Fast_Spiking_Interneurons_v = 50;
int32_t * _array_GABA_fromFSItoFSI_N;
const int _num__array_GABA_fromFSItoFSI_N = 1;
int32_t * _array_GABA_fromFSItoPC_N;
const int _num__array_GABA_fromFSItoPC_N = 1;
int32_t * _array_GABA_fromFSItoRSI_N;
const int _num__array_GABA_fromFSItoRSI_N = 1;
int32_t * _array_GABA_fromRSItoFSI_N;
const int _num__array_GABA_fromRSItoFSI_N = 1;
int32_t * _array_GABA_fromRSItoPC_N;
const int _num__array_GABA_fromRSItoPC_N = 1;
int32_t * _array_GABA_fromRSItoRSI_N;
const int _num__array_GABA_fromRSItoRSI_N = 1;
int32_t * _array_poissongroup__spikespace;
const int _num__array_poissongroup__spikespace = 801;
int32_t * _array_poissongroup_i;
const int _num__array_poissongroup_i = 800;
double * _array_poissongroup_rates;
const int _num__array_poissongroup_rates = 800;
int32_t * _array_Pyramidal_Cells__spikespace;
const int _num__array_Pyramidal_Cells__spikespace = 801;
double * _array_Pyramidal_Cells_g_AMPA_d;
const int _num__array_Pyramidal_Cells_g_AMPA_d = 800;
double * _array_Pyramidal_Cells_g_AMPA_r;
const int _num__array_Pyramidal_Cells_g_AMPA_r = 800;
double * _array_Pyramidal_Cells_g_GABA_d;
const int _num__array_Pyramidal_Cells_g_GABA_d = 800;
double * _array_Pyramidal_Cells_g_GABA_r;
const int _num__array_Pyramidal_Cells_g_GABA_r = 800;
double * _array_Pyramidal_Cells_g_NMDA_d;
const int _num__array_Pyramidal_Cells_g_NMDA_d = 800;
double * _array_Pyramidal_Cells_g_NMDA_r;
const int _num__array_Pyramidal_Cells_g_NMDA_r = 800;
int32_t * _array_Pyramidal_Cells_i;
const int _num__array_Pyramidal_Cells_i = 800;
double * _array_Pyramidal_Cells_v;
const int _num__array_Pyramidal_Cells_v = 800;
int32_t * _array_Regular_Spiking_Interneurons__spikespace;
const int _num__array_Regular_Spiking_Interneurons__spikespace = 151;
double * _array_Regular_Spiking_Interneurons_g_AMPA_d;
const int _num__array_Regular_Spiking_Interneurons_g_AMPA_d = 150;
double * _array_Regular_Spiking_Interneurons_g_AMPA_r;
const int _num__array_Regular_Spiking_Interneurons_g_AMPA_r = 150;
double * _array_Regular_Spiking_Interneurons_g_GABA_d;
const int _num__array_Regular_Spiking_Interneurons_g_GABA_d = 150;
double * _array_Regular_Spiking_Interneurons_g_GABA_r;
const int _num__array_Regular_Spiking_Interneurons_g_GABA_r = 150;
double * _array_Regular_Spiking_Interneurons_g_NMDA_d;
const int _num__array_Regular_Spiking_Interneurons_g_NMDA_d = 150;
double * _array_Regular_Spiking_Interneurons_g_NMDA_r;
const int _num__array_Regular_Spiking_Interneurons_g_NMDA_r = 150;
int32_t * _array_Regular_Spiking_Interneurons_i;
const int _num__array_Regular_Spiking_Interneurons_i = 150;
double * _array_Regular_Spiking_Interneurons_v;
const int _num__array_Regular_Spiking_Interneurons_v = 150;
int32_t * _array_spikemonitor_1__source_idx;
const int _num__array_spikemonitor_1__source_idx = 150;
int32_t * _array_spikemonitor_1_count;
const int _num__array_spikemonitor_1_count = 150;
int32_t * _array_spikemonitor_1_N;
const int _num__array_spikemonitor_1_N = 1;
int32_t * _array_spikemonitor_2__source_idx;
const int _num__array_spikemonitor_2__source_idx = 50;
int32_t * _array_spikemonitor_2_count;
const int _num__array_spikemonitor_2_count = 50;
int32_t * _array_spikemonitor_2_N;
const int _num__array_spikemonitor_2_N = 1;
int32_t * _array_spikemonitor_3__source_idx;
const int _num__array_spikemonitor_3__source_idx = 800;
int32_t * _array_spikemonitor_3_count;
const int _num__array_spikemonitor_3_count = 800;
int32_t * _array_spikemonitor_3_N;
const int _num__array_spikemonitor_3_N = 1;
int32_t * _array_spikemonitor__source_idx;
const int _num__array_spikemonitor__source_idx = 800;
int32_t * _array_spikemonitor_count;
const int _num__array_spikemonitor_count = 800;
int32_t * _array_spikemonitor_N;
const int _num__array_spikemonitor_N = 1;
int32_t * _array_statemonitor_10__indices;
const int _num__array_statemonitor_10__indices = 10;
double * _array_statemonitor_10_g_AMPA_d;
const int _num__array_statemonitor_10_g_AMPA_d = (0, 10);
double * _array_statemonitor_10_g_GABA_d;
const int _num__array_statemonitor_10_g_GABA_d = (0, 10);
double * _array_statemonitor_10_g_NMDA_d;
const int _num__array_statemonitor_10_g_NMDA_d = (0, 10);
int32_t * _array_statemonitor_10_N;
const int _num__array_statemonitor_10_N = 1;
int32_t * _array_statemonitor_11__indices;
const int _num__array_statemonitor_11__indices = 10;
double * _array_statemonitor_11_g_AMPA_d;
const int _num__array_statemonitor_11_g_AMPA_d = (0, 10);
double * _array_statemonitor_11_g_GABA_d;
const int _num__array_statemonitor_11_g_GABA_d = (0, 10);
double * _array_statemonitor_11_g_NMDA_d;
const int _num__array_statemonitor_11_g_NMDA_d = (0, 10);
int32_t * _array_statemonitor_11_N;
const int _num__array_statemonitor_11_N = 1;
int32_t * _array_statemonitor_12__indices;
const int _num__array_statemonitor_12__indices = 10;
double * _array_statemonitor_12_I_AMPA;
const int _num__array_statemonitor_12_I_AMPA = (0, 10);
double * _array_statemonitor_12_I_GABA;
const int _num__array_statemonitor_12_I_GABA = (0, 10);
double * _array_statemonitor_12_I_NMDA;
const int _num__array_statemonitor_12_I_NMDA = (0, 10);
double * _array_statemonitor_12_I_syn;
const int _num__array_statemonitor_12_I_syn = (0, 10);
int32_t * _array_statemonitor_12_N;
const int _num__array_statemonitor_12_N = 1;
int32_t * _array_statemonitor_13__indices;
const int _num__array_statemonitor_13__indices = 10;
double * _array_statemonitor_13_I_AMPA;
const int _num__array_statemonitor_13_I_AMPA = (0, 10);
double * _array_statemonitor_13_I_GABA;
const int _num__array_statemonitor_13_I_GABA = (0, 10);
double * _array_statemonitor_13_I_NMDA;
const int _num__array_statemonitor_13_I_NMDA = (0, 10);
double * _array_statemonitor_13_I_syn;
const int _num__array_statemonitor_13_I_syn = (0, 10);
int32_t * _array_statemonitor_13_N;
const int _num__array_statemonitor_13_N = 1;
int32_t * _array_statemonitor_14__indices;
const int _num__array_statemonitor_14__indices = 10;
double * _array_statemonitor_14_I_AMPA;
const int _num__array_statemonitor_14_I_AMPA = (0, 10);
double * _array_statemonitor_14_I_GABA;
const int _num__array_statemonitor_14_I_GABA = (0, 10);
double * _array_statemonitor_14_I_NMDA;
const int _num__array_statemonitor_14_I_NMDA = (0, 10);
double * _array_statemonitor_14_I_syn;
const int _num__array_statemonitor_14_I_syn = (0, 10);
int32_t * _array_statemonitor_14_N;
const int _num__array_statemonitor_14_N = 1;
int32_t * _array_statemonitor_1__indices;
const int _num__array_statemonitor_1__indices = 10;
int32_t * _array_statemonitor_1_N;
const int _num__array_statemonitor_1_N = 1;
double * _array_statemonitor_1_v;
const int _num__array_statemonitor_1_v = (0, 10);
int32_t * _array_statemonitor_2__indices;
const int _num__array_statemonitor_2__indices = 10;
int32_t * _array_statemonitor_2_N;
const int _num__array_statemonitor_2_N = 1;
double * _array_statemonitor_2_v;
const int _num__array_statemonitor_2_v = (0, 10);
int32_t * _array_statemonitor_3__indices;
const int _num__array_statemonitor_3__indices = 10;
double * _array_statemonitor_3_g_AMPA;
const int _num__array_statemonitor_3_g_AMPA = (0, 10);
double * _array_statemonitor_3_g_GABA;
const int _num__array_statemonitor_3_g_GABA = (0, 10);
double * _array_statemonitor_3_g_NMDA;
const int _num__array_statemonitor_3_g_NMDA = (0, 10);
int32_t * _array_statemonitor_3_N;
const int _num__array_statemonitor_3_N = 1;
int32_t * _array_statemonitor_4__indices;
const int _num__array_statemonitor_4__indices = 10;
double * _array_statemonitor_4_g_AMPA;
const int _num__array_statemonitor_4_g_AMPA = (0, 10);
double * _array_statemonitor_4_g_GABA;
const int _num__array_statemonitor_4_g_GABA = (0, 10);
double * _array_statemonitor_4_g_NMDA;
const int _num__array_statemonitor_4_g_NMDA = (0, 10);
int32_t * _array_statemonitor_4_N;
const int _num__array_statemonitor_4_N = 1;
int32_t * _array_statemonitor_5__indices;
const int _num__array_statemonitor_5__indices = 10;
double * _array_statemonitor_5_g_AMPA;
const int _num__array_statemonitor_5_g_AMPA = (0, 10);
double * _array_statemonitor_5_g_GABA;
const int _num__array_statemonitor_5_g_GABA = (0, 10);
double * _array_statemonitor_5_g_NMDA;
const int _num__array_statemonitor_5_g_NMDA = (0, 10);
int32_t * _array_statemonitor_5_N;
const int _num__array_statemonitor_5_N = 1;
int32_t * _array_statemonitor_6__indices;
const int _num__array_statemonitor_6__indices = 10;
double * _array_statemonitor_6_g_AMPA_r;
const int _num__array_statemonitor_6_g_AMPA_r = (0, 10);
double * _array_statemonitor_6_g_GABA_r;
const int _num__array_statemonitor_6_g_GABA_r = (0, 10);
double * _array_statemonitor_6_g_NMDA_r;
const int _num__array_statemonitor_6_g_NMDA_r = (0, 10);
int32_t * _array_statemonitor_6_N;
const int _num__array_statemonitor_6_N = 1;
int32_t * _array_statemonitor_7__indices;
const int _num__array_statemonitor_7__indices = 10;
double * _array_statemonitor_7_g_AMPA_r;
const int _num__array_statemonitor_7_g_AMPA_r = (0, 10);
double * _array_statemonitor_7_g_GABA_r;
const int _num__array_statemonitor_7_g_GABA_r = (0, 10);
double * _array_statemonitor_7_g_NMDA_r;
const int _num__array_statemonitor_7_g_NMDA_r = (0, 10);
int32_t * _array_statemonitor_7_N;
const int _num__array_statemonitor_7_N = 1;
int32_t * _array_statemonitor_8__indices;
const int _num__array_statemonitor_8__indices = 10;
double * _array_statemonitor_8_g_AMPA_r;
const int _num__array_statemonitor_8_g_AMPA_r = (0, 10);
double * _array_statemonitor_8_g_GABA_r;
const int _num__array_statemonitor_8_g_GABA_r = (0, 10);
double * _array_statemonitor_8_g_NMDA_r;
const int _num__array_statemonitor_8_g_NMDA_r = (0, 10);
int32_t * _array_statemonitor_8_N;
const int _num__array_statemonitor_8_N = 1;
int32_t * _array_statemonitor_9__indices;
const int _num__array_statemonitor_9__indices = 10;
double * _array_statemonitor_9_g_AMPA_d;
const int _num__array_statemonitor_9_g_AMPA_d = (0, 10);
double * _array_statemonitor_9_g_GABA_d;
const int _num__array_statemonitor_9_g_GABA_d = (0, 10);
double * _array_statemonitor_9_g_NMDA_d;
const int _num__array_statemonitor_9_g_NMDA_d = (0, 10);
int32_t * _array_statemonitor_9_N;
const int _num__array_statemonitor_9_N = 1;
int32_t * _array_statemonitor__indices;
const int _num__array_statemonitor__indices = 10;
int32_t * _array_statemonitor_N;
const int _num__array_statemonitor_N = 1;
double * _array_statemonitor_v;
const int _num__array_statemonitor_v = (0, 10);
int32_t * _array_synapses_N;
const int _num__array_synapses_N = 1;

//////////////// dynamic arrays 1d /////////
std::vector<int32_t> _dynamic_array_AMPA_NMDA_fromPCtoFSI__synaptic_post;
std::vector<int32_t> _dynamic_array_AMPA_NMDA_fromPCtoFSI__synaptic_pre;
std::vector<double> _dynamic_array_AMPA_NMDA_fromPCtoFSI_delay;
std::vector<int32_t> _dynamic_array_AMPA_NMDA_fromPCtoFSI_N_incoming;
std::vector<int32_t> _dynamic_array_AMPA_NMDA_fromPCtoFSI_N_outgoing;
std::vector<int32_t> _dynamic_array_AMPA_NMDA_fromPCtoPC__synaptic_post;
std::vector<int32_t> _dynamic_array_AMPA_NMDA_fromPCtoPC__synaptic_pre;
std::vector<double> _dynamic_array_AMPA_NMDA_fromPCtoPC_delay;
std::vector<int32_t> _dynamic_array_AMPA_NMDA_fromPCtoPC_N_incoming;
std::vector<int32_t> _dynamic_array_AMPA_NMDA_fromPCtoPC_N_outgoing;
std::vector<int32_t> _dynamic_array_AMPA_NMDA_fromPCtoRSI__synaptic_post;
std::vector<int32_t> _dynamic_array_AMPA_NMDA_fromPCtoRSI__synaptic_pre;
std::vector<double> _dynamic_array_AMPA_NMDA_fromPCtoRSI_delay;
std::vector<int32_t> _dynamic_array_AMPA_NMDA_fromPCtoRSI_N_incoming;
std::vector<int32_t> _dynamic_array_AMPA_NMDA_fromPCtoRSI_N_outgoing;
std::vector<int32_t> _dynamic_array_GABA_fromFSItoFSI__synaptic_post;
std::vector<int32_t> _dynamic_array_GABA_fromFSItoFSI__synaptic_pre;
std::vector<double> _dynamic_array_GABA_fromFSItoFSI_delay;
std::vector<int32_t> _dynamic_array_GABA_fromFSItoFSI_N_incoming;
std::vector<int32_t> _dynamic_array_GABA_fromFSItoFSI_N_outgoing;
std::vector<int32_t> _dynamic_array_GABA_fromFSItoPC__synaptic_post;
std::vector<int32_t> _dynamic_array_GABA_fromFSItoPC__synaptic_pre;
std::vector<double> _dynamic_array_GABA_fromFSItoPC_delay;
std::vector<int32_t> _dynamic_array_GABA_fromFSItoPC_N_incoming;
std::vector<int32_t> _dynamic_array_GABA_fromFSItoPC_N_outgoing;
std::vector<int32_t> _dynamic_array_GABA_fromFSItoRSI__synaptic_post;
std::vector<int32_t> _dynamic_array_GABA_fromFSItoRSI__synaptic_pre;
std::vector<double> _dynamic_array_GABA_fromFSItoRSI_delay;
std::vector<int32_t> _dynamic_array_GABA_fromFSItoRSI_N_incoming;
std::vector<int32_t> _dynamic_array_GABA_fromFSItoRSI_N_outgoing;
std::vector<int32_t> _dynamic_array_GABA_fromRSItoFSI__synaptic_post;
std::vector<int32_t> _dynamic_array_GABA_fromRSItoFSI__synaptic_pre;
std::vector<double> _dynamic_array_GABA_fromRSItoFSI_delay;
std::vector<int32_t> _dynamic_array_GABA_fromRSItoFSI_N_incoming;
std::vector<int32_t> _dynamic_array_GABA_fromRSItoFSI_N_outgoing;
std::vector<int32_t> _dynamic_array_GABA_fromRSItoPC__synaptic_post;
std::vector<int32_t> _dynamic_array_GABA_fromRSItoPC__synaptic_pre;
std::vector<double> _dynamic_array_GABA_fromRSItoPC_delay;
std::vector<int32_t> _dynamic_array_GABA_fromRSItoPC_N_incoming;
std::vector<int32_t> _dynamic_array_GABA_fromRSItoPC_N_outgoing;
std::vector<int32_t> _dynamic_array_GABA_fromRSItoRSI__synaptic_post;
std::vector<int32_t> _dynamic_array_GABA_fromRSItoRSI__synaptic_pre;
std::vector<double> _dynamic_array_GABA_fromRSItoRSI_delay;
std::vector<int32_t> _dynamic_array_GABA_fromRSItoRSI_N_incoming;
std::vector<int32_t> _dynamic_array_GABA_fromRSItoRSI_N_outgoing;
std::vector<int32_t> _dynamic_array_spikemonitor_1_i;
std::vector<double> _dynamic_array_spikemonitor_1_t;
std::vector<int32_t> _dynamic_array_spikemonitor_2_i;
std::vector<double> _dynamic_array_spikemonitor_2_t;
std::vector<int32_t> _dynamic_array_spikemonitor_3_i;
std::vector<double> _dynamic_array_spikemonitor_3_t;
std::vector<int32_t> _dynamic_array_spikemonitor_i;
std::vector<double> _dynamic_array_spikemonitor_t;
std::vector<double> _dynamic_array_statemonitor_10_t;
std::vector<double> _dynamic_array_statemonitor_11_t;
std::vector<double> _dynamic_array_statemonitor_12_t;
std::vector<double> _dynamic_array_statemonitor_13_t;
std::vector<double> _dynamic_array_statemonitor_14_t;
std::vector<double> _dynamic_array_statemonitor_1_t;
std::vector<double> _dynamic_array_statemonitor_2_t;
std::vector<double> _dynamic_array_statemonitor_3_t;
std::vector<double> _dynamic_array_statemonitor_4_t;
std::vector<double> _dynamic_array_statemonitor_5_t;
std::vector<double> _dynamic_array_statemonitor_6_t;
std::vector<double> _dynamic_array_statemonitor_7_t;
std::vector<double> _dynamic_array_statemonitor_8_t;
std::vector<double> _dynamic_array_statemonitor_9_t;
std::vector<double> _dynamic_array_statemonitor_t;
std::vector<int32_t> _dynamic_array_synapses__synaptic_post;
std::vector<int32_t> _dynamic_array_synapses__synaptic_pre;
std::vector<double> _dynamic_array_synapses_delay;
std::vector<int32_t> _dynamic_array_synapses_N_incoming;
std::vector<int32_t> _dynamic_array_synapses_N_outgoing;

//////////////// dynamic arrays 2d /////////
DynamicArray2D<double> _dynamic_array_statemonitor_10_g_AMPA_d;
DynamicArray2D<double> _dynamic_array_statemonitor_10_g_GABA_d;
DynamicArray2D<double> _dynamic_array_statemonitor_10_g_NMDA_d;
DynamicArray2D<double> _dynamic_array_statemonitor_11_g_AMPA_d;
DynamicArray2D<double> _dynamic_array_statemonitor_11_g_GABA_d;
DynamicArray2D<double> _dynamic_array_statemonitor_11_g_NMDA_d;
DynamicArray2D<double> _dynamic_array_statemonitor_12_I_AMPA;
DynamicArray2D<double> _dynamic_array_statemonitor_12_I_GABA;
DynamicArray2D<double> _dynamic_array_statemonitor_12_I_NMDA;
DynamicArray2D<double> _dynamic_array_statemonitor_12_I_syn;
DynamicArray2D<double> _dynamic_array_statemonitor_13_I_AMPA;
DynamicArray2D<double> _dynamic_array_statemonitor_13_I_GABA;
DynamicArray2D<double> _dynamic_array_statemonitor_13_I_NMDA;
DynamicArray2D<double> _dynamic_array_statemonitor_13_I_syn;
DynamicArray2D<double> _dynamic_array_statemonitor_14_I_AMPA;
DynamicArray2D<double> _dynamic_array_statemonitor_14_I_GABA;
DynamicArray2D<double> _dynamic_array_statemonitor_14_I_NMDA;
DynamicArray2D<double> _dynamic_array_statemonitor_14_I_syn;
DynamicArray2D<double> _dynamic_array_statemonitor_1_v;
DynamicArray2D<double> _dynamic_array_statemonitor_2_v;
DynamicArray2D<double> _dynamic_array_statemonitor_3_g_AMPA;
DynamicArray2D<double> _dynamic_array_statemonitor_3_g_GABA;
DynamicArray2D<double> _dynamic_array_statemonitor_3_g_NMDA;
DynamicArray2D<double> _dynamic_array_statemonitor_4_g_AMPA;
DynamicArray2D<double> _dynamic_array_statemonitor_4_g_GABA;
DynamicArray2D<double> _dynamic_array_statemonitor_4_g_NMDA;
DynamicArray2D<double> _dynamic_array_statemonitor_5_g_AMPA;
DynamicArray2D<double> _dynamic_array_statemonitor_5_g_GABA;
DynamicArray2D<double> _dynamic_array_statemonitor_5_g_NMDA;
DynamicArray2D<double> _dynamic_array_statemonitor_6_g_AMPA_r;
DynamicArray2D<double> _dynamic_array_statemonitor_6_g_GABA_r;
DynamicArray2D<double> _dynamic_array_statemonitor_6_g_NMDA_r;
DynamicArray2D<double> _dynamic_array_statemonitor_7_g_AMPA_r;
DynamicArray2D<double> _dynamic_array_statemonitor_7_g_GABA_r;
DynamicArray2D<double> _dynamic_array_statemonitor_7_g_NMDA_r;
DynamicArray2D<double> _dynamic_array_statemonitor_8_g_AMPA_r;
DynamicArray2D<double> _dynamic_array_statemonitor_8_g_GABA_r;
DynamicArray2D<double> _dynamic_array_statemonitor_8_g_NMDA_r;
DynamicArray2D<double> _dynamic_array_statemonitor_9_g_AMPA_d;
DynamicArray2D<double> _dynamic_array_statemonitor_9_g_GABA_d;
DynamicArray2D<double> _dynamic_array_statemonitor_9_g_NMDA_d;
DynamicArray2D<double> _dynamic_array_statemonitor_v;

/////////////// static arrays /////////////
int32_t * _static_array__array_statemonitor_10__indices;
const int _num__static_array__array_statemonitor_10__indices = 10;
int32_t * _static_array__array_statemonitor_11__indices;
const int _num__static_array__array_statemonitor_11__indices = 10;
int32_t * _static_array__array_statemonitor_12__indices;
const int _num__static_array__array_statemonitor_12__indices = 10;
int32_t * _static_array__array_statemonitor_13__indices;
const int _num__static_array__array_statemonitor_13__indices = 10;
int32_t * _static_array__array_statemonitor_14__indices;
const int _num__static_array__array_statemonitor_14__indices = 10;
int32_t * _static_array__array_statemonitor_1__indices;
const int _num__static_array__array_statemonitor_1__indices = 10;
int32_t * _static_array__array_statemonitor_2__indices;
const int _num__static_array__array_statemonitor_2__indices = 10;
int32_t * _static_array__array_statemonitor_3__indices;
const int _num__static_array__array_statemonitor_3__indices = 10;
int32_t * _static_array__array_statemonitor_4__indices;
const int _num__static_array__array_statemonitor_4__indices = 10;
int32_t * _static_array__array_statemonitor_5__indices;
const int _num__static_array__array_statemonitor_5__indices = 10;
int32_t * _static_array__array_statemonitor_6__indices;
const int _num__static_array__array_statemonitor_6__indices = 10;
int32_t * _static_array__array_statemonitor_7__indices;
const int _num__static_array__array_statemonitor_7__indices = 10;
int32_t * _static_array__array_statemonitor_8__indices;
const int _num__static_array__array_statemonitor_8__indices = 10;
int32_t * _static_array__array_statemonitor_9__indices;
const int _num__static_array__array_statemonitor_9__indices = 10;
int32_t * _static_array__array_statemonitor__indices;
const int _num__static_array__array_statemonitor__indices = 10;

//////////////// synapses /////////////////
// AMPA_NMDA_fromPCtoFSI
SynapticPathway AMPA_NMDA_fromPCtoFSI_pre(
		_dynamic_array_AMPA_NMDA_fromPCtoFSI__synaptic_pre,
		0, 800);
// AMPA_NMDA_fromPCtoPC
SynapticPathway AMPA_NMDA_fromPCtoPC_pre(
		_dynamic_array_AMPA_NMDA_fromPCtoPC__synaptic_pre,
		0, 800);
// AMPA_NMDA_fromPCtoRSI
SynapticPathway AMPA_NMDA_fromPCtoRSI_pre(
		_dynamic_array_AMPA_NMDA_fromPCtoRSI__synaptic_pre,
		0, 800);
// GABA_fromFSItoFSI
SynapticPathway GABA_fromFSItoFSI_pre(
		_dynamic_array_GABA_fromFSItoFSI__synaptic_pre,
		0, 50);
// GABA_fromFSItoPC
SynapticPathway GABA_fromFSItoPC_pre(
		_dynamic_array_GABA_fromFSItoPC__synaptic_pre,
		0, 50);
// GABA_fromFSItoRSI
SynapticPathway GABA_fromFSItoRSI_pre(
		_dynamic_array_GABA_fromFSItoRSI__synaptic_pre,
		0, 50);
// GABA_fromRSItoFSI
SynapticPathway GABA_fromRSItoFSI_pre(
		_dynamic_array_GABA_fromRSItoFSI__synaptic_pre,
		0, 150);
// GABA_fromRSItoPC
SynapticPathway GABA_fromRSItoPC_pre(
		_dynamic_array_GABA_fromRSItoPC__synaptic_pre,
		0, 150);
// GABA_fromRSItoRSI
SynapticPathway GABA_fromRSItoRSI_pre(
		_dynamic_array_GABA_fromRSItoRSI__synaptic_pre,
		0, 150);
// synapses
SynapticPathway synapses_pre(
		_dynamic_array_synapses__synaptic_pre,
		0, 800);

//////////////// clocks ///////////////////
Clock defaultclock;  // attributes will be set in run.cpp

// Profiling information for each code object
}

void _init_arrays()
{
	using namespace brian;

    // Arrays initialized to 0
	_array_AMPA_NMDA_fromPCtoFSI_N = new int32_t[1];
    #pragma omp parallel for schedule(static)
	for(int i=0; i<1; i++) _array_AMPA_NMDA_fromPCtoFSI_N[i] = 0;

	_array_AMPA_NMDA_fromPCtoPC_N = new int32_t[1];
    #pragma omp parallel for schedule(static)
	for(int i=0; i<1; i++) _array_AMPA_NMDA_fromPCtoPC_N[i] = 0;

	_array_AMPA_NMDA_fromPCtoRSI_N = new int32_t[1];
    #pragma omp parallel for schedule(static)
	for(int i=0; i<1; i++) _array_AMPA_NMDA_fromPCtoRSI_N[i] = 0;

	_array_defaultclock_dt = new double[1];
    #pragma omp parallel for schedule(static)
	for(int i=0; i<1; i++) _array_defaultclock_dt[i] = 0;

	_array_defaultclock_t = new double[1];
    #pragma omp parallel for schedule(static)
	for(int i=0; i<1; i++) _array_defaultclock_t[i] = 0;

	_array_defaultclock_timestep = new int64_t[1];
    #pragma omp parallel for schedule(static)
	for(int i=0; i<1; i++) _array_defaultclock_timestep[i] = 0;

	_array_Fast_Spiking_Interneurons__spikespace = new int32_t[51];
    #pragma omp parallel for schedule(static)
	for(int i=0; i<51; i++) _array_Fast_Spiking_Interneurons__spikespace[i] = 0;

	_array_Fast_Spiking_Interneurons_g_AMPA_d = new double[50];
    #pragma omp parallel for schedule(static)
	for(int i=0; i<50; i++) _array_Fast_Spiking_Interneurons_g_AMPA_d[i] = 0;

	_array_Fast_Spiking_Interneurons_g_AMPA_r = new double[50];
    #pragma omp parallel for schedule(static)
	for(int i=0; i<50; i++) _array_Fast_Spiking_Interneurons_g_AMPA_r[i] = 0;

	_array_Fast_Spiking_Interneurons_g_GABA_d = new double[50];
    #pragma omp parallel for schedule(static)
	for(int i=0; i<50; i++) _array_Fast_Spiking_Interneurons_g_GABA_d[i] = 0;

	_array_Fast_Spiking_Interneurons_g_GABA_r = new double[50];
    #pragma omp parallel for schedule(static)
	for(int i=0; i<50; i++) _array_Fast_Spiking_Interneurons_g_GABA_r[i] = 0;

	_array_Fast_Spiking_Interneurons_g_NMDA_d = new double[50];
    #pragma omp parallel for schedule(static)
	for(int i=0; i<50; i++) _array_Fast_Spiking_Interneurons_g_NMDA_d[i] = 0;

	_array_Fast_Spiking_Interneurons_g_NMDA_r = new double[50];
    #pragma omp parallel for schedule(static)
	for(int i=0; i<50; i++) _array_Fast_Spiking_Interneurons_g_NMDA_r[i] = 0;

	_array_Fast_Spiking_Interneurons_i = new int32_t[50];
    #pragma omp parallel for schedule(static)
	for(int i=0; i<50; i++) _array_Fast_Spiking_Interneurons_i[i] = 0;

	_array_Fast_Spiking_Interneurons_v = new double[50];
    #pragma omp parallel for schedule(static)
	for(int i=0; i<50; i++) _array_Fast_Spiking_Interneurons_v[i] = 0;

	_array_GABA_fromFSItoFSI_N = new int32_t[1];
    #pragma omp parallel for schedule(static)
	for(int i=0; i<1; i++) _array_GABA_fromFSItoFSI_N[i] = 0;

	_array_GABA_fromFSItoPC_N = new int32_t[1];
    #pragma omp parallel for schedule(static)
	for(int i=0; i<1; i++) _array_GABA_fromFSItoPC_N[i] = 0;

	_array_GABA_fromFSItoRSI_N = new int32_t[1];
    #pragma omp parallel for schedule(static)
	for(int i=0; i<1; i++) _array_GABA_fromFSItoRSI_N[i] = 0;

	_array_GABA_fromRSItoFSI_N = new int32_t[1];
    #pragma omp parallel for schedule(static)
	for(int i=0; i<1; i++) _array_GABA_fromRSItoFSI_N[i] = 0;

	_array_GABA_fromRSItoPC_N = new int32_t[1];
    #pragma omp parallel for schedule(static)
	for(int i=0; i<1; i++) _array_GABA_fromRSItoPC_N[i] = 0;

	_array_GABA_fromRSItoRSI_N = new int32_t[1];
    #pragma omp parallel for schedule(static)
	for(int i=0; i<1; i++) _array_GABA_fromRSItoRSI_N[i] = 0;

	_array_poissongroup__spikespace = new int32_t[801];
    #pragma omp parallel for schedule(static)
	for(int i=0; i<801; i++) _array_poissongroup__spikespace[i] = 0;

	_array_poissongroup_i = new int32_t[800];
    #pragma omp parallel for schedule(static)
	for(int i=0; i<800; i++) _array_poissongroup_i[i] = 0;

	_array_poissongroup_rates = new double[800];
    #pragma omp parallel for schedule(static)
	for(int i=0; i<800; i++) _array_poissongroup_rates[i] = 0;

	_array_Pyramidal_Cells__spikespace = new int32_t[801];
    #pragma omp parallel for schedule(static)
	for(int i=0; i<801; i++) _array_Pyramidal_Cells__spikespace[i] = 0;

	_array_Pyramidal_Cells_g_AMPA_d = new double[800];
    #pragma omp parallel for schedule(static)
	for(int i=0; i<800; i++) _array_Pyramidal_Cells_g_AMPA_d[i] = 0;

	_array_Pyramidal_Cells_g_AMPA_r = new double[800];
    #pragma omp parallel for schedule(static)
	for(int i=0; i<800; i++) _array_Pyramidal_Cells_g_AMPA_r[i] = 0;

	_array_Pyramidal_Cells_g_GABA_d = new double[800];
    #pragma omp parallel for schedule(static)
	for(int i=0; i<800; i++) _array_Pyramidal_Cells_g_GABA_d[i] = 0;

	_array_Pyramidal_Cells_g_GABA_r = new double[800];
    #pragma omp parallel for schedule(static)
	for(int i=0; i<800; i++) _array_Pyramidal_Cells_g_GABA_r[i] = 0;

	_array_Pyramidal_Cells_g_NMDA_d = new double[800];
    #pragma omp parallel for schedule(static)
	for(int i=0; i<800; i++) _array_Pyramidal_Cells_g_NMDA_d[i] = 0;

	_array_Pyramidal_Cells_g_NMDA_r = new double[800];
    #pragma omp parallel for schedule(static)
	for(int i=0; i<800; i++) _array_Pyramidal_Cells_g_NMDA_r[i] = 0;

	_array_Pyramidal_Cells_i = new int32_t[800];
    #pragma omp parallel for schedule(static)
	for(int i=0; i<800; i++) _array_Pyramidal_Cells_i[i] = 0;

	_array_Pyramidal_Cells_v = new double[800];
    #pragma omp parallel for schedule(static)
	for(int i=0; i<800; i++) _array_Pyramidal_Cells_v[i] = 0;

	_array_Regular_Spiking_Interneurons__spikespace = new int32_t[151];
    #pragma omp parallel for schedule(static)
	for(int i=0; i<151; i++) _array_Regular_Spiking_Interneurons__spikespace[i] = 0;

	_array_Regular_Spiking_Interneurons_g_AMPA_d = new double[150];
    #pragma omp parallel for schedule(static)
	for(int i=0; i<150; i++) _array_Regular_Spiking_Interneurons_g_AMPA_d[i] = 0;

	_array_Regular_Spiking_Interneurons_g_AMPA_r = new double[150];
    #pragma omp parallel for schedule(static)
	for(int i=0; i<150; i++) _array_Regular_Spiking_Interneurons_g_AMPA_r[i] = 0;

	_array_Regular_Spiking_Interneurons_g_GABA_d = new double[150];
    #pragma omp parallel for schedule(static)
	for(int i=0; i<150; i++) _array_Regular_Spiking_Interneurons_g_GABA_d[i] = 0;

	_array_Regular_Spiking_Interneurons_g_GABA_r = new double[150];
    #pragma omp parallel for schedule(static)
	for(int i=0; i<150; i++) _array_Regular_Spiking_Interneurons_g_GABA_r[i] = 0;

	_array_Regular_Spiking_Interneurons_g_NMDA_d = new double[150];
    #pragma omp parallel for schedule(static)
	for(int i=0; i<150; i++) _array_Regular_Spiking_Interneurons_g_NMDA_d[i] = 0;

	_array_Regular_Spiking_Interneurons_g_NMDA_r = new double[150];
    #pragma omp parallel for schedule(static)
	for(int i=0; i<150; i++) _array_Regular_Spiking_Interneurons_g_NMDA_r[i] = 0;

	_array_Regular_Spiking_Interneurons_i = new int32_t[150];
    #pragma omp parallel for schedule(static)
	for(int i=0; i<150; i++) _array_Regular_Spiking_Interneurons_i[i] = 0;

	_array_Regular_Spiking_Interneurons_v = new double[150];
    #pragma omp parallel for schedule(static)
	for(int i=0; i<150; i++) _array_Regular_Spiking_Interneurons_v[i] = 0;

	_array_spikemonitor_1__source_idx = new int32_t[150];
    #pragma omp parallel for schedule(static)
	for(int i=0; i<150; i++) _array_spikemonitor_1__source_idx[i] = 0;

	_array_spikemonitor_1_count = new int32_t[150];
    #pragma omp parallel for schedule(static)
	for(int i=0; i<150; i++) _array_spikemonitor_1_count[i] = 0;

	_array_spikemonitor_1_N = new int32_t[1];
    #pragma omp parallel for schedule(static)
	for(int i=0; i<1; i++) _array_spikemonitor_1_N[i] = 0;

	_array_spikemonitor_2__source_idx = new int32_t[50];
    #pragma omp parallel for schedule(static)
	for(int i=0; i<50; i++) _array_spikemonitor_2__source_idx[i] = 0;

	_array_spikemonitor_2_count = new int32_t[50];
    #pragma omp parallel for schedule(static)
	for(int i=0; i<50; i++) _array_spikemonitor_2_count[i] = 0;

	_array_spikemonitor_2_N = new int32_t[1];
    #pragma omp parallel for schedule(static)
	for(int i=0; i<1; i++) _array_spikemonitor_2_N[i] = 0;

	_array_spikemonitor_3__source_idx = new int32_t[800];
    #pragma omp parallel for schedule(static)
	for(int i=0; i<800; i++) _array_spikemonitor_3__source_idx[i] = 0;

	_array_spikemonitor_3_count = new int32_t[800];
    #pragma omp parallel for schedule(static)
	for(int i=0; i<800; i++) _array_spikemonitor_3_count[i] = 0;

	_array_spikemonitor_3_N = new int32_t[1];
    #pragma omp parallel for schedule(static)
	for(int i=0; i<1; i++) _array_spikemonitor_3_N[i] = 0;

	_array_spikemonitor__source_idx = new int32_t[800];
    #pragma omp parallel for schedule(static)
	for(int i=0; i<800; i++) _array_spikemonitor__source_idx[i] = 0;

	_array_spikemonitor_count = new int32_t[800];
    #pragma omp parallel for schedule(static)
	for(int i=0; i<800; i++) _array_spikemonitor_count[i] = 0;

	_array_spikemonitor_N = new int32_t[1];
    #pragma omp parallel for schedule(static)
	for(int i=0; i<1; i++) _array_spikemonitor_N[i] = 0;

	_array_statemonitor_10__indices = new int32_t[10];
    #pragma omp parallel for schedule(static)
	for(int i=0; i<10; i++) _array_statemonitor_10__indices[i] = 0;

	_array_statemonitor_10_N = new int32_t[1];
    #pragma omp parallel for schedule(static)
	for(int i=0; i<1; i++) _array_statemonitor_10_N[i] = 0;

	_array_statemonitor_11__indices = new int32_t[10];
    #pragma omp parallel for schedule(static)
	for(int i=0; i<10; i++) _array_statemonitor_11__indices[i] = 0;

	_array_statemonitor_11_N = new int32_t[1];
    #pragma omp parallel for schedule(static)
	for(int i=0; i<1; i++) _array_statemonitor_11_N[i] = 0;

	_array_statemonitor_12__indices = new int32_t[10];
    #pragma omp parallel for schedule(static)
	for(int i=0; i<10; i++) _array_statemonitor_12__indices[i] = 0;

	_array_statemonitor_12_N = new int32_t[1];
    #pragma omp parallel for schedule(static)
	for(int i=0; i<1; i++) _array_statemonitor_12_N[i] = 0;

	_array_statemonitor_13__indices = new int32_t[10];
    #pragma omp parallel for schedule(static)
	for(int i=0; i<10; i++) _array_statemonitor_13__indices[i] = 0;

	_array_statemonitor_13_N = new int32_t[1];
    #pragma omp parallel for schedule(static)
	for(int i=0; i<1; i++) _array_statemonitor_13_N[i] = 0;

	_array_statemonitor_14__indices = new int32_t[10];
    #pragma omp parallel for schedule(static)
	for(int i=0; i<10; i++) _array_statemonitor_14__indices[i] = 0;

	_array_statemonitor_14_N = new int32_t[1];
    #pragma omp parallel for schedule(static)
	for(int i=0; i<1; i++) _array_statemonitor_14_N[i] = 0;

	_array_statemonitor_1__indices = new int32_t[10];
    #pragma omp parallel for schedule(static)
	for(int i=0; i<10; i++) _array_statemonitor_1__indices[i] = 0;

	_array_statemonitor_1_N = new int32_t[1];
    #pragma omp parallel for schedule(static)
	for(int i=0; i<1; i++) _array_statemonitor_1_N[i] = 0;

	_array_statemonitor_2__indices = new int32_t[10];
    #pragma omp parallel for schedule(static)
	for(int i=0; i<10; i++) _array_statemonitor_2__indices[i] = 0;

	_array_statemonitor_2_N = new int32_t[1];
    #pragma omp parallel for schedule(static)
	for(int i=0; i<1; i++) _array_statemonitor_2_N[i] = 0;

	_array_statemonitor_3__indices = new int32_t[10];
    #pragma omp parallel for schedule(static)
	for(int i=0; i<10; i++) _array_statemonitor_3__indices[i] = 0;

	_array_statemonitor_3_N = new int32_t[1];
    #pragma omp parallel for schedule(static)
	for(int i=0; i<1; i++) _array_statemonitor_3_N[i] = 0;

	_array_statemonitor_4__indices = new int32_t[10];
    #pragma omp parallel for schedule(static)
	for(int i=0; i<10; i++) _array_statemonitor_4__indices[i] = 0;

	_array_statemonitor_4_N = new int32_t[1];
    #pragma omp parallel for schedule(static)
	for(int i=0; i<1; i++) _array_statemonitor_4_N[i] = 0;

	_array_statemonitor_5__indices = new int32_t[10];
    #pragma omp parallel for schedule(static)
	for(int i=0; i<10; i++) _array_statemonitor_5__indices[i] = 0;

	_array_statemonitor_5_N = new int32_t[1];
    #pragma omp parallel for schedule(static)
	for(int i=0; i<1; i++) _array_statemonitor_5_N[i] = 0;

	_array_statemonitor_6__indices = new int32_t[10];
    #pragma omp parallel for schedule(static)
	for(int i=0; i<10; i++) _array_statemonitor_6__indices[i] = 0;

	_array_statemonitor_6_N = new int32_t[1];
    #pragma omp parallel for schedule(static)
	for(int i=0; i<1; i++) _array_statemonitor_6_N[i] = 0;

	_array_statemonitor_7__indices = new int32_t[10];
    #pragma omp parallel for schedule(static)
	for(int i=0; i<10; i++) _array_statemonitor_7__indices[i] = 0;

	_array_statemonitor_7_N = new int32_t[1];
    #pragma omp parallel for schedule(static)
	for(int i=0; i<1; i++) _array_statemonitor_7_N[i] = 0;

	_array_statemonitor_8__indices = new int32_t[10];
    #pragma omp parallel for schedule(static)
	for(int i=0; i<10; i++) _array_statemonitor_8__indices[i] = 0;

	_array_statemonitor_8_N = new int32_t[1];
    #pragma omp parallel for schedule(static)
	for(int i=0; i<1; i++) _array_statemonitor_8_N[i] = 0;

	_array_statemonitor_9__indices = new int32_t[10];
    #pragma omp parallel for schedule(static)
	for(int i=0; i<10; i++) _array_statemonitor_9__indices[i] = 0;

	_array_statemonitor_9_N = new int32_t[1];
    #pragma omp parallel for schedule(static)
	for(int i=0; i<1; i++) _array_statemonitor_9_N[i] = 0;

	_array_statemonitor__indices = new int32_t[10];
    #pragma omp parallel for schedule(static)
	for(int i=0; i<10; i++) _array_statemonitor__indices[i] = 0;

	_array_statemonitor_N = new int32_t[1];
    #pragma omp parallel for schedule(static)
	for(int i=0; i<1; i++) _array_statemonitor_N[i] = 0;

	_array_synapses_N = new int32_t[1];
    #pragma omp parallel for schedule(static)
	for(int i=0; i<1; i++) _array_synapses_N[i] = 0;


	// Arrays initialized to an "arange"
	_array_Fast_Spiking_Interneurons_i = new int32_t[50];
    #pragma omp parallel for schedule(static)
	for(int i=0; i<50; i++) _array_Fast_Spiking_Interneurons_i[i] = 0 + i;

	_array_poissongroup_i = new int32_t[800];
    #pragma omp parallel for schedule(static)
	for(int i=0; i<800; i++) _array_poissongroup_i[i] = 0 + i;

	_array_Pyramidal_Cells_i = new int32_t[800];
    #pragma omp parallel for schedule(static)
	for(int i=0; i<800; i++) _array_Pyramidal_Cells_i[i] = 0 + i;

	_array_Regular_Spiking_Interneurons_i = new int32_t[150];
    #pragma omp parallel for schedule(static)
	for(int i=0; i<150; i++) _array_Regular_Spiking_Interneurons_i[i] = 0 + i;

	_array_spikemonitor_1__source_idx = new int32_t[150];
    #pragma omp parallel for schedule(static)
	for(int i=0; i<150; i++) _array_spikemonitor_1__source_idx[i] = 0 + i;

	_array_spikemonitor_2__source_idx = new int32_t[50];
    #pragma omp parallel for schedule(static)
	for(int i=0; i<50; i++) _array_spikemonitor_2__source_idx[i] = 0 + i;

	_array_spikemonitor_3__source_idx = new int32_t[800];
    #pragma omp parallel for schedule(static)
	for(int i=0; i<800; i++) _array_spikemonitor_3__source_idx[i] = 0 + i;

	_array_spikemonitor__source_idx = new int32_t[800];
    #pragma omp parallel for schedule(static)
	for(int i=0; i<800; i++) _array_spikemonitor__source_idx[i] = 0 + i;


	// static arrays
	_static_array__array_statemonitor_10__indices = new int32_t[10];
	_static_array__array_statemonitor_11__indices = new int32_t[10];
	_static_array__array_statemonitor_12__indices = new int32_t[10];
	_static_array__array_statemonitor_13__indices = new int32_t[10];
	_static_array__array_statemonitor_14__indices = new int32_t[10];
	_static_array__array_statemonitor_1__indices = new int32_t[10];
	_static_array__array_statemonitor_2__indices = new int32_t[10];
	_static_array__array_statemonitor_3__indices = new int32_t[10];
	_static_array__array_statemonitor_4__indices = new int32_t[10];
	_static_array__array_statemonitor_5__indices = new int32_t[10];
	_static_array__array_statemonitor_6__indices = new int32_t[10];
	_static_array__array_statemonitor_7__indices = new int32_t[10];
	_static_array__array_statemonitor_8__indices = new int32_t[10];
	_static_array__array_statemonitor_9__indices = new int32_t[10];
	_static_array__array_statemonitor__indices = new int32_t[10];

	// Random number generator states
	for (int i=0; i<12; i++)
	    _mersenne_twister_states.push_back(new rk_state());
}

void _load_arrays()
{
	using namespace brian;

	ifstream f_static_array__array_statemonitor_10__indices;
	f_static_array__array_statemonitor_10__indices.open("static_arrays/_static_array__array_statemonitor_10__indices", ios::in | ios::binary);
	if(f_static_array__array_statemonitor_10__indices.is_open())
	{
		f_static_array__array_statemonitor_10__indices.read(reinterpret_cast<char*>(_static_array__array_statemonitor_10__indices), 10*sizeof(int32_t));
	} else
	{
		std::cout << "Error opening static array _static_array__array_statemonitor_10__indices." << endl;
	}
	ifstream f_static_array__array_statemonitor_11__indices;
	f_static_array__array_statemonitor_11__indices.open("static_arrays/_static_array__array_statemonitor_11__indices", ios::in | ios::binary);
	if(f_static_array__array_statemonitor_11__indices.is_open())
	{
		f_static_array__array_statemonitor_11__indices.read(reinterpret_cast<char*>(_static_array__array_statemonitor_11__indices), 10*sizeof(int32_t));
	} else
	{
		std::cout << "Error opening static array _static_array__array_statemonitor_11__indices." << endl;
	}
	ifstream f_static_array__array_statemonitor_12__indices;
	f_static_array__array_statemonitor_12__indices.open("static_arrays/_static_array__array_statemonitor_12__indices", ios::in | ios::binary);
	if(f_static_array__array_statemonitor_12__indices.is_open())
	{
		f_static_array__array_statemonitor_12__indices.read(reinterpret_cast<char*>(_static_array__array_statemonitor_12__indices), 10*sizeof(int32_t));
	} else
	{
		std::cout << "Error opening static array _static_array__array_statemonitor_12__indices." << endl;
	}
	ifstream f_static_array__array_statemonitor_13__indices;
	f_static_array__array_statemonitor_13__indices.open("static_arrays/_static_array__array_statemonitor_13__indices", ios::in | ios::binary);
	if(f_static_array__array_statemonitor_13__indices.is_open())
	{
		f_static_array__array_statemonitor_13__indices.read(reinterpret_cast<char*>(_static_array__array_statemonitor_13__indices), 10*sizeof(int32_t));
	} else
	{
		std::cout << "Error opening static array _static_array__array_statemonitor_13__indices." << endl;
	}
	ifstream f_static_array__array_statemonitor_14__indices;
	f_static_array__array_statemonitor_14__indices.open("static_arrays/_static_array__array_statemonitor_14__indices", ios::in | ios::binary);
	if(f_static_array__array_statemonitor_14__indices.is_open())
	{
		f_static_array__array_statemonitor_14__indices.read(reinterpret_cast<char*>(_static_array__array_statemonitor_14__indices), 10*sizeof(int32_t));
	} else
	{
		std::cout << "Error opening static array _static_array__array_statemonitor_14__indices." << endl;
	}
	ifstream f_static_array__array_statemonitor_1__indices;
	f_static_array__array_statemonitor_1__indices.open("static_arrays/_static_array__array_statemonitor_1__indices", ios::in | ios::binary);
	if(f_static_array__array_statemonitor_1__indices.is_open())
	{
		f_static_array__array_statemonitor_1__indices.read(reinterpret_cast<char*>(_static_array__array_statemonitor_1__indices), 10*sizeof(int32_t));
	} else
	{
		std::cout << "Error opening static array _static_array__array_statemonitor_1__indices." << endl;
	}
	ifstream f_static_array__array_statemonitor_2__indices;
	f_static_array__array_statemonitor_2__indices.open("static_arrays/_static_array__array_statemonitor_2__indices", ios::in | ios::binary);
	if(f_static_array__array_statemonitor_2__indices.is_open())
	{
		f_static_array__array_statemonitor_2__indices.read(reinterpret_cast<char*>(_static_array__array_statemonitor_2__indices), 10*sizeof(int32_t));
	} else
	{
		std::cout << "Error opening static array _static_array__array_statemonitor_2__indices." << endl;
	}
	ifstream f_static_array__array_statemonitor_3__indices;
	f_static_array__array_statemonitor_3__indices.open("static_arrays/_static_array__array_statemonitor_3__indices", ios::in | ios::binary);
	if(f_static_array__array_statemonitor_3__indices.is_open())
	{
		f_static_array__array_statemonitor_3__indices.read(reinterpret_cast<char*>(_static_array__array_statemonitor_3__indices), 10*sizeof(int32_t));
	} else
	{
		std::cout << "Error opening static array _static_array__array_statemonitor_3__indices." << endl;
	}
	ifstream f_static_array__array_statemonitor_4__indices;
	f_static_array__array_statemonitor_4__indices.open("static_arrays/_static_array__array_statemonitor_4__indices", ios::in | ios::binary);
	if(f_static_array__array_statemonitor_4__indices.is_open())
	{
		f_static_array__array_statemonitor_4__indices.read(reinterpret_cast<char*>(_static_array__array_statemonitor_4__indices), 10*sizeof(int32_t));
	} else
	{
		std::cout << "Error opening static array _static_array__array_statemonitor_4__indices." << endl;
	}
	ifstream f_static_array__array_statemonitor_5__indices;
	f_static_array__array_statemonitor_5__indices.open("static_arrays/_static_array__array_statemonitor_5__indices", ios::in | ios::binary);
	if(f_static_array__array_statemonitor_5__indices.is_open())
	{
		f_static_array__array_statemonitor_5__indices.read(reinterpret_cast<char*>(_static_array__array_statemonitor_5__indices), 10*sizeof(int32_t));
	} else
	{
		std::cout << "Error opening static array _static_array__array_statemonitor_5__indices." << endl;
	}
	ifstream f_static_array__array_statemonitor_6__indices;
	f_static_array__array_statemonitor_6__indices.open("static_arrays/_static_array__array_statemonitor_6__indices", ios::in | ios::binary);
	if(f_static_array__array_statemonitor_6__indices.is_open())
	{
		f_static_array__array_statemonitor_6__indices.read(reinterpret_cast<char*>(_static_array__array_statemonitor_6__indices), 10*sizeof(int32_t));
	} else
	{
		std::cout << "Error opening static array _static_array__array_statemonitor_6__indices." << endl;
	}
	ifstream f_static_array__array_statemonitor_7__indices;
	f_static_array__array_statemonitor_7__indices.open("static_arrays/_static_array__array_statemonitor_7__indices", ios::in | ios::binary);
	if(f_static_array__array_statemonitor_7__indices.is_open())
	{
		f_static_array__array_statemonitor_7__indices.read(reinterpret_cast<char*>(_static_array__array_statemonitor_7__indices), 10*sizeof(int32_t));
	} else
	{
		std::cout << "Error opening static array _static_array__array_statemonitor_7__indices." << endl;
	}
	ifstream f_static_array__array_statemonitor_8__indices;
	f_static_array__array_statemonitor_8__indices.open("static_arrays/_static_array__array_statemonitor_8__indices", ios::in | ios::binary);
	if(f_static_array__array_statemonitor_8__indices.is_open())
	{
		f_static_array__array_statemonitor_8__indices.read(reinterpret_cast<char*>(_static_array__array_statemonitor_8__indices), 10*sizeof(int32_t));
	} else
	{
		std::cout << "Error opening static array _static_array__array_statemonitor_8__indices." << endl;
	}
	ifstream f_static_array__array_statemonitor_9__indices;
	f_static_array__array_statemonitor_9__indices.open("static_arrays/_static_array__array_statemonitor_9__indices", ios::in | ios::binary);
	if(f_static_array__array_statemonitor_9__indices.is_open())
	{
		f_static_array__array_statemonitor_9__indices.read(reinterpret_cast<char*>(_static_array__array_statemonitor_9__indices), 10*sizeof(int32_t));
	} else
	{
		std::cout << "Error opening static array _static_array__array_statemonitor_9__indices." << endl;
	}
	ifstream f_static_array__array_statemonitor__indices;
	f_static_array__array_statemonitor__indices.open("static_arrays/_static_array__array_statemonitor__indices", ios::in | ios::binary);
	if(f_static_array__array_statemonitor__indices.is_open())
	{
		f_static_array__array_statemonitor__indices.read(reinterpret_cast<char*>(_static_array__array_statemonitor__indices), 10*sizeof(int32_t));
	} else
	{
		std::cout << "Error opening static array _static_array__array_statemonitor__indices." << endl;
	}
}

void _write_arrays()
{
	using namespace brian;

	ofstream outfile__array_AMPA_NMDA_fromPCtoFSI_N;
	outfile__array_AMPA_NMDA_fromPCtoFSI_N.open("results/_array_AMPA_NMDA_fromPCtoFSI_N_-818043868752905173", ios::binary | ios::out);
	if(outfile__array_AMPA_NMDA_fromPCtoFSI_N.is_open())
	{
		outfile__array_AMPA_NMDA_fromPCtoFSI_N.write(reinterpret_cast<char*>(_array_AMPA_NMDA_fromPCtoFSI_N), 1*sizeof(_array_AMPA_NMDA_fromPCtoFSI_N[0]));
		outfile__array_AMPA_NMDA_fromPCtoFSI_N.close();
	} else
	{
		std::cout << "Error writing output file for _array_AMPA_NMDA_fromPCtoFSI_N." << endl;
	}
	ofstream outfile__array_AMPA_NMDA_fromPCtoPC_N;
	outfile__array_AMPA_NMDA_fromPCtoPC_N.open("results/_array_AMPA_NMDA_fromPCtoPC_N_-4332208164337521958", ios::binary | ios::out);
	if(outfile__array_AMPA_NMDA_fromPCtoPC_N.is_open())
	{
		outfile__array_AMPA_NMDA_fromPCtoPC_N.write(reinterpret_cast<char*>(_array_AMPA_NMDA_fromPCtoPC_N), 1*sizeof(_array_AMPA_NMDA_fromPCtoPC_N[0]));
		outfile__array_AMPA_NMDA_fromPCtoPC_N.close();
	} else
	{
		std::cout << "Error writing output file for _array_AMPA_NMDA_fromPCtoPC_N." << endl;
	}
	ofstream outfile__array_AMPA_NMDA_fromPCtoRSI_N;
	outfile__array_AMPA_NMDA_fromPCtoRSI_N.open("results/_array_AMPA_NMDA_fromPCtoRSI_N_4937727406569620098", ios::binary | ios::out);
	if(outfile__array_AMPA_NMDA_fromPCtoRSI_N.is_open())
	{
		outfile__array_AMPA_NMDA_fromPCtoRSI_N.write(reinterpret_cast<char*>(_array_AMPA_NMDA_fromPCtoRSI_N), 1*sizeof(_array_AMPA_NMDA_fromPCtoRSI_N[0]));
		outfile__array_AMPA_NMDA_fromPCtoRSI_N.close();
	} else
	{
		std::cout << "Error writing output file for _array_AMPA_NMDA_fromPCtoRSI_N." << endl;
	}
	ofstream outfile__array_defaultclock_dt;
	outfile__array_defaultclock_dt.open("results/_array_defaultclock_dt_-732045685278223169", ios::binary | ios::out);
	if(outfile__array_defaultclock_dt.is_open())
	{
		outfile__array_defaultclock_dt.write(reinterpret_cast<char*>(_array_defaultclock_dt), 1*sizeof(_array_defaultclock_dt[0]));
		outfile__array_defaultclock_dt.close();
	} else
	{
		std::cout << "Error writing output file for _array_defaultclock_dt." << endl;
	}
	ofstream outfile__array_defaultclock_t;
	outfile__array_defaultclock_t.open("results/_array_defaultclock_t_923924220243601226", ios::binary | ios::out);
	if(outfile__array_defaultclock_t.is_open())
	{
		outfile__array_defaultclock_t.write(reinterpret_cast<char*>(_array_defaultclock_t), 1*sizeof(_array_defaultclock_t[0]));
		outfile__array_defaultclock_t.close();
	} else
	{
		std::cout << "Error writing output file for _array_defaultclock_t." << endl;
	}
	ofstream outfile__array_defaultclock_timestep;
	outfile__array_defaultclock_timestep.open("results/_array_defaultclock_timestep_-2782472716636971105", ios::binary | ios::out);
	if(outfile__array_defaultclock_timestep.is_open())
	{
		outfile__array_defaultclock_timestep.write(reinterpret_cast<char*>(_array_defaultclock_timestep), 1*sizeof(_array_defaultclock_timestep[0]));
		outfile__array_defaultclock_timestep.close();
	} else
	{
		std::cout << "Error writing output file for _array_defaultclock_timestep." << endl;
	}
	ofstream outfile__array_Fast_Spiking_Interneurons__spikespace;
	outfile__array_Fast_Spiking_Interneurons__spikespace.open("results/_array_Fast_Spiking_Interneurons__spikespace_-8670611720071145241", ios::binary | ios::out);
	if(outfile__array_Fast_Spiking_Interneurons__spikespace.is_open())
	{
		outfile__array_Fast_Spiking_Interneurons__spikespace.write(reinterpret_cast<char*>(_array_Fast_Spiking_Interneurons__spikespace), 51*sizeof(_array_Fast_Spiking_Interneurons__spikespace[0]));
		outfile__array_Fast_Spiking_Interneurons__spikespace.close();
	} else
	{
		std::cout << "Error writing output file for _array_Fast_Spiking_Interneurons__spikespace." << endl;
	}
	ofstream outfile__array_Fast_Spiking_Interneurons_g_AMPA_d;
	outfile__array_Fast_Spiking_Interneurons_g_AMPA_d.open("results/_array_Fast_Spiking_Interneurons_g_AMPA_d_1289788204978901111", ios::binary | ios::out);
	if(outfile__array_Fast_Spiking_Interneurons_g_AMPA_d.is_open())
	{
		outfile__array_Fast_Spiking_Interneurons_g_AMPA_d.write(reinterpret_cast<char*>(_array_Fast_Spiking_Interneurons_g_AMPA_d), 50*sizeof(_array_Fast_Spiking_Interneurons_g_AMPA_d[0]));
		outfile__array_Fast_Spiking_Interneurons_g_AMPA_d.close();
	} else
	{
		std::cout << "Error writing output file for _array_Fast_Spiking_Interneurons_g_AMPA_d." << endl;
	}
	ofstream outfile__array_Fast_Spiking_Interneurons_g_AMPA_r;
	outfile__array_Fast_Spiking_Interneurons_g_AMPA_r.open("results/_array_Fast_Spiking_Interneurons_g_AMPA_r_-6412408490284342845", ios::binary | ios::out);
	if(outfile__array_Fast_Spiking_Interneurons_g_AMPA_r.is_open())
	{
		outfile__array_Fast_Spiking_Interneurons_g_AMPA_r.write(reinterpret_cast<char*>(_array_Fast_Spiking_Interneurons_g_AMPA_r), 50*sizeof(_array_Fast_Spiking_Interneurons_g_AMPA_r[0]));
		outfile__array_Fast_Spiking_Interneurons_g_AMPA_r.close();
	} else
	{
		std::cout << "Error writing output file for _array_Fast_Spiking_Interneurons_g_AMPA_r." << endl;
	}
	ofstream outfile__array_Fast_Spiking_Interneurons_g_GABA_d;
	outfile__array_Fast_Spiking_Interneurons_g_GABA_d.open("results/_array_Fast_Spiking_Interneurons_g_GABA_d_487276559210021443", ios::binary | ios::out);
	if(outfile__array_Fast_Spiking_Interneurons_g_GABA_d.is_open())
	{
		outfile__array_Fast_Spiking_Interneurons_g_GABA_d.write(reinterpret_cast<char*>(_array_Fast_Spiking_Interneurons_g_GABA_d), 50*sizeof(_array_Fast_Spiking_Interneurons_g_GABA_d[0]));
		outfile__array_Fast_Spiking_Interneurons_g_GABA_d.close();
	} else
	{
		std::cout << "Error writing output file for _array_Fast_Spiking_Interneurons_g_GABA_d." << endl;
	}
	ofstream outfile__array_Fast_Spiking_Interneurons_g_GABA_r;
	outfile__array_Fast_Spiking_Interneurons_g_GABA_r.open("results/_array_Fast_Spiking_Interneurons_g_GABA_r_1276394956744085377", ios::binary | ios::out);
	if(outfile__array_Fast_Spiking_Interneurons_g_GABA_r.is_open())
	{
		outfile__array_Fast_Spiking_Interneurons_g_GABA_r.write(reinterpret_cast<char*>(_array_Fast_Spiking_Interneurons_g_GABA_r), 50*sizeof(_array_Fast_Spiking_Interneurons_g_GABA_r[0]));
		outfile__array_Fast_Spiking_Interneurons_g_GABA_r.close();
	} else
	{
		std::cout << "Error writing output file for _array_Fast_Spiking_Interneurons_g_GABA_r." << endl;
	}
	ofstream outfile__array_Fast_Spiking_Interneurons_g_NMDA_d;
	outfile__array_Fast_Spiking_Interneurons_g_NMDA_d.open("results/_array_Fast_Spiking_Interneurons_g_NMDA_d_-2504343418875343659", ios::binary | ios::out);
	if(outfile__array_Fast_Spiking_Interneurons_g_NMDA_d.is_open())
	{
		outfile__array_Fast_Spiking_Interneurons_g_NMDA_d.write(reinterpret_cast<char*>(_array_Fast_Spiking_Interneurons_g_NMDA_d), 50*sizeof(_array_Fast_Spiking_Interneurons_g_NMDA_d[0]));
		outfile__array_Fast_Spiking_Interneurons_g_NMDA_d.close();
	} else
	{
		std::cout << "Error writing output file for _array_Fast_Spiking_Interneurons_g_NMDA_d." << endl;
	}
	ofstream outfile__array_Fast_Spiking_Interneurons_g_NMDA_r;
	outfile__array_Fast_Spiking_Interneurons_g_NMDA_r.open("results/_array_Fast_Spiking_Interneurons_g_NMDA_r_-105190813311377398", ios::binary | ios::out);
	if(outfile__array_Fast_Spiking_Interneurons_g_NMDA_r.is_open())
	{
		outfile__array_Fast_Spiking_Interneurons_g_NMDA_r.write(reinterpret_cast<char*>(_array_Fast_Spiking_Interneurons_g_NMDA_r), 50*sizeof(_array_Fast_Spiking_Interneurons_g_NMDA_r[0]));
		outfile__array_Fast_Spiking_Interneurons_g_NMDA_r.close();
	} else
	{
		std::cout << "Error writing output file for _array_Fast_Spiking_Interneurons_g_NMDA_r." << endl;
	}
	ofstream outfile__array_Fast_Spiking_Interneurons_i;
	outfile__array_Fast_Spiking_Interneurons_i.open("results/_array_Fast_Spiking_Interneurons_i_-76987701712653764", ios::binary | ios::out);
	if(outfile__array_Fast_Spiking_Interneurons_i.is_open())
	{
		outfile__array_Fast_Spiking_Interneurons_i.write(reinterpret_cast<char*>(_array_Fast_Spiking_Interneurons_i), 50*sizeof(_array_Fast_Spiking_Interneurons_i[0]));
		outfile__array_Fast_Spiking_Interneurons_i.close();
	} else
	{
		std::cout << "Error writing output file for _array_Fast_Spiking_Interneurons_i." << endl;
	}
	ofstream outfile__array_Fast_Spiking_Interneurons_v;
	outfile__array_Fast_Spiking_Interneurons_v.open("results/_array_Fast_Spiking_Interneurons_v_2776894821203263087", ios::binary | ios::out);
	if(outfile__array_Fast_Spiking_Interneurons_v.is_open())
	{
		outfile__array_Fast_Spiking_Interneurons_v.write(reinterpret_cast<char*>(_array_Fast_Spiking_Interneurons_v), 50*sizeof(_array_Fast_Spiking_Interneurons_v[0]));
		outfile__array_Fast_Spiking_Interneurons_v.close();
	} else
	{
		std::cout << "Error writing output file for _array_Fast_Spiking_Interneurons_v." << endl;
	}
	ofstream outfile__array_GABA_fromFSItoFSI_N;
	outfile__array_GABA_fromFSItoFSI_N.open("results/_array_GABA_fromFSItoFSI_N_-8499433043017646014", ios::binary | ios::out);
	if(outfile__array_GABA_fromFSItoFSI_N.is_open())
	{
		outfile__array_GABA_fromFSItoFSI_N.write(reinterpret_cast<char*>(_array_GABA_fromFSItoFSI_N), 1*sizeof(_array_GABA_fromFSItoFSI_N[0]));
		outfile__array_GABA_fromFSItoFSI_N.close();
	} else
	{
		std::cout << "Error writing output file for _array_GABA_fromFSItoFSI_N." << endl;
	}
	ofstream outfile__array_GABA_fromFSItoPC_N;
	outfile__array_GABA_fromFSItoPC_N.open("results/_array_GABA_fromFSItoPC_N_-8362318348376105589", ios::binary | ios::out);
	if(outfile__array_GABA_fromFSItoPC_N.is_open())
	{
		outfile__array_GABA_fromFSItoPC_N.write(reinterpret_cast<char*>(_array_GABA_fromFSItoPC_N), 1*sizeof(_array_GABA_fromFSItoPC_N[0]));
		outfile__array_GABA_fromFSItoPC_N.close();
	} else
	{
		std::cout << "Error writing output file for _array_GABA_fromFSItoPC_N." << endl;
	}
	ofstream outfile__array_GABA_fromFSItoRSI_N;
	outfile__array_GABA_fromFSItoRSI_N.open("results/_array_GABA_fromFSItoRSI_N_-1029750068445635191", ios::binary | ios::out);
	if(outfile__array_GABA_fromFSItoRSI_N.is_open())
	{
		outfile__array_GABA_fromFSItoRSI_N.write(reinterpret_cast<char*>(_array_GABA_fromFSItoRSI_N), 1*sizeof(_array_GABA_fromFSItoRSI_N[0]));
		outfile__array_GABA_fromFSItoRSI_N.close();
	} else
	{
		std::cout << "Error writing output file for _array_GABA_fromFSItoRSI_N." << endl;
	}
	ofstream outfile__array_GABA_fromRSItoFSI_N;
	outfile__array_GABA_fromRSItoFSI_N.open("results/_array_GABA_fromRSItoFSI_N_8287224744867178394", ios::binary | ios::out);
	if(outfile__array_GABA_fromRSItoFSI_N.is_open())
	{
		outfile__array_GABA_fromRSItoFSI_N.write(reinterpret_cast<char*>(_array_GABA_fromRSItoFSI_N), 1*sizeof(_array_GABA_fromRSItoFSI_N[0]));
		outfile__array_GABA_fromRSItoFSI_N.close();
	} else
	{
		std::cout << "Error writing output file for _array_GABA_fromRSItoFSI_N." << endl;
	}
	ofstream outfile__array_GABA_fromRSItoPC_N;
	outfile__array_GABA_fromRSItoPC_N.open("results/_array_GABA_fromRSItoPC_N_-6958798005383057470", ios::binary | ios::out);
	if(outfile__array_GABA_fromRSItoPC_N.is_open())
	{
		outfile__array_GABA_fromRSItoPC_N.write(reinterpret_cast<char*>(_array_GABA_fromRSItoPC_N), 1*sizeof(_array_GABA_fromRSItoPC_N[0]));
		outfile__array_GABA_fromRSItoPC_N.close();
	} else
	{
		std::cout << "Error writing output file for _array_GABA_fromRSItoPC_N." << endl;
	}
	ofstream outfile__array_GABA_fromRSItoRSI_N;
	outfile__array_GABA_fromRSItoRSI_N.open("results/_array_GABA_fromRSItoRSI_N_-650694085115291033", ios::binary | ios::out);
	if(outfile__array_GABA_fromRSItoRSI_N.is_open())
	{
		outfile__array_GABA_fromRSItoRSI_N.write(reinterpret_cast<char*>(_array_GABA_fromRSItoRSI_N), 1*sizeof(_array_GABA_fromRSItoRSI_N[0]));
		outfile__array_GABA_fromRSItoRSI_N.close();
	} else
	{
		std::cout << "Error writing output file for _array_GABA_fromRSItoRSI_N." << endl;
	}
	ofstream outfile__array_poissongroup__spikespace;
	outfile__array_poissongroup__spikespace.open("results/_array_poissongroup__spikespace_-4600289981255081628", ios::binary | ios::out);
	if(outfile__array_poissongroup__spikespace.is_open())
	{
		outfile__array_poissongroup__spikespace.write(reinterpret_cast<char*>(_array_poissongroup__spikespace), 801*sizeof(_array_poissongroup__spikespace[0]));
		outfile__array_poissongroup__spikespace.close();
	} else
	{
		std::cout << "Error writing output file for _array_poissongroup__spikespace." << endl;
	}
	ofstream outfile__array_poissongroup_i;
	outfile__array_poissongroup_i.open("results/_array_poissongroup_i_9060042193458146093", ios::binary | ios::out);
	if(outfile__array_poissongroup_i.is_open())
	{
		outfile__array_poissongroup_i.write(reinterpret_cast<char*>(_array_poissongroup_i), 800*sizeof(_array_poissongroup_i[0]));
		outfile__array_poissongroup_i.close();
	} else
	{
		std::cout << "Error writing output file for _array_poissongroup_i." << endl;
	}
	ofstream outfile__array_poissongroup_rates;
	outfile__array_poissongroup_rates.open("results/_array_poissongroup_rates_-7549886902379680465", ios::binary | ios::out);
	if(outfile__array_poissongroup_rates.is_open())
	{
		outfile__array_poissongroup_rates.write(reinterpret_cast<char*>(_array_poissongroup_rates), 800*sizeof(_array_poissongroup_rates[0]));
		outfile__array_poissongroup_rates.close();
	} else
	{
		std::cout << "Error writing output file for _array_poissongroup_rates." << endl;
	}
	ofstream outfile__array_Pyramidal_Cells__spikespace;
	outfile__array_Pyramidal_Cells__spikespace.open("results/_array_Pyramidal_Cells__spikespace_-4547683514656314244", ios::binary | ios::out);
	if(outfile__array_Pyramidal_Cells__spikespace.is_open())
	{
		outfile__array_Pyramidal_Cells__spikespace.write(reinterpret_cast<char*>(_array_Pyramidal_Cells__spikespace), 801*sizeof(_array_Pyramidal_Cells__spikespace[0]));
		outfile__array_Pyramidal_Cells__spikespace.close();
	} else
	{
		std::cout << "Error writing output file for _array_Pyramidal_Cells__spikespace." << endl;
	}
	ofstream outfile__array_Pyramidal_Cells_g_AMPA_d;
	outfile__array_Pyramidal_Cells_g_AMPA_d.open("results/_array_Pyramidal_Cells_g_AMPA_d_5990792717300477082", ios::binary | ios::out);
	if(outfile__array_Pyramidal_Cells_g_AMPA_d.is_open())
	{
		outfile__array_Pyramidal_Cells_g_AMPA_d.write(reinterpret_cast<char*>(_array_Pyramidal_Cells_g_AMPA_d), 800*sizeof(_array_Pyramidal_Cells_g_AMPA_d[0]));
		outfile__array_Pyramidal_Cells_g_AMPA_d.close();
	} else
	{
		std::cout << "Error writing output file for _array_Pyramidal_Cells_g_AMPA_d." << endl;
	}
	ofstream outfile__array_Pyramidal_Cells_g_AMPA_r;
	outfile__array_Pyramidal_Cells_g_AMPA_r.open("results/_array_Pyramidal_Cells_g_AMPA_r_6637910078915844357", ios::binary | ios::out);
	if(outfile__array_Pyramidal_Cells_g_AMPA_r.is_open())
	{
		outfile__array_Pyramidal_Cells_g_AMPA_r.write(reinterpret_cast<char*>(_array_Pyramidal_Cells_g_AMPA_r), 800*sizeof(_array_Pyramidal_Cells_g_AMPA_r[0]));
		outfile__array_Pyramidal_Cells_g_AMPA_r.close();
	} else
	{
		std::cout << "Error writing output file for _array_Pyramidal_Cells_g_AMPA_r." << endl;
	}
	ofstream outfile__array_Pyramidal_Cells_g_GABA_d;
	outfile__array_Pyramidal_Cells_g_GABA_d.open("results/_array_Pyramidal_Cells_g_GABA_d_-6077390996601526823", ios::binary | ios::out);
	if(outfile__array_Pyramidal_Cells_g_GABA_d.is_open())
	{
		outfile__array_Pyramidal_Cells_g_GABA_d.write(reinterpret_cast<char*>(_array_Pyramidal_Cells_g_GABA_d), 800*sizeof(_array_Pyramidal_Cells_g_GABA_d[0]));
		outfile__array_Pyramidal_Cells_g_GABA_d.close();
	} else
	{
		std::cout << "Error writing output file for _array_Pyramidal_Cells_g_GABA_d." << endl;
	}
	ofstream outfile__array_Pyramidal_Cells_g_GABA_r;
	outfile__array_Pyramidal_Cells_g_GABA_r.open("results/_array_Pyramidal_Cells_g_GABA_r_-8118001274181652590", ios::binary | ios::out);
	if(outfile__array_Pyramidal_Cells_g_GABA_r.is_open())
	{
		outfile__array_Pyramidal_Cells_g_GABA_r.write(reinterpret_cast<char*>(_array_Pyramidal_Cells_g_GABA_r), 800*sizeof(_array_Pyramidal_Cells_g_GABA_r[0]));
		outfile__array_Pyramidal_Cells_g_GABA_r.close();
	} else
	{
		std::cout << "Error writing output file for _array_Pyramidal_Cells_g_GABA_r." << endl;
	}
	ofstream outfile__array_Pyramidal_Cells_g_NMDA_d;
	outfile__array_Pyramidal_Cells_g_NMDA_d.open("results/_array_Pyramidal_Cells_g_NMDA_d_-3902123405026197772", ios::binary | ios::out);
	if(outfile__array_Pyramidal_Cells_g_NMDA_d.is_open())
	{
		outfile__array_Pyramidal_Cells_g_NMDA_d.write(reinterpret_cast<char*>(_array_Pyramidal_Cells_g_NMDA_d), 800*sizeof(_array_Pyramidal_Cells_g_NMDA_d[0]));
		outfile__array_Pyramidal_Cells_g_NMDA_d.close();
	} else
	{
		std::cout << "Error writing output file for _array_Pyramidal_Cells_g_NMDA_d." << endl;
	}
	ofstream outfile__array_Pyramidal_Cells_g_NMDA_r;
	outfile__array_Pyramidal_Cells_g_NMDA_r.open("results/_array_Pyramidal_Cells_g_NMDA_r_-5423463203790744156", ios::binary | ios::out);
	if(outfile__array_Pyramidal_Cells_g_NMDA_r.is_open())
	{
		outfile__array_Pyramidal_Cells_g_NMDA_r.write(reinterpret_cast<char*>(_array_Pyramidal_Cells_g_NMDA_r), 800*sizeof(_array_Pyramidal_Cells_g_NMDA_r[0]));
		outfile__array_Pyramidal_Cells_g_NMDA_r.close();
	} else
	{
		std::cout << "Error writing output file for _array_Pyramidal_Cells_g_NMDA_r." << endl;
	}
	ofstream outfile__array_Pyramidal_Cells_i;
	outfile__array_Pyramidal_Cells_i.open("results/_array_Pyramidal_Cells_i_-1021064210253988763", ios::binary | ios::out);
	if(outfile__array_Pyramidal_Cells_i.is_open())
	{
		outfile__array_Pyramidal_Cells_i.write(reinterpret_cast<char*>(_array_Pyramidal_Cells_i), 800*sizeof(_array_Pyramidal_Cells_i[0]));
		outfile__array_Pyramidal_Cells_i.close();
	} else
	{
		std::cout << "Error writing output file for _array_Pyramidal_Cells_i." << endl;
	}
	ofstream outfile__array_Pyramidal_Cells_v;
	outfile__array_Pyramidal_Cells_v.open("results/_array_Pyramidal_Cells_v_5175781394629961860", ios::binary | ios::out);
	if(outfile__array_Pyramidal_Cells_v.is_open())
	{
		outfile__array_Pyramidal_Cells_v.write(reinterpret_cast<char*>(_array_Pyramidal_Cells_v), 800*sizeof(_array_Pyramidal_Cells_v[0]));
		outfile__array_Pyramidal_Cells_v.close();
	} else
	{
		std::cout << "Error writing output file for _array_Pyramidal_Cells_v." << endl;
	}
	ofstream outfile__array_Regular_Spiking_Interneurons__spikespace;
	outfile__array_Regular_Spiking_Interneurons__spikespace.open("results/_array_Regular_Spiking_Interneurons__spikespace_-7823130702717368113", ios::binary | ios::out);
	if(outfile__array_Regular_Spiking_Interneurons__spikespace.is_open())
	{
		outfile__array_Regular_Spiking_Interneurons__spikespace.write(reinterpret_cast<char*>(_array_Regular_Spiking_Interneurons__spikespace), 151*sizeof(_array_Regular_Spiking_Interneurons__spikespace[0]));
		outfile__array_Regular_Spiking_Interneurons__spikespace.close();
	} else
	{
		std::cout << "Error writing output file for _array_Regular_Spiking_Interneurons__spikespace." << endl;
	}
	ofstream outfile__array_Regular_Spiking_Interneurons_g_AMPA_d;
	outfile__array_Regular_Spiking_Interneurons_g_AMPA_d.open("results/_array_Regular_Spiking_Interneurons_g_AMPA_d_8997374000950352890", ios::binary | ios::out);
	if(outfile__array_Regular_Spiking_Interneurons_g_AMPA_d.is_open())
	{
		outfile__array_Regular_Spiking_Interneurons_g_AMPA_d.write(reinterpret_cast<char*>(_array_Regular_Spiking_Interneurons_g_AMPA_d), 150*sizeof(_array_Regular_Spiking_Interneurons_g_AMPA_d[0]));
		outfile__array_Regular_Spiking_Interneurons_g_AMPA_d.close();
	} else
	{
		std::cout << "Error writing output file for _array_Regular_Spiking_Interneurons_g_AMPA_d." << endl;
	}
	ofstream outfile__array_Regular_Spiking_Interneurons_g_AMPA_r;
	outfile__array_Regular_Spiking_Interneurons_g_AMPA_r.open("results/_array_Regular_Spiking_Interneurons_g_AMPA_r_2689376825278940930", ios::binary | ios::out);
	if(outfile__array_Regular_Spiking_Interneurons_g_AMPA_r.is_open())
	{
		outfile__array_Regular_Spiking_Interneurons_g_AMPA_r.write(reinterpret_cast<char*>(_array_Regular_Spiking_Interneurons_g_AMPA_r), 150*sizeof(_array_Regular_Spiking_Interneurons_g_AMPA_r[0]));
		outfile__array_Regular_Spiking_Interneurons_g_AMPA_r.close();
	} else
	{
		std::cout << "Error writing output file for _array_Regular_Spiking_Interneurons_g_AMPA_r." << endl;
	}
	ofstream outfile__array_Regular_Spiking_Interneurons_g_GABA_d;
	outfile__array_Regular_Spiking_Interneurons_g_GABA_d.open("results/_array_Regular_Spiking_Interneurons_g_GABA_d_3387249075669818440", ios::binary | ios::out);
	if(outfile__array_Regular_Spiking_Interneurons_g_GABA_d.is_open())
	{
		outfile__array_Regular_Spiking_Interneurons_g_GABA_d.write(reinterpret_cast<char*>(_array_Regular_Spiking_Interneurons_g_GABA_d), 150*sizeof(_array_Regular_Spiking_Interneurons_g_GABA_d[0]));
		outfile__array_Regular_Spiking_Interneurons_g_GABA_d.close();
	} else
	{
		std::cout << "Error writing output file for _array_Regular_Spiking_Interneurons_g_GABA_d." << endl;
	}
	ofstream outfile__array_Regular_Spiking_Interneurons_g_GABA_r;
	outfile__array_Regular_Spiking_Interneurons_g_GABA_r.open("results/_array_Regular_Spiking_Interneurons_g_GABA_r_-6341076031789777981", ios::binary | ios::out);
	if(outfile__array_Regular_Spiking_Interneurons_g_GABA_r.is_open())
	{
		outfile__array_Regular_Spiking_Interneurons_g_GABA_r.write(reinterpret_cast<char*>(_array_Regular_Spiking_Interneurons_g_GABA_r), 150*sizeof(_array_Regular_Spiking_Interneurons_g_GABA_r[0]));
		outfile__array_Regular_Spiking_Interneurons_g_GABA_r.close();
	} else
	{
		std::cout << "Error writing output file for _array_Regular_Spiking_Interneurons_g_GABA_r." << endl;
	}
	ofstream outfile__array_Regular_Spiking_Interneurons_g_NMDA_d;
	outfile__array_Regular_Spiking_Interneurons_g_NMDA_d.open("results/_array_Regular_Spiking_Interneurons_g_NMDA_d_7669482009407325604", ios::binary | ios::out);
	if(outfile__array_Regular_Spiking_Interneurons_g_NMDA_d.is_open())
	{
		outfile__array_Regular_Spiking_Interneurons_g_NMDA_d.write(reinterpret_cast<char*>(_array_Regular_Spiking_Interneurons_g_NMDA_d), 150*sizeof(_array_Regular_Spiking_Interneurons_g_NMDA_d[0]));
		outfile__array_Regular_Spiking_Interneurons_g_NMDA_d.close();
	} else
	{
		std::cout << "Error writing output file for _array_Regular_Spiking_Interneurons_g_NMDA_d." << endl;
	}
	ofstream outfile__array_Regular_Spiking_Interneurons_g_NMDA_r;
	outfile__array_Regular_Spiking_Interneurons_g_NMDA_r.open("results/_array_Regular_Spiking_Interneurons_g_NMDA_r_3522971143629469077", ios::binary | ios::out);
	if(outfile__array_Regular_Spiking_Interneurons_g_NMDA_r.is_open())
	{
		outfile__array_Regular_Spiking_Interneurons_g_NMDA_r.write(reinterpret_cast<char*>(_array_Regular_Spiking_Interneurons_g_NMDA_r), 150*sizeof(_array_Regular_Spiking_Interneurons_g_NMDA_r[0]));
		outfile__array_Regular_Spiking_Interneurons_g_NMDA_r.close();
	} else
	{
		std::cout << "Error writing output file for _array_Regular_Spiking_Interneurons_g_NMDA_r." << endl;
	}
	ofstream outfile__array_Regular_Spiking_Interneurons_i;
	outfile__array_Regular_Spiking_Interneurons_i.open("results/_array_Regular_Spiking_Interneurons_i_-172336858083093196", ios::binary | ios::out);
	if(outfile__array_Regular_Spiking_Interneurons_i.is_open())
	{
		outfile__array_Regular_Spiking_Interneurons_i.write(reinterpret_cast<char*>(_array_Regular_Spiking_Interneurons_i), 150*sizeof(_array_Regular_Spiking_Interneurons_i[0]));
		outfile__array_Regular_Spiking_Interneurons_i.close();
	} else
	{
		std::cout << "Error writing output file for _array_Regular_Spiking_Interneurons_i." << endl;
	}
	ofstream outfile__array_Regular_Spiking_Interneurons_v;
	outfile__array_Regular_Spiking_Interneurons_v.open("results/_array_Regular_Spiking_Interneurons_v_4270025247295897859", ios::binary | ios::out);
	if(outfile__array_Regular_Spiking_Interneurons_v.is_open())
	{
		outfile__array_Regular_Spiking_Interneurons_v.write(reinterpret_cast<char*>(_array_Regular_Spiking_Interneurons_v), 150*sizeof(_array_Regular_Spiking_Interneurons_v[0]));
		outfile__array_Regular_Spiking_Interneurons_v.close();
	} else
	{
		std::cout << "Error writing output file for _array_Regular_Spiking_Interneurons_v." << endl;
	}
	ofstream outfile__array_spikemonitor_1__source_idx;
	outfile__array_spikemonitor_1__source_idx.open("results/_array_spikemonitor_1__source_idx_5999180630170317038", ios::binary | ios::out);
	if(outfile__array_spikemonitor_1__source_idx.is_open())
	{
		outfile__array_spikemonitor_1__source_idx.write(reinterpret_cast<char*>(_array_spikemonitor_1__source_idx), 150*sizeof(_array_spikemonitor_1__source_idx[0]));
		outfile__array_spikemonitor_1__source_idx.close();
	} else
	{
		std::cout << "Error writing output file for _array_spikemonitor_1__source_idx." << endl;
	}
	ofstream outfile__array_spikemonitor_1_count;
	outfile__array_spikemonitor_1_count.open("results/_array_spikemonitor_1_count_4106906384294940916", ios::binary | ios::out);
	if(outfile__array_spikemonitor_1_count.is_open())
	{
		outfile__array_spikemonitor_1_count.write(reinterpret_cast<char*>(_array_spikemonitor_1_count), 150*sizeof(_array_spikemonitor_1_count[0]));
		outfile__array_spikemonitor_1_count.close();
	} else
	{
		std::cout << "Error writing output file for _array_spikemonitor_1_count." << endl;
	}
	ofstream outfile__array_spikemonitor_1_N;
	outfile__array_spikemonitor_1_N.open("results/_array_spikemonitor_1_N_8158277244410931957", ios::binary | ios::out);
	if(outfile__array_spikemonitor_1_N.is_open())
	{
		outfile__array_spikemonitor_1_N.write(reinterpret_cast<char*>(_array_spikemonitor_1_N), 1*sizeof(_array_spikemonitor_1_N[0]));
		outfile__array_spikemonitor_1_N.close();
	} else
	{
		std::cout << "Error writing output file for _array_spikemonitor_1_N." << endl;
	}
	ofstream outfile__array_spikemonitor_2__source_idx;
	outfile__array_spikemonitor_2__source_idx.open("results/_array_spikemonitor_2__source_idx_6489027120849475434", ios::binary | ios::out);
	if(outfile__array_spikemonitor_2__source_idx.is_open())
	{
		outfile__array_spikemonitor_2__source_idx.write(reinterpret_cast<char*>(_array_spikemonitor_2__source_idx), 50*sizeof(_array_spikemonitor_2__source_idx[0]));
		outfile__array_spikemonitor_2__source_idx.close();
	} else
	{
		std::cout << "Error writing output file for _array_spikemonitor_2__source_idx." << endl;
	}
	ofstream outfile__array_spikemonitor_2_count;
	outfile__array_spikemonitor_2_count.open("results/_array_spikemonitor_2_count_-7295925005197020042", ios::binary | ios::out);
	if(outfile__array_spikemonitor_2_count.is_open())
	{
		outfile__array_spikemonitor_2_count.write(reinterpret_cast<char*>(_array_spikemonitor_2_count), 50*sizeof(_array_spikemonitor_2_count[0]));
		outfile__array_spikemonitor_2_count.close();
	} else
	{
		std::cout << "Error writing output file for _array_spikemonitor_2_count." << endl;
	}
	ofstream outfile__array_spikemonitor_2_N;
	outfile__array_spikemonitor_2_N.open("results/_array_spikemonitor_2_N_6714936517428226874", ios::binary | ios::out);
	if(outfile__array_spikemonitor_2_N.is_open())
	{
		outfile__array_spikemonitor_2_N.write(reinterpret_cast<char*>(_array_spikemonitor_2_N), 1*sizeof(_array_spikemonitor_2_N[0]));
		outfile__array_spikemonitor_2_N.close();
	} else
	{
		std::cout << "Error writing output file for _array_spikemonitor_2_N." << endl;
	}
	ofstream outfile__array_spikemonitor_3__source_idx;
	outfile__array_spikemonitor_3__source_idx.open("results/_array_spikemonitor_3__source_idx_-2298285704987901997", ios::binary | ios::out);
	if(outfile__array_spikemonitor_3__source_idx.is_open())
	{
		outfile__array_spikemonitor_3__source_idx.write(reinterpret_cast<char*>(_array_spikemonitor_3__source_idx), 800*sizeof(_array_spikemonitor_3__source_idx[0]));
		outfile__array_spikemonitor_3__source_idx.close();
	} else
	{
		std::cout << "Error writing output file for _array_spikemonitor_3__source_idx." << endl;
	}
	ofstream outfile__array_spikemonitor_3_count;
	outfile__array_spikemonitor_3_count.open("results/_array_spikemonitor_3_count_7147920960925573761", ios::binary | ios::out);
	if(outfile__array_spikemonitor_3_count.is_open())
	{
		outfile__array_spikemonitor_3_count.write(reinterpret_cast<char*>(_array_spikemonitor_3_count), 800*sizeof(_array_spikemonitor_3_count[0]));
		outfile__array_spikemonitor_3_count.close();
	} else
	{
		std::cout << "Error writing output file for _array_spikemonitor_3_count." << endl;
	}
	ofstream outfile__array_spikemonitor_3_N;
	outfile__array_spikemonitor_3_N.open("results/_array_spikemonitor_3_N_-5369373042821133657", ios::binary | ios::out);
	if(outfile__array_spikemonitor_3_N.is_open())
	{
		outfile__array_spikemonitor_3_N.write(reinterpret_cast<char*>(_array_spikemonitor_3_N), 1*sizeof(_array_spikemonitor_3_N[0]));
		outfile__array_spikemonitor_3_N.close();
	} else
	{
		std::cout << "Error writing output file for _array_spikemonitor_3_N." << endl;
	}
	ofstream outfile__array_spikemonitor__source_idx;
	outfile__array_spikemonitor__source_idx.open("results/_array_spikemonitor__source_idx_6496070981450293772", ios::binary | ios::out);
	if(outfile__array_spikemonitor__source_idx.is_open())
	{
		outfile__array_spikemonitor__source_idx.write(reinterpret_cast<char*>(_array_spikemonitor__source_idx), 800*sizeof(_array_spikemonitor__source_idx[0]));
		outfile__array_spikemonitor__source_idx.close();
	} else
	{
		std::cout << "Error writing output file for _array_spikemonitor__source_idx." << endl;
	}
	ofstream outfile__array_spikemonitor_count;
	outfile__array_spikemonitor_count.open("results/_array_spikemonitor_count_4775147338659473104", ios::binary | ios::out);
	if(outfile__array_spikemonitor_count.is_open())
	{
		outfile__array_spikemonitor_count.write(reinterpret_cast<char*>(_array_spikemonitor_count), 800*sizeof(_array_spikemonitor_count[0]));
		outfile__array_spikemonitor_count.close();
	} else
	{
		std::cout << "Error writing output file for _array_spikemonitor_count." << endl;
	}
	ofstream outfile__array_spikemonitor_N;
	outfile__array_spikemonitor_N.open("results/_array_spikemonitor_N_-3512250197654524777", ios::binary | ios::out);
	if(outfile__array_spikemonitor_N.is_open())
	{
		outfile__array_spikemonitor_N.write(reinterpret_cast<char*>(_array_spikemonitor_N), 1*sizeof(_array_spikemonitor_N[0]));
		outfile__array_spikemonitor_N.close();
	} else
	{
		std::cout << "Error writing output file for _array_spikemonitor_N." << endl;
	}
	ofstream outfile__array_statemonitor_10__indices;
	outfile__array_statemonitor_10__indices.open("results/_array_statemonitor_10__indices_-3409743634892146919", ios::binary | ios::out);
	if(outfile__array_statemonitor_10__indices.is_open())
	{
		outfile__array_statemonitor_10__indices.write(reinterpret_cast<char*>(_array_statemonitor_10__indices), 10*sizeof(_array_statemonitor_10__indices[0]));
		outfile__array_statemonitor_10__indices.close();
	} else
	{
		std::cout << "Error writing output file for _array_statemonitor_10__indices." << endl;
	}
	ofstream outfile__array_statemonitor_10_N;
	outfile__array_statemonitor_10_N.open("results/_array_statemonitor_10_N_6202757444002434244", ios::binary | ios::out);
	if(outfile__array_statemonitor_10_N.is_open())
	{
		outfile__array_statemonitor_10_N.write(reinterpret_cast<char*>(_array_statemonitor_10_N), 1*sizeof(_array_statemonitor_10_N[0]));
		outfile__array_statemonitor_10_N.close();
	} else
	{
		std::cout << "Error writing output file for _array_statemonitor_10_N." << endl;
	}
	ofstream outfile__array_statemonitor_11__indices;
	outfile__array_statemonitor_11__indices.open("results/_array_statemonitor_11__indices_-3758794212971068398", ios::binary | ios::out);
	if(outfile__array_statemonitor_11__indices.is_open())
	{
		outfile__array_statemonitor_11__indices.write(reinterpret_cast<char*>(_array_statemonitor_11__indices), 10*sizeof(_array_statemonitor_11__indices[0]));
		outfile__array_statemonitor_11__indices.close();
	} else
	{
		std::cout << "Error writing output file for _array_statemonitor_11__indices." << endl;
	}
	ofstream outfile__array_statemonitor_11_N;
	outfile__array_statemonitor_11_N.open("results/_array_statemonitor_11_N_-3258865333136148369", ios::binary | ios::out);
	if(outfile__array_statemonitor_11_N.is_open())
	{
		outfile__array_statemonitor_11_N.write(reinterpret_cast<char*>(_array_statemonitor_11_N), 1*sizeof(_array_statemonitor_11_N[0]));
		outfile__array_statemonitor_11_N.close();
	} else
	{
		std::cout << "Error writing output file for _array_statemonitor_11_N." << endl;
	}
	ofstream outfile__array_statemonitor_12__indices;
	outfile__array_statemonitor_12__indices.open("results/_array_statemonitor_12__indices_2624903534362341648", ios::binary | ios::out);
	if(outfile__array_statemonitor_12__indices.is_open())
	{
		outfile__array_statemonitor_12__indices.write(reinterpret_cast<char*>(_array_statemonitor_12__indices), 10*sizeof(_array_statemonitor_12__indices[0]));
		outfile__array_statemonitor_12__indices.close();
	} else
	{
		std::cout << "Error writing output file for _array_statemonitor_12__indices." << endl;
	}
	ofstream outfile__array_statemonitor_12_N;
	outfile__array_statemonitor_12_N.open("results/_array_statemonitor_12_N_-703450120203528457", ios::binary | ios::out);
	if(outfile__array_statemonitor_12_N.is_open())
	{
		outfile__array_statemonitor_12_N.write(reinterpret_cast<char*>(_array_statemonitor_12_N), 1*sizeof(_array_statemonitor_12_N[0]));
		outfile__array_statemonitor_12_N.close();
	} else
	{
		std::cout << "Error writing output file for _array_statemonitor_12_N." << endl;
	}
	ofstream outfile__array_statemonitor_13__indices;
	outfile__array_statemonitor_13__indices.open("results/_array_statemonitor_13__indices_-5177736638531413882", ios::binary | ios::out);
	if(outfile__array_statemonitor_13__indices.is_open())
	{
		outfile__array_statemonitor_13__indices.write(reinterpret_cast<char*>(_array_statemonitor_13__indices), 10*sizeof(_array_statemonitor_13__indices[0]));
		outfile__array_statemonitor_13__indices.close();
	} else
	{
		std::cout << "Error writing output file for _array_statemonitor_13__indices." << endl;
	}
	ofstream outfile__array_statemonitor_13_N;
	outfile__array_statemonitor_13_N.open("results/_array_statemonitor_13_N_-1988663990213937427", ios::binary | ios::out);
	if(outfile__array_statemonitor_13_N.is_open())
	{
		outfile__array_statemonitor_13_N.write(reinterpret_cast<char*>(_array_statemonitor_13_N), 1*sizeof(_array_statemonitor_13_N[0]));
		outfile__array_statemonitor_13_N.close();
	} else
	{
		std::cout << "Error writing output file for _array_statemonitor_13_N." << endl;
	}
	ofstream outfile__array_statemonitor_14__indices;
	outfile__array_statemonitor_14__indices.open("results/_array_statemonitor_14__indices_2234247567734391947", ios::binary | ios::out);
	if(outfile__array_statemonitor_14__indices.is_open())
	{
		outfile__array_statemonitor_14__indices.write(reinterpret_cast<char*>(_array_statemonitor_14__indices), 10*sizeof(_array_statemonitor_14__indices[0]));
		outfile__array_statemonitor_14__indices.close();
	} else
	{
		std::cout << "Error writing output file for _array_statemonitor_14__indices." << endl;
	}
	ofstream outfile__array_statemonitor_14_N;
	outfile__array_statemonitor_14_N.open("results/_array_statemonitor_14_N_8734734666366252998", ios::binary | ios::out);
	if(outfile__array_statemonitor_14_N.is_open())
	{
		outfile__array_statemonitor_14_N.write(reinterpret_cast<char*>(_array_statemonitor_14_N), 1*sizeof(_array_statemonitor_14_N[0]));
		outfile__array_statemonitor_14_N.close();
	} else
	{
		std::cout << "Error writing output file for _array_statemonitor_14_N." << endl;
	}
	ofstream outfile__array_statemonitor_1__indices;
	outfile__array_statemonitor_1__indices.open("results/_array_statemonitor_1__indices_1351380958974605204", ios::binary | ios::out);
	if(outfile__array_statemonitor_1__indices.is_open())
	{
		outfile__array_statemonitor_1__indices.write(reinterpret_cast<char*>(_array_statemonitor_1__indices), 10*sizeof(_array_statemonitor_1__indices[0]));
		outfile__array_statemonitor_1__indices.close();
	} else
	{
		std::cout << "Error writing output file for _array_statemonitor_1__indices." << endl;
	}
	ofstream outfile__array_statemonitor_1_N;
	outfile__array_statemonitor_1_N.open("results/_array_statemonitor_1_N_-3687681067883140129", ios::binary | ios::out);
	if(outfile__array_statemonitor_1_N.is_open())
	{
		outfile__array_statemonitor_1_N.write(reinterpret_cast<char*>(_array_statemonitor_1_N), 1*sizeof(_array_statemonitor_1_N[0]));
		outfile__array_statemonitor_1_N.close();
	} else
	{
		std::cout << "Error writing output file for _array_statemonitor_1_N." << endl;
	}
	ofstream outfile__array_statemonitor_2__indices;
	outfile__array_statemonitor_2__indices.open("results/_array_statemonitor_2__indices_-9170536923315336113", ios::binary | ios::out);
	if(outfile__array_statemonitor_2__indices.is_open())
	{
		outfile__array_statemonitor_2__indices.write(reinterpret_cast<char*>(_array_statemonitor_2__indices), 10*sizeof(_array_statemonitor_2__indices[0]));
		outfile__array_statemonitor_2__indices.close();
	} else
	{
		std::cout << "Error writing output file for _array_statemonitor_2__indices." << endl;
	}
	ofstream outfile__array_statemonitor_2_N;
	outfile__array_statemonitor_2_N.open("results/_array_statemonitor_2_N_4509116572378078388", ios::binary | ios::out);
	if(outfile__array_statemonitor_2_N.is_open())
	{
		outfile__array_statemonitor_2_N.write(reinterpret_cast<char*>(_array_statemonitor_2_N), 1*sizeof(_array_statemonitor_2_N[0]));
		outfile__array_statemonitor_2_N.close();
	} else
	{
		std::cout << "Error writing output file for _array_statemonitor_2_N." << endl;
	}
	ofstream outfile__array_statemonitor_3__indices;
	outfile__array_statemonitor_3__indices.open("results/_array_statemonitor_3__indices_6502013609274869011", ios::binary | ios::out);
	if(outfile__array_statemonitor_3__indices.is_open())
	{
		outfile__array_statemonitor_3__indices.write(reinterpret_cast<char*>(_array_statemonitor_3__indices), 10*sizeof(_array_statemonitor_3__indices[0]));
		outfile__array_statemonitor_3__indices.close();
	} else
	{
		std::cout << "Error writing output file for _array_statemonitor_3__indices." << endl;
	}
	ofstream outfile__array_statemonitor_3_N;
	outfile__array_statemonitor_3_N.open("results/_array_statemonitor_3_N_-5876447453678366185", ios::binary | ios::out);
	if(outfile__array_statemonitor_3_N.is_open())
	{
		outfile__array_statemonitor_3_N.write(reinterpret_cast<char*>(_array_statemonitor_3_N), 1*sizeof(_array_statemonitor_3_N[0]));
		outfile__array_statemonitor_3_N.close();
	} else
	{
		std::cout << "Error writing output file for _array_statemonitor_3_N." << endl;
	}
	ofstream outfile__array_statemonitor_4__indices;
	outfile__array_statemonitor_4__indices.open("results/_array_statemonitor_4__indices_1410709822888712283", ios::binary | ios::out);
	if(outfile__array_statemonitor_4__indices.is_open())
	{
		outfile__array_statemonitor_4__indices.write(reinterpret_cast<char*>(_array_statemonitor_4__indices), 10*sizeof(_array_statemonitor_4__indices[0]));
		outfile__array_statemonitor_4__indices.close();
	} else
	{
		std::cout << "Error writing output file for _array_statemonitor_4__indices." << endl;
	}
	ofstream outfile__array_statemonitor_4_N;
	outfile__array_statemonitor_4_N.open("results/_array_statemonitor_4_N_7757164478214048117", ios::binary | ios::out);
	if(outfile__array_statemonitor_4_N.is_open())
	{
		outfile__array_statemonitor_4_N.write(reinterpret_cast<char*>(_array_statemonitor_4_N), 1*sizeof(_array_statemonitor_4_N[0]));
		outfile__array_statemonitor_4_N.close();
	} else
	{
		std::cout << "Error writing output file for _array_statemonitor_4_N." << endl;
	}
	ofstream outfile__array_statemonitor_5__indices;
	outfile__array_statemonitor_5__indices.open("results/_array_statemonitor_5__indices_-8452927918640109382", ios::binary | ios::out);
	if(outfile__array_statemonitor_5__indices.is_open())
	{
		outfile__array_statemonitor_5__indices.write(reinterpret_cast<char*>(_array_statemonitor_5__indices), 10*sizeof(_array_statemonitor_5__indices[0]));
		outfile__array_statemonitor_5__indices.close();
	} else
	{
		std::cout << "Error writing output file for _array_statemonitor_5__indices." << endl;
	}
	ofstream outfile__array_statemonitor_5_N;
	outfile__array_statemonitor_5_N.open("results/_array_statemonitor_5_N_-1634096276223815325", ios::binary | ios::out);
	if(outfile__array_statemonitor_5_N.is_open())
	{
		outfile__array_statemonitor_5_N.write(reinterpret_cast<char*>(_array_statemonitor_5_N), 1*sizeof(_array_statemonitor_5_N[0]));
		outfile__array_statemonitor_5_N.close();
	} else
	{
		std::cout << "Error writing output file for _array_statemonitor_5_N." << endl;
	}
	ofstream outfile__array_statemonitor_6__indices;
	outfile__array_statemonitor_6__indices.open("results/_array_statemonitor_6__indices_-8404962414775088503", ios::binary | ios::out);
	if(outfile__array_statemonitor_6__indices.is_open())
	{
		outfile__array_statemonitor_6__indices.write(reinterpret_cast<char*>(_array_statemonitor_6__indices), 10*sizeof(_array_statemonitor_6__indices[0]));
		outfile__array_statemonitor_6__indices.close();
	} else
	{
		std::cout << "Error writing output file for _array_statemonitor_6__indices." << endl;
	}
	ofstream outfile__array_statemonitor_6_N;
	outfile__array_statemonitor_6_N.open("results/_array_statemonitor_6_N_-2435845486983236382", ios::binary | ios::out);
	if(outfile__array_statemonitor_6_N.is_open())
	{
		outfile__array_statemonitor_6_N.write(reinterpret_cast<char*>(_array_statemonitor_6_N), 1*sizeof(_array_statemonitor_6_N[0]));
		outfile__array_statemonitor_6_N.close();
	} else
	{
		std::cout << "Error writing output file for _array_statemonitor_6_N." << endl;
	}
	ofstream outfile__array_statemonitor_7__indices;
	outfile__array_statemonitor_7__indices.open("results/_array_statemonitor_7__indices_-7270323594586264185", ios::binary | ios::out);
	if(outfile__array_statemonitor_7__indices.is_open())
	{
		outfile__array_statemonitor_7__indices.write(reinterpret_cast<char*>(_array_statemonitor_7__indices), 10*sizeof(_array_statemonitor_7__indices[0]));
		outfile__array_statemonitor_7__indices.close();
	} else
	{
		std::cout << "Error writing output file for _array_statemonitor_7__indices." << endl;
	}
	ofstream outfile__array_statemonitor_7_N;
	outfile__array_statemonitor_7_N.open("results/_array_statemonitor_7_N_8405387445498458318", ios::binary | ios::out);
	if(outfile__array_statemonitor_7_N.is_open())
	{
		outfile__array_statemonitor_7_N.write(reinterpret_cast<char*>(_array_statemonitor_7_N), 1*sizeof(_array_statemonitor_7_N[0]));
		outfile__array_statemonitor_7_N.close();
	} else
	{
		std::cout << "Error writing output file for _array_statemonitor_7_N." << endl;
	}
	ofstream outfile__array_statemonitor_8__indices;
	outfile__array_statemonitor_8__indices.open("results/_array_statemonitor_8__indices_-7599709787505080993", ios::binary | ios::out);
	if(outfile__array_statemonitor_8__indices.is_open())
	{
		outfile__array_statemonitor_8__indices.write(reinterpret_cast<char*>(_array_statemonitor_8__indices), 10*sizeof(_array_statemonitor_8__indices[0]));
		outfile__array_statemonitor_8__indices.close();
	} else
	{
		std::cout << "Error writing output file for _array_statemonitor_8__indices." << endl;
	}
	ofstream outfile__array_statemonitor_8_N;
	outfile__array_statemonitor_8_N.open("results/_array_statemonitor_8_N_9016288221048422612", ios::binary | ios::out);
	if(outfile__array_statemonitor_8_N.is_open())
	{
		outfile__array_statemonitor_8_N.write(reinterpret_cast<char*>(_array_statemonitor_8_N), 1*sizeof(_array_statemonitor_8_N[0]));
		outfile__array_statemonitor_8_N.close();
	} else
	{
		std::cout << "Error writing output file for _array_statemonitor_8_N." << endl;
	}
	ofstream outfile__array_statemonitor_9__indices;
	outfile__array_statemonitor_9__indices.open("results/_array_statemonitor_9__indices_7009009403027020375", ios::binary | ios::out);
	if(outfile__array_statemonitor_9__indices.is_open())
	{
		outfile__array_statemonitor_9__indices.write(reinterpret_cast<char*>(_array_statemonitor_9__indices), 10*sizeof(_array_statemonitor_9__indices[0]));
		outfile__array_statemonitor_9__indices.close();
	} else
	{
		std::cout << "Error writing output file for _array_statemonitor_9__indices." << endl;
	}
	ofstream outfile__array_statemonitor_9_N;
	outfile__array_statemonitor_9_N.open("results/_array_statemonitor_9_N_5084530216145731415", ios::binary | ios::out);
	if(outfile__array_statemonitor_9_N.is_open())
	{
		outfile__array_statemonitor_9_N.write(reinterpret_cast<char*>(_array_statemonitor_9_N), 1*sizeof(_array_statemonitor_9_N[0]));
		outfile__array_statemonitor_9_N.close();
	} else
	{
		std::cout << "Error writing output file for _array_statemonitor_9_N." << endl;
	}
	ofstream outfile__array_statemonitor__indices;
	outfile__array_statemonitor__indices.open("results/_array_statemonitor__indices_8039001758410230084", ios::binary | ios::out);
	if(outfile__array_statemonitor__indices.is_open())
	{
		outfile__array_statemonitor__indices.write(reinterpret_cast<char*>(_array_statemonitor__indices), 10*sizeof(_array_statemonitor__indices[0]));
		outfile__array_statemonitor__indices.close();
	} else
	{
		std::cout << "Error writing output file for _array_statemonitor__indices." << endl;
	}
	ofstream outfile__array_statemonitor_N;
	outfile__array_statemonitor_N.open("results/_array_statemonitor_N_-2403116250176497187", ios::binary | ios::out);
	if(outfile__array_statemonitor_N.is_open())
	{
		outfile__array_statemonitor_N.write(reinterpret_cast<char*>(_array_statemonitor_N), 1*sizeof(_array_statemonitor_N[0]));
		outfile__array_statemonitor_N.close();
	} else
	{
		std::cout << "Error writing output file for _array_statemonitor_N." << endl;
	}
	ofstream outfile__array_synapses_N;
	outfile__array_synapses_N.open("results/_array_synapses_N_7823546933516614990", ios::binary | ios::out);
	if(outfile__array_synapses_N.is_open())
	{
		outfile__array_synapses_N.write(reinterpret_cast<char*>(_array_synapses_N), 1*sizeof(_array_synapses_N[0]));
		outfile__array_synapses_N.close();
	} else
	{
		std::cout << "Error writing output file for _array_synapses_N." << endl;
	}

	ofstream outfile__dynamic_array_AMPA_NMDA_fromPCtoFSI__synaptic_post;
	outfile__dynamic_array_AMPA_NMDA_fromPCtoFSI__synaptic_post.open("results/_dynamic_array_AMPA_NMDA_fromPCtoFSI__synaptic_post_4909553872946318509", ios::binary | ios::out);
	if(outfile__dynamic_array_AMPA_NMDA_fromPCtoFSI__synaptic_post.is_open())
	{
        if (! _dynamic_array_AMPA_NMDA_fromPCtoFSI__synaptic_post.empty() )
        {
			outfile__dynamic_array_AMPA_NMDA_fromPCtoFSI__synaptic_post.write(reinterpret_cast<char*>(&_dynamic_array_AMPA_NMDA_fromPCtoFSI__synaptic_post[0]), _dynamic_array_AMPA_NMDA_fromPCtoFSI__synaptic_post.size()*sizeof(_dynamic_array_AMPA_NMDA_fromPCtoFSI__synaptic_post[0]));
		    outfile__dynamic_array_AMPA_NMDA_fromPCtoFSI__synaptic_post.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_AMPA_NMDA_fromPCtoFSI__synaptic_post." << endl;
	}
	ofstream outfile__dynamic_array_AMPA_NMDA_fromPCtoFSI__synaptic_pre;
	outfile__dynamic_array_AMPA_NMDA_fromPCtoFSI__synaptic_pre.open("results/_dynamic_array_AMPA_NMDA_fromPCtoFSI__synaptic_pre_1604632271264937746", ios::binary | ios::out);
	if(outfile__dynamic_array_AMPA_NMDA_fromPCtoFSI__synaptic_pre.is_open())
	{
        if (! _dynamic_array_AMPA_NMDA_fromPCtoFSI__synaptic_pre.empty() )
        {
			outfile__dynamic_array_AMPA_NMDA_fromPCtoFSI__synaptic_pre.write(reinterpret_cast<char*>(&_dynamic_array_AMPA_NMDA_fromPCtoFSI__synaptic_pre[0]), _dynamic_array_AMPA_NMDA_fromPCtoFSI__synaptic_pre.size()*sizeof(_dynamic_array_AMPA_NMDA_fromPCtoFSI__synaptic_pre[0]));
		    outfile__dynamic_array_AMPA_NMDA_fromPCtoFSI__synaptic_pre.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_AMPA_NMDA_fromPCtoFSI__synaptic_pre." << endl;
	}
	ofstream outfile__dynamic_array_AMPA_NMDA_fromPCtoFSI_delay;
	outfile__dynamic_array_AMPA_NMDA_fromPCtoFSI_delay.open("results/_dynamic_array_AMPA_NMDA_fromPCtoFSI_delay_3556447657235163880", ios::binary | ios::out);
	if(outfile__dynamic_array_AMPA_NMDA_fromPCtoFSI_delay.is_open())
	{
        if (! _dynamic_array_AMPA_NMDA_fromPCtoFSI_delay.empty() )
        {
			outfile__dynamic_array_AMPA_NMDA_fromPCtoFSI_delay.write(reinterpret_cast<char*>(&_dynamic_array_AMPA_NMDA_fromPCtoFSI_delay[0]), _dynamic_array_AMPA_NMDA_fromPCtoFSI_delay.size()*sizeof(_dynamic_array_AMPA_NMDA_fromPCtoFSI_delay[0]));
		    outfile__dynamic_array_AMPA_NMDA_fromPCtoFSI_delay.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_AMPA_NMDA_fromPCtoFSI_delay." << endl;
	}
	ofstream outfile__dynamic_array_AMPA_NMDA_fromPCtoFSI_N_incoming;
	outfile__dynamic_array_AMPA_NMDA_fromPCtoFSI_N_incoming.open("results/_dynamic_array_AMPA_NMDA_fromPCtoFSI_N_incoming_-7253598703787064757", ios::binary | ios::out);
	if(outfile__dynamic_array_AMPA_NMDA_fromPCtoFSI_N_incoming.is_open())
	{
        if (! _dynamic_array_AMPA_NMDA_fromPCtoFSI_N_incoming.empty() )
        {
			outfile__dynamic_array_AMPA_NMDA_fromPCtoFSI_N_incoming.write(reinterpret_cast<char*>(&_dynamic_array_AMPA_NMDA_fromPCtoFSI_N_incoming[0]), _dynamic_array_AMPA_NMDA_fromPCtoFSI_N_incoming.size()*sizeof(_dynamic_array_AMPA_NMDA_fromPCtoFSI_N_incoming[0]));
		    outfile__dynamic_array_AMPA_NMDA_fromPCtoFSI_N_incoming.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_AMPA_NMDA_fromPCtoFSI_N_incoming." << endl;
	}
	ofstream outfile__dynamic_array_AMPA_NMDA_fromPCtoFSI_N_outgoing;
	outfile__dynamic_array_AMPA_NMDA_fromPCtoFSI_N_outgoing.open("results/_dynamic_array_AMPA_NMDA_fromPCtoFSI_N_outgoing_8568479774443409700", ios::binary | ios::out);
	if(outfile__dynamic_array_AMPA_NMDA_fromPCtoFSI_N_outgoing.is_open())
	{
        if (! _dynamic_array_AMPA_NMDA_fromPCtoFSI_N_outgoing.empty() )
        {
			outfile__dynamic_array_AMPA_NMDA_fromPCtoFSI_N_outgoing.write(reinterpret_cast<char*>(&_dynamic_array_AMPA_NMDA_fromPCtoFSI_N_outgoing[0]), _dynamic_array_AMPA_NMDA_fromPCtoFSI_N_outgoing.size()*sizeof(_dynamic_array_AMPA_NMDA_fromPCtoFSI_N_outgoing[0]));
		    outfile__dynamic_array_AMPA_NMDA_fromPCtoFSI_N_outgoing.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_AMPA_NMDA_fromPCtoFSI_N_outgoing." << endl;
	}
	ofstream outfile__dynamic_array_AMPA_NMDA_fromPCtoPC__synaptic_post;
	outfile__dynamic_array_AMPA_NMDA_fromPCtoPC__synaptic_post.open("results/_dynamic_array_AMPA_NMDA_fromPCtoPC__synaptic_post_-2656920448642579546", ios::binary | ios::out);
	if(outfile__dynamic_array_AMPA_NMDA_fromPCtoPC__synaptic_post.is_open())
	{
        if (! _dynamic_array_AMPA_NMDA_fromPCtoPC__synaptic_post.empty() )
        {
			outfile__dynamic_array_AMPA_NMDA_fromPCtoPC__synaptic_post.write(reinterpret_cast<char*>(&_dynamic_array_AMPA_NMDA_fromPCtoPC__synaptic_post[0]), _dynamic_array_AMPA_NMDA_fromPCtoPC__synaptic_post.size()*sizeof(_dynamic_array_AMPA_NMDA_fromPCtoPC__synaptic_post[0]));
		    outfile__dynamic_array_AMPA_NMDA_fromPCtoPC__synaptic_post.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_AMPA_NMDA_fromPCtoPC__synaptic_post." << endl;
	}
	ofstream outfile__dynamic_array_AMPA_NMDA_fromPCtoPC__synaptic_pre;
	outfile__dynamic_array_AMPA_NMDA_fromPCtoPC__synaptic_pre.open("results/_dynamic_array_AMPA_NMDA_fromPCtoPC__synaptic_pre_-3951974475101470756", ios::binary | ios::out);
	if(outfile__dynamic_array_AMPA_NMDA_fromPCtoPC__synaptic_pre.is_open())
	{
        if (! _dynamic_array_AMPA_NMDA_fromPCtoPC__synaptic_pre.empty() )
        {
			outfile__dynamic_array_AMPA_NMDA_fromPCtoPC__synaptic_pre.write(reinterpret_cast<char*>(&_dynamic_array_AMPA_NMDA_fromPCtoPC__synaptic_pre[0]), _dynamic_array_AMPA_NMDA_fromPCtoPC__synaptic_pre.size()*sizeof(_dynamic_array_AMPA_NMDA_fromPCtoPC__synaptic_pre[0]));
		    outfile__dynamic_array_AMPA_NMDA_fromPCtoPC__synaptic_pre.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_AMPA_NMDA_fromPCtoPC__synaptic_pre." << endl;
	}
	ofstream outfile__dynamic_array_AMPA_NMDA_fromPCtoPC_delay;
	outfile__dynamic_array_AMPA_NMDA_fromPCtoPC_delay.open("results/_dynamic_array_AMPA_NMDA_fromPCtoPC_delay_1993468325990398388", ios::binary | ios::out);
	if(outfile__dynamic_array_AMPA_NMDA_fromPCtoPC_delay.is_open())
	{
        if (! _dynamic_array_AMPA_NMDA_fromPCtoPC_delay.empty() )
        {
			outfile__dynamic_array_AMPA_NMDA_fromPCtoPC_delay.write(reinterpret_cast<char*>(&_dynamic_array_AMPA_NMDA_fromPCtoPC_delay[0]), _dynamic_array_AMPA_NMDA_fromPCtoPC_delay.size()*sizeof(_dynamic_array_AMPA_NMDA_fromPCtoPC_delay[0]));
		    outfile__dynamic_array_AMPA_NMDA_fromPCtoPC_delay.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_AMPA_NMDA_fromPCtoPC_delay." << endl;
	}
	ofstream outfile__dynamic_array_AMPA_NMDA_fromPCtoPC_N_incoming;
	outfile__dynamic_array_AMPA_NMDA_fromPCtoPC_N_incoming.open("results/_dynamic_array_AMPA_NMDA_fromPCtoPC_N_incoming_-7972766542117824642", ios::binary | ios::out);
	if(outfile__dynamic_array_AMPA_NMDA_fromPCtoPC_N_incoming.is_open())
	{
        if (! _dynamic_array_AMPA_NMDA_fromPCtoPC_N_incoming.empty() )
        {
			outfile__dynamic_array_AMPA_NMDA_fromPCtoPC_N_incoming.write(reinterpret_cast<char*>(&_dynamic_array_AMPA_NMDA_fromPCtoPC_N_incoming[0]), _dynamic_array_AMPA_NMDA_fromPCtoPC_N_incoming.size()*sizeof(_dynamic_array_AMPA_NMDA_fromPCtoPC_N_incoming[0]));
		    outfile__dynamic_array_AMPA_NMDA_fromPCtoPC_N_incoming.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_AMPA_NMDA_fromPCtoPC_N_incoming." << endl;
	}
	ofstream outfile__dynamic_array_AMPA_NMDA_fromPCtoPC_N_outgoing;
	outfile__dynamic_array_AMPA_NMDA_fromPCtoPC_N_outgoing.open("results/_dynamic_array_AMPA_NMDA_fromPCtoPC_N_outgoing_199651931455372991", ios::binary | ios::out);
	if(outfile__dynamic_array_AMPA_NMDA_fromPCtoPC_N_outgoing.is_open())
	{
        if (! _dynamic_array_AMPA_NMDA_fromPCtoPC_N_outgoing.empty() )
        {
			outfile__dynamic_array_AMPA_NMDA_fromPCtoPC_N_outgoing.write(reinterpret_cast<char*>(&_dynamic_array_AMPA_NMDA_fromPCtoPC_N_outgoing[0]), _dynamic_array_AMPA_NMDA_fromPCtoPC_N_outgoing.size()*sizeof(_dynamic_array_AMPA_NMDA_fromPCtoPC_N_outgoing[0]));
		    outfile__dynamic_array_AMPA_NMDA_fromPCtoPC_N_outgoing.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_AMPA_NMDA_fromPCtoPC_N_outgoing." << endl;
	}
	ofstream outfile__dynamic_array_AMPA_NMDA_fromPCtoRSI__synaptic_post;
	outfile__dynamic_array_AMPA_NMDA_fromPCtoRSI__synaptic_post.open("results/_dynamic_array_AMPA_NMDA_fromPCtoRSI__synaptic_post_-6799248617750956077", ios::binary | ios::out);
	if(outfile__dynamic_array_AMPA_NMDA_fromPCtoRSI__synaptic_post.is_open())
	{
        if (! _dynamic_array_AMPA_NMDA_fromPCtoRSI__synaptic_post.empty() )
        {
			outfile__dynamic_array_AMPA_NMDA_fromPCtoRSI__synaptic_post.write(reinterpret_cast<char*>(&_dynamic_array_AMPA_NMDA_fromPCtoRSI__synaptic_post[0]), _dynamic_array_AMPA_NMDA_fromPCtoRSI__synaptic_post.size()*sizeof(_dynamic_array_AMPA_NMDA_fromPCtoRSI__synaptic_post[0]));
		    outfile__dynamic_array_AMPA_NMDA_fromPCtoRSI__synaptic_post.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_AMPA_NMDA_fromPCtoRSI__synaptic_post." << endl;
	}
	ofstream outfile__dynamic_array_AMPA_NMDA_fromPCtoRSI__synaptic_pre;
	outfile__dynamic_array_AMPA_NMDA_fromPCtoRSI__synaptic_pre.open("results/_dynamic_array_AMPA_NMDA_fromPCtoRSI__synaptic_pre_-7339388053089463526", ios::binary | ios::out);
	if(outfile__dynamic_array_AMPA_NMDA_fromPCtoRSI__synaptic_pre.is_open())
	{
        if (! _dynamic_array_AMPA_NMDA_fromPCtoRSI__synaptic_pre.empty() )
        {
			outfile__dynamic_array_AMPA_NMDA_fromPCtoRSI__synaptic_pre.write(reinterpret_cast<char*>(&_dynamic_array_AMPA_NMDA_fromPCtoRSI__synaptic_pre[0]), _dynamic_array_AMPA_NMDA_fromPCtoRSI__synaptic_pre.size()*sizeof(_dynamic_array_AMPA_NMDA_fromPCtoRSI__synaptic_pre[0]));
		    outfile__dynamic_array_AMPA_NMDA_fromPCtoRSI__synaptic_pre.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_AMPA_NMDA_fromPCtoRSI__synaptic_pre." << endl;
	}
	ofstream outfile__dynamic_array_AMPA_NMDA_fromPCtoRSI_delay;
	outfile__dynamic_array_AMPA_NMDA_fromPCtoRSI_delay.open("results/_dynamic_array_AMPA_NMDA_fromPCtoRSI_delay_-4376015159413115049", ios::binary | ios::out);
	if(outfile__dynamic_array_AMPA_NMDA_fromPCtoRSI_delay.is_open())
	{
        if (! _dynamic_array_AMPA_NMDA_fromPCtoRSI_delay.empty() )
        {
			outfile__dynamic_array_AMPA_NMDA_fromPCtoRSI_delay.write(reinterpret_cast<char*>(&_dynamic_array_AMPA_NMDA_fromPCtoRSI_delay[0]), _dynamic_array_AMPA_NMDA_fromPCtoRSI_delay.size()*sizeof(_dynamic_array_AMPA_NMDA_fromPCtoRSI_delay[0]));
		    outfile__dynamic_array_AMPA_NMDA_fromPCtoRSI_delay.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_AMPA_NMDA_fromPCtoRSI_delay." << endl;
	}
	ofstream outfile__dynamic_array_AMPA_NMDA_fromPCtoRSI_N_incoming;
	outfile__dynamic_array_AMPA_NMDA_fromPCtoRSI_N_incoming.open("results/_dynamic_array_AMPA_NMDA_fromPCtoRSI_N_incoming_225044259996340998", ios::binary | ios::out);
	if(outfile__dynamic_array_AMPA_NMDA_fromPCtoRSI_N_incoming.is_open())
	{
        if (! _dynamic_array_AMPA_NMDA_fromPCtoRSI_N_incoming.empty() )
        {
			outfile__dynamic_array_AMPA_NMDA_fromPCtoRSI_N_incoming.write(reinterpret_cast<char*>(&_dynamic_array_AMPA_NMDA_fromPCtoRSI_N_incoming[0]), _dynamic_array_AMPA_NMDA_fromPCtoRSI_N_incoming.size()*sizeof(_dynamic_array_AMPA_NMDA_fromPCtoRSI_N_incoming[0]));
		    outfile__dynamic_array_AMPA_NMDA_fromPCtoRSI_N_incoming.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_AMPA_NMDA_fromPCtoRSI_N_incoming." << endl;
	}
	ofstream outfile__dynamic_array_AMPA_NMDA_fromPCtoRSI_N_outgoing;
	outfile__dynamic_array_AMPA_NMDA_fromPCtoRSI_N_outgoing.open("results/_dynamic_array_AMPA_NMDA_fromPCtoRSI_N_outgoing_6706305927212172925", ios::binary | ios::out);
	if(outfile__dynamic_array_AMPA_NMDA_fromPCtoRSI_N_outgoing.is_open())
	{
        if (! _dynamic_array_AMPA_NMDA_fromPCtoRSI_N_outgoing.empty() )
        {
			outfile__dynamic_array_AMPA_NMDA_fromPCtoRSI_N_outgoing.write(reinterpret_cast<char*>(&_dynamic_array_AMPA_NMDA_fromPCtoRSI_N_outgoing[0]), _dynamic_array_AMPA_NMDA_fromPCtoRSI_N_outgoing.size()*sizeof(_dynamic_array_AMPA_NMDA_fromPCtoRSI_N_outgoing[0]));
		    outfile__dynamic_array_AMPA_NMDA_fromPCtoRSI_N_outgoing.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_AMPA_NMDA_fromPCtoRSI_N_outgoing." << endl;
	}
	ofstream outfile__dynamic_array_GABA_fromFSItoFSI__synaptic_post;
	outfile__dynamic_array_GABA_fromFSItoFSI__synaptic_post.open("results/_dynamic_array_GABA_fromFSItoFSI__synaptic_post_1901362890490089619", ios::binary | ios::out);
	if(outfile__dynamic_array_GABA_fromFSItoFSI__synaptic_post.is_open())
	{
        if (! _dynamic_array_GABA_fromFSItoFSI__synaptic_post.empty() )
        {
			outfile__dynamic_array_GABA_fromFSItoFSI__synaptic_post.write(reinterpret_cast<char*>(&_dynamic_array_GABA_fromFSItoFSI__synaptic_post[0]), _dynamic_array_GABA_fromFSItoFSI__synaptic_post.size()*sizeof(_dynamic_array_GABA_fromFSItoFSI__synaptic_post[0]));
		    outfile__dynamic_array_GABA_fromFSItoFSI__synaptic_post.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_GABA_fromFSItoFSI__synaptic_post." << endl;
	}
	ofstream outfile__dynamic_array_GABA_fromFSItoFSI__synaptic_pre;
	outfile__dynamic_array_GABA_fromFSItoFSI__synaptic_pre.open("results/_dynamic_array_GABA_fromFSItoFSI__synaptic_pre_1838107670598664021", ios::binary | ios::out);
	if(outfile__dynamic_array_GABA_fromFSItoFSI__synaptic_pre.is_open())
	{
        if (! _dynamic_array_GABA_fromFSItoFSI__synaptic_pre.empty() )
        {
			outfile__dynamic_array_GABA_fromFSItoFSI__synaptic_pre.write(reinterpret_cast<char*>(&_dynamic_array_GABA_fromFSItoFSI__synaptic_pre[0]), _dynamic_array_GABA_fromFSItoFSI__synaptic_pre.size()*sizeof(_dynamic_array_GABA_fromFSItoFSI__synaptic_pre[0]));
		    outfile__dynamic_array_GABA_fromFSItoFSI__synaptic_pre.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_GABA_fromFSItoFSI__synaptic_pre." << endl;
	}
	ofstream outfile__dynamic_array_GABA_fromFSItoFSI_delay;
	outfile__dynamic_array_GABA_fromFSItoFSI_delay.open("results/_dynamic_array_GABA_fromFSItoFSI_delay_7277159855521340670", ios::binary | ios::out);
	if(outfile__dynamic_array_GABA_fromFSItoFSI_delay.is_open())
	{
        if (! _dynamic_array_GABA_fromFSItoFSI_delay.empty() )
        {
			outfile__dynamic_array_GABA_fromFSItoFSI_delay.write(reinterpret_cast<char*>(&_dynamic_array_GABA_fromFSItoFSI_delay[0]), _dynamic_array_GABA_fromFSItoFSI_delay.size()*sizeof(_dynamic_array_GABA_fromFSItoFSI_delay[0]));
		    outfile__dynamic_array_GABA_fromFSItoFSI_delay.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_GABA_fromFSItoFSI_delay." << endl;
	}
	ofstream outfile__dynamic_array_GABA_fromFSItoFSI_N_incoming;
	outfile__dynamic_array_GABA_fromFSItoFSI_N_incoming.open("results/_dynamic_array_GABA_fromFSItoFSI_N_incoming_7294403742685232685", ios::binary | ios::out);
	if(outfile__dynamic_array_GABA_fromFSItoFSI_N_incoming.is_open())
	{
        if (! _dynamic_array_GABA_fromFSItoFSI_N_incoming.empty() )
        {
			outfile__dynamic_array_GABA_fromFSItoFSI_N_incoming.write(reinterpret_cast<char*>(&_dynamic_array_GABA_fromFSItoFSI_N_incoming[0]), _dynamic_array_GABA_fromFSItoFSI_N_incoming.size()*sizeof(_dynamic_array_GABA_fromFSItoFSI_N_incoming[0]));
		    outfile__dynamic_array_GABA_fromFSItoFSI_N_incoming.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_GABA_fromFSItoFSI_N_incoming." << endl;
	}
	ofstream outfile__dynamic_array_GABA_fromFSItoFSI_N_outgoing;
	outfile__dynamic_array_GABA_fromFSItoFSI_N_outgoing.open("results/_dynamic_array_GABA_fromFSItoFSI_N_outgoing_1360157507424231817", ios::binary | ios::out);
	if(outfile__dynamic_array_GABA_fromFSItoFSI_N_outgoing.is_open())
	{
        if (! _dynamic_array_GABA_fromFSItoFSI_N_outgoing.empty() )
        {
			outfile__dynamic_array_GABA_fromFSItoFSI_N_outgoing.write(reinterpret_cast<char*>(&_dynamic_array_GABA_fromFSItoFSI_N_outgoing[0]), _dynamic_array_GABA_fromFSItoFSI_N_outgoing.size()*sizeof(_dynamic_array_GABA_fromFSItoFSI_N_outgoing[0]));
		    outfile__dynamic_array_GABA_fromFSItoFSI_N_outgoing.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_GABA_fromFSItoFSI_N_outgoing." << endl;
	}
	ofstream outfile__dynamic_array_GABA_fromFSItoPC__synaptic_post;
	outfile__dynamic_array_GABA_fromFSItoPC__synaptic_post.open("results/_dynamic_array_GABA_fromFSItoPC__synaptic_post_1878648360475424845", ios::binary | ios::out);
	if(outfile__dynamic_array_GABA_fromFSItoPC__synaptic_post.is_open())
	{
        if (! _dynamic_array_GABA_fromFSItoPC__synaptic_post.empty() )
        {
			outfile__dynamic_array_GABA_fromFSItoPC__synaptic_post.write(reinterpret_cast<char*>(&_dynamic_array_GABA_fromFSItoPC__synaptic_post[0]), _dynamic_array_GABA_fromFSItoPC__synaptic_post.size()*sizeof(_dynamic_array_GABA_fromFSItoPC__synaptic_post[0]));
		    outfile__dynamic_array_GABA_fromFSItoPC__synaptic_post.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_GABA_fromFSItoPC__synaptic_post." << endl;
	}
	ofstream outfile__dynamic_array_GABA_fromFSItoPC__synaptic_pre;
	outfile__dynamic_array_GABA_fromFSItoPC__synaptic_pre.open("results/_dynamic_array_GABA_fromFSItoPC__synaptic_pre_2091311982566821718", ios::binary | ios::out);
	if(outfile__dynamic_array_GABA_fromFSItoPC__synaptic_pre.is_open())
	{
        if (! _dynamic_array_GABA_fromFSItoPC__synaptic_pre.empty() )
        {
			outfile__dynamic_array_GABA_fromFSItoPC__synaptic_pre.write(reinterpret_cast<char*>(&_dynamic_array_GABA_fromFSItoPC__synaptic_pre[0]), _dynamic_array_GABA_fromFSItoPC__synaptic_pre.size()*sizeof(_dynamic_array_GABA_fromFSItoPC__synaptic_pre[0]));
		    outfile__dynamic_array_GABA_fromFSItoPC__synaptic_pre.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_GABA_fromFSItoPC__synaptic_pre." << endl;
	}
	ofstream outfile__dynamic_array_GABA_fromFSItoPC_delay;
	outfile__dynamic_array_GABA_fromFSItoPC_delay.open("results/_dynamic_array_GABA_fromFSItoPC_delay_-4090978682108799455", ios::binary | ios::out);
	if(outfile__dynamic_array_GABA_fromFSItoPC_delay.is_open())
	{
        if (! _dynamic_array_GABA_fromFSItoPC_delay.empty() )
        {
			outfile__dynamic_array_GABA_fromFSItoPC_delay.write(reinterpret_cast<char*>(&_dynamic_array_GABA_fromFSItoPC_delay[0]), _dynamic_array_GABA_fromFSItoPC_delay.size()*sizeof(_dynamic_array_GABA_fromFSItoPC_delay[0]));
		    outfile__dynamic_array_GABA_fromFSItoPC_delay.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_GABA_fromFSItoPC_delay." << endl;
	}
	ofstream outfile__dynamic_array_GABA_fromFSItoPC_N_incoming;
	outfile__dynamic_array_GABA_fromFSItoPC_N_incoming.open("results/_dynamic_array_GABA_fromFSItoPC_N_incoming_-4158888328059470279", ios::binary | ios::out);
	if(outfile__dynamic_array_GABA_fromFSItoPC_N_incoming.is_open())
	{
        if (! _dynamic_array_GABA_fromFSItoPC_N_incoming.empty() )
        {
			outfile__dynamic_array_GABA_fromFSItoPC_N_incoming.write(reinterpret_cast<char*>(&_dynamic_array_GABA_fromFSItoPC_N_incoming[0]), _dynamic_array_GABA_fromFSItoPC_N_incoming.size()*sizeof(_dynamic_array_GABA_fromFSItoPC_N_incoming[0]));
		    outfile__dynamic_array_GABA_fromFSItoPC_N_incoming.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_GABA_fromFSItoPC_N_incoming." << endl;
	}
	ofstream outfile__dynamic_array_GABA_fromFSItoPC_N_outgoing;
	outfile__dynamic_array_GABA_fromFSItoPC_N_outgoing.open("results/_dynamic_array_GABA_fromFSItoPC_N_outgoing_2188677788448805425", ios::binary | ios::out);
	if(outfile__dynamic_array_GABA_fromFSItoPC_N_outgoing.is_open())
	{
        if (! _dynamic_array_GABA_fromFSItoPC_N_outgoing.empty() )
        {
			outfile__dynamic_array_GABA_fromFSItoPC_N_outgoing.write(reinterpret_cast<char*>(&_dynamic_array_GABA_fromFSItoPC_N_outgoing[0]), _dynamic_array_GABA_fromFSItoPC_N_outgoing.size()*sizeof(_dynamic_array_GABA_fromFSItoPC_N_outgoing[0]));
		    outfile__dynamic_array_GABA_fromFSItoPC_N_outgoing.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_GABA_fromFSItoPC_N_outgoing." << endl;
	}
	ofstream outfile__dynamic_array_GABA_fromFSItoRSI__synaptic_post;
	outfile__dynamic_array_GABA_fromFSItoRSI__synaptic_post.open("results/_dynamic_array_GABA_fromFSItoRSI__synaptic_post_4907930584657883657", ios::binary | ios::out);
	if(outfile__dynamic_array_GABA_fromFSItoRSI__synaptic_post.is_open())
	{
        if (! _dynamic_array_GABA_fromFSItoRSI__synaptic_post.empty() )
        {
			outfile__dynamic_array_GABA_fromFSItoRSI__synaptic_post.write(reinterpret_cast<char*>(&_dynamic_array_GABA_fromFSItoRSI__synaptic_post[0]), _dynamic_array_GABA_fromFSItoRSI__synaptic_post.size()*sizeof(_dynamic_array_GABA_fromFSItoRSI__synaptic_post[0]));
		    outfile__dynamic_array_GABA_fromFSItoRSI__synaptic_post.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_GABA_fromFSItoRSI__synaptic_post." << endl;
	}
	ofstream outfile__dynamic_array_GABA_fromFSItoRSI__synaptic_pre;
	outfile__dynamic_array_GABA_fromFSItoRSI__synaptic_pre.open("results/_dynamic_array_GABA_fromFSItoRSI__synaptic_pre_-251792772835425101", ios::binary | ios::out);
	if(outfile__dynamic_array_GABA_fromFSItoRSI__synaptic_pre.is_open())
	{
        if (! _dynamic_array_GABA_fromFSItoRSI__synaptic_pre.empty() )
        {
			outfile__dynamic_array_GABA_fromFSItoRSI__synaptic_pre.write(reinterpret_cast<char*>(&_dynamic_array_GABA_fromFSItoRSI__synaptic_pre[0]), _dynamic_array_GABA_fromFSItoRSI__synaptic_pre.size()*sizeof(_dynamic_array_GABA_fromFSItoRSI__synaptic_pre[0]));
		    outfile__dynamic_array_GABA_fromFSItoRSI__synaptic_pre.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_GABA_fromFSItoRSI__synaptic_pre." << endl;
	}
	ofstream outfile__dynamic_array_GABA_fromFSItoRSI_delay;
	outfile__dynamic_array_GABA_fromFSItoRSI_delay.open("results/_dynamic_array_GABA_fromFSItoRSI_delay_-2681293152607554821", ios::binary | ios::out);
	if(outfile__dynamic_array_GABA_fromFSItoRSI_delay.is_open())
	{
        if (! _dynamic_array_GABA_fromFSItoRSI_delay.empty() )
        {
			outfile__dynamic_array_GABA_fromFSItoRSI_delay.write(reinterpret_cast<char*>(&_dynamic_array_GABA_fromFSItoRSI_delay[0]), _dynamic_array_GABA_fromFSItoRSI_delay.size()*sizeof(_dynamic_array_GABA_fromFSItoRSI_delay[0]));
		    outfile__dynamic_array_GABA_fromFSItoRSI_delay.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_GABA_fromFSItoRSI_delay." << endl;
	}
	ofstream outfile__dynamic_array_GABA_fromFSItoRSI_N_incoming;
	outfile__dynamic_array_GABA_fromFSItoRSI_N_incoming.open("results/_dynamic_array_GABA_fromFSItoRSI_N_incoming_-1243603894329339582", ios::binary | ios::out);
	if(outfile__dynamic_array_GABA_fromFSItoRSI_N_incoming.is_open())
	{
        if (! _dynamic_array_GABA_fromFSItoRSI_N_incoming.empty() )
        {
			outfile__dynamic_array_GABA_fromFSItoRSI_N_incoming.write(reinterpret_cast<char*>(&_dynamic_array_GABA_fromFSItoRSI_N_incoming[0]), _dynamic_array_GABA_fromFSItoRSI_N_incoming.size()*sizeof(_dynamic_array_GABA_fromFSItoRSI_N_incoming[0]));
		    outfile__dynamic_array_GABA_fromFSItoRSI_N_incoming.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_GABA_fromFSItoRSI_N_incoming." << endl;
	}
	ofstream outfile__dynamic_array_GABA_fromFSItoRSI_N_outgoing;
	outfile__dynamic_array_GABA_fromFSItoRSI_N_outgoing.open("results/_dynamic_array_GABA_fromFSItoRSI_N_outgoing_3968990920335919582", ios::binary | ios::out);
	if(outfile__dynamic_array_GABA_fromFSItoRSI_N_outgoing.is_open())
	{
        if (! _dynamic_array_GABA_fromFSItoRSI_N_outgoing.empty() )
        {
			outfile__dynamic_array_GABA_fromFSItoRSI_N_outgoing.write(reinterpret_cast<char*>(&_dynamic_array_GABA_fromFSItoRSI_N_outgoing[0]), _dynamic_array_GABA_fromFSItoRSI_N_outgoing.size()*sizeof(_dynamic_array_GABA_fromFSItoRSI_N_outgoing[0]));
		    outfile__dynamic_array_GABA_fromFSItoRSI_N_outgoing.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_GABA_fromFSItoRSI_N_outgoing." << endl;
	}
	ofstream outfile__dynamic_array_GABA_fromRSItoFSI__synaptic_post;
	outfile__dynamic_array_GABA_fromRSItoFSI__synaptic_post.open("results/_dynamic_array_GABA_fromRSItoFSI__synaptic_post_-6607463885525929037", ios::binary | ios::out);
	if(outfile__dynamic_array_GABA_fromRSItoFSI__synaptic_post.is_open())
	{
        if (! _dynamic_array_GABA_fromRSItoFSI__synaptic_post.empty() )
        {
			outfile__dynamic_array_GABA_fromRSItoFSI__synaptic_post.write(reinterpret_cast<char*>(&_dynamic_array_GABA_fromRSItoFSI__synaptic_post[0]), _dynamic_array_GABA_fromRSItoFSI__synaptic_post.size()*sizeof(_dynamic_array_GABA_fromRSItoFSI__synaptic_post[0]));
		    outfile__dynamic_array_GABA_fromRSItoFSI__synaptic_post.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_GABA_fromRSItoFSI__synaptic_post." << endl;
	}
	ofstream outfile__dynamic_array_GABA_fromRSItoFSI__synaptic_pre;
	outfile__dynamic_array_GABA_fromRSItoFSI__synaptic_pre.open("results/_dynamic_array_GABA_fromRSItoFSI__synaptic_pre_2172779685794635576", ios::binary | ios::out);
	if(outfile__dynamic_array_GABA_fromRSItoFSI__synaptic_pre.is_open())
	{
        if (! _dynamic_array_GABA_fromRSItoFSI__synaptic_pre.empty() )
        {
			outfile__dynamic_array_GABA_fromRSItoFSI__synaptic_pre.write(reinterpret_cast<char*>(&_dynamic_array_GABA_fromRSItoFSI__synaptic_pre[0]), _dynamic_array_GABA_fromRSItoFSI__synaptic_pre.size()*sizeof(_dynamic_array_GABA_fromRSItoFSI__synaptic_pre[0]));
		    outfile__dynamic_array_GABA_fromRSItoFSI__synaptic_pre.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_GABA_fromRSItoFSI__synaptic_pre." << endl;
	}
	ofstream outfile__dynamic_array_GABA_fromRSItoFSI_delay;
	outfile__dynamic_array_GABA_fromRSItoFSI_delay.open("results/_dynamic_array_GABA_fromRSItoFSI_delay_-3171333298139550025", ios::binary | ios::out);
	if(outfile__dynamic_array_GABA_fromRSItoFSI_delay.is_open())
	{
        if (! _dynamic_array_GABA_fromRSItoFSI_delay.empty() )
        {
			outfile__dynamic_array_GABA_fromRSItoFSI_delay.write(reinterpret_cast<char*>(&_dynamic_array_GABA_fromRSItoFSI_delay[0]), _dynamic_array_GABA_fromRSItoFSI_delay.size()*sizeof(_dynamic_array_GABA_fromRSItoFSI_delay[0]));
		    outfile__dynamic_array_GABA_fromRSItoFSI_delay.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_GABA_fromRSItoFSI_delay." << endl;
	}
	ofstream outfile__dynamic_array_GABA_fromRSItoFSI_N_incoming;
	outfile__dynamic_array_GABA_fromRSItoFSI_N_incoming.open("results/_dynamic_array_GABA_fromRSItoFSI_N_incoming_83795755121669845", ios::binary | ios::out);
	if(outfile__dynamic_array_GABA_fromRSItoFSI_N_incoming.is_open())
	{
        if (! _dynamic_array_GABA_fromRSItoFSI_N_incoming.empty() )
        {
			outfile__dynamic_array_GABA_fromRSItoFSI_N_incoming.write(reinterpret_cast<char*>(&_dynamic_array_GABA_fromRSItoFSI_N_incoming[0]), _dynamic_array_GABA_fromRSItoFSI_N_incoming.size()*sizeof(_dynamic_array_GABA_fromRSItoFSI_N_incoming[0]));
		    outfile__dynamic_array_GABA_fromRSItoFSI_N_incoming.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_GABA_fromRSItoFSI_N_incoming." << endl;
	}
	ofstream outfile__dynamic_array_GABA_fromRSItoFSI_N_outgoing;
	outfile__dynamic_array_GABA_fromRSItoFSI_N_outgoing.open("results/_dynamic_array_GABA_fromRSItoFSI_N_outgoing_-4005436913023828640", ios::binary | ios::out);
	if(outfile__dynamic_array_GABA_fromRSItoFSI_N_outgoing.is_open())
	{
        if (! _dynamic_array_GABA_fromRSItoFSI_N_outgoing.empty() )
        {
			outfile__dynamic_array_GABA_fromRSItoFSI_N_outgoing.write(reinterpret_cast<char*>(&_dynamic_array_GABA_fromRSItoFSI_N_outgoing[0]), _dynamic_array_GABA_fromRSItoFSI_N_outgoing.size()*sizeof(_dynamic_array_GABA_fromRSItoFSI_N_outgoing[0]));
		    outfile__dynamic_array_GABA_fromRSItoFSI_N_outgoing.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_GABA_fromRSItoFSI_N_outgoing." << endl;
	}
	ofstream outfile__dynamic_array_GABA_fromRSItoPC__synaptic_post;
	outfile__dynamic_array_GABA_fromRSItoPC__synaptic_post.open("results/_dynamic_array_GABA_fromRSItoPC__synaptic_post_3416958163696525206", ios::binary | ios::out);
	if(outfile__dynamic_array_GABA_fromRSItoPC__synaptic_post.is_open())
	{
        if (! _dynamic_array_GABA_fromRSItoPC__synaptic_post.empty() )
        {
			outfile__dynamic_array_GABA_fromRSItoPC__synaptic_post.write(reinterpret_cast<char*>(&_dynamic_array_GABA_fromRSItoPC__synaptic_post[0]), _dynamic_array_GABA_fromRSItoPC__synaptic_post.size()*sizeof(_dynamic_array_GABA_fromRSItoPC__synaptic_post[0]));
		    outfile__dynamic_array_GABA_fromRSItoPC__synaptic_post.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_GABA_fromRSItoPC__synaptic_post." << endl;
	}
	ofstream outfile__dynamic_array_GABA_fromRSItoPC__synaptic_pre;
	outfile__dynamic_array_GABA_fromRSItoPC__synaptic_pre.open("results/_dynamic_array_GABA_fromRSItoPC__synaptic_pre_-8812916223842326728", ios::binary | ios::out);
	if(outfile__dynamic_array_GABA_fromRSItoPC__synaptic_pre.is_open())
	{
        if (! _dynamic_array_GABA_fromRSItoPC__synaptic_pre.empty() )
        {
			outfile__dynamic_array_GABA_fromRSItoPC__synaptic_pre.write(reinterpret_cast<char*>(&_dynamic_array_GABA_fromRSItoPC__synaptic_pre[0]), _dynamic_array_GABA_fromRSItoPC__synaptic_pre.size()*sizeof(_dynamic_array_GABA_fromRSItoPC__synaptic_pre[0]));
		    outfile__dynamic_array_GABA_fromRSItoPC__synaptic_pre.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_GABA_fromRSItoPC__synaptic_pre." << endl;
	}
	ofstream outfile__dynamic_array_GABA_fromRSItoPC_delay;
	outfile__dynamic_array_GABA_fromRSItoPC_delay.open("results/_dynamic_array_GABA_fromRSItoPC_delay_-2323480939083108010", ios::binary | ios::out);
	if(outfile__dynamic_array_GABA_fromRSItoPC_delay.is_open())
	{
        if (! _dynamic_array_GABA_fromRSItoPC_delay.empty() )
        {
			outfile__dynamic_array_GABA_fromRSItoPC_delay.write(reinterpret_cast<char*>(&_dynamic_array_GABA_fromRSItoPC_delay[0]), _dynamic_array_GABA_fromRSItoPC_delay.size()*sizeof(_dynamic_array_GABA_fromRSItoPC_delay[0]));
		    outfile__dynamic_array_GABA_fromRSItoPC_delay.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_GABA_fromRSItoPC_delay." << endl;
	}
	ofstream outfile__dynamic_array_GABA_fromRSItoPC_N_incoming;
	outfile__dynamic_array_GABA_fromRSItoPC_N_incoming.open("results/_dynamic_array_GABA_fromRSItoPC_N_incoming_3618806563899693416", ios::binary | ios::out);
	if(outfile__dynamic_array_GABA_fromRSItoPC_N_incoming.is_open())
	{
        if (! _dynamic_array_GABA_fromRSItoPC_N_incoming.empty() )
        {
			outfile__dynamic_array_GABA_fromRSItoPC_N_incoming.write(reinterpret_cast<char*>(&_dynamic_array_GABA_fromRSItoPC_N_incoming[0]), _dynamic_array_GABA_fromRSItoPC_N_incoming.size()*sizeof(_dynamic_array_GABA_fromRSItoPC_N_incoming[0]));
		    outfile__dynamic_array_GABA_fromRSItoPC_N_incoming.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_GABA_fromRSItoPC_N_incoming." << endl;
	}
	ofstream outfile__dynamic_array_GABA_fromRSItoPC_N_outgoing;
	outfile__dynamic_array_GABA_fromRSItoPC_N_outgoing.open("results/_dynamic_array_GABA_fromRSItoPC_N_outgoing_-4359032096997778189", ios::binary | ios::out);
	if(outfile__dynamic_array_GABA_fromRSItoPC_N_outgoing.is_open())
	{
        if (! _dynamic_array_GABA_fromRSItoPC_N_outgoing.empty() )
        {
			outfile__dynamic_array_GABA_fromRSItoPC_N_outgoing.write(reinterpret_cast<char*>(&_dynamic_array_GABA_fromRSItoPC_N_outgoing[0]), _dynamic_array_GABA_fromRSItoPC_N_outgoing.size()*sizeof(_dynamic_array_GABA_fromRSItoPC_N_outgoing[0]));
		    outfile__dynamic_array_GABA_fromRSItoPC_N_outgoing.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_GABA_fromRSItoPC_N_outgoing." << endl;
	}
	ofstream outfile__dynamic_array_GABA_fromRSItoRSI__synaptic_post;
	outfile__dynamic_array_GABA_fromRSItoRSI__synaptic_post.open("results/_dynamic_array_GABA_fromRSItoRSI__synaptic_post_-3358297470602943323", ios::binary | ios::out);
	if(outfile__dynamic_array_GABA_fromRSItoRSI__synaptic_post.is_open())
	{
        if (! _dynamic_array_GABA_fromRSItoRSI__synaptic_post.empty() )
        {
			outfile__dynamic_array_GABA_fromRSItoRSI__synaptic_post.write(reinterpret_cast<char*>(&_dynamic_array_GABA_fromRSItoRSI__synaptic_post[0]), _dynamic_array_GABA_fromRSItoRSI__synaptic_post.size()*sizeof(_dynamic_array_GABA_fromRSItoRSI__synaptic_post[0]));
		    outfile__dynamic_array_GABA_fromRSItoRSI__synaptic_post.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_GABA_fromRSItoRSI__synaptic_post." << endl;
	}
	ofstream outfile__dynamic_array_GABA_fromRSItoRSI__synaptic_pre;
	outfile__dynamic_array_GABA_fromRSItoRSI__synaptic_pre.open("results/_dynamic_array_GABA_fromRSItoRSI__synaptic_pre_-6844975343337054885", ios::binary | ios::out);
	if(outfile__dynamic_array_GABA_fromRSItoRSI__synaptic_pre.is_open())
	{
        if (! _dynamic_array_GABA_fromRSItoRSI__synaptic_pre.empty() )
        {
			outfile__dynamic_array_GABA_fromRSItoRSI__synaptic_pre.write(reinterpret_cast<char*>(&_dynamic_array_GABA_fromRSItoRSI__synaptic_pre[0]), _dynamic_array_GABA_fromRSItoRSI__synaptic_pre.size()*sizeof(_dynamic_array_GABA_fromRSItoRSI__synaptic_pre[0]));
		    outfile__dynamic_array_GABA_fromRSItoRSI__synaptic_pre.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_GABA_fromRSItoRSI__synaptic_pre." << endl;
	}
	ofstream outfile__dynamic_array_GABA_fromRSItoRSI_delay;
	outfile__dynamic_array_GABA_fromRSItoRSI_delay.open("results/_dynamic_array_GABA_fromRSItoRSI_delay_-8808439136336401588", ios::binary | ios::out);
	if(outfile__dynamic_array_GABA_fromRSItoRSI_delay.is_open())
	{
        if (! _dynamic_array_GABA_fromRSItoRSI_delay.empty() )
        {
			outfile__dynamic_array_GABA_fromRSItoRSI_delay.write(reinterpret_cast<char*>(&_dynamic_array_GABA_fromRSItoRSI_delay[0]), _dynamic_array_GABA_fromRSItoRSI_delay.size()*sizeof(_dynamic_array_GABA_fromRSItoRSI_delay[0]));
		    outfile__dynamic_array_GABA_fromRSItoRSI_delay.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_GABA_fromRSItoRSI_delay." << endl;
	}
	ofstream outfile__dynamic_array_GABA_fromRSItoRSI_N_incoming;
	outfile__dynamic_array_GABA_fromRSItoRSI_N_incoming.open("results/_dynamic_array_GABA_fromRSItoRSI_N_incoming_-6550150312591427589", ios::binary | ios::out);
	if(outfile__dynamic_array_GABA_fromRSItoRSI_N_incoming.is_open())
	{
        if (! _dynamic_array_GABA_fromRSItoRSI_N_incoming.empty() )
        {
			outfile__dynamic_array_GABA_fromRSItoRSI_N_incoming.write(reinterpret_cast<char*>(&_dynamic_array_GABA_fromRSItoRSI_N_incoming[0]), _dynamic_array_GABA_fromRSItoRSI_N_incoming.size()*sizeof(_dynamic_array_GABA_fromRSItoRSI_N_incoming[0]));
		    outfile__dynamic_array_GABA_fromRSItoRSI_N_incoming.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_GABA_fromRSItoRSI_N_incoming." << endl;
	}
	ofstream outfile__dynamic_array_GABA_fromRSItoRSI_N_outgoing;
	outfile__dynamic_array_GABA_fromRSItoRSI_N_outgoing.open("results/_dynamic_array_GABA_fromRSItoRSI_N_outgoing_-7864831476690404543", ios::binary | ios::out);
	if(outfile__dynamic_array_GABA_fromRSItoRSI_N_outgoing.is_open())
	{
        if (! _dynamic_array_GABA_fromRSItoRSI_N_outgoing.empty() )
        {
			outfile__dynamic_array_GABA_fromRSItoRSI_N_outgoing.write(reinterpret_cast<char*>(&_dynamic_array_GABA_fromRSItoRSI_N_outgoing[0]), _dynamic_array_GABA_fromRSItoRSI_N_outgoing.size()*sizeof(_dynamic_array_GABA_fromRSItoRSI_N_outgoing[0]));
		    outfile__dynamic_array_GABA_fromRSItoRSI_N_outgoing.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_GABA_fromRSItoRSI_N_outgoing." << endl;
	}
	ofstream outfile__dynamic_array_spikemonitor_1_i;
	outfile__dynamic_array_spikemonitor_1_i.open("results/_dynamic_array_spikemonitor_1_i_-4751917019472503091", ios::binary | ios::out);
	if(outfile__dynamic_array_spikemonitor_1_i.is_open())
	{
        if (! _dynamic_array_spikemonitor_1_i.empty() )
        {
			outfile__dynamic_array_spikemonitor_1_i.write(reinterpret_cast<char*>(&_dynamic_array_spikemonitor_1_i[0]), _dynamic_array_spikemonitor_1_i.size()*sizeof(_dynamic_array_spikemonitor_1_i[0]));
		    outfile__dynamic_array_spikemonitor_1_i.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_spikemonitor_1_i." << endl;
	}
	ofstream outfile__dynamic_array_spikemonitor_1_t;
	outfile__dynamic_array_spikemonitor_1_t.open("results/_dynamic_array_spikemonitor_1_t_-8485881640564591990", ios::binary | ios::out);
	if(outfile__dynamic_array_spikemonitor_1_t.is_open())
	{
        if (! _dynamic_array_spikemonitor_1_t.empty() )
        {
			outfile__dynamic_array_spikemonitor_1_t.write(reinterpret_cast<char*>(&_dynamic_array_spikemonitor_1_t[0]), _dynamic_array_spikemonitor_1_t.size()*sizeof(_dynamic_array_spikemonitor_1_t[0]));
		    outfile__dynamic_array_spikemonitor_1_t.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_spikemonitor_1_t." << endl;
	}
	ofstream outfile__dynamic_array_spikemonitor_2_i;
	outfile__dynamic_array_spikemonitor_2_i.open("results/_dynamic_array_spikemonitor_2_i_3448431337782320500", ios::binary | ios::out);
	if(outfile__dynamic_array_spikemonitor_2_i.is_open())
	{
        if (! _dynamic_array_spikemonitor_2_i.empty() )
        {
			outfile__dynamic_array_spikemonitor_2_i.write(reinterpret_cast<char*>(&_dynamic_array_spikemonitor_2_i[0]), _dynamic_array_spikemonitor_2_i.size()*sizeof(_dynamic_array_spikemonitor_2_i[0]));
		    outfile__dynamic_array_spikemonitor_2_i.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_spikemonitor_2_i." << endl;
	}
	ofstream outfile__dynamic_array_spikemonitor_2_t;
	outfile__dynamic_array_spikemonitor_2_t.open("results/_dynamic_array_spikemonitor_2_t_1984142415086756787", ios::binary | ios::out);
	if(outfile__dynamic_array_spikemonitor_2_t.is_open())
	{
        if (! _dynamic_array_spikemonitor_2_t.empty() )
        {
			outfile__dynamic_array_spikemonitor_2_t.write(reinterpret_cast<char*>(&_dynamic_array_spikemonitor_2_t[0]), _dynamic_array_spikemonitor_2_t.size()*sizeof(_dynamic_array_spikemonitor_2_t[0]));
		    outfile__dynamic_array_spikemonitor_2_t.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_spikemonitor_2_t." << endl;
	}
	ofstream outfile__dynamic_array_spikemonitor_3_i;
	outfile__dynamic_array_spikemonitor_3_i.open("results/_dynamic_array_spikemonitor_3_i_8046291853616905402", ios::binary | ios::out);
	if(outfile__dynamic_array_spikemonitor_3_i.is_open())
	{
        if (! _dynamic_array_spikemonitor_3_i.empty() )
        {
			outfile__dynamic_array_spikemonitor_3_i.write(reinterpret_cast<char*>(&_dynamic_array_spikemonitor_3_i[0]), _dynamic_array_spikemonitor_3_i.size()*sizeof(_dynamic_array_spikemonitor_3_i[0]));
		    outfile__dynamic_array_spikemonitor_3_i.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_spikemonitor_3_i." << endl;
	}
	ofstream outfile__dynamic_array_spikemonitor_3_t;
	outfile__dynamic_array_spikemonitor_3_t.open("results/_dynamic_array_spikemonitor_3_t_5300534115210473502", ios::binary | ios::out);
	if(outfile__dynamic_array_spikemonitor_3_t.is_open())
	{
        if (! _dynamic_array_spikemonitor_3_t.empty() )
        {
			outfile__dynamic_array_spikemonitor_3_t.write(reinterpret_cast<char*>(&_dynamic_array_spikemonitor_3_t[0]), _dynamic_array_spikemonitor_3_t.size()*sizeof(_dynamic_array_spikemonitor_3_t[0]));
		    outfile__dynamic_array_spikemonitor_3_t.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_spikemonitor_3_t." << endl;
	}
	ofstream outfile__dynamic_array_spikemonitor_i;
	outfile__dynamic_array_spikemonitor_i.open("results/_dynamic_array_spikemonitor_i_8313896254274025875", ios::binary | ios::out);
	if(outfile__dynamic_array_spikemonitor_i.is_open())
	{
        if (! _dynamic_array_spikemonitor_i.empty() )
        {
			outfile__dynamic_array_spikemonitor_i.write(reinterpret_cast<char*>(&_dynamic_array_spikemonitor_i[0]), _dynamic_array_spikemonitor_i.size()*sizeof(_dynamic_array_spikemonitor_i[0]));
		    outfile__dynamic_array_spikemonitor_i.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_spikemonitor_i." << endl;
	}
	ofstream outfile__dynamic_array_spikemonitor_t;
	outfile__dynamic_array_spikemonitor_t.open("results/_dynamic_array_spikemonitor_t_8669397808799099231", ios::binary | ios::out);
	if(outfile__dynamic_array_spikemonitor_t.is_open())
	{
        if (! _dynamic_array_spikemonitor_t.empty() )
        {
			outfile__dynamic_array_spikemonitor_t.write(reinterpret_cast<char*>(&_dynamic_array_spikemonitor_t[0]), _dynamic_array_spikemonitor_t.size()*sizeof(_dynamic_array_spikemonitor_t[0]));
		    outfile__dynamic_array_spikemonitor_t.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_spikemonitor_t." << endl;
	}
	ofstream outfile__dynamic_array_statemonitor_10_t;
	outfile__dynamic_array_statemonitor_10_t.open("results/_dynamic_array_statemonitor_10_t_-8428435862476834789", ios::binary | ios::out);
	if(outfile__dynamic_array_statemonitor_10_t.is_open())
	{
        if (! _dynamic_array_statemonitor_10_t.empty() )
        {
			outfile__dynamic_array_statemonitor_10_t.write(reinterpret_cast<char*>(&_dynamic_array_statemonitor_10_t[0]), _dynamic_array_statemonitor_10_t.size()*sizeof(_dynamic_array_statemonitor_10_t[0]));
		    outfile__dynamic_array_statemonitor_10_t.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_statemonitor_10_t." << endl;
	}
	ofstream outfile__dynamic_array_statemonitor_11_t;
	outfile__dynamic_array_statemonitor_11_t.open("results/_dynamic_array_statemonitor_11_t_4003187568113401885", ios::binary | ios::out);
	if(outfile__dynamic_array_statemonitor_11_t.is_open())
	{
        if (! _dynamic_array_statemonitor_11_t.empty() )
        {
			outfile__dynamic_array_statemonitor_11_t.write(reinterpret_cast<char*>(&_dynamic_array_statemonitor_11_t[0]), _dynamic_array_statemonitor_11_t.size()*sizeof(_dynamic_array_statemonitor_11_t[0]));
		    outfile__dynamic_array_statemonitor_11_t.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_statemonitor_11_t." << endl;
	}
	ofstream outfile__dynamic_array_statemonitor_12_t;
	outfile__dynamic_array_statemonitor_12_t.open("results/_dynamic_array_statemonitor_12_t_-5933345261947258352", ios::binary | ios::out);
	if(outfile__dynamic_array_statemonitor_12_t.is_open())
	{
        if (! _dynamic_array_statemonitor_12_t.empty() )
        {
			outfile__dynamic_array_statemonitor_12_t.write(reinterpret_cast<char*>(&_dynamic_array_statemonitor_12_t[0]), _dynamic_array_statemonitor_12_t.size()*sizeof(_dynamic_array_statemonitor_12_t[0]));
		    outfile__dynamic_array_statemonitor_12_t.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_statemonitor_12_t." << endl;
	}
	ofstream outfile__dynamic_array_statemonitor_13_t;
	outfile__dynamic_array_statemonitor_13_t.open("results/_dynamic_array_statemonitor_13_t_5967426648550961092", ios::binary | ios::out);
	if(outfile__dynamic_array_statemonitor_13_t.is_open())
	{
        if (! _dynamic_array_statemonitor_13_t.empty() )
        {
			outfile__dynamic_array_statemonitor_13_t.write(reinterpret_cast<char*>(&_dynamic_array_statemonitor_13_t[0]), _dynamic_array_statemonitor_13_t.size()*sizeof(_dynamic_array_statemonitor_13_t[0]));
		    outfile__dynamic_array_statemonitor_13_t.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_statemonitor_13_t." << endl;
	}
	ofstream outfile__dynamic_array_statemonitor_14_t;
	outfile__dynamic_array_statemonitor_14_t.open("results/_dynamic_array_statemonitor_14_t_-7922746595111365445", ios::binary | ios::out);
	if(outfile__dynamic_array_statemonitor_14_t.is_open())
	{
        if (! _dynamic_array_statemonitor_14_t.empty() )
        {
			outfile__dynamic_array_statemonitor_14_t.write(reinterpret_cast<char*>(&_dynamic_array_statemonitor_14_t[0]), _dynamic_array_statemonitor_14_t.size()*sizeof(_dynamic_array_statemonitor_14_t[0]));
		    outfile__dynamic_array_statemonitor_14_t.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_statemonitor_14_t." << endl;
	}
	ofstream outfile__dynamic_array_statemonitor_1_t;
	outfile__dynamic_array_statemonitor_1_t.open("results/_dynamic_array_statemonitor_1_t_-4878176573194271832", ios::binary | ios::out);
	if(outfile__dynamic_array_statemonitor_1_t.is_open())
	{
        if (! _dynamic_array_statemonitor_1_t.empty() )
        {
			outfile__dynamic_array_statemonitor_1_t.write(reinterpret_cast<char*>(&_dynamic_array_statemonitor_1_t[0]), _dynamic_array_statemonitor_1_t.size()*sizeof(_dynamic_array_statemonitor_1_t[0]));
		    outfile__dynamic_array_statemonitor_1_t.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_statemonitor_1_t." << endl;
	}
	ofstream outfile__dynamic_array_statemonitor_2_t;
	outfile__dynamic_array_statemonitor_2_t.open("results/_dynamic_array_statemonitor_2_t_1199724538361511481", ios::binary | ios::out);
	if(outfile__dynamic_array_statemonitor_2_t.is_open())
	{
        if (! _dynamic_array_statemonitor_2_t.empty() )
        {
			outfile__dynamic_array_statemonitor_2_t.write(reinterpret_cast<char*>(&_dynamic_array_statemonitor_2_t[0]), _dynamic_array_statemonitor_2_t.size()*sizeof(_dynamic_array_statemonitor_2_t[0]));
		    outfile__dynamic_array_statemonitor_2_t.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_statemonitor_2_t." << endl;
	}
	ofstream outfile__dynamic_array_statemonitor_3_t;
	outfile__dynamic_array_statemonitor_3_t.open("results/_dynamic_array_statemonitor_3_t_2621702772680153793", ios::binary | ios::out);
	if(outfile__dynamic_array_statemonitor_3_t.is_open())
	{
        if (! _dynamic_array_statemonitor_3_t.empty() )
        {
			outfile__dynamic_array_statemonitor_3_t.write(reinterpret_cast<char*>(&_dynamic_array_statemonitor_3_t[0]), _dynamic_array_statemonitor_3_t.size()*sizeof(_dynamic_array_statemonitor_3_t[0]));
		    outfile__dynamic_array_statemonitor_3_t.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_statemonitor_3_t." << endl;
	}
	ofstream outfile__dynamic_array_statemonitor_4_t;
	outfile__dynamic_array_statemonitor_4_t.open("results/_dynamic_array_statemonitor_4_t_-1146769489523764090", ios::binary | ios::out);
	if(outfile__dynamic_array_statemonitor_4_t.is_open())
	{
        if (! _dynamic_array_statemonitor_4_t.empty() )
        {
			outfile__dynamic_array_statemonitor_4_t.write(reinterpret_cast<char*>(&_dynamic_array_statemonitor_4_t[0]), _dynamic_array_statemonitor_4_t.size()*sizeof(_dynamic_array_statemonitor_4_t[0]));
		    outfile__dynamic_array_statemonitor_4_t.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_statemonitor_4_t." << endl;
	}
	ofstream outfile__dynamic_array_statemonitor_5_t;
	outfile__dynamic_array_statemonitor_5_t.open("results/_dynamic_array_statemonitor_5_t_-3507557695647750212", ios::binary | ios::out);
	if(outfile__dynamic_array_statemonitor_5_t.is_open())
	{
        if (! _dynamic_array_statemonitor_5_t.empty() )
        {
			outfile__dynamic_array_statemonitor_5_t.write(reinterpret_cast<char*>(&_dynamic_array_statemonitor_5_t[0]), _dynamic_array_statemonitor_5_t.size()*sizeof(_dynamic_array_statemonitor_5_t[0]));
		    outfile__dynamic_array_statemonitor_5_t.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_statemonitor_5_t." << endl;
	}
	ofstream outfile__dynamic_array_statemonitor_6_t;
	outfile__dynamic_array_statemonitor_6_t.open("results/_dynamic_array_statemonitor_6_t_-8389991229305541728", ios::binary | ios::out);
	if(outfile__dynamic_array_statemonitor_6_t.is_open())
	{
        if (! _dynamic_array_statemonitor_6_t.empty() )
        {
			outfile__dynamic_array_statemonitor_6_t.write(reinterpret_cast<char*>(&_dynamic_array_statemonitor_6_t[0]), _dynamic_array_statemonitor_6_t.size()*sizeof(_dynamic_array_statemonitor_6_t[0]));
		    outfile__dynamic_array_statemonitor_6_t.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_statemonitor_6_t." << endl;
	}
	ofstream outfile__dynamic_array_statemonitor_7_t;
	outfile__dynamic_array_statemonitor_7_t.open("results/_dynamic_array_statemonitor_7_t_-2892490490114533977", ios::binary | ios::out);
	if(outfile__dynamic_array_statemonitor_7_t.is_open())
	{
        if (! _dynamic_array_statemonitor_7_t.empty() )
        {
			outfile__dynamic_array_statemonitor_7_t.write(reinterpret_cast<char*>(&_dynamic_array_statemonitor_7_t[0]), _dynamic_array_statemonitor_7_t.size()*sizeof(_dynamic_array_statemonitor_7_t[0]));
		    outfile__dynamic_array_statemonitor_7_t.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_statemonitor_7_t." << endl;
	}
	ofstream outfile__dynamic_array_statemonitor_8_t;
	outfile__dynamic_array_statemonitor_8_t.open("results/_dynamic_array_statemonitor_8_t_-1917788763996655003", ios::binary | ios::out);
	if(outfile__dynamic_array_statemonitor_8_t.is_open())
	{
        if (! _dynamic_array_statemonitor_8_t.empty() )
        {
			outfile__dynamic_array_statemonitor_8_t.write(reinterpret_cast<char*>(&_dynamic_array_statemonitor_8_t[0]), _dynamic_array_statemonitor_8_t.size()*sizeof(_dynamic_array_statemonitor_8_t[0]));
		    outfile__dynamic_array_statemonitor_8_t.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_statemonitor_8_t." << endl;
	}
	ofstream outfile__dynamic_array_statemonitor_9_t;
	outfile__dynamic_array_statemonitor_9_t.open("results/_dynamic_array_statemonitor_9_t_-7884165759313586765", ios::binary | ios::out);
	if(outfile__dynamic_array_statemonitor_9_t.is_open())
	{
        if (! _dynamic_array_statemonitor_9_t.empty() )
        {
			outfile__dynamic_array_statemonitor_9_t.write(reinterpret_cast<char*>(&_dynamic_array_statemonitor_9_t[0]), _dynamic_array_statemonitor_9_t.size()*sizeof(_dynamic_array_statemonitor_9_t[0]));
		    outfile__dynamic_array_statemonitor_9_t.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_statemonitor_9_t." << endl;
	}
	ofstream outfile__dynamic_array_statemonitor_t;
	outfile__dynamic_array_statemonitor_t.open("results/_dynamic_array_statemonitor_t_2814386410981671228", ios::binary | ios::out);
	if(outfile__dynamic_array_statemonitor_t.is_open())
	{
        if (! _dynamic_array_statemonitor_t.empty() )
        {
			outfile__dynamic_array_statemonitor_t.write(reinterpret_cast<char*>(&_dynamic_array_statemonitor_t[0]), _dynamic_array_statemonitor_t.size()*sizeof(_dynamic_array_statemonitor_t[0]));
		    outfile__dynamic_array_statemonitor_t.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_statemonitor_t." << endl;
	}
	ofstream outfile__dynamic_array_synapses__synaptic_post;
	outfile__dynamic_array_synapses__synaptic_post.open("results/_dynamic_array_synapses__synaptic_post_-2076224398277909013", ios::binary | ios::out);
	if(outfile__dynamic_array_synapses__synaptic_post.is_open())
	{
        if (! _dynamic_array_synapses__synaptic_post.empty() )
        {
			outfile__dynamic_array_synapses__synaptic_post.write(reinterpret_cast<char*>(&_dynamic_array_synapses__synaptic_post[0]), _dynamic_array_synapses__synaptic_post.size()*sizeof(_dynamic_array_synapses__synaptic_post[0]));
		    outfile__dynamic_array_synapses__synaptic_post.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_synapses__synaptic_post." << endl;
	}
	ofstream outfile__dynamic_array_synapses__synaptic_pre;
	outfile__dynamic_array_synapses__synaptic_pre.open("results/_dynamic_array_synapses__synaptic_pre_7774403738926919154", ios::binary | ios::out);
	if(outfile__dynamic_array_synapses__synaptic_pre.is_open())
	{
        if (! _dynamic_array_synapses__synaptic_pre.empty() )
        {
			outfile__dynamic_array_synapses__synaptic_pre.write(reinterpret_cast<char*>(&_dynamic_array_synapses__synaptic_pre[0]), _dynamic_array_synapses__synaptic_pre.size()*sizeof(_dynamic_array_synapses__synaptic_pre[0]));
		    outfile__dynamic_array_synapses__synaptic_pre.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_synapses__synaptic_pre." << endl;
	}
	ofstream outfile__dynamic_array_synapses_delay;
	outfile__dynamic_array_synapses_delay.open("results/_dynamic_array_synapses_delay_-7062412229874514508", ios::binary | ios::out);
	if(outfile__dynamic_array_synapses_delay.is_open())
	{
        if (! _dynamic_array_synapses_delay.empty() )
        {
			outfile__dynamic_array_synapses_delay.write(reinterpret_cast<char*>(&_dynamic_array_synapses_delay[0]), _dynamic_array_synapses_delay.size()*sizeof(_dynamic_array_synapses_delay[0]));
		    outfile__dynamic_array_synapses_delay.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_synapses_delay." << endl;
	}
	ofstream outfile__dynamic_array_synapses_N_incoming;
	outfile__dynamic_array_synapses_N_incoming.open("results/_dynamic_array_synapses_N_incoming_3277092659248833589", ios::binary | ios::out);
	if(outfile__dynamic_array_synapses_N_incoming.is_open())
	{
        if (! _dynamic_array_synapses_N_incoming.empty() )
        {
			outfile__dynamic_array_synapses_N_incoming.write(reinterpret_cast<char*>(&_dynamic_array_synapses_N_incoming[0]), _dynamic_array_synapses_N_incoming.size()*sizeof(_dynamic_array_synapses_N_incoming[0]));
		    outfile__dynamic_array_synapses_N_incoming.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_synapses_N_incoming." << endl;
	}
	ofstream outfile__dynamic_array_synapses_N_outgoing;
	outfile__dynamic_array_synapses_N_outgoing.open("results/_dynamic_array_synapses_N_outgoing_4185823351704341282", ios::binary | ios::out);
	if(outfile__dynamic_array_synapses_N_outgoing.is_open())
	{
        if (! _dynamic_array_synapses_N_outgoing.empty() )
        {
			outfile__dynamic_array_synapses_N_outgoing.write(reinterpret_cast<char*>(&_dynamic_array_synapses_N_outgoing[0]), _dynamic_array_synapses_N_outgoing.size()*sizeof(_dynamic_array_synapses_N_outgoing[0]));
		    outfile__dynamic_array_synapses_N_outgoing.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_synapses_N_outgoing." << endl;
	}

	ofstream outfile__dynamic_array_statemonitor_10_g_AMPA_d;
	outfile__dynamic_array_statemonitor_10_g_AMPA_d.open("results/_dynamic_array_statemonitor_10_g_AMPA_d_1837427833428125726", ios::binary | ios::out);
	if(outfile__dynamic_array_statemonitor_10_g_AMPA_d.is_open())
	{
        for (int n=0; n<_dynamic_array_statemonitor_10_g_AMPA_d.n; n++)
        {
            if (! _dynamic_array_statemonitor_10_g_AMPA_d(n).empty())
            {
                outfile__dynamic_array_statemonitor_10_g_AMPA_d.write(reinterpret_cast<char*>(&_dynamic_array_statemonitor_10_g_AMPA_d(n, 0)), _dynamic_array_statemonitor_10_g_AMPA_d.m*sizeof(_dynamic_array_statemonitor_10_g_AMPA_d(0, 0)));
            }
        }
        outfile__dynamic_array_statemonitor_10_g_AMPA_d.close();
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_statemonitor_10_g_AMPA_d." << endl;
	}
	ofstream outfile__dynamic_array_statemonitor_10_g_GABA_d;
	outfile__dynamic_array_statemonitor_10_g_GABA_d.open("results/_dynamic_array_statemonitor_10_g_GABA_d_384352048587735558", ios::binary | ios::out);
	if(outfile__dynamic_array_statemonitor_10_g_GABA_d.is_open())
	{
        for (int n=0; n<_dynamic_array_statemonitor_10_g_GABA_d.n; n++)
        {
            if (! _dynamic_array_statemonitor_10_g_GABA_d(n).empty())
            {
                outfile__dynamic_array_statemonitor_10_g_GABA_d.write(reinterpret_cast<char*>(&_dynamic_array_statemonitor_10_g_GABA_d(n, 0)), _dynamic_array_statemonitor_10_g_GABA_d.m*sizeof(_dynamic_array_statemonitor_10_g_GABA_d(0, 0)));
            }
        }
        outfile__dynamic_array_statemonitor_10_g_GABA_d.close();
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_statemonitor_10_g_GABA_d." << endl;
	}
	ofstream outfile__dynamic_array_statemonitor_10_g_NMDA_d;
	outfile__dynamic_array_statemonitor_10_g_NMDA_d.open("results/_dynamic_array_statemonitor_10_g_NMDA_d_-5015576491860306111", ios::binary | ios::out);
	if(outfile__dynamic_array_statemonitor_10_g_NMDA_d.is_open())
	{
        for (int n=0; n<_dynamic_array_statemonitor_10_g_NMDA_d.n; n++)
        {
            if (! _dynamic_array_statemonitor_10_g_NMDA_d(n).empty())
            {
                outfile__dynamic_array_statemonitor_10_g_NMDA_d.write(reinterpret_cast<char*>(&_dynamic_array_statemonitor_10_g_NMDA_d(n, 0)), _dynamic_array_statemonitor_10_g_NMDA_d.m*sizeof(_dynamic_array_statemonitor_10_g_NMDA_d(0, 0)));
            }
        }
        outfile__dynamic_array_statemonitor_10_g_NMDA_d.close();
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_statemonitor_10_g_NMDA_d." << endl;
	}
	ofstream outfile__dynamic_array_statemonitor_11_g_AMPA_d;
	outfile__dynamic_array_statemonitor_11_g_AMPA_d.open("results/_dynamic_array_statemonitor_11_g_AMPA_d_1138700216583065250", ios::binary | ios::out);
	if(outfile__dynamic_array_statemonitor_11_g_AMPA_d.is_open())
	{
        for (int n=0; n<_dynamic_array_statemonitor_11_g_AMPA_d.n; n++)
        {
            if (! _dynamic_array_statemonitor_11_g_AMPA_d(n).empty())
            {
                outfile__dynamic_array_statemonitor_11_g_AMPA_d.write(reinterpret_cast<char*>(&_dynamic_array_statemonitor_11_g_AMPA_d(n, 0)), _dynamic_array_statemonitor_11_g_AMPA_d.m*sizeof(_dynamic_array_statemonitor_11_g_AMPA_d(0, 0)));
            }
        }
        outfile__dynamic_array_statemonitor_11_g_AMPA_d.close();
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_statemonitor_11_g_AMPA_d." << endl;
	}
	ofstream outfile__dynamic_array_statemonitor_11_g_GABA_d;
	outfile__dynamic_array_statemonitor_11_g_GABA_d.open("results/_dynamic_array_statemonitor_11_g_GABA_d_6282383658959769155", ios::binary | ios::out);
	if(outfile__dynamic_array_statemonitor_11_g_GABA_d.is_open())
	{
        for (int n=0; n<_dynamic_array_statemonitor_11_g_GABA_d.n; n++)
        {
            if (! _dynamic_array_statemonitor_11_g_GABA_d(n).empty())
            {
                outfile__dynamic_array_statemonitor_11_g_GABA_d.write(reinterpret_cast<char*>(&_dynamic_array_statemonitor_11_g_GABA_d(n, 0)), _dynamic_array_statemonitor_11_g_GABA_d.m*sizeof(_dynamic_array_statemonitor_11_g_GABA_d(0, 0)));
            }
        }
        outfile__dynamic_array_statemonitor_11_g_GABA_d.close();
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_statemonitor_11_g_GABA_d." << endl;
	}
	ofstream outfile__dynamic_array_statemonitor_11_g_NMDA_d;
	outfile__dynamic_array_statemonitor_11_g_NMDA_d.open("results/_dynamic_array_statemonitor_11_g_NMDA_d_-6555591427642483033", ios::binary | ios::out);
	if(outfile__dynamic_array_statemonitor_11_g_NMDA_d.is_open())
	{
        for (int n=0; n<_dynamic_array_statemonitor_11_g_NMDA_d.n; n++)
        {
            if (! _dynamic_array_statemonitor_11_g_NMDA_d(n).empty())
            {
                outfile__dynamic_array_statemonitor_11_g_NMDA_d.write(reinterpret_cast<char*>(&_dynamic_array_statemonitor_11_g_NMDA_d(n, 0)), _dynamic_array_statemonitor_11_g_NMDA_d.m*sizeof(_dynamic_array_statemonitor_11_g_NMDA_d(0, 0)));
            }
        }
        outfile__dynamic_array_statemonitor_11_g_NMDA_d.close();
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_statemonitor_11_g_NMDA_d." << endl;
	}
	ofstream outfile__dynamic_array_statemonitor_12_I_AMPA;
	outfile__dynamic_array_statemonitor_12_I_AMPA.open("results/_dynamic_array_statemonitor_12_I_AMPA_8650913988066782605", ios::binary | ios::out);
	if(outfile__dynamic_array_statemonitor_12_I_AMPA.is_open())
	{
        for (int n=0; n<_dynamic_array_statemonitor_12_I_AMPA.n; n++)
        {
            if (! _dynamic_array_statemonitor_12_I_AMPA(n).empty())
            {
                outfile__dynamic_array_statemonitor_12_I_AMPA.write(reinterpret_cast<char*>(&_dynamic_array_statemonitor_12_I_AMPA(n, 0)), _dynamic_array_statemonitor_12_I_AMPA.m*sizeof(_dynamic_array_statemonitor_12_I_AMPA(0, 0)));
            }
        }
        outfile__dynamic_array_statemonitor_12_I_AMPA.close();
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_statemonitor_12_I_AMPA." << endl;
	}
	ofstream outfile__dynamic_array_statemonitor_12_I_GABA;
	outfile__dynamic_array_statemonitor_12_I_GABA.open("results/_dynamic_array_statemonitor_12_I_GABA_-8991933111774054001", ios::binary | ios::out);
	if(outfile__dynamic_array_statemonitor_12_I_GABA.is_open())
	{
        for (int n=0; n<_dynamic_array_statemonitor_12_I_GABA.n; n++)
        {
            if (! _dynamic_array_statemonitor_12_I_GABA(n).empty())
            {
                outfile__dynamic_array_statemonitor_12_I_GABA.write(reinterpret_cast<char*>(&_dynamic_array_statemonitor_12_I_GABA(n, 0)), _dynamic_array_statemonitor_12_I_GABA.m*sizeof(_dynamic_array_statemonitor_12_I_GABA(0, 0)));
            }
        }
        outfile__dynamic_array_statemonitor_12_I_GABA.close();
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_statemonitor_12_I_GABA." << endl;
	}
	ofstream outfile__dynamic_array_statemonitor_12_I_NMDA;
	outfile__dynamic_array_statemonitor_12_I_NMDA.open("results/_dynamic_array_statemonitor_12_I_NMDA_7839933364110373775", ios::binary | ios::out);
	if(outfile__dynamic_array_statemonitor_12_I_NMDA.is_open())
	{
        for (int n=0; n<_dynamic_array_statemonitor_12_I_NMDA.n; n++)
        {
            if (! _dynamic_array_statemonitor_12_I_NMDA(n).empty())
            {
                outfile__dynamic_array_statemonitor_12_I_NMDA.write(reinterpret_cast<char*>(&_dynamic_array_statemonitor_12_I_NMDA(n, 0)), _dynamic_array_statemonitor_12_I_NMDA.m*sizeof(_dynamic_array_statemonitor_12_I_NMDA(0, 0)));
            }
        }
        outfile__dynamic_array_statemonitor_12_I_NMDA.close();
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_statemonitor_12_I_NMDA." << endl;
	}
	ofstream outfile__dynamic_array_statemonitor_12_I_syn;
	outfile__dynamic_array_statemonitor_12_I_syn.open("results/_dynamic_array_statemonitor_12_I_syn_-6651787024421483352", ios::binary | ios::out);
	if(outfile__dynamic_array_statemonitor_12_I_syn.is_open())
	{
        for (int n=0; n<_dynamic_array_statemonitor_12_I_syn.n; n++)
        {
            if (! _dynamic_array_statemonitor_12_I_syn(n).empty())
            {
                outfile__dynamic_array_statemonitor_12_I_syn.write(reinterpret_cast<char*>(&_dynamic_array_statemonitor_12_I_syn(n, 0)), _dynamic_array_statemonitor_12_I_syn.m*sizeof(_dynamic_array_statemonitor_12_I_syn(0, 0)));
            }
        }
        outfile__dynamic_array_statemonitor_12_I_syn.close();
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_statemonitor_12_I_syn." << endl;
	}
	ofstream outfile__dynamic_array_statemonitor_13_I_AMPA;
	outfile__dynamic_array_statemonitor_13_I_AMPA.open("results/_dynamic_array_statemonitor_13_I_AMPA_-6284087783286400501", ios::binary | ios::out);
	if(outfile__dynamic_array_statemonitor_13_I_AMPA.is_open())
	{
        for (int n=0; n<_dynamic_array_statemonitor_13_I_AMPA.n; n++)
        {
            if (! _dynamic_array_statemonitor_13_I_AMPA(n).empty())
            {
                outfile__dynamic_array_statemonitor_13_I_AMPA.write(reinterpret_cast<char*>(&_dynamic_array_statemonitor_13_I_AMPA(n, 0)), _dynamic_array_statemonitor_13_I_AMPA.m*sizeof(_dynamic_array_statemonitor_13_I_AMPA(0, 0)));
            }
        }
        outfile__dynamic_array_statemonitor_13_I_AMPA.close();
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_statemonitor_13_I_AMPA." << endl;
	}
	ofstream outfile__dynamic_array_statemonitor_13_I_GABA;
	outfile__dynamic_array_statemonitor_13_I_GABA.open("results/_dynamic_array_statemonitor_13_I_GABA_-8359132296270368847", ios::binary | ios::out);
	if(outfile__dynamic_array_statemonitor_13_I_GABA.is_open())
	{
        for (int n=0; n<_dynamic_array_statemonitor_13_I_GABA.n; n++)
        {
            if (! _dynamic_array_statemonitor_13_I_GABA(n).empty())
            {
                outfile__dynamic_array_statemonitor_13_I_GABA.write(reinterpret_cast<char*>(&_dynamic_array_statemonitor_13_I_GABA(n, 0)), _dynamic_array_statemonitor_13_I_GABA.m*sizeof(_dynamic_array_statemonitor_13_I_GABA(0, 0)));
            }
        }
        outfile__dynamic_array_statemonitor_13_I_GABA.close();
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_statemonitor_13_I_GABA." << endl;
	}
	ofstream outfile__dynamic_array_statemonitor_13_I_NMDA;
	outfile__dynamic_array_statemonitor_13_I_NMDA.open("results/_dynamic_array_statemonitor_13_I_NMDA_-2839662109986320315", ios::binary | ios::out);
	if(outfile__dynamic_array_statemonitor_13_I_NMDA.is_open())
	{
        for (int n=0; n<_dynamic_array_statemonitor_13_I_NMDA.n; n++)
        {
            if (! _dynamic_array_statemonitor_13_I_NMDA(n).empty())
            {
                outfile__dynamic_array_statemonitor_13_I_NMDA.write(reinterpret_cast<char*>(&_dynamic_array_statemonitor_13_I_NMDA(n, 0)), _dynamic_array_statemonitor_13_I_NMDA.m*sizeof(_dynamic_array_statemonitor_13_I_NMDA(0, 0)));
            }
        }
        outfile__dynamic_array_statemonitor_13_I_NMDA.close();
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_statemonitor_13_I_NMDA." << endl;
	}
	ofstream outfile__dynamic_array_statemonitor_13_I_syn;
	outfile__dynamic_array_statemonitor_13_I_syn.open("results/_dynamic_array_statemonitor_13_I_syn_3502299299017818520", ios::binary | ios::out);
	if(outfile__dynamic_array_statemonitor_13_I_syn.is_open())
	{
        for (int n=0; n<_dynamic_array_statemonitor_13_I_syn.n; n++)
        {
            if (! _dynamic_array_statemonitor_13_I_syn(n).empty())
            {
                outfile__dynamic_array_statemonitor_13_I_syn.write(reinterpret_cast<char*>(&_dynamic_array_statemonitor_13_I_syn(n, 0)), _dynamic_array_statemonitor_13_I_syn.m*sizeof(_dynamic_array_statemonitor_13_I_syn(0, 0)));
            }
        }
        outfile__dynamic_array_statemonitor_13_I_syn.close();
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_statemonitor_13_I_syn." << endl;
	}
	ofstream outfile__dynamic_array_statemonitor_14_I_AMPA;
	outfile__dynamic_array_statemonitor_14_I_AMPA.open("results/_dynamic_array_statemonitor_14_I_AMPA_1593700728595873473", ios::binary | ios::out);
	if(outfile__dynamic_array_statemonitor_14_I_AMPA.is_open())
	{
        for (int n=0; n<_dynamic_array_statemonitor_14_I_AMPA.n; n++)
        {
            if (! _dynamic_array_statemonitor_14_I_AMPA(n).empty())
            {
                outfile__dynamic_array_statemonitor_14_I_AMPA.write(reinterpret_cast<char*>(&_dynamic_array_statemonitor_14_I_AMPA(n, 0)), _dynamic_array_statemonitor_14_I_AMPA.m*sizeof(_dynamic_array_statemonitor_14_I_AMPA(0, 0)));
            }
        }
        outfile__dynamic_array_statemonitor_14_I_AMPA.close();
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_statemonitor_14_I_AMPA." << endl;
	}
	ofstream outfile__dynamic_array_statemonitor_14_I_GABA;
	outfile__dynamic_array_statemonitor_14_I_GABA.open("results/_dynamic_array_statemonitor_14_I_GABA_-5606252995313079820", ios::binary | ios::out);
	if(outfile__dynamic_array_statemonitor_14_I_GABA.is_open())
	{
        for (int n=0; n<_dynamic_array_statemonitor_14_I_GABA.n; n++)
        {
            if (! _dynamic_array_statemonitor_14_I_GABA(n).empty())
            {
                outfile__dynamic_array_statemonitor_14_I_GABA.write(reinterpret_cast<char*>(&_dynamic_array_statemonitor_14_I_GABA(n, 0)), _dynamic_array_statemonitor_14_I_GABA.m*sizeof(_dynamic_array_statemonitor_14_I_GABA(0, 0)));
            }
        }
        outfile__dynamic_array_statemonitor_14_I_GABA.close();
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_statemonitor_14_I_GABA." << endl;
	}
	ofstream outfile__dynamic_array_statemonitor_14_I_NMDA;
	outfile__dynamic_array_statemonitor_14_I_NMDA.open("results/_dynamic_array_statemonitor_14_I_NMDA_4350802371320198683", ios::binary | ios::out);
	if(outfile__dynamic_array_statemonitor_14_I_NMDA.is_open())
	{
        for (int n=0; n<_dynamic_array_statemonitor_14_I_NMDA.n; n++)
        {
            if (! _dynamic_array_statemonitor_14_I_NMDA(n).empty())
            {
                outfile__dynamic_array_statemonitor_14_I_NMDA.write(reinterpret_cast<char*>(&_dynamic_array_statemonitor_14_I_NMDA(n, 0)), _dynamic_array_statemonitor_14_I_NMDA.m*sizeof(_dynamic_array_statemonitor_14_I_NMDA(0, 0)));
            }
        }
        outfile__dynamic_array_statemonitor_14_I_NMDA.close();
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_statemonitor_14_I_NMDA." << endl;
	}
	ofstream outfile__dynamic_array_statemonitor_14_I_syn;
	outfile__dynamic_array_statemonitor_14_I_syn.open("results/_dynamic_array_statemonitor_14_I_syn_381926373636971251", ios::binary | ios::out);
	if(outfile__dynamic_array_statemonitor_14_I_syn.is_open())
	{
        for (int n=0; n<_dynamic_array_statemonitor_14_I_syn.n; n++)
        {
            if (! _dynamic_array_statemonitor_14_I_syn(n).empty())
            {
                outfile__dynamic_array_statemonitor_14_I_syn.write(reinterpret_cast<char*>(&_dynamic_array_statemonitor_14_I_syn(n, 0)), _dynamic_array_statemonitor_14_I_syn.m*sizeof(_dynamic_array_statemonitor_14_I_syn(0, 0)));
            }
        }
        outfile__dynamic_array_statemonitor_14_I_syn.close();
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_statemonitor_14_I_syn." << endl;
	}
	ofstream outfile__dynamic_array_statemonitor_1_v;
	outfile__dynamic_array_statemonitor_1_v.open("results/_dynamic_array_statemonitor_1_v_4330594536737983149", ios::binary | ios::out);
	if(outfile__dynamic_array_statemonitor_1_v.is_open())
	{
        for (int n=0; n<_dynamic_array_statemonitor_1_v.n; n++)
        {
            if (! _dynamic_array_statemonitor_1_v(n).empty())
            {
                outfile__dynamic_array_statemonitor_1_v.write(reinterpret_cast<char*>(&_dynamic_array_statemonitor_1_v(n, 0)), _dynamic_array_statemonitor_1_v.m*sizeof(_dynamic_array_statemonitor_1_v(0, 0)));
            }
        }
        outfile__dynamic_array_statemonitor_1_v.close();
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_statemonitor_1_v." << endl;
	}
	ofstream outfile__dynamic_array_statemonitor_2_v;
	outfile__dynamic_array_statemonitor_2_v.open("results/_dynamic_array_statemonitor_2_v_5736436622055415627", ios::binary | ios::out);
	if(outfile__dynamic_array_statemonitor_2_v.is_open())
	{
        for (int n=0; n<_dynamic_array_statemonitor_2_v.n; n++)
        {
            if (! _dynamic_array_statemonitor_2_v(n).empty())
            {
                outfile__dynamic_array_statemonitor_2_v.write(reinterpret_cast<char*>(&_dynamic_array_statemonitor_2_v(n, 0)), _dynamic_array_statemonitor_2_v.m*sizeof(_dynamic_array_statemonitor_2_v(0, 0)));
            }
        }
        outfile__dynamic_array_statemonitor_2_v.close();
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_statemonitor_2_v." << endl;
	}
	ofstream outfile__dynamic_array_statemonitor_3_g_AMPA;
	outfile__dynamic_array_statemonitor_3_g_AMPA.open("results/_dynamic_array_statemonitor_3_g_AMPA_-4095577036014751230", ios::binary | ios::out);
	if(outfile__dynamic_array_statemonitor_3_g_AMPA.is_open())
	{
        for (int n=0; n<_dynamic_array_statemonitor_3_g_AMPA.n; n++)
        {
            if (! _dynamic_array_statemonitor_3_g_AMPA(n).empty())
            {
                outfile__dynamic_array_statemonitor_3_g_AMPA.write(reinterpret_cast<char*>(&_dynamic_array_statemonitor_3_g_AMPA(n, 0)), _dynamic_array_statemonitor_3_g_AMPA.m*sizeof(_dynamic_array_statemonitor_3_g_AMPA(0, 0)));
            }
        }
        outfile__dynamic_array_statemonitor_3_g_AMPA.close();
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_statemonitor_3_g_AMPA." << endl;
	}
	ofstream outfile__dynamic_array_statemonitor_3_g_GABA;
	outfile__dynamic_array_statemonitor_3_g_GABA.open("results/_dynamic_array_statemonitor_3_g_GABA_-1591442845834208542", ios::binary | ios::out);
	if(outfile__dynamic_array_statemonitor_3_g_GABA.is_open())
	{
        for (int n=0; n<_dynamic_array_statemonitor_3_g_GABA.n; n++)
        {
            if (! _dynamic_array_statemonitor_3_g_GABA(n).empty())
            {
                outfile__dynamic_array_statemonitor_3_g_GABA.write(reinterpret_cast<char*>(&_dynamic_array_statemonitor_3_g_GABA(n, 0)), _dynamic_array_statemonitor_3_g_GABA.m*sizeof(_dynamic_array_statemonitor_3_g_GABA(0, 0)));
            }
        }
        outfile__dynamic_array_statemonitor_3_g_GABA.close();
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_statemonitor_3_g_GABA." << endl;
	}
	ofstream outfile__dynamic_array_statemonitor_3_g_NMDA;
	outfile__dynamic_array_statemonitor_3_g_NMDA.open("results/_dynamic_array_statemonitor_3_g_NMDA_1074320609953376044", ios::binary | ios::out);
	if(outfile__dynamic_array_statemonitor_3_g_NMDA.is_open())
	{
        for (int n=0; n<_dynamic_array_statemonitor_3_g_NMDA.n; n++)
        {
            if (! _dynamic_array_statemonitor_3_g_NMDA(n).empty())
            {
                outfile__dynamic_array_statemonitor_3_g_NMDA.write(reinterpret_cast<char*>(&_dynamic_array_statemonitor_3_g_NMDA(n, 0)), _dynamic_array_statemonitor_3_g_NMDA.m*sizeof(_dynamic_array_statemonitor_3_g_NMDA(0, 0)));
            }
        }
        outfile__dynamic_array_statemonitor_3_g_NMDA.close();
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_statemonitor_3_g_NMDA." << endl;
	}
	ofstream outfile__dynamic_array_statemonitor_4_g_AMPA;
	outfile__dynamic_array_statemonitor_4_g_AMPA.open("results/_dynamic_array_statemonitor_4_g_AMPA_-5338574377940975725", ios::binary | ios::out);
	if(outfile__dynamic_array_statemonitor_4_g_AMPA.is_open())
	{
        for (int n=0; n<_dynamic_array_statemonitor_4_g_AMPA.n; n++)
        {
            if (! _dynamic_array_statemonitor_4_g_AMPA(n).empty())
            {
                outfile__dynamic_array_statemonitor_4_g_AMPA.write(reinterpret_cast<char*>(&_dynamic_array_statemonitor_4_g_AMPA(n, 0)), _dynamic_array_statemonitor_4_g_AMPA.m*sizeof(_dynamic_array_statemonitor_4_g_AMPA(0, 0)));
            }
        }
        outfile__dynamic_array_statemonitor_4_g_AMPA.close();
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_statemonitor_4_g_AMPA." << endl;
	}
	ofstream outfile__dynamic_array_statemonitor_4_g_GABA;
	outfile__dynamic_array_statemonitor_4_g_GABA.open("results/_dynamic_array_statemonitor_4_g_GABA_8092286213834153709", ios::binary | ios::out);
	if(outfile__dynamic_array_statemonitor_4_g_GABA.is_open())
	{
        for (int n=0; n<_dynamic_array_statemonitor_4_g_GABA.n; n++)
        {
            if (! _dynamic_array_statemonitor_4_g_GABA(n).empty())
            {
                outfile__dynamic_array_statemonitor_4_g_GABA.write(reinterpret_cast<char*>(&_dynamic_array_statemonitor_4_g_GABA(n, 0)), _dynamic_array_statemonitor_4_g_GABA.m*sizeof(_dynamic_array_statemonitor_4_g_GABA(0, 0)));
            }
        }
        outfile__dynamic_array_statemonitor_4_g_GABA.close();
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_statemonitor_4_g_GABA." << endl;
	}
	ofstream outfile__dynamic_array_statemonitor_4_g_NMDA;
	outfile__dynamic_array_statemonitor_4_g_NMDA.open("results/_dynamic_array_statemonitor_4_g_NMDA_-739836728664498353", ios::binary | ios::out);
	if(outfile__dynamic_array_statemonitor_4_g_NMDA.is_open())
	{
        for (int n=0; n<_dynamic_array_statemonitor_4_g_NMDA.n; n++)
        {
            if (! _dynamic_array_statemonitor_4_g_NMDA(n).empty())
            {
                outfile__dynamic_array_statemonitor_4_g_NMDA.write(reinterpret_cast<char*>(&_dynamic_array_statemonitor_4_g_NMDA(n, 0)), _dynamic_array_statemonitor_4_g_NMDA.m*sizeof(_dynamic_array_statemonitor_4_g_NMDA(0, 0)));
            }
        }
        outfile__dynamic_array_statemonitor_4_g_NMDA.close();
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_statemonitor_4_g_NMDA." << endl;
	}
	ofstream outfile__dynamic_array_statemonitor_5_g_AMPA;
	outfile__dynamic_array_statemonitor_5_g_AMPA.open("results/_dynamic_array_statemonitor_5_g_AMPA_4809314941680302797", ios::binary | ios::out);
	if(outfile__dynamic_array_statemonitor_5_g_AMPA.is_open())
	{
        for (int n=0; n<_dynamic_array_statemonitor_5_g_AMPA.n; n++)
        {
            if (! _dynamic_array_statemonitor_5_g_AMPA(n).empty())
            {
                outfile__dynamic_array_statemonitor_5_g_AMPA.write(reinterpret_cast<char*>(&_dynamic_array_statemonitor_5_g_AMPA(n, 0)), _dynamic_array_statemonitor_5_g_AMPA.m*sizeof(_dynamic_array_statemonitor_5_g_AMPA(0, 0)));
            }
        }
        outfile__dynamic_array_statemonitor_5_g_AMPA.close();
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_statemonitor_5_g_AMPA." << endl;
	}
	ofstream outfile__dynamic_array_statemonitor_5_g_GABA;
	outfile__dynamic_array_statemonitor_5_g_GABA.open("results/_dynamic_array_statemonitor_5_g_GABA_7212218885843565887", ios::binary | ios::out);
	if(outfile__dynamic_array_statemonitor_5_g_GABA.is_open())
	{
        for (int n=0; n<_dynamic_array_statemonitor_5_g_GABA.n; n++)
        {
            if (! _dynamic_array_statemonitor_5_g_GABA(n).empty())
            {
                outfile__dynamic_array_statemonitor_5_g_GABA.write(reinterpret_cast<char*>(&_dynamic_array_statemonitor_5_g_GABA(n, 0)), _dynamic_array_statemonitor_5_g_GABA.m*sizeof(_dynamic_array_statemonitor_5_g_GABA(0, 0)));
            }
        }
        outfile__dynamic_array_statemonitor_5_g_GABA.close();
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_statemonitor_5_g_GABA." << endl;
	}
	ofstream outfile__dynamic_array_statemonitor_5_g_NMDA;
	outfile__dynamic_array_statemonitor_5_g_NMDA.open("results/_dynamic_array_statemonitor_5_g_NMDA_-1960843048409394338", ios::binary | ios::out);
	if(outfile__dynamic_array_statemonitor_5_g_NMDA.is_open())
	{
        for (int n=0; n<_dynamic_array_statemonitor_5_g_NMDA.n; n++)
        {
            if (! _dynamic_array_statemonitor_5_g_NMDA(n).empty())
            {
                outfile__dynamic_array_statemonitor_5_g_NMDA.write(reinterpret_cast<char*>(&_dynamic_array_statemonitor_5_g_NMDA(n, 0)), _dynamic_array_statemonitor_5_g_NMDA.m*sizeof(_dynamic_array_statemonitor_5_g_NMDA(0, 0)));
            }
        }
        outfile__dynamic_array_statemonitor_5_g_NMDA.close();
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_statemonitor_5_g_NMDA." << endl;
	}
	ofstream outfile__dynamic_array_statemonitor_6_g_AMPA_r;
	outfile__dynamic_array_statemonitor_6_g_AMPA_r.open("results/_dynamic_array_statemonitor_6_g_AMPA_r_-2975501228655877873", ios::binary | ios::out);
	if(outfile__dynamic_array_statemonitor_6_g_AMPA_r.is_open())
	{
        for (int n=0; n<_dynamic_array_statemonitor_6_g_AMPA_r.n; n++)
        {
            if (! _dynamic_array_statemonitor_6_g_AMPA_r(n).empty())
            {
                outfile__dynamic_array_statemonitor_6_g_AMPA_r.write(reinterpret_cast<char*>(&_dynamic_array_statemonitor_6_g_AMPA_r(n, 0)), _dynamic_array_statemonitor_6_g_AMPA_r.m*sizeof(_dynamic_array_statemonitor_6_g_AMPA_r(0, 0)));
            }
        }
        outfile__dynamic_array_statemonitor_6_g_AMPA_r.close();
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_statemonitor_6_g_AMPA_r." << endl;
	}
	ofstream outfile__dynamic_array_statemonitor_6_g_GABA_r;
	outfile__dynamic_array_statemonitor_6_g_GABA_r.open("results/_dynamic_array_statemonitor_6_g_GABA_r_7621076015825629203", ios::binary | ios::out);
	if(outfile__dynamic_array_statemonitor_6_g_GABA_r.is_open())
	{
        for (int n=0; n<_dynamic_array_statemonitor_6_g_GABA_r.n; n++)
        {
            if (! _dynamic_array_statemonitor_6_g_GABA_r(n).empty())
            {
                outfile__dynamic_array_statemonitor_6_g_GABA_r.write(reinterpret_cast<char*>(&_dynamic_array_statemonitor_6_g_GABA_r(n, 0)), _dynamic_array_statemonitor_6_g_GABA_r.m*sizeof(_dynamic_array_statemonitor_6_g_GABA_r(0, 0)));
            }
        }
        outfile__dynamic_array_statemonitor_6_g_GABA_r.close();
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_statemonitor_6_g_GABA_r." << endl;
	}
	ofstream outfile__dynamic_array_statemonitor_6_g_NMDA_r;
	outfile__dynamic_array_statemonitor_6_g_NMDA_r.open("results/_dynamic_array_statemonitor_6_g_NMDA_r_5315515107544013100", ios::binary | ios::out);
	if(outfile__dynamic_array_statemonitor_6_g_NMDA_r.is_open())
	{
        for (int n=0; n<_dynamic_array_statemonitor_6_g_NMDA_r.n; n++)
        {
            if (! _dynamic_array_statemonitor_6_g_NMDA_r(n).empty())
            {
                outfile__dynamic_array_statemonitor_6_g_NMDA_r.write(reinterpret_cast<char*>(&_dynamic_array_statemonitor_6_g_NMDA_r(n, 0)), _dynamic_array_statemonitor_6_g_NMDA_r.m*sizeof(_dynamic_array_statemonitor_6_g_NMDA_r(0, 0)));
            }
        }
        outfile__dynamic_array_statemonitor_6_g_NMDA_r.close();
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_statemonitor_6_g_NMDA_r." << endl;
	}
	ofstream outfile__dynamic_array_statemonitor_7_g_AMPA_r;
	outfile__dynamic_array_statemonitor_7_g_AMPA_r.open("results/_dynamic_array_statemonitor_7_g_AMPA_r_-3897628174806608087", ios::binary | ios::out);
	if(outfile__dynamic_array_statemonitor_7_g_AMPA_r.is_open())
	{
        for (int n=0; n<_dynamic_array_statemonitor_7_g_AMPA_r.n; n++)
        {
            if (! _dynamic_array_statemonitor_7_g_AMPA_r(n).empty())
            {
                outfile__dynamic_array_statemonitor_7_g_AMPA_r.write(reinterpret_cast<char*>(&_dynamic_array_statemonitor_7_g_AMPA_r(n, 0)), _dynamic_array_statemonitor_7_g_AMPA_r.m*sizeof(_dynamic_array_statemonitor_7_g_AMPA_r(0, 0)));
            }
        }
        outfile__dynamic_array_statemonitor_7_g_AMPA_r.close();
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_statemonitor_7_g_AMPA_r." << endl;
	}
	ofstream outfile__dynamic_array_statemonitor_7_g_GABA_r;
	outfile__dynamic_array_statemonitor_7_g_GABA_r.open("results/_dynamic_array_statemonitor_7_g_GABA_r_2961628764805490848", ios::binary | ios::out);
	if(outfile__dynamic_array_statemonitor_7_g_GABA_r.is_open())
	{
        for (int n=0; n<_dynamic_array_statemonitor_7_g_GABA_r.n; n++)
        {
            if (! _dynamic_array_statemonitor_7_g_GABA_r(n).empty())
            {
                outfile__dynamic_array_statemonitor_7_g_GABA_r.write(reinterpret_cast<char*>(&_dynamic_array_statemonitor_7_g_GABA_r(n, 0)), _dynamic_array_statemonitor_7_g_GABA_r.m*sizeof(_dynamic_array_statemonitor_7_g_GABA_r(0, 0)));
            }
        }
        outfile__dynamic_array_statemonitor_7_g_GABA_r.close();
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_statemonitor_7_g_GABA_r." << endl;
	}
	ofstream outfile__dynamic_array_statemonitor_7_g_NMDA_r;
	outfile__dynamic_array_statemonitor_7_g_NMDA_r.open("results/_dynamic_array_statemonitor_7_g_NMDA_r_2979484093733826997", ios::binary | ios::out);
	if(outfile__dynamic_array_statemonitor_7_g_NMDA_r.is_open())
	{
        for (int n=0; n<_dynamic_array_statemonitor_7_g_NMDA_r.n; n++)
        {
            if (! _dynamic_array_statemonitor_7_g_NMDA_r(n).empty())
            {
                outfile__dynamic_array_statemonitor_7_g_NMDA_r.write(reinterpret_cast<char*>(&_dynamic_array_statemonitor_7_g_NMDA_r(n, 0)), _dynamic_array_statemonitor_7_g_NMDA_r.m*sizeof(_dynamic_array_statemonitor_7_g_NMDA_r(0, 0)));
            }
        }
        outfile__dynamic_array_statemonitor_7_g_NMDA_r.close();
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_statemonitor_7_g_NMDA_r." << endl;
	}
	ofstream outfile__dynamic_array_statemonitor_8_g_AMPA_r;
	outfile__dynamic_array_statemonitor_8_g_AMPA_r.open("results/_dynamic_array_statemonitor_8_g_AMPA_r_-4506910061533693397", ios::binary | ios::out);
	if(outfile__dynamic_array_statemonitor_8_g_AMPA_r.is_open())
	{
        for (int n=0; n<_dynamic_array_statemonitor_8_g_AMPA_r.n; n++)
        {
            if (! _dynamic_array_statemonitor_8_g_AMPA_r(n).empty())
            {
                outfile__dynamic_array_statemonitor_8_g_AMPA_r.write(reinterpret_cast<char*>(&_dynamic_array_statemonitor_8_g_AMPA_r(n, 0)), _dynamic_array_statemonitor_8_g_AMPA_r.m*sizeof(_dynamic_array_statemonitor_8_g_AMPA_r(0, 0)));
            }
        }
        outfile__dynamic_array_statemonitor_8_g_AMPA_r.close();
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_statemonitor_8_g_AMPA_r." << endl;
	}
	ofstream outfile__dynamic_array_statemonitor_8_g_GABA_r;
	outfile__dynamic_array_statemonitor_8_g_GABA_r.open("results/_dynamic_array_statemonitor_8_g_GABA_r_-124116121368156052", ios::binary | ios::out);
	if(outfile__dynamic_array_statemonitor_8_g_GABA_r.is_open())
	{
        for (int n=0; n<_dynamic_array_statemonitor_8_g_GABA_r.n; n++)
        {
            if (! _dynamic_array_statemonitor_8_g_GABA_r(n).empty())
            {
                outfile__dynamic_array_statemonitor_8_g_GABA_r.write(reinterpret_cast<char*>(&_dynamic_array_statemonitor_8_g_GABA_r(n, 0)), _dynamic_array_statemonitor_8_g_GABA_r.m*sizeof(_dynamic_array_statemonitor_8_g_GABA_r(0, 0)));
            }
        }
        outfile__dynamic_array_statemonitor_8_g_GABA_r.close();
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_statemonitor_8_g_GABA_r." << endl;
	}
	ofstream outfile__dynamic_array_statemonitor_8_g_NMDA_r;
	outfile__dynamic_array_statemonitor_8_g_NMDA_r.open("results/_dynamic_array_statemonitor_8_g_NMDA_r_-3677760368651503575", ios::binary | ios::out);
	if(outfile__dynamic_array_statemonitor_8_g_NMDA_r.is_open())
	{
        for (int n=0; n<_dynamic_array_statemonitor_8_g_NMDA_r.n; n++)
        {
            if (! _dynamic_array_statemonitor_8_g_NMDA_r(n).empty())
            {
                outfile__dynamic_array_statemonitor_8_g_NMDA_r.write(reinterpret_cast<char*>(&_dynamic_array_statemonitor_8_g_NMDA_r(n, 0)), _dynamic_array_statemonitor_8_g_NMDA_r.m*sizeof(_dynamic_array_statemonitor_8_g_NMDA_r(0, 0)));
            }
        }
        outfile__dynamic_array_statemonitor_8_g_NMDA_r.close();
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_statemonitor_8_g_NMDA_r." << endl;
	}
	ofstream outfile__dynamic_array_statemonitor_9_g_AMPA_d;
	outfile__dynamic_array_statemonitor_9_g_AMPA_d.open("results/_dynamic_array_statemonitor_9_g_AMPA_d_7498585453070050782", ios::binary | ios::out);
	if(outfile__dynamic_array_statemonitor_9_g_AMPA_d.is_open())
	{
        for (int n=0; n<_dynamic_array_statemonitor_9_g_AMPA_d.n; n++)
        {
            if (! _dynamic_array_statemonitor_9_g_AMPA_d(n).empty())
            {
                outfile__dynamic_array_statemonitor_9_g_AMPA_d.write(reinterpret_cast<char*>(&_dynamic_array_statemonitor_9_g_AMPA_d(n, 0)), _dynamic_array_statemonitor_9_g_AMPA_d.m*sizeof(_dynamic_array_statemonitor_9_g_AMPA_d(0, 0)));
            }
        }
        outfile__dynamic_array_statemonitor_9_g_AMPA_d.close();
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_statemonitor_9_g_AMPA_d." << endl;
	}
	ofstream outfile__dynamic_array_statemonitor_9_g_GABA_d;
	outfile__dynamic_array_statemonitor_9_g_GABA_d.open("results/_dynamic_array_statemonitor_9_g_GABA_d_417495411370080837", ios::binary | ios::out);
	if(outfile__dynamic_array_statemonitor_9_g_GABA_d.is_open())
	{
        for (int n=0; n<_dynamic_array_statemonitor_9_g_GABA_d.n; n++)
        {
            if (! _dynamic_array_statemonitor_9_g_GABA_d(n).empty())
            {
                outfile__dynamic_array_statemonitor_9_g_GABA_d.write(reinterpret_cast<char*>(&_dynamic_array_statemonitor_9_g_GABA_d(n, 0)), _dynamic_array_statemonitor_9_g_GABA_d.m*sizeof(_dynamic_array_statemonitor_9_g_GABA_d(0, 0)));
            }
        }
        outfile__dynamic_array_statemonitor_9_g_GABA_d.close();
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_statemonitor_9_g_GABA_d." << endl;
	}
	ofstream outfile__dynamic_array_statemonitor_9_g_NMDA_d;
	outfile__dynamic_array_statemonitor_9_g_NMDA_d.open("results/_dynamic_array_statemonitor_9_g_NMDA_d_-2849491704553535869", ios::binary | ios::out);
	if(outfile__dynamic_array_statemonitor_9_g_NMDA_d.is_open())
	{
        for (int n=0; n<_dynamic_array_statemonitor_9_g_NMDA_d.n; n++)
        {
            if (! _dynamic_array_statemonitor_9_g_NMDA_d(n).empty())
            {
                outfile__dynamic_array_statemonitor_9_g_NMDA_d.write(reinterpret_cast<char*>(&_dynamic_array_statemonitor_9_g_NMDA_d(n, 0)), _dynamic_array_statemonitor_9_g_NMDA_d.m*sizeof(_dynamic_array_statemonitor_9_g_NMDA_d(0, 0)));
            }
        }
        outfile__dynamic_array_statemonitor_9_g_NMDA_d.close();
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_statemonitor_9_g_NMDA_d." << endl;
	}
	ofstream outfile__dynamic_array_statemonitor_v;
	outfile__dynamic_array_statemonitor_v.open("results/_dynamic_array_statemonitor_v_-3675528573134730966", ios::binary | ios::out);
	if(outfile__dynamic_array_statemonitor_v.is_open())
	{
        for (int n=0; n<_dynamic_array_statemonitor_v.n; n++)
        {
            if (! _dynamic_array_statemonitor_v(n).empty())
            {
                outfile__dynamic_array_statemonitor_v.write(reinterpret_cast<char*>(&_dynamic_array_statemonitor_v(n, 0)), _dynamic_array_statemonitor_v.m*sizeof(_dynamic_array_statemonitor_v(0, 0)));
            }
        }
        outfile__dynamic_array_statemonitor_v.close();
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_statemonitor_v." << endl;
	}
	// Write last run info to disk
	ofstream outfile_last_run_info;
	outfile_last_run_info.open("results/last_run_info.txt", ios::out);
	if(outfile_last_run_info.is_open())
	{
		outfile_last_run_info << (Network::_last_run_time) << " " << (Network::_last_run_completed_fraction) << std::endl;
		outfile_last_run_info.close();
	} else
	{
	    std::cout << "Error writing last run info to file." << std::endl;
	}
}

void _dealloc_arrays()
{
	using namespace brian;


	// static arrays
	if(_static_array__array_statemonitor_10__indices!=0)
	{
		delete [] _static_array__array_statemonitor_10__indices;
		_static_array__array_statemonitor_10__indices = 0;
	}
	if(_static_array__array_statemonitor_11__indices!=0)
	{
		delete [] _static_array__array_statemonitor_11__indices;
		_static_array__array_statemonitor_11__indices = 0;
	}
	if(_static_array__array_statemonitor_12__indices!=0)
	{
		delete [] _static_array__array_statemonitor_12__indices;
		_static_array__array_statemonitor_12__indices = 0;
	}
	if(_static_array__array_statemonitor_13__indices!=0)
	{
		delete [] _static_array__array_statemonitor_13__indices;
		_static_array__array_statemonitor_13__indices = 0;
	}
	if(_static_array__array_statemonitor_14__indices!=0)
	{
		delete [] _static_array__array_statemonitor_14__indices;
		_static_array__array_statemonitor_14__indices = 0;
	}
	if(_static_array__array_statemonitor_1__indices!=0)
	{
		delete [] _static_array__array_statemonitor_1__indices;
		_static_array__array_statemonitor_1__indices = 0;
	}
	if(_static_array__array_statemonitor_2__indices!=0)
	{
		delete [] _static_array__array_statemonitor_2__indices;
		_static_array__array_statemonitor_2__indices = 0;
	}
	if(_static_array__array_statemonitor_3__indices!=0)
	{
		delete [] _static_array__array_statemonitor_3__indices;
		_static_array__array_statemonitor_3__indices = 0;
	}
	if(_static_array__array_statemonitor_4__indices!=0)
	{
		delete [] _static_array__array_statemonitor_4__indices;
		_static_array__array_statemonitor_4__indices = 0;
	}
	if(_static_array__array_statemonitor_5__indices!=0)
	{
		delete [] _static_array__array_statemonitor_5__indices;
		_static_array__array_statemonitor_5__indices = 0;
	}
	if(_static_array__array_statemonitor_6__indices!=0)
	{
		delete [] _static_array__array_statemonitor_6__indices;
		_static_array__array_statemonitor_6__indices = 0;
	}
	if(_static_array__array_statemonitor_7__indices!=0)
	{
		delete [] _static_array__array_statemonitor_7__indices;
		_static_array__array_statemonitor_7__indices = 0;
	}
	if(_static_array__array_statemonitor_8__indices!=0)
	{
		delete [] _static_array__array_statemonitor_8__indices;
		_static_array__array_statemonitor_8__indices = 0;
	}
	if(_static_array__array_statemonitor_9__indices!=0)
	{
		delete [] _static_array__array_statemonitor_9__indices;
		_static_array__array_statemonitor_9__indices = 0;
	}
	if(_static_array__array_statemonitor__indices!=0)
	{
		delete [] _static_array__array_statemonitor__indices;
		_static_array__array_statemonitor__indices = 0;
	}
}

