#include "objects.h"
#include "code_objects/statemonitor_12_codeobject.h"
#include "brianlib/common_math.h"
#include "brianlib/stdint_compat.h"
#include<cmath>
#include<ctime>
#include<iostream>
#include<fstream>
#include<climits>

////// SUPPORT CODE ///////
namespace {
 	
 template < typename T1, typename T2 > struct _higher_type;
 template < > struct _higher_type<int,int> { typedef int type; };
 template < > struct _higher_type<int,long> { typedef long type; };
 template < > struct _higher_type<int,long long> { typedef long long type; };
 template < > struct _higher_type<int,float> { typedef float type; };
 template < > struct _higher_type<int,double> { typedef double type; };
 template < > struct _higher_type<int,long double> { typedef long double type; };
 template < > struct _higher_type<long,int> { typedef long type; };
 template < > struct _higher_type<long,long> { typedef long type; };
 template < > struct _higher_type<long,long long> { typedef long long type; };
 template < > struct _higher_type<long,float> { typedef float type; };
 template < > struct _higher_type<long,double> { typedef double type; };
 template < > struct _higher_type<long,long double> { typedef long double type; };
 template < > struct _higher_type<long long,int> { typedef long long type; };
 template < > struct _higher_type<long long,long> { typedef long long type; };
 template < > struct _higher_type<long long,long long> { typedef long long type; };
 template < > struct _higher_type<long long,float> { typedef float type; };
 template < > struct _higher_type<long long,double> { typedef double type; };
 template < > struct _higher_type<long long,long double> { typedef long double type; };
 template < > struct _higher_type<float,int> { typedef float type; };
 template < > struct _higher_type<float,long> { typedef float type; };
 template < > struct _higher_type<float,long long> { typedef float type; };
 template < > struct _higher_type<float,float> { typedef float type; };
 template < > struct _higher_type<float,double> { typedef double type; };
 template < > struct _higher_type<float,long double> { typedef long double type; };
 template < > struct _higher_type<double,int> { typedef double type; };
 template < > struct _higher_type<double,long> { typedef double type; };
 template < > struct _higher_type<double,long long> { typedef double type; };
 template < > struct _higher_type<double,float> { typedef double type; };
 template < > struct _higher_type<double,double> { typedef double type; };
 template < > struct _higher_type<double,long double> { typedef long double type; };
 template < > struct _higher_type<long double,int> { typedef long double type; };
 template < > struct _higher_type<long double,long> { typedef long double type; };
 template < > struct _higher_type<long double,long long> { typedef long double type; };
 template < > struct _higher_type<long double,float> { typedef long double type; };
 template < > struct _higher_type<long double,double> { typedef long double type; };
 template < > struct _higher_type<long double,long double> { typedef long double type; };
 template < typename T1, typename T2 >
 static inline typename _higher_type<T1,T2>::type
 _brian_mod(T1 x, T2 y)
 {{
     return x-y*floor(1.0*x/y);
 }}
 template < typename T1, typename T2 >
 static inline typename _higher_type<T1,T2>::type
 _brian_floordiv(T1 x, T2 y)
 {{
     return floor(1.0*x/y);
 }}
 #ifdef _MSC_VER
 #define _brian_pow(x, y) (pow((double)(x), (y)))
 #else
 #define _brian_pow(x, y) (pow((x), (y)))
 #endif

}

////// HASH DEFINES ///////



void _run_statemonitor_12_codeobject()
{
	using namespace brian;


	///// CONSTANTS ///////////
	const size_t _num___source_I_syn_Pyramidal_Cells_I_AMPA_Pyramidal_Cells_v = 800;
const size_t _num___source_I_GABA_Pyramidal_Cells_g_GABA_Pyramidal_Cells_g_GABA_r = 800;
double* const _array_statemonitor_12_t = _dynamic_array_statemonitor_12_t.empty()? 0 : &_dynamic_array_statemonitor_12_t[0];
const size_t _numt = _dynamic_array_statemonitor_12_t.size();
const size_t _num_clock_t = 1;
const size_t _num__source_I_NMDA_Pyramidal_Cells_v = 800;
const size_t _num_indices = 10;
const size_t _num__source_I_GABA_Pyramidal_Cells_v = 800;
const size_t _num____source_I_syn_Pyramidal_Cells_I_NMDA_Pyramidal_Cells_g_NMDA_Pyramidal_Cells_g_NMDA_d = 800;
const size_t _num___source_I_NMDA_Pyramidal_Cells_g_NMDA_Pyramidal_Cells_g_NMDA_d = 800;
const size_t _num____source_I_syn_Pyramidal_Cells_I_AMPA_Pyramidal_Cells_g_AMPA_Pyramidal_Cells_g_AMPA_d = 800;
const size_t _num___source_I_NMDA_Pyramidal_Cells_g_NMDA_Pyramidal_Cells_g_NMDA_r = 800;
const size_t _num___source_I_AMPA_Pyramidal_Cells_g_AMPA_Pyramidal_Cells_g_AMPA_d = 800;
const size_t _num____source_I_syn_Pyramidal_Cells_I_GABA_Pyramidal_Cells_g_GABA_Pyramidal_Cells_g_GABA_r = 800;
const size_t _num____source_I_syn_Pyramidal_Cells_I_NMDA_Pyramidal_Cells_g_NMDA_Pyramidal_Cells_g_NMDA_r = 800;
const size_t _numN = 1;
const size_t _num___source_I_syn_Pyramidal_Cells_I_NMDA_Pyramidal_Cells_v = 800;
const size_t _num____source_I_syn_Pyramidal_Cells_I_AMPA_Pyramidal_Cells_g_AMPA_Pyramidal_Cells_g_AMPA_r = 800;
const size_t _num____source_I_syn_Pyramidal_Cells_I_GABA_Pyramidal_Cells_g_GABA_Pyramidal_Cells_g_GABA_d = 800;
const size_t _num___source_I_AMPA_Pyramidal_Cells_g_AMPA_Pyramidal_Cells_g_AMPA_r = 800;
const size_t _num___source_I_syn_Pyramidal_Cells_I_GABA_Pyramidal_Cells_v = 800;
const size_t _num__source_I_AMPA_Pyramidal_Cells_v = 800;
const size_t _num___source_I_GABA_Pyramidal_Cells_g_GABA_Pyramidal_Cells_g_GABA_d = 800;
	///// POINTERS ////////////
 	
 double* __restrict  _ptr_array_Pyramidal_Cells_v = _array_Pyramidal_Cells_v;
 double* __restrict  _ptr_array_Pyramidal_Cells_g_GABA_r = _array_Pyramidal_Cells_g_GABA_r;
 double* __restrict  _ptr_array_statemonitor_12_t = _array_statemonitor_12_t;
 double*   _ptr_array_defaultclock_t = _array_defaultclock_t;
 int32_t* __restrict  _ptr_array_statemonitor_12__indices = _array_statemonitor_12__indices;
 double* __restrict  _ptr_array_Pyramidal_Cells_g_NMDA_d = _array_Pyramidal_Cells_g_NMDA_d;
 double* __restrict  _ptr_array_Pyramidal_Cells_g_AMPA_d = _array_Pyramidal_Cells_g_AMPA_d;
 double* __restrict  _ptr_array_Pyramidal_Cells_g_NMDA_r = _array_Pyramidal_Cells_g_NMDA_r;
 int32_t*   _ptr_array_statemonitor_12_N = _array_statemonitor_12_N;
 double* __restrict  _ptr_array_Pyramidal_Cells_g_AMPA_r = _array_Pyramidal_Cells_g_AMPA_r;
 double* __restrict  _ptr_array_Pyramidal_Cells_g_GABA_d = _array_Pyramidal_Cells_g_GABA_d;


    _dynamic_array_statemonitor_12_t.push_back(_ptr_array_defaultclock_t[0]);

    const size_t _new_size = _dynamic_array_statemonitor_12_t.size();
    // Resize the dynamic arrays
    _dynamic_array_statemonitor_12_I_AMPA.resize(_new_size, _num_indices);
    _dynamic_array_statemonitor_12_I_GABA.resize(_new_size, _num_indices);
    _dynamic_array_statemonitor_12_I_NMDA.resize(_new_size, _num_indices);
    _dynamic_array_statemonitor_12_I_syn.resize(_new_size, _num_indices);

    // scalar code
    const size_t _vectorisation_idx = -1;
        
    const double _lio_1 = 1.0f*1.0/0.697016;
    const double _lio_2 = 1.0f*1.0/0.904821;
    const double _lio_3 = 1.0f*1.0/0.472689;
    const double _lio_4 = - 1.0;
    const double _lio_5 = 0.0 - (- 0.07);
    const double _lio_6 = - 1.0;
    const double _lio_7 = 0.0 - 0.0;
    const double _lio_8 = 1.0f*(- 0.062)/0.001;
    const double _lio_9 = - 1.0;


    #pragma omp parallel for schedule(static)
    for (int _i = 0; _i < (int)_num_indices; _i++)
    {
        // vector code
        const size_t _idx = _ptr_array_statemonitor_12__indices[_i];
        const size_t _vectorisation_idx = _idx;
                                        
                    const double ___source_I_syn_Pyramidal_Cells_I_AMPA_Pyramidal_Cells_v = _ptr_array_Pyramidal_Cells_v[_idx];
                    const double __source_I_GABA_Pyramidal_Cells_v = _ptr_array_Pyramidal_Cells_v[_idx];
                    const double ____source_I_syn_Pyramidal_Cells_I_NMDA_Pyramidal_Cells_g_NMDA_Pyramidal_Cells_g_NMDA_d = _ptr_array_Pyramidal_Cells_g_NMDA_d[_idx];
                    const double ____source_I_syn_Pyramidal_Cells_I_NMDA_Pyramidal_Cells_g_NMDA_Pyramidal_Cells_g_NMDA_r = _ptr_array_Pyramidal_Cells_g_NMDA_r[_idx];
                    const double ___source_I_syn_Pyramidal_Cells_I_NMDA_Pyramidal_Cells_v = _ptr_array_Pyramidal_Cells_v[_idx];
                    const double ___source_I_GABA_Pyramidal_Cells_g_GABA_Pyramidal_Cells_g_GABA_r = _ptr_array_Pyramidal_Cells_g_GABA_r[_idx];
                    const double ___source_I_NMDA_Pyramidal_Cells_g_NMDA_Pyramidal_Cells_g_NMDA_d = _ptr_array_Pyramidal_Cells_g_NMDA_d[_idx];
                    const double ____source_I_syn_Pyramidal_Cells_I_AMPA_Pyramidal_Cells_g_AMPA_Pyramidal_Cells_g_AMPA_d = _ptr_array_Pyramidal_Cells_g_AMPA_d[_idx];
                    const double ___source_I_NMDA_Pyramidal_Cells_g_NMDA_Pyramidal_Cells_g_NMDA_r = _ptr_array_Pyramidal_Cells_g_NMDA_r[_idx];
                    const double ____source_I_syn_Pyramidal_Cells_I_GABA_Pyramidal_Cells_g_GABA_Pyramidal_Cells_g_GABA_d = _ptr_array_Pyramidal_Cells_g_GABA_d[_idx];
                    const double ___source_I_AMPA_Pyramidal_Cells_g_AMPA_Pyramidal_Cells_g_AMPA_r = _ptr_array_Pyramidal_Cells_g_AMPA_r[_idx];
                    const double ____source_I_syn_Pyramidal_Cells_I_AMPA_Pyramidal_Cells_g_AMPA_Pyramidal_Cells_g_AMPA_r = _ptr_array_Pyramidal_Cells_g_AMPA_r[_idx];
                    const double ___source_I_syn_Pyramidal_Cells_I_GABA_Pyramidal_Cells_v = _ptr_array_Pyramidal_Cells_v[_idx];
                    const double __source_I_AMPA_Pyramidal_Cells_v = _ptr_array_Pyramidal_Cells_v[_idx];
                    const double __source_I_NMDA_Pyramidal_Cells_v = _ptr_array_Pyramidal_Cells_v[_idx];
                    const double ____source_I_syn_Pyramidal_Cells_I_GABA_Pyramidal_Cells_g_GABA_Pyramidal_Cells_g_GABA_r = _ptr_array_Pyramidal_Cells_g_GABA_r[_idx];
                    const double ___source_I_GABA_Pyramidal_Cells_g_GABA_Pyramidal_Cells_g_GABA_d = _ptr_array_Pyramidal_Cells_g_GABA_d[_idx];
                    const double ___source_I_AMPA_Pyramidal_Cells_g_AMPA_Pyramidal_Cells_g_AMPA_d = _ptr_array_Pyramidal_Cells_g_AMPA_d[_idx];
                    const double ___source_I_syn_Pyramidal_Cells_I_GABA_Pyramidal_Cells_g_GABA = _lio_1 * (____source_I_syn_Pyramidal_Cells_I_GABA_Pyramidal_Cells_g_GABA_Pyramidal_Cells_g_GABA_d - ____source_I_syn_Pyramidal_Cells_I_GABA_Pyramidal_Cells_g_GABA_Pyramidal_Cells_g_GABA_r);
                    const double ___source_I_syn_Pyramidal_Cells_I_NMDA_Pyramidal_Cells_g_NMDA = _lio_2 * (____source_I_syn_Pyramidal_Cells_I_NMDA_Pyramidal_Cells_g_NMDA_Pyramidal_Cells_g_NMDA_d - ____source_I_syn_Pyramidal_Cells_I_NMDA_Pyramidal_Cells_g_NMDA_Pyramidal_Cells_g_NMDA_r);
                    const double ___source_I_syn_Pyramidal_Cells_I_AMPA_Pyramidal_Cells_g_AMPA = _lio_3 * (____source_I_syn_Pyramidal_Cells_I_AMPA_Pyramidal_Cells_g_AMPA_Pyramidal_Cells_g_AMPA_d - ____source_I_syn_Pyramidal_Cells_I_AMPA_Pyramidal_Cells_g_AMPA_Pyramidal_Cells_g_AMPA_r);
                    const double __source_I_syn_Pyramidal_Cells_I_GABA = _lio_4 * (___source_I_syn_Pyramidal_Cells_I_GABA_Pyramidal_Cells_g_GABA * (_lio_5 + ___source_I_syn_Pyramidal_Cells_I_GABA_Pyramidal_Cells_v));
                    const double __source_I_syn_Pyramidal_Cells_I_NMDA = 1.0f*(_lio_6 * (___source_I_syn_Pyramidal_Cells_I_NMDA_Pyramidal_Cells_g_NMDA * (_lio_7 + ___source_I_syn_Pyramidal_Cells_I_NMDA_Pyramidal_Cells_v)))/(1.0 + (0.2801120448179272 * exp(_lio_8 * ___source_I_syn_Pyramidal_Cells_I_NMDA_Pyramidal_Cells_v)));
                    const double __source_I_syn_Pyramidal_Cells_I_AMPA = _lio_9 * (___source_I_syn_Pyramidal_Cells_I_AMPA_Pyramidal_Cells_g_AMPA * (_lio_7 + ___source_I_syn_Pyramidal_Cells_I_AMPA_Pyramidal_Cells_v));
                    const double _source_I_syn = (__source_I_syn_Pyramidal_Cells_I_AMPA + __source_I_syn_Pyramidal_Cells_I_NMDA) + __source_I_syn_Pyramidal_Cells_I_GABA;
                    const double _to_record_I_syn = _source_I_syn;
                    const double __source_I_AMPA_Pyramidal_Cells_g_AMPA = _lio_3 * (___source_I_AMPA_Pyramidal_Cells_g_AMPA_Pyramidal_Cells_g_AMPA_d - ___source_I_AMPA_Pyramidal_Cells_g_AMPA_Pyramidal_Cells_g_AMPA_r);
                    const double _source_I_AMPA = _lio_9 * (__source_I_AMPA_Pyramidal_Cells_g_AMPA * (_lio_7 + __source_I_AMPA_Pyramidal_Cells_v));
                    const double _to_record_I_AMPA = _source_I_AMPA;
                    const double __source_I_NMDA_Pyramidal_Cells_g_NMDA = _lio_2 * (___source_I_NMDA_Pyramidal_Cells_g_NMDA_Pyramidal_Cells_g_NMDA_d - ___source_I_NMDA_Pyramidal_Cells_g_NMDA_Pyramidal_Cells_g_NMDA_r);
                    const double _source_I_NMDA = 1.0f*(_lio_6 * (__source_I_NMDA_Pyramidal_Cells_g_NMDA * (_lio_7 + __source_I_NMDA_Pyramidal_Cells_v)))/(1.0 + (0.2801120448179272 * exp(_lio_8 * __source_I_NMDA_Pyramidal_Cells_v)));
                    const double _to_record_I_NMDA = _source_I_NMDA;
                    const double __source_I_GABA_Pyramidal_Cells_g_GABA = _lio_1 * (___source_I_GABA_Pyramidal_Cells_g_GABA_Pyramidal_Cells_g_GABA_d - ___source_I_GABA_Pyramidal_Cells_g_GABA_Pyramidal_Cells_g_GABA_r);
                    const double _source_I_GABA = _lio_4 * (__source_I_GABA_Pyramidal_Cells_g_GABA * (_lio_5 + __source_I_GABA_Pyramidal_Cells_v));
                    const double _to_record_I_GABA = _source_I_GABA;



            _dynamic_array_statemonitor_12_I_AMPA(_new_size-1, _i) = _to_record_I_AMPA;
            _dynamic_array_statemonitor_12_I_GABA(_new_size-1, _i) = _to_record_I_GABA;
            _dynamic_array_statemonitor_12_I_NMDA(_new_size-1, _i) = _to_record_I_NMDA;
            _dynamic_array_statemonitor_12_I_syn(_new_size-1, _i) = _to_record_I_syn;
    }

    _ptr_array_statemonitor_12_N[0] = _new_size;


}


