#include <stdlib.h>
#include "objects.h"
#include <ctime>
#include <time.h>
#include <omp.h>
#include "run.h"
#include "brianlib/common_math.h"
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


#include <iostream>
#include <fstream>


        void report_progress(const double elapsed, const double completed, const double start, const double duration)
        {
            if (completed == 0.0)
            {
                std::cout << "Starting simulation at t=" << start << " s for duration " << duration << " s";
            } else
            {
                std::cout << completed*duration << " s (" << (int)(completed*100.) << "%) simulated in " << elapsed << " s";
                if (completed < 1.0)
                {
                    const int remaining = (int)((1-completed)/completed*elapsed+0.5);
                    std::cout << ", estimated " << remaining << " s remaining.";
                }
            }

            std::cout << std::endl << std::flush;
        }
        


int main(int argc, char **argv)
{
        

	brian_start();
        

	{
		using namespace brian;

		omp_set_dynamic(0);
omp_set_num_threads(12);
                
        _array_defaultclock_dt[0] = 0.0001;
        _array_defaultclock_dt[0] = 0.0001;
        _array_defaultclock_dt[0] = 1e-06;
        
                        #pragma omp for schedule(static)
                        for(int i=0; i<_num__array_Pyramidal_Cells_v; i++)
                        {
                            _array_Pyramidal_Cells_v[i] = - 0.07;
                        }
                        
        
                        #pragma omp for schedule(static)
                        for(int i=0; i<_num__array_Regular_Spiking_Interneurons_v; i++)
                        {
                            _array_Regular_Spiking_Interneurons_v[i] = - 0.07;
                        }
                        
        
                        #pragma omp for schedule(static)
                        for(int i=0; i<_num__array_Fast_Spiking_Interneurons_v; i++)
                        {
                            _array_Fast_Spiking_Interneurons_v[i] = - 0.07;
                        }
                        
        _run_AMPA_NMDA_fromPCtoPC_synapses_create_generator_codeobject();
        _run_AMPA_NMDA_fromPCtoRSI_synapses_create_generator_codeobject();
        _run_AMPA_NMDA_fromPCtoFSI_synapses_create_generator_codeobject();
        _run_GABA_fromRSItoPC_synapses_create_generator_codeobject();
        _run_GABA_fromRSItoRSI_synapses_create_generator_codeobject();
        _run_GABA_fromRSItoFSI_synapses_create_generator_codeobject();
        _run_GABA_fromFSItoPC_synapses_create_generator_codeobject();
        _run_GABA_fromFSItoRSI_synapses_create_generator_codeobject();
        _run_GABA_fromFSItoFSI_synapses_create_generator_codeobject();
        
                        #pragma omp for schedule(static)
                        for(int i=0; i<_num__array_poissongroup_rates; i++)
                        {
                            _array_poissongroup_rates[i] = 100.0;
                        }
                        
        _run_synapses_synapses_create_generator_codeobject();
        
                        #pragma omp for schedule(static)
                        for(int i=0; i<_num__array_statemonitor__indices; i++)
                        {
                            _array_statemonitor__indices[i] = _static_array__array_statemonitor__indices[i];
                        }
                        
        
                        #pragma omp for schedule(static)
                        for(int i=0; i<_num__array_statemonitor_1__indices; i++)
                        {
                            _array_statemonitor_1__indices[i] = _static_array__array_statemonitor_1__indices[i];
                        }
                        
        
                        #pragma omp for schedule(static)
                        for(int i=0; i<_num__array_statemonitor_2__indices; i++)
                        {
                            _array_statemonitor_2__indices[i] = _static_array__array_statemonitor_2__indices[i];
                        }
                        
        
                        #pragma omp for schedule(static)
                        for(int i=0; i<_num__array_statemonitor_3__indices; i++)
                        {
                            _array_statemonitor_3__indices[i] = _static_array__array_statemonitor_3__indices[i];
                        }
                        
        
                        #pragma omp for schedule(static)
                        for(int i=0; i<_num__array_statemonitor_4__indices; i++)
                        {
                            _array_statemonitor_4__indices[i] = _static_array__array_statemonitor_4__indices[i];
                        }
                        
        
                        #pragma omp for schedule(static)
                        for(int i=0; i<_num__array_statemonitor_5__indices; i++)
                        {
                            _array_statemonitor_5__indices[i] = _static_array__array_statemonitor_5__indices[i];
                        }
                        
        
                        #pragma omp for schedule(static)
                        for(int i=0; i<_num__array_statemonitor_6__indices; i++)
                        {
                            _array_statemonitor_6__indices[i] = _static_array__array_statemonitor_6__indices[i];
                        }
                        
        
                        #pragma omp for schedule(static)
                        for(int i=0; i<_num__array_statemonitor_7__indices; i++)
                        {
                            _array_statemonitor_7__indices[i] = _static_array__array_statemonitor_7__indices[i];
                        }
                        
        
                        #pragma omp for schedule(static)
                        for(int i=0; i<_num__array_statemonitor_8__indices; i++)
                        {
                            _array_statemonitor_8__indices[i] = _static_array__array_statemonitor_8__indices[i];
                        }
                        
        
                        #pragma omp for schedule(static)
                        for(int i=0; i<_num__array_statemonitor_9__indices; i++)
                        {
                            _array_statemonitor_9__indices[i] = _static_array__array_statemonitor_9__indices[i];
                        }
                        
        
                        #pragma omp for schedule(static)
                        for(int i=0; i<_num__array_statemonitor_10__indices; i++)
                        {
                            _array_statemonitor_10__indices[i] = _static_array__array_statemonitor_10__indices[i];
                        }
                        
        
                        #pragma omp for schedule(static)
                        for(int i=0; i<_num__array_statemonitor_11__indices; i++)
                        {
                            _array_statemonitor_11__indices[i] = _static_array__array_statemonitor_11__indices[i];
                        }
                        
        
                        #pragma omp for schedule(static)
                        for(int i=0; i<_num__array_statemonitor_12__indices; i++)
                        {
                            _array_statemonitor_12__indices[i] = _static_array__array_statemonitor_12__indices[i];
                        }
                        
        
                        #pragma omp for schedule(static)
                        for(int i=0; i<_num__array_statemonitor_13__indices; i++)
                        {
                            _array_statemonitor_13__indices[i] = _static_array__array_statemonitor_13__indices[i];
                        }
                        
        
                        #pragma omp for schedule(static)
                        for(int i=0; i<_num__array_statemonitor_14__indices; i++)
                        {
                            _array_statemonitor_14__indices[i] = _static_array__array_statemonitor_14__indices[i];
                        }
                        
        _array_defaultclock_timestep[0] = 0;
        _array_defaultclock_t[0] = 0.0;
        _run_AMPA_NMDA_fromPCtoFSI_pre_initialise_queue();
        _run_AMPA_NMDA_fromPCtoPC_pre_initialise_queue();
        _run_AMPA_NMDA_fromPCtoRSI_pre_initialise_queue();
        _run_GABA_fromFSItoFSI_pre_initialise_queue();
        _run_GABA_fromFSItoPC_pre_initialise_queue();
        _run_GABA_fromFSItoRSI_pre_initialise_queue();
        _run_GABA_fromRSItoFSI_pre_initialise_queue();
        _run_GABA_fromRSItoPC_pre_initialise_queue();
        _run_GABA_fromRSItoRSI_pre_initialise_queue();
        _run_synapses_pre_initialise_queue();
        network.clear();
        network.add(&defaultclock, _run_statemonitor_codeobject);
        network.add(&defaultclock, _run_statemonitor_1_codeobject);
        network.add(&defaultclock, _run_statemonitor_12_codeobject);
        network.add(&defaultclock, _run_statemonitor_13_codeobject);
        network.add(&defaultclock, _run_statemonitor_14_codeobject);
        network.add(&defaultclock, _run_statemonitor_2_codeobject);
        network.add(&defaultclock, _run_statemonitor_3_codeobject);
        network.add(&defaultclock, _run_statemonitor_4_codeobject);
        network.add(&defaultclock, _run_statemonitor_5_codeobject);
        network.add(&defaultclock, _run_Fast_Spiking_Interneurons_stateupdater_codeobject);
        network.add(&defaultclock, _run_Pyramidal_Cells_stateupdater_codeobject);
        network.add(&defaultclock, _run_Regular_Spiking_Interneurons_stateupdater_codeobject);
        network.add(&defaultclock, _run_Fast_Spiking_Interneurons_thresholder_codeobject);
        network.add(&defaultclock, _run_Pyramidal_Cells_thresholder_codeobject);
        network.add(&defaultclock, _run_Regular_Spiking_Interneurons_thresholder_codeobject);
        network.add(&defaultclock, _run_poissongroup_thresholder_codeobject);
        network.add(&defaultclock, _run_spikemonitor_codeobject);
        network.add(&defaultclock, _run_spikemonitor_1_codeobject);
        network.add(&defaultclock, _run_spikemonitor_2_codeobject);
        network.add(&defaultclock, _run_spikemonitor_3_codeobject);
        network.add(&defaultclock, _run_AMPA_NMDA_fromPCtoFSI_pre_push_spikes);
        network.add(&defaultclock, _run_AMPA_NMDA_fromPCtoFSI_pre_codeobject);
        network.add(&defaultclock, _run_AMPA_NMDA_fromPCtoPC_pre_push_spikes);
        network.add(&defaultclock, _run_AMPA_NMDA_fromPCtoPC_pre_codeobject);
        network.add(&defaultclock, _run_AMPA_NMDA_fromPCtoRSI_pre_push_spikes);
        network.add(&defaultclock, _run_AMPA_NMDA_fromPCtoRSI_pre_codeobject);
        network.add(&defaultclock, _run_GABA_fromFSItoFSI_pre_push_spikes);
        network.add(&defaultclock, _run_GABA_fromFSItoFSI_pre_codeobject);
        network.add(&defaultclock, _run_GABA_fromFSItoPC_pre_push_spikes);
        network.add(&defaultclock, _run_GABA_fromFSItoPC_pre_codeobject);
        network.add(&defaultclock, _run_GABA_fromFSItoRSI_pre_push_spikes);
        network.add(&defaultclock, _run_GABA_fromFSItoRSI_pre_codeobject);
        network.add(&defaultclock, _run_GABA_fromRSItoFSI_pre_push_spikes);
        network.add(&defaultclock, _run_GABA_fromRSItoFSI_pre_codeobject);
        network.add(&defaultclock, _run_GABA_fromRSItoPC_pre_push_spikes);
        network.add(&defaultclock, _run_GABA_fromRSItoPC_pre_codeobject);
        network.add(&defaultclock, _run_GABA_fromRSItoRSI_pre_push_spikes);
        network.add(&defaultclock, _run_GABA_fromRSItoRSI_pre_codeobject);
        network.add(&defaultclock, _run_synapses_pre_push_spikes);
        network.add(&defaultclock, _run_synapses_pre_codeobject);
        network.add(&defaultclock, _run_Fast_Spiking_Interneurons_resetter_codeobject);
        network.add(&defaultclock, _run_Pyramidal_Cells_resetter_codeobject);
        network.add(&defaultclock, _run_Regular_Spiking_Interneurons_resetter_codeobject);
        network.run(1.0, report_progress, 10.0);
        #ifdef DEBUG
        _debugmsg_spikemonitor_codeobject();
        #endif
        
        #ifdef DEBUG
        _debugmsg_spikemonitor_1_codeobject();
        #endif
        
        #ifdef DEBUG
        _debugmsg_spikemonitor_2_codeobject();
        #endif
        
        #ifdef DEBUG
        _debugmsg_spikemonitor_3_codeobject();
        #endif
        
        #ifdef DEBUG
        _debugmsg_AMPA_NMDA_fromPCtoFSI_pre_codeobject();
        #endif
        
        #ifdef DEBUG
        _debugmsg_AMPA_NMDA_fromPCtoPC_pre_codeobject();
        #endif
        
        #ifdef DEBUG
        _debugmsg_AMPA_NMDA_fromPCtoRSI_pre_codeobject();
        #endif
        
        #ifdef DEBUG
        _debugmsg_GABA_fromFSItoFSI_pre_codeobject();
        #endif
        
        #ifdef DEBUG
        _debugmsg_GABA_fromFSItoPC_pre_codeobject();
        #endif
        
        #ifdef DEBUG
        _debugmsg_GABA_fromFSItoRSI_pre_codeobject();
        #endif
        
        #ifdef DEBUG
        _debugmsg_GABA_fromRSItoFSI_pre_codeobject();
        #endif
        
        #ifdef DEBUG
        _debugmsg_GABA_fromRSItoPC_pre_codeobject();
        #endif
        
        #ifdef DEBUG
        _debugmsg_GABA_fromRSItoRSI_pre_codeobject();
        #endif
        
        #ifdef DEBUG
        _debugmsg_synapses_pre_codeobject();
        #endif

	}
        

	brian_end();
        

	return 0;
}