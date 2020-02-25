#include "objects.h"
#include "code_objects/Regular_Spiking_Interneurons_stateupdater_codeobject.h"
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



void _run_Regular_Spiking_Interneurons_stateupdater_codeobject()
{
	using namespace brian;


	///// CONSTANTS ///////////
	const size_t _numg_GABA_r = 150;
const size_t _numv = 150;
const size_t _numg_NMDA_r = 150;
const size_t _numg_AMPA_r = 150;
const size_t _numg_NMDA_d = 150;
const size_t _numdt = 1;
const size_t _numg_GABA_d = 150;
const size_t _numg_AMPA_d = 150;
	///// POINTERS ////////////
 	
 double* __restrict  _ptr_array_Regular_Spiking_Interneurons_g_GABA_r = _array_Regular_Spiking_Interneurons_g_GABA_r;
 double* __restrict  _ptr_array_Regular_Spiking_Interneurons_v = _array_Regular_Spiking_Interneurons_v;
 double* __restrict  _ptr_array_Regular_Spiking_Interneurons_g_NMDA_r = _array_Regular_Spiking_Interneurons_g_NMDA_r;
 double* __restrict  _ptr_array_Regular_Spiking_Interneurons_g_AMPA_r = _array_Regular_Spiking_Interneurons_g_AMPA_r;
 double* __restrict  _ptr_array_Regular_Spiking_Interneurons_g_NMDA_d = _array_Regular_Spiking_Interneurons_g_NMDA_d;
 double*   _ptr_array_defaultclock_dt = _array_defaultclock_dt;
 double* __restrict  _ptr_array_Regular_Spiking_Interneurons_g_GABA_d = _array_Regular_Spiking_Interneurons_g_GABA_d;
 double* __restrict  _ptr_array_Regular_Spiking_Interneurons_g_AMPA_d = _array_Regular_Spiking_Interneurons_g_AMPA_d;


	//// MAIN CODE ////////////
	// scalar code
	const size_t _vectorisation_idx = -1;
 	
 const double dt = _ptr_array_defaultclock_dt[0];
 const double _lio_1 = 1.0f*(- dt)/0.002;
 const double _lio_2 = 1.0f*(- dt)/0.0005;
 const double _lio_3 = 1.0f*(- dt)/0.005;
 const double _lio_4 = 1.0f*(- dt)/0.0005;
 const double _lio_5 = 1.0f*(- dt)/0.1;
 const double _lio_6 = 1.0f*(- dt)/0.002;
 const double _lio_7 = 1.0f*1.0/1e-06;
 const double _lio_8 = 1.0f*((- 1e-06) * 1.0)/0.904821;
 const double _lio_9 = - 0.0;
 const double _lio_10 = 1.0f*(- 0.062)/0.001;
 const double _lio_11 = 1.0f*(1e-06 * 1.0)/0.697016;
 const double _lio_12 = - (- 0.07);
 const double _lio_13 = 1.0f*(1e-06 * 1.0)/0.472689;
 const double _lio_14 = 1.0f*1.0/0.02;
 const double _lio_15 = - (- 0.07);


	const int _N = 150;
	#pragma omp parallel for schedule(static)
	for(int _idx=0; _idx<_N; _idx++)
	{
	    // vector code
		const size_t _vectorisation_idx = _idx;
                
        double g_AMPA_r = _ptr_array_Regular_Spiking_Interneurons_g_AMPA_r[_idx];
        double g_NMDA_d = _ptr_array_Regular_Spiking_Interneurons_g_NMDA_d[_idx];
        double g_GABA_r = _ptr_array_Regular_Spiking_Interneurons_g_GABA_r[_idx];
        double v = _ptr_array_Regular_Spiking_Interneurons_v[_idx];
        double g_GABA_d = _ptr_array_Regular_Spiking_Interneurons_g_GABA_d[_idx];
        double g_AMPA_d = _ptr_array_Regular_Spiking_Interneurons_g_AMPA_d[_idx];
        double g_NMDA_r = _ptr_array_Regular_Spiking_Interneurons_g_NMDA_r[_idx];
        const double _g_AMPA_d = (_lio_1 * g_AMPA_d) + g_AMPA_d;
        const double _g_AMPA_r = (_lio_2 * g_AMPA_r) + g_AMPA_r;
        const double _g_GABA_d = (_lio_3 * g_GABA_d) + g_GABA_d;
        const double _g_GABA_r = (_lio_4 * g_GABA_r) + g_GABA_r;
        const double _g_NMDA_d = (_lio_5 * g_NMDA_d) + g_NMDA_d;
        const double _g_NMDA_r = (_lio_6 * g_NMDA_r) + g_NMDA_r;
        const double _v = (dt * ((_lio_7 * ((1.0f*(_lio_8 * ((_lio_9 + v) * (g_NMDA_d - g_NMDA_r)))/(1.0 + (0.280112044817927 * exp(_lio_10 * v)))) - ((_lio_11 * ((_lio_12 + v) * (g_GABA_d - g_GABA_r))) + (_lio_13 * ((_lio_9 + v) * (g_AMPA_d - g_AMPA_r)))))) + (_lio_14 * (_lio_15 + v)))) + v;
        g_AMPA_d = _g_AMPA_d;
        g_AMPA_r = _g_AMPA_r;
        g_GABA_d = _g_GABA_d;
        g_GABA_r = _g_GABA_r;
        g_NMDA_d = _g_NMDA_d;
        g_NMDA_r = _g_NMDA_r;
        v = _v;
        _ptr_array_Regular_Spiking_Interneurons_g_AMPA_r[_idx] = g_AMPA_r;
        _ptr_array_Regular_Spiking_Interneurons_g_NMDA_d[_idx] = g_NMDA_d;
        _ptr_array_Regular_Spiking_Interneurons_g_GABA_r[_idx] = g_GABA_r;
        _ptr_array_Regular_Spiking_Interneurons_v[_idx] = v;
        _ptr_array_Regular_Spiking_Interneurons_g_GABA_d[_idx] = g_GABA_d;
        _ptr_array_Regular_Spiking_Interneurons_g_AMPA_d[_idx] = g_AMPA_d;
        _ptr_array_Regular_Spiking_Interneurons_g_NMDA_r[_idx] = g_NMDA_r;

	}

}


