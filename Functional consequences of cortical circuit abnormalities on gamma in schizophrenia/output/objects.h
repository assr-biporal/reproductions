
#ifndef _BRIAN_OBJECTS_H
#define _BRIAN_OBJECTS_H

#include "synapses_classes.h"
#include "brianlib/clocks.h"
#include "brianlib/dynamic_array.h"
#include "brianlib/stdint_compat.h"
#include "network.h"
#include "randomkit.h"
#include<vector>
#include <omp.h>

namespace brian {

// In OpenMP we need one state per thread
extern std::vector< rk_state* > _mersenne_twister_states;

//////////////// clocks ///////////////////
extern Clock defaultclock;

//////////////// networks /////////////////
extern Network magicnetwork;
extern Network network;

//////////////// dynamic arrays ///////////
extern std::vector<int32_t> _dynamic_array_AMPA_NMDA_fromPCtoFSI__synaptic_post;
extern std::vector<int32_t> _dynamic_array_AMPA_NMDA_fromPCtoFSI__synaptic_pre;
extern std::vector<double> _dynamic_array_AMPA_NMDA_fromPCtoFSI_delay;
extern std::vector<int32_t> _dynamic_array_AMPA_NMDA_fromPCtoFSI_N_incoming;
extern std::vector<int32_t> _dynamic_array_AMPA_NMDA_fromPCtoFSI_N_outgoing;
extern std::vector<int32_t> _dynamic_array_AMPA_NMDA_fromPCtoPC__synaptic_post;
extern std::vector<int32_t> _dynamic_array_AMPA_NMDA_fromPCtoPC__synaptic_pre;
extern std::vector<double> _dynamic_array_AMPA_NMDA_fromPCtoPC_delay;
extern std::vector<int32_t> _dynamic_array_AMPA_NMDA_fromPCtoPC_N_incoming;
extern std::vector<int32_t> _dynamic_array_AMPA_NMDA_fromPCtoPC_N_outgoing;
extern std::vector<int32_t> _dynamic_array_AMPA_NMDA_fromPCtoRSI__synaptic_post;
extern std::vector<int32_t> _dynamic_array_AMPA_NMDA_fromPCtoRSI__synaptic_pre;
extern std::vector<double> _dynamic_array_AMPA_NMDA_fromPCtoRSI_delay;
extern std::vector<int32_t> _dynamic_array_AMPA_NMDA_fromPCtoRSI_N_incoming;
extern std::vector<int32_t> _dynamic_array_AMPA_NMDA_fromPCtoRSI_N_outgoing;
extern std::vector<int32_t> _dynamic_array_GABA_fromFSItoFSI__synaptic_post;
extern std::vector<int32_t> _dynamic_array_GABA_fromFSItoFSI__synaptic_pre;
extern std::vector<double> _dynamic_array_GABA_fromFSItoFSI_delay;
extern std::vector<int32_t> _dynamic_array_GABA_fromFSItoFSI_N_incoming;
extern std::vector<int32_t> _dynamic_array_GABA_fromFSItoFSI_N_outgoing;
extern std::vector<int32_t> _dynamic_array_GABA_fromFSItoPC__synaptic_post;
extern std::vector<int32_t> _dynamic_array_GABA_fromFSItoPC__synaptic_pre;
extern std::vector<double> _dynamic_array_GABA_fromFSItoPC_delay;
extern std::vector<int32_t> _dynamic_array_GABA_fromFSItoPC_N_incoming;
extern std::vector<int32_t> _dynamic_array_GABA_fromFSItoPC_N_outgoing;
extern std::vector<int32_t> _dynamic_array_GABA_fromFSItoRSI__synaptic_post;
extern std::vector<int32_t> _dynamic_array_GABA_fromFSItoRSI__synaptic_pre;
extern std::vector<double> _dynamic_array_GABA_fromFSItoRSI_delay;
extern std::vector<int32_t> _dynamic_array_GABA_fromFSItoRSI_N_incoming;
extern std::vector<int32_t> _dynamic_array_GABA_fromFSItoRSI_N_outgoing;
extern std::vector<int32_t> _dynamic_array_GABA_fromRSItoFSI__synaptic_post;
extern std::vector<int32_t> _dynamic_array_GABA_fromRSItoFSI__synaptic_pre;
extern std::vector<double> _dynamic_array_GABA_fromRSItoFSI_delay;
extern std::vector<int32_t> _dynamic_array_GABA_fromRSItoFSI_N_incoming;
extern std::vector<int32_t> _dynamic_array_GABA_fromRSItoFSI_N_outgoing;
extern std::vector<int32_t> _dynamic_array_GABA_fromRSItoPC__synaptic_post;
extern std::vector<int32_t> _dynamic_array_GABA_fromRSItoPC__synaptic_pre;
extern std::vector<double> _dynamic_array_GABA_fromRSItoPC_delay;
extern std::vector<int32_t> _dynamic_array_GABA_fromRSItoPC_N_incoming;
extern std::vector<int32_t> _dynamic_array_GABA_fromRSItoPC_N_outgoing;
extern std::vector<int32_t> _dynamic_array_GABA_fromRSItoRSI__synaptic_post;
extern std::vector<int32_t> _dynamic_array_GABA_fromRSItoRSI__synaptic_pre;
extern std::vector<double> _dynamic_array_GABA_fromRSItoRSI_delay;
extern std::vector<int32_t> _dynamic_array_GABA_fromRSItoRSI_N_incoming;
extern std::vector<int32_t> _dynamic_array_GABA_fromRSItoRSI_N_outgoing;
extern std::vector<int32_t> _dynamic_array_spikemonitor_1_i;
extern std::vector<double> _dynamic_array_spikemonitor_1_t;
extern std::vector<int32_t> _dynamic_array_spikemonitor_2_i;
extern std::vector<double> _dynamic_array_spikemonitor_2_t;
extern std::vector<int32_t> _dynamic_array_spikemonitor_3_i;
extern std::vector<double> _dynamic_array_spikemonitor_3_t;
extern std::vector<int32_t> _dynamic_array_spikemonitor_i;
extern std::vector<double> _dynamic_array_spikemonitor_t;
extern std::vector<double> _dynamic_array_statemonitor_10_t;
extern std::vector<double> _dynamic_array_statemonitor_11_t;
extern std::vector<double> _dynamic_array_statemonitor_12_t;
extern std::vector<double> _dynamic_array_statemonitor_13_t;
extern std::vector<double> _dynamic_array_statemonitor_14_t;
extern std::vector<double> _dynamic_array_statemonitor_1_t;
extern std::vector<double> _dynamic_array_statemonitor_2_t;
extern std::vector<double> _dynamic_array_statemonitor_3_t;
extern std::vector<double> _dynamic_array_statemonitor_4_t;
extern std::vector<double> _dynamic_array_statemonitor_5_t;
extern std::vector<double> _dynamic_array_statemonitor_6_t;
extern std::vector<double> _dynamic_array_statemonitor_7_t;
extern std::vector<double> _dynamic_array_statemonitor_8_t;
extern std::vector<double> _dynamic_array_statemonitor_9_t;
extern std::vector<double> _dynamic_array_statemonitor_t;
extern std::vector<int32_t> _dynamic_array_synapses__synaptic_post;
extern std::vector<int32_t> _dynamic_array_synapses__synaptic_pre;
extern std::vector<double> _dynamic_array_synapses_delay;
extern std::vector<int32_t> _dynamic_array_synapses_N_incoming;
extern std::vector<int32_t> _dynamic_array_synapses_N_outgoing;

//////////////// arrays ///////////////////
extern int32_t *_array_AMPA_NMDA_fromPCtoFSI_N;
extern const int _num__array_AMPA_NMDA_fromPCtoFSI_N;
extern int32_t *_array_AMPA_NMDA_fromPCtoPC_N;
extern const int _num__array_AMPA_NMDA_fromPCtoPC_N;
extern int32_t *_array_AMPA_NMDA_fromPCtoRSI_N;
extern const int _num__array_AMPA_NMDA_fromPCtoRSI_N;
extern double *_array_defaultclock_dt;
extern const int _num__array_defaultclock_dt;
extern double *_array_defaultclock_t;
extern const int _num__array_defaultclock_t;
extern int64_t *_array_defaultclock_timestep;
extern const int _num__array_defaultclock_timestep;
extern int32_t *_array_Fast_Spiking_Interneurons__spikespace;
extern const int _num__array_Fast_Spiking_Interneurons__spikespace;
extern double *_array_Fast_Spiking_Interneurons_g_AMPA_d;
extern const int _num__array_Fast_Spiking_Interneurons_g_AMPA_d;
extern double *_array_Fast_Spiking_Interneurons_g_AMPA_r;
extern const int _num__array_Fast_Spiking_Interneurons_g_AMPA_r;
extern double *_array_Fast_Spiking_Interneurons_g_GABA_d;
extern const int _num__array_Fast_Spiking_Interneurons_g_GABA_d;
extern double *_array_Fast_Spiking_Interneurons_g_GABA_r;
extern const int _num__array_Fast_Spiking_Interneurons_g_GABA_r;
extern double *_array_Fast_Spiking_Interneurons_g_NMDA_d;
extern const int _num__array_Fast_Spiking_Interneurons_g_NMDA_d;
extern double *_array_Fast_Spiking_Interneurons_g_NMDA_r;
extern const int _num__array_Fast_Spiking_Interneurons_g_NMDA_r;
extern int32_t *_array_Fast_Spiking_Interneurons_i;
extern const int _num__array_Fast_Spiking_Interneurons_i;
extern double *_array_Fast_Spiking_Interneurons_v;
extern const int _num__array_Fast_Spiking_Interneurons_v;
extern int32_t *_array_GABA_fromFSItoFSI_N;
extern const int _num__array_GABA_fromFSItoFSI_N;
extern int32_t *_array_GABA_fromFSItoPC_N;
extern const int _num__array_GABA_fromFSItoPC_N;
extern int32_t *_array_GABA_fromFSItoRSI_N;
extern const int _num__array_GABA_fromFSItoRSI_N;
extern int32_t *_array_GABA_fromRSItoFSI_N;
extern const int _num__array_GABA_fromRSItoFSI_N;
extern int32_t *_array_GABA_fromRSItoPC_N;
extern const int _num__array_GABA_fromRSItoPC_N;
extern int32_t *_array_GABA_fromRSItoRSI_N;
extern const int _num__array_GABA_fromRSItoRSI_N;
extern int32_t *_array_poissongroup__spikespace;
extern const int _num__array_poissongroup__spikespace;
extern int32_t *_array_poissongroup_i;
extern const int _num__array_poissongroup_i;
extern double *_array_poissongroup_rates;
extern const int _num__array_poissongroup_rates;
extern int32_t *_array_Pyramidal_Cells__spikespace;
extern const int _num__array_Pyramidal_Cells__spikespace;
extern double *_array_Pyramidal_Cells_g_AMPA_d;
extern const int _num__array_Pyramidal_Cells_g_AMPA_d;
extern double *_array_Pyramidal_Cells_g_AMPA_r;
extern const int _num__array_Pyramidal_Cells_g_AMPA_r;
extern double *_array_Pyramidal_Cells_g_GABA_d;
extern const int _num__array_Pyramidal_Cells_g_GABA_d;
extern double *_array_Pyramidal_Cells_g_GABA_r;
extern const int _num__array_Pyramidal_Cells_g_GABA_r;
extern double *_array_Pyramidal_Cells_g_NMDA_d;
extern const int _num__array_Pyramidal_Cells_g_NMDA_d;
extern double *_array_Pyramidal_Cells_g_NMDA_r;
extern const int _num__array_Pyramidal_Cells_g_NMDA_r;
extern int32_t *_array_Pyramidal_Cells_i;
extern const int _num__array_Pyramidal_Cells_i;
extern double *_array_Pyramidal_Cells_v;
extern const int _num__array_Pyramidal_Cells_v;
extern int32_t *_array_Regular_Spiking_Interneurons__spikespace;
extern const int _num__array_Regular_Spiking_Interneurons__spikespace;
extern double *_array_Regular_Spiking_Interneurons_g_AMPA_d;
extern const int _num__array_Regular_Spiking_Interneurons_g_AMPA_d;
extern double *_array_Regular_Spiking_Interneurons_g_AMPA_r;
extern const int _num__array_Regular_Spiking_Interneurons_g_AMPA_r;
extern double *_array_Regular_Spiking_Interneurons_g_GABA_d;
extern const int _num__array_Regular_Spiking_Interneurons_g_GABA_d;
extern double *_array_Regular_Spiking_Interneurons_g_GABA_r;
extern const int _num__array_Regular_Spiking_Interneurons_g_GABA_r;
extern double *_array_Regular_Spiking_Interneurons_g_NMDA_d;
extern const int _num__array_Regular_Spiking_Interneurons_g_NMDA_d;
extern double *_array_Regular_Spiking_Interneurons_g_NMDA_r;
extern const int _num__array_Regular_Spiking_Interneurons_g_NMDA_r;
extern int32_t *_array_Regular_Spiking_Interneurons_i;
extern const int _num__array_Regular_Spiking_Interneurons_i;
extern double *_array_Regular_Spiking_Interneurons_v;
extern const int _num__array_Regular_Spiking_Interneurons_v;
extern int32_t *_array_spikemonitor_1__source_idx;
extern const int _num__array_spikemonitor_1__source_idx;
extern int32_t *_array_spikemonitor_1_count;
extern const int _num__array_spikemonitor_1_count;
extern int32_t *_array_spikemonitor_1_N;
extern const int _num__array_spikemonitor_1_N;
extern int32_t *_array_spikemonitor_2__source_idx;
extern const int _num__array_spikemonitor_2__source_idx;
extern int32_t *_array_spikemonitor_2_count;
extern const int _num__array_spikemonitor_2_count;
extern int32_t *_array_spikemonitor_2_N;
extern const int _num__array_spikemonitor_2_N;
extern int32_t *_array_spikemonitor_3__source_idx;
extern const int _num__array_spikemonitor_3__source_idx;
extern int32_t *_array_spikemonitor_3_count;
extern const int _num__array_spikemonitor_3_count;
extern int32_t *_array_spikemonitor_3_N;
extern const int _num__array_spikemonitor_3_N;
extern int32_t *_array_spikemonitor__source_idx;
extern const int _num__array_spikemonitor__source_idx;
extern int32_t *_array_spikemonitor_count;
extern const int _num__array_spikemonitor_count;
extern int32_t *_array_spikemonitor_N;
extern const int _num__array_spikemonitor_N;
extern int32_t *_array_statemonitor_10__indices;
extern const int _num__array_statemonitor_10__indices;
extern double *_array_statemonitor_10_g_AMPA_d;
extern const int _num__array_statemonitor_10_g_AMPA_d;
extern double *_array_statemonitor_10_g_GABA_d;
extern const int _num__array_statemonitor_10_g_GABA_d;
extern double *_array_statemonitor_10_g_NMDA_d;
extern const int _num__array_statemonitor_10_g_NMDA_d;
extern int32_t *_array_statemonitor_10_N;
extern const int _num__array_statemonitor_10_N;
extern int32_t *_array_statemonitor_11__indices;
extern const int _num__array_statemonitor_11__indices;
extern double *_array_statemonitor_11_g_AMPA_d;
extern const int _num__array_statemonitor_11_g_AMPA_d;
extern double *_array_statemonitor_11_g_GABA_d;
extern const int _num__array_statemonitor_11_g_GABA_d;
extern double *_array_statemonitor_11_g_NMDA_d;
extern const int _num__array_statemonitor_11_g_NMDA_d;
extern int32_t *_array_statemonitor_11_N;
extern const int _num__array_statemonitor_11_N;
extern int32_t *_array_statemonitor_12__indices;
extern const int _num__array_statemonitor_12__indices;
extern double *_array_statemonitor_12_I_AMPA;
extern const int _num__array_statemonitor_12_I_AMPA;
extern double *_array_statemonitor_12_I_GABA;
extern const int _num__array_statemonitor_12_I_GABA;
extern double *_array_statemonitor_12_I_NMDA;
extern const int _num__array_statemonitor_12_I_NMDA;
extern double *_array_statemonitor_12_I_syn;
extern const int _num__array_statemonitor_12_I_syn;
extern int32_t *_array_statemonitor_12_N;
extern const int _num__array_statemonitor_12_N;
extern int32_t *_array_statemonitor_13__indices;
extern const int _num__array_statemonitor_13__indices;
extern double *_array_statemonitor_13_I_AMPA;
extern const int _num__array_statemonitor_13_I_AMPA;
extern double *_array_statemonitor_13_I_GABA;
extern const int _num__array_statemonitor_13_I_GABA;
extern double *_array_statemonitor_13_I_NMDA;
extern const int _num__array_statemonitor_13_I_NMDA;
extern double *_array_statemonitor_13_I_syn;
extern const int _num__array_statemonitor_13_I_syn;
extern int32_t *_array_statemonitor_13_N;
extern const int _num__array_statemonitor_13_N;
extern int32_t *_array_statemonitor_14__indices;
extern const int _num__array_statemonitor_14__indices;
extern double *_array_statemonitor_14_I_AMPA;
extern const int _num__array_statemonitor_14_I_AMPA;
extern double *_array_statemonitor_14_I_GABA;
extern const int _num__array_statemonitor_14_I_GABA;
extern double *_array_statemonitor_14_I_NMDA;
extern const int _num__array_statemonitor_14_I_NMDA;
extern double *_array_statemonitor_14_I_syn;
extern const int _num__array_statemonitor_14_I_syn;
extern int32_t *_array_statemonitor_14_N;
extern const int _num__array_statemonitor_14_N;
extern int32_t *_array_statemonitor_1__indices;
extern const int _num__array_statemonitor_1__indices;
extern int32_t *_array_statemonitor_1_N;
extern const int _num__array_statemonitor_1_N;
extern double *_array_statemonitor_1_v;
extern const int _num__array_statemonitor_1_v;
extern int32_t *_array_statemonitor_2__indices;
extern const int _num__array_statemonitor_2__indices;
extern int32_t *_array_statemonitor_2_N;
extern const int _num__array_statemonitor_2_N;
extern double *_array_statemonitor_2_v;
extern const int _num__array_statemonitor_2_v;
extern int32_t *_array_statemonitor_3__indices;
extern const int _num__array_statemonitor_3__indices;
extern double *_array_statemonitor_3_g_AMPA;
extern const int _num__array_statemonitor_3_g_AMPA;
extern double *_array_statemonitor_3_g_GABA;
extern const int _num__array_statemonitor_3_g_GABA;
extern double *_array_statemonitor_3_g_NMDA;
extern const int _num__array_statemonitor_3_g_NMDA;
extern int32_t *_array_statemonitor_3_N;
extern const int _num__array_statemonitor_3_N;
extern int32_t *_array_statemonitor_4__indices;
extern const int _num__array_statemonitor_4__indices;
extern double *_array_statemonitor_4_g_AMPA;
extern const int _num__array_statemonitor_4_g_AMPA;
extern double *_array_statemonitor_4_g_GABA;
extern const int _num__array_statemonitor_4_g_GABA;
extern double *_array_statemonitor_4_g_NMDA;
extern const int _num__array_statemonitor_4_g_NMDA;
extern int32_t *_array_statemonitor_4_N;
extern const int _num__array_statemonitor_4_N;
extern int32_t *_array_statemonitor_5__indices;
extern const int _num__array_statemonitor_5__indices;
extern double *_array_statemonitor_5_g_AMPA;
extern const int _num__array_statemonitor_5_g_AMPA;
extern double *_array_statemonitor_5_g_GABA;
extern const int _num__array_statemonitor_5_g_GABA;
extern double *_array_statemonitor_5_g_NMDA;
extern const int _num__array_statemonitor_5_g_NMDA;
extern int32_t *_array_statemonitor_5_N;
extern const int _num__array_statemonitor_5_N;
extern int32_t *_array_statemonitor_6__indices;
extern const int _num__array_statemonitor_6__indices;
extern double *_array_statemonitor_6_g_AMPA_r;
extern const int _num__array_statemonitor_6_g_AMPA_r;
extern double *_array_statemonitor_6_g_GABA_r;
extern const int _num__array_statemonitor_6_g_GABA_r;
extern double *_array_statemonitor_6_g_NMDA_r;
extern const int _num__array_statemonitor_6_g_NMDA_r;
extern int32_t *_array_statemonitor_6_N;
extern const int _num__array_statemonitor_6_N;
extern int32_t *_array_statemonitor_7__indices;
extern const int _num__array_statemonitor_7__indices;
extern double *_array_statemonitor_7_g_AMPA_r;
extern const int _num__array_statemonitor_7_g_AMPA_r;
extern double *_array_statemonitor_7_g_GABA_r;
extern const int _num__array_statemonitor_7_g_GABA_r;
extern double *_array_statemonitor_7_g_NMDA_r;
extern const int _num__array_statemonitor_7_g_NMDA_r;
extern int32_t *_array_statemonitor_7_N;
extern const int _num__array_statemonitor_7_N;
extern int32_t *_array_statemonitor_8__indices;
extern const int _num__array_statemonitor_8__indices;
extern double *_array_statemonitor_8_g_AMPA_r;
extern const int _num__array_statemonitor_8_g_AMPA_r;
extern double *_array_statemonitor_8_g_GABA_r;
extern const int _num__array_statemonitor_8_g_GABA_r;
extern double *_array_statemonitor_8_g_NMDA_r;
extern const int _num__array_statemonitor_8_g_NMDA_r;
extern int32_t *_array_statemonitor_8_N;
extern const int _num__array_statemonitor_8_N;
extern int32_t *_array_statemonitor_9__indices;
extern const int _num__array_statemonitor_9__indices;
extern double *_array_statemonitor_9_g_AMPA_d;
extern const int _num__array_statemonitor_9_g_AMPA_d;
extern double *_array_statemonitor_9_g_GABA_d;
extern const int _num__array_statemonitor_9_g_GABA_d;
extern double *_array_statemonitor_9_g_NMDA_d;
extern const int _num__array_statemonitor_9_g_NMDA_d;
extern int32_t *_array_statemonitor_9_N;
extern const int _num__array_statemonitor_9_N;
extern int32_t *_array_statemonitor__indices;
extern const int _num__array_statemonitor__indices;
extern int32_t *_array_statemonitor_N;
extern const int _num__array_statemonitor_N;
extern double *_array_statemonitor_v;
extern const int _num__array_statemonitor_v;
extern int32_t *_array_synapses_N;
extern const int _num__array_synapses_N;

//////////////// dynamic arrays 2d /////////
extern DynamicArray2D<double> _dynamic_array_statemonitor_10_g_AMPA_d;
extern DynamicArray2D<double> _dynamic_array_statemonitor_10_g_GABA_d;
extern DynamicArray2D<double> _dynamic_array_statemonitor_10_g_NMDA_d;
extern DynamicArray2D<double> _dynamic_array_statemonitor_11_g_AMPA_d;
extern DynamicArray2D<double> _dynamic_array_statemonitor_11_g_GABA_d;
extern DynamicArray2D<double> _dynamic_array_statemonitor_11_g_NMDA_d;
extern DynamicArray2D<double> _dynamic_array_statemonitor_12_I_AMPA;
extern DynamicArray2D<double> _dynamic_array_statemonitor_12_I_GABA;
extern DynamicArray2D<double> _dynamic_array_statemonitor_12_I_NMDA;
extern DynamicArray2D<double> _dynamic_array_statemonitor_12_I_syn;
extern DynamicArray2D<double> _dynamic_array_statemonitor_13_I_AMPA;
extern DynamicArray2D<double> _dynamic_array_statemonitor_13_I_GABA;
extern DynamicArray2D<double> _dynamic_array_statemonitor_13_I_NMDA;
extern DynamicArray2D<double> _dynamic_array_statemonitor_13_I_syn;
extern DynamicArray2D<double> _dynamic_array_statemonitor_14_I_AMPA;
extern DynamicArray2D<double> _dynamic_array_statemonitor_14_I_GABA;
extern DynamicArray2D<double> _dynamic_array_statemonitor_14_I_NMDA;
extern DynamicArray2D<double> _dynamic_array_statemonitor_14_I_syn;
extern DynamicArray2D<double> _dynamic_array_statemonitor_1_v;
extern DynamicArray2D<double> _dynamic_array_statemonitor_2_v;
extern DynamicArray2D<double> _dynamic_array_statemonitor_3_g_AMPA;
extern DynamicArray2D<double> _dynamic_array_statemonitor_3_g_GABA;
extern DynamicArray2D<double> _dynamic_array_statemonitor_3_g_NMDA;
extern DynamicArray2D<double> _dynamic_array_statemonitor_4_g_AMPA;
extern DynamicArray2D<double> _dynamic_array_statemonitor_4_g_GABA;
extern DynamicArray2D<double> _dynamic_array_statemonitor_4_g_NMDA;
extern DynamicArray2D<double> _dynamic_array_statemonitor_5_g_AMPA;
extern DynamicArray2D<double> _dynamic_array_statemonitor_5_g_GABA;
extern DynamicArray2D<double> _dynamic_array_statemonitor_5_g_NMDA;
extern DynamicArray2D<double> _dynamic_array_statemonitor_6_g_AMPA_r;
extern DynamicArray2D<double> _dynamic_array_statemonitor_6_g_GABA_r;
extern DynamicArray2D<double> _dynamic_array_statemonitor_6_g_NMDA_r;
extern DynamicArray2D<double> _dynamic_array_statemonitor_7_g_AMPA_r;
extern DynamicArray2D<double> _dynamic_array_statemonitor_7_g_GABA_r;
extern DynamicArray2D<double> _dynamic_array_statemonitor_7_g_NMDA_r;
extern DynamicArray2D<double> _dynamic_array_statemonitor_8_g_AMPA_r;
extern DynamicArray2D<double> _dynamic_array_statemonitor_8_g_GABA_r;
extern DynamicArray2D<double> _dynamic_array_statemonitor_8_g_NMDA_r;
extern DynamicArray2D<double> _dynamic_array_statemonitor_9_g_AMPA_d;
extern DynamicArray2D<double> _dynamic_array_statemonitor_9_g_GABA_d;
extern DynamicArray2D<double> _dynamic_array_statemonitor_9_g_NMDA_d;
extern DynamicArray2D<double> _dynamic_array_statemonitor_v;

/////////////// static arrays /////////////
extern int32_t *_static_array__array_statemonitor_10__indices;
extern const int _num__static_array__array_statemonitor_10__indices;
extern int32_t *_static_array__array_statemonitor_11__indices;
extern const int _num__static_array__array_statemonitor_11__indices;
extern int32_t *_static_array__array_statemonitor_12__indices;
extern const int _num__static_array__array_statemonitor_12__indices;
extern int32_t *_static_array__array_statemonitor_13__indices;
extern const int _num__static_array__array_statemonitor_13__indices;
extern int32_t *_static_array__array_statemonitor_14__indices;
extern const int _num__static_array__array_statemonitor_14__indices;
extern int32_t *_static_array__array_statemonitor_1__indices;
extern const int _num__static_array__array_statemonitor_1__indices;
extern int32_t *_static_array__array_statemonitor_2__indices;
extern const int _num__static_array__array_statemonitor_2__indices;
extern int32_t *_static_array__array_statemonitor_3__indices;
extern const int _num__static_array__array_statemonitor_3__indices;
extern int32_t *_static_array__array_statemonitor_4__indices;
extern const int _num__static_array__array_statemonitor_4__indices;
extern int32_t *_static_array__array_statemonitor_5__indices;
extern const int _num__static_array__array_statemonitor_5__indices;
extern int32_t *_static_array__array_statemonitor_6__indices;
extern const int _num__static_array__array_statemonitor_6__indices;
extern int32_t *_static_array__array_statemonitor_7__indices;
extern const int _num__static_array__array_statemonitor_7__indices;
extern int32_t *_static_array__array_statemonitor_8__indices;
extern const int _num__static_array__array_statemonitor_8__indices;
extern int32_t *_static_array__array_statemonitor_9__indices;
extern const int _num__static_array__array_statemonitor_9__indices;
extern int32_t *_static_array__array_statemonitor__indices;
extern const int _num__static_array__array_statemonitor__indices;

//////////////// synapses /////////////////
// AMPA_NMDA_fromPCtoFSI
extern SynapticPathway AMPA_NMDA_fromPCtoFSI_pre;
// AMPA_NMDA_fromPCtoPC
extern SynapticPathway AMPA_NMDA_fromPCtoPC_pre;
// AMPA_NMDA_fromPCtoRSI
extern SynapticPathway AMPA_NMDA_fromPCtoRSI_pre;
// GABA_fromFSItoFSI
extern SynapticPathway GABA_fromFSItoFSI_pre;
// GABA_fromFSItoPC
extern SynapticPathway GABA_fromFSItoPC_pre;
// GABA_fromFSItoRSI
extern SynapticPathway GABA_fromFSItoRSI_pre;
// GABA_fromRSItoFSI
extern SynapticPathway GABA_fromRSItoFSI_pre;
// GABA_fromRSItoPC
extern SynapticPathway GABA_fromRSItoPC_pre;
// GABA_fromRSItoRSI
extern SynapticPathway GABA_fromRSItoRSI_pre;
// synapses
extern SynapticPathway synapses_pre;

// Profiling information for each code object
}

void _init_arrays();
void _load_arrays();
void _write_arrays();
void _dealloc_arrays();

#endif


