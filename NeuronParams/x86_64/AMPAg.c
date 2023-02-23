/* Created by Language version: 7.7.0 */
/* VECTORIZED */
#define NRN_VECTORIZED 1
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "scoplib.h"
#undef PI
#define nil 0
#include "md1redef.h"
#include "section.h"
#include "nrniv_mf.h"
#include "md2redef.h"
 
#if METHOD3
extern int _method3;
#endif

#if !NRNGPU
#undef exp
#define exp hoc_Exp
extern double hoc_Exp(double);
#endif
 
#define nrn_init _nrn_init__AMPAg
#define _nrn_initial _nrn_initial__AMPAg
#define nrn_cur _nrn_cur__AMPAg
#define _nrn_current _nrn_current__AMPAg
#define nrn_jacob _nrn_jacob__AMPAg
#define nrn_state _nrn_state__AMPAg
#define _net_receive _net_receive__AMPAg 
 
#define _threadargscomma_ _p, _ppvar, _thread, _nt,
#define _threadargsprotocomma_ double* _p, Datum* _ppvar, Datum* _thread, NrnThread* _nt,
#define _threadargs_ _p, _ppvar, _thread, _nt
#define _threadargsproto_ double* _p, Datum* _ppvar, Datum* _thread, NrnThread* _nt
 	/*SUPPRESS 761*/
	/*SUPPRESS 762*/
	/*SUPPRESS 763*/
	/*SUPPRESS 765*/
	 extern double *getarg();
 /* Thread safe. No static _p or _ppvar. */
 
#define t _nt->_t
#define dt _nt->_dt
#define onset _p[0]
#define tau0 _p[1]
#define tau1 _p[2]
#define gmax _p[3]
#define e _p[4]
#define i _p[5]
#define g _p[6]
#define factor _p[7]
#define a0 _p[8]
#define a1 _p[9]
#define v _p[10]
#define _g _p[11]
#define _nd_area  *_ppvar[0]._pval
 
#if MAC
#if !defined(v)
#define v _mlhv
#endif
#if !defined(h)
#define h _mlhh
#endif
#endif
 
#if defined(__cplusplus)
extern "C" {
#endif
 static int hoc_nrnpointerindex =  -1;
 static Datum* _extcall_thread;
 static Prop* _extcall_prop;
 /* external NEURON variables */
 /* declaration of user functions */
 static double _hoc_cond(void*);
 static int _mechtype;
extern void _nrn_cacheloop_reg(int, int);
extern void hoc_register_prop_size(int, int, int);
extern void hoc_register_limits(int, HocParmLimits*);
extern void hoc_register_units(int, HocParmUnits*);
extern void nrn_promote(Prop*, int, int);
extern Memb_func* memb_func;
 
#define NMODL_TEXT 1
#if NMODL_TEXT
static const char* nmodl_file_text;
static const char* nmodl_filename;
extern void hoc_reg_nmodl_text(int, const char*);
extern void hoc_reg_nmodl_filename(int, const char*);
#endif

 extern Prop* nrn_point_prop_;
 static int _pointtype;
 static void* _hoc_create_pnt(Object* _ho) { void* create_point_process(int, Object*);
 return create_point_process(_pointtype, _ho);
}
 static void _hoc_destroy_pnt(void*);
 static double _hoc_loc_pnt(void* _vptr) {double loc_point_process(int, void*);
 return loc_point_process(_pointtype, _vptr);
}
 static double _hoc_has_loc(void* _vptr) {double has_loc_point(void*);
 return has_loc_point(_vptr);
}
 static double _hoc_get_loc_pnt(void* _vptr) {
 double get_loc_point_process(void*); return (get_loc_point_process(_vptr));
}
 extern void _nrn_setdata_reg(int, void(*)(Prop*));
 static void _setdata(Prop* _prop) {
 _extcall_prop = _prop;
 }
 static void _hoc_setdata(void* _vptr) { Prop* _prop;
 _prop = ((Point_process*)_vptr)->_prop;
   _setdata(_prop);
 }
 /* connect user functions to hoc names */
 static VoidFunc hoc_intfunc[] = {
 0,0
};
 static Member_func _member_func[] = {
 "loc", _hoc_loc_pnt,
 "has_loc", _hoc_has_loc,
 "get_loc", _hoc_get_loc_pnt,
 "cond", _hoc_cond,
 0, 0
};
#define cond cond_AMPAg
 extern double cond( _threadargsprotocomma_ double );
 /* declare global and static user variables */
 /* some parameters have upper and lower limits */
 static HocParmLimits _hoc_parm_limits[] = {
 "gmax", 0, 1e+09,
 "tau1", 0.001, 1e+06,
 "tau0", 0.001, 1e+06,
 0,0,0
};
 static HocParmUnits _hoc_parm_units[] = {
 "onset", "ms",
 "tau0", "ms",
 "tau1", "ms",
 "gmax", "uS",
 "e", "mV",
 "i", "nA",
 0,0
};
 /* connect global user variables to hoc */
 static DoubScal hoc_scdoub[] = {
 0,0
};
 static DoubVec hoc_vdoub[] = {
 0,0,0
};
 static double _sav_indep;
 static void nrn_alloc(Prop*);
static void  nrn_init(NrnThread*, _Memb_list*, int);
static void nrn_state(NrnThread*, _Memb_list*, int);
 static void nrn_cur(NrnThread*, _Memb_list*, int);
static void  nrn_jacob(NrnThread*, _Memb_list*, int);
 static void _hoc_destroy_pnt(void* _vptr) {
   destroy_point_process(_vptr);
}
 /* connect range variables in _p that hoc is supposed to know about */
 static const char *_mechanism[] = {
 "7.7.0",
"AMPAg",
 "onset",
 "tau0",
 "tau1",
 "gmax",
 "e",
 0,
 "i",
 0,
 0,
 0};
 
extern Prop* need_memb(Symbol*);

static void nrn_alloc(Prop* _prop) {
	Prop *prop_ion;
	double *_p; Datum *_ppvar;
  if (nrn_point_prop_) {
	_prop->_alloc_seq = nrn_point_prop_->_alloc_seq;
	_p = nrn_point_prop_->param;
	_ppvar = nrn_point_prop_->dparam;
 }else{
 	_p = nrn_prop_data_alloc(_mechtype, 12, _prop);
 	/*initialize range parameters*/
 	onset = 0;
 	tau0 = 0.5;
 	tau1 = 5;
 	gmax = 0;
 	e = 0;
  }
 	_prop->param = _p;
 	_prop->param_size = 12;
  if (!nrn_point_prop_) {
 	_ppvar = nrn_prop_datum_alloc(_mechtype, 2, _prop);
  }
 	_prop->dparam = _ppvar;
 	/*connect ionic variables to this model*/
 
}
 static void _initlists();
 extern Symbol* hoc_lookup(const char*);
extern void _nrn_thread_reg(int, int, void(*)(Datum*));
extern void _nrn_thread_table_reg(int, void(*)(double*, Datum*, Datum*, NrnThread*, int));
extern void hoc_register_tolerance(int, HocStateTolerance*, Symbol***);
extern void _cvode_abstol( Symbol**, double*, int);

 void _AMPAg_reg() {
	int _vectorized = 1;
  _initlists();
 	_pointtype = point_register_mech(_mechanism,
	 nrn_alloc,nrn_cur, nrn_jacob, nrn_state, nrn_init,
	 hoc_nrnpointerindex, 1,
	 _hoc_create_pnt, _hoc_destroy_pnt, _member_func);
 _mechtype = nrn_get_mechtype(_mechanism[1]);
     _nrn_setdata_reg(_mechtype, _setdata);
 #if NMODL_TEXT
  hoc_reg_nmodl_text(_mechtype, nmodl_file_text);
  hoc_reg_nmodl_filename(_mechtype, nmodl_filename);
#endif
  hoc_register_prop_size(_mechtype, 12, 2);
  hoc_register_dparam_semantics(_mechtype, 0, "area");
  hoc_register_dparam_semantics(_mechtype, 1, "pntproc");
 	hoc_register_var(hoc_scdoub, hoc_vdoub, hoc_intfunc);
 	ivoc_help("help ?1 AMPAg /Users/gili/Desktop/NewJupyter/mod/AMPAg.mod\n");
 hoc_register_limits(_mechtype, _hoc_parm_limits);
 hoc_register_units(_mechtype, _hoc_parm_units);
 }
static int _reset;
static char *modelname = "";

static int error;
static int _ninits = 0;
static int _match_recurse=1;
static void _modl_cleanup(){ _match_recurse=1;}
 
double cond ( _threadargsprotocomma_ double _lx ) {
   double _lcond;
 double _ltemp ;
 if ( _lx < 0.0 ) {
     _lcond = 0.0 ;
     }
   else {
     _ltemp = _lx / tau0 ;
     if ( _ltemp > 10.0 ) {
       a0 = 1.0 ;
       }
     else {
       a0 = 1.0 - exp ( - _ltemp ) ;
       }
     _ltemp = _lx / tau1 ;
     if ( _ltemp > 10.0 ) {
       a1 = 1.0 ;
       }
     else {
       a1 = 1.0 - exp ( - _ltemp ) ;
       }
     _lcond = factor * ( a0 - a1 ) ;
     }
   
return _lcond;
 }
 
static double _hoc_cond(void* _vptr) {
 double _r;
   double* _p; Datum* _ppvar; Datum* _thread; NrnThread* _nt;
   _p = ((Point_process*)_vptr)->_prop->param;
  _ppvar = ((Point_process*)_vptr)->_prop->dparam;
  _thread = _extcall_thread;
  _nt = (NrnThread*)((Point_process*)_vptr)->_vnt;
 _r =  cond ( _p, _ppvar, _thread, _nt, *getarg(1) );
 return(_r);
}

static void initmodel(double* _p, Datum* _ppvar, Datum* _thread, NrnThread* _nt) {
  int _i; double _save;{
 {
   double _ltpeak ;
 if ( tau0 / tau1 > 0.9999 ) {
     tau0 = 0.9999 * tau1 ;
     }
   _ltpeak = tau0 * tau1 * log ( tau0 / tau1 ) / ( tau0 - tau1 ) ;
   factor = 1.0 / ( ( 1.0 - exp ( - _ltpeak / tau0 ) ) - ( 1.0 - exp ( - _ltpeak / tau1 ) ) ) ;
   }

}
}

static void nrn_init(NrnThread* _nt, _Memb_list* _ml, int _type){
double* _p; Datum* _ppvar; Datum* _thread;
Node *_nd; double _v; int* _ni; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
_thread = _ml->_thread;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
#if CACHEVEC
  if (use_cachevec) {
    _v = VEC_V(_ni[_iml]);
  }else
#endif
  {
    _nd = _ml->_nodelist[_iml];
    _v = NODEV(_nd);
  }
 v = _v;
 initmodel(_p, _ppvar, _thread, _nt);
}
}

static double _nrn_current(double* _p, Datum* _ppvar, Datum* _thread, NrnThread* _nt, double _v){double _current=0.;v=_v;{ {
   if ( gmax ) {
     at_time ( _nt, onset ) ;
     }
   g = gmax * cond ( _threadargscomma_ t - onset ) ;
   i = 0.001 * g * ( v - e ) ;
   }
 _current += i;

} return _current;
}

static void nrn_cur(NrnThread* _nt, _Memb_list* _ml, int _type) {
double* _p; Datum* _ppvar; Datum* _thread;
Node *_nd; int* _ni; double _rhs, _v; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
_thread = _ml->_thread;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
#if CACHEVEC
  if (use_cachevec) {
    _v = VEC_V(_ni[_iml]);
  }else
#endif
  {
    _nd = _ml->_nodelist[_iml];
    _v = NODEV(_nd);
  }
 _g = _nrn_current(_p, _ppvar, _thread, _nt, _v + .001);
 	{ _rhs = _nrn_current(_p, _ppvar, _thread, _nt, _v);
 	}
 _g = (_g - _rhs)/.001;
 _g *=  1.e2/(_nd_area);
 _rhs *= 1.e2/(_nd_area);
#if CACHEVEC
  if (use_cachevec) {
	VEC_RHS(_ni[_iml]) -= _rhs;
  }else
#endif
  {
	NODERHS(_nd) -= _rhs;
  }
 
}
 
}

static void nrn_jacob(NrnThread* _nt, _Memb_list* _ml, int _type) {
double* _p; Datum* _ppvar; Datum* _thread;
Node *_nd; int* _ni; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
_thread = _ml->_thread;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml];
#if CACHEVEC
  if (use_cachevec) {
	VEC_D(_ni[_iml]) += _g;
  }else
#endif
  {
     _nd = _ml->_nodelist[_iml];
	NODED(_nd) += _g;
  }
 
}
 
}

static void nrn_state(NrnThread* _nt, _Memb_list* _ml, int _type) {

}

static void terminal(){}

static void _initlists(){
 double _x; double* _p = &_x;
 int _i; static int _first = 1;
  if (!_first) return;
_first = 0;
}

#if defined(__cplusplus)
} /* extern "C" */
#endif

#if NMODL_TEXT
static const char* nmodl_filename = "/Users/gili/Desktop/NewJupyter/mod/AMPAg.mod";
static const char* nmodl_file_text = 
  "COMMENT\n"
  "synaptic current with exponential rise and decay conductance defined by\n"
  "        i = g * (v - e)      i(nanoamps), g(micromhos);\n"
  "        where\n"
  "         g = 0 for t < onset and\n"
  "         g=amp*((1-exp(-(t-onset)/tau0))-(1-exp(-(t-onset)/tau1)))\n"
  "          for t > onset\n"
  "plus a little bulletproofing and stuff to make it run a mite faster\n"
  "and make it compatible with cvode\n"
  "ENDCOMMENT\n"
  "\n"
  "NEURON {\n"
  "	POINT_PROCESS AMPAg\n"
  "	RANGE onset, tau0, tau1, gmax, e, i\n"
  "	NONSPECIFIC_CURRENT i\n"
  "}\n"
  "\n"
  "UNITS {\n"
  "	(nA) = (nanoamp)\n"
  "	(mV) = (millivolt)\n"
  "	(uS) = (microsiemens)\n"
  "	(nS) = (nanosiemens)\n"
  "\n"
  "}\n"
  "\n"
  "PARAMETER {\n"
  "	onset=0  (ms)\n"
  "	tau0=0.5 (ms) <1e-3,1e6>\n"
  "	tau1=5.0 (ms) <1e-3,1e6>\n"
  "	gmax=0 	 (uS) <0,1e9>\n"
  "	e=0	 (mV)\n"
  "}\n"
  "\n"
  "ASSIGNED {\n"
  "	v (mV)\n"
  "	i (nA)\n"
  "	g (nS)\n"
  "	factor\n"
  "	a0\n"
  "	a1\n"
  "}\n"
  "\n"
  "INITIAL { LOCAL tpeak\n"
  "	if (tau0/tau1 > 0.9999) {\n"
  "		tau0 = 0.9999*tau1\n"
  "	}\n"
  "	tpeak=tau0*tau1*log(tau0/tau1)/(tau0-tau1)\n"
  "	factor=1/((1-exp(-tpeak/tau0))-(1-exp(-tpeak/tau1)))\n"
  "}\n"
  "\n"
  "BREAKPOINT {\n"
  "	if (gmax) { at_time(onset) }\n"
  "	g = gmax*cond(t-onset)\n"
  "	i = 0.001*g*(v - e)\n"
  "}\n"
  "\n"
  "FUNCTION cond(x (ms)) { LOCAL temp\n"
  "	if (x < 0) {\n"
  "		cond = 0\n"
  "	}else{\n"
  "		temp = x/tau0\n"
  "		if (temp > 10) {\n"
  "			a0 = 1\n"
  "		} else {\n"
  "			a0=1-exp(-temp)\n"
  "		}\n"
  "		temp = x/tau1\n"
  "		if (temp > 10) {\n"
  "			a1 = 1\n"
  "		} else {\n"
  "			a1=1-exp(-temp)\n"
  "		}\n"
  "		cond = factor*(a0-a1)\n"
  "	}\n"
  "}\n"
  ;
#endif
