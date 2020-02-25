#include "objects.h"
#include "code_objects/GABA_fromRSItoFSI_pre_push_spikes.h"
#include "brianlib/common_math.h"
#include "brianlib/stdint_compat.h"
#include<cmath>
#include<ctime>

void _run_GABA_fromRSItoFSI_pre_push_spikes()
{
    using namespace brian;


    ///// CONSTANTS ///////////
    const size_t _num_spikespace = 151;
    ///// POINTERS ////////////
        
    int32_t* __restrict  _ptr_array_Regular_Spiking_Interneurons__spikespace = _array_Regular_Spiking_Interneurons__spikespace;


    //// MAIN CODE ////////////
    // we do advance at the beginning rather than at the end because it saves us making
    // a copy of the current spiking synapses
    #pragma omp parallel
    {
        GABA_fromRSItoFSI_pre.advance();
        GABA_fromRSItoFSI_pre.push(_ptr_array_Regular_Spiking_Interneurons__spikespace, _ptr_array_Regular_Spiking_Interneurons__spikespace[_num_spikespace-1]);
    }

}
