#include<stdlib.h>
#include "objects.h"
#include<ctime>
#include "randomkit.h"

#include "code_objects/AMPA_NMDA_fromPCtoFSI_pre_codeobject.h"
#include "code_objects/AMPA_NMDA_fromPCtoFSI_pre_initialise_queue.h"
#include "code_objects/AMPA_NMDA_fromPCtoFSI_pre_push_spikes.h"
#include "code_objects/AMPA_NMDA_fromPCtoFSI_synapses_create_generator_codeobject.h"
#include "code_objects/AMPA_NMDA_fromPCtoPC_pre_codeobject.h"
#include "code_objects/AMPA_NMDA_fromPCtoPC_pre_initialise_queue.h"
#include "code_objects/AMPA_NMDA_fromPCtoPC_pre_push_spikes.h"
#include "code_objects/AMPA_NMDA_fromPCtoPC_synapses_create_generator_codeobject.h"
#include "code_objects/AMPA_NMDA_fromPCtoRSI_pre_codeobject.h"
#include "code_objects/AMPA_NMDA_fromPCtoRSI_pre_initialise_queue.h"
#include "code_objects/AMPA_NMDA_fromPCtoRSI_pre_push_spikes.h"
#include "code_objects/AMPA_NMDA_fromPCtoRSI_synapses_create_generator_codeobject.h"
#include "code_objects/Fast_Spiking_Interneurons_resetter_codeobject.h"
#include "code_objects/Fast_Spiking_Interneurons_stateupdater_codeobject.h"
#include "code_objects/Fast_Spiking_Interneurons_thresholder_codeobject.h"
#include "code_objects/GABA_fromFSItoFSI_pre_codeobject.h"
#include "code_objects/GABA_fromFSItoFSI_pre_initialise_queue.h"
#include "code_objects/GABA_fromFSItoFSI_pre_push_spikes.h"
#include "code_objects/GABA_fromFSItoFSI_synapses_create_generator_codeobject.h"
#include "code_objects/GABA_fromFSItoPC_pre_codeobject.h"
#include "code_objects/GABA_fromFSItoPC_pre_initialise_queue.h"
#include "code_objects/GABA_fromFSItoPC_pre_push_spikes.h"
#include "code_objects/GABA_fromFSItoPC_synapses_create_generator_codeobject.h"
#include "code_objects/GABA_fromFSItoRSI_pre_codeobject.h"
#include "code_objects/GABA_fromFSItoRSI_pre_initialise_queue.h"
#include "code_objects/GABA_fromFSItoRSI_pre_push_spikes.h"
#include "code_objects/GABA_fromFSItoRSI_synapses_create_generator_codeobject.h"
#include "code_objects/GABA_fromRSItoFSI_pre_codeobject.h"
#include "code_objects/GABA_fromRSItoFSI_pre_initialise_queue.h"
#include "code_objects/GABA_fromRSItoFSI_pre_push_spikes.h"
#include "code_objects/GABA_fromRSItoFSI_synapses_create_generator_codeobject.h"
#include "code_objects/GABA_fromRSItoPC_pre_codeobject.h"
#include "code_objects/GABA_fromRSItoPC_pre_initialise_queue.h"
#include "code_objects/GABA_fromRSItoPC_pre_push_spikes.h"
#include "code_objects/GABA_fromRSItoPC_synapses_create_generator_codeobject.h"
#include "code_objects/GABA_fromRSItoRSI_pre_codeobject.h"
#include "code_objects/GABA_fromRSItoRSI_pre_initialise_queue.h"
#include "code_objects/GABA_fromRSItoRSI_pre_push_spikes.h"
#include "code_objects/GABA_fromRSItoRSI_synapses_create_generator_codeobject.h"
#include "code_objects/poissongroup_thresholder_codeobject.h"
#include "code_objects/Pyramidal_Cells_resetter_codeobject.h"
#include "code_objects/Pyramidal_Cells_stateupdater_codeobject.h"
#include "code_objects/Pyramidal_Cells_thresholder_codeobject.h"
#include "code_objects/Regular_Spiking_Interneurons_resetter_codeobject.h"
#include "code_objects/Regular_Spiking_Interneurons_stateupdater_codeobject.h"
#include "code_objects/Regular_Spiking_Interneurons_thresholder_codeobject.h"
#include "code_objects/spikemonitor_1_codeobject.h"
#include "code_objects/spikemonitor_2_codeobject.h"
#include "code_objects/spikemonitor_3_codeobject.h"
#include "code_objects/spikemonitor_codeobject.h"
#include "code_objects/statemonitor_12_codeobject.h"
#include "code_objects/statemonitor_13_codeobject.h"
#include "code_objects/statemonitor_14_codeobject.h"
#include "code_objects/statemonitor_1_codeobject.h"
#include "code_objects/statemonitor_2_codeobject.h"
#include "code_objects/statemonitor_3_codeobject.h"
#include "code_objects/statemonitor_4_codeobject.h"
#include "code_objects/statemonitor_5_codeobject.h"
#include "code_objects/statemonitor_codeobject.h"
#include "code_objects/synapses_pre_codeobject.h"
#include "code_objects/synapses_pre_initialise_queue.h"
#include "code_objects/synapses_pre_push_spikes.h"
#include "code_objects/synapses_synapses_create_generator_codeobject.h"


void brian_start()
{
	_init_arrays();
	_load_arrays();
	// Initialize clocks (link timestep and dt to the respective arrays)
    brian::defaultclock.timestep = brian::_array_defaultclock_timestep;
    brian::defaultclock.dt = brian::_array_defaultclock_dt;
    brian::defaultclock.t = brian::_array_defaultclock_t;
    for (int i=0; i<12; i++)
	    rk_randomseed(brian::_mersenne_twister_states[i]);  // Note that this seed can be potentially replaced in main.cpp
}

void brian_end()
{
	_write_arrays();
	_dealloc_arrays();
}


