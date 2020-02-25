#include "objects.h"
#include "code_objects/GABA_fromFSItoPC_pre_initialise_queue.h"
void _run_GABA_fromFSItoPC_pre_initialise_queue() {
	using namespace brian;
        
    double*   _ptr_array_defaultclock_dt = _array_defaultclock_dt;

    std::vector<double> &real_delays = _dynamic_array_GABA_fromFSItoPC_delay;
    double* real_delays_data = real_delays.empty() ? 0 : &(real_delays[0]);
    int32_t* sources = GABA_fromFSItoPC_pre.sources.empty() ? 0 : &(GABA_fromFSItoPC_pre.sources[0]);
    const size_t n_delays = real_delays.size();
    const size_t n_synapses = GABA_fromFSItoPC_pre.sources.size();
    GABA_fromFSItoPC_pre.prepare(50,
                        800,
                        real_delays_data, n_delays, sources,
                        n_synapses,
                        _ptr_array_defaultclock_dt[0]);
}
