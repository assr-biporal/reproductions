#include "objects.h"
#include "code_objects/AMPA_NMDA_fromPCtoRSI_pre_initialise_queue.h"
void _run_AMPA_NMDA_fromPCtoRSI_pre_initialise_queue() {
	using namespace brian;
        
    double*   _ptr_array_defaultclock_dt = _array_defaultclock_dt;

    std::vector<double> &real_delays = _dynamic_array_AMPA_NMDA_fromPCtoRSI_delay;
    double* real_delays_data = real_delays.empty() ? 0 : &(real_delays[0]);
    int32_t* sources = AMPA_NMDA_fromPCtoRSI_pre.sources.empty() ? 0 : &(AMPA_NMDA_fromPCtoRSI_pre.sources[0]);
    const size_t n_delays = real_delays.size();
    const size_t n_synapses = AMPA_NMDA_fromPCtoRSI_pre.sources.size();
    AMPA_NMDA_fromPCtoRSI_pre.prepare(800,
                        150,
                        real_delays_data, n_delays, sources,
                        n_synapses,
                        _ptr_array_defaultclock_dt[0]);
}
