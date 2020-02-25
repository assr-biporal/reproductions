#include "objects.h"
#include "code_objects/AMPA_NMDA_fromPCtoRSI_pre_push_spikes.h"
#include "brianlib/common_math.h"
#include "brianlib/stdint_compat.h"
#include<cmath>
#include<ctime>

void _run_AMPA_NMDA_fromPCtoRSI_pre_push_spikes()
{
    using namespace brian;


    ///// CONSTANTS ///////////
    const size_t _num_spikespace = 801;
    ///// POINTERS ////////////
        
    int32_t* __restrict  _ptr_array_Pyramidal_Cells__spikespace = _array_Pyramidal_Cells__spikespace;


    //// MAIN CODE ////////////
    // we do advance at the beginning rather than at the end because it saves us making
    // a copy of the current spiking synapses
    #pragma omp parallel
    {
        AMPA_NMDA_fromPCtoRSI_pre.advance();
        AMPA_NMDA_fromPCtoRSI_pre.push(_ptr_array_Pyramidal_Cells__spikespace, _ptr_array_Pyramidal_Cells__spikespace[_num_spikespace-1]);
    }

}
