: Suffix syn2

COMMENT
synaptic current with exponential rise and decay conductance defined by
        i = g * (v - e)      i(nanoamps), g(micromhos);
        where
         g = 0 for t < onset and
         g=amp*((1-exp(-(t-onset)/tau0))-(1-exp(-(t-onset)/tau1)))
          for t > onset
plus a little bulletproofing and stuff to make it run a mite faster
and make it compatible with cvode
ENDCOMMENT

NEURON {
	POINT_PROCESS NMDAg
	RANGE onset, tau0, tau1,K1,K2, gmax, e, i
	NONSPECIFIC_CURRENT i
}

UNITS {
	(nA) = (nanoamp)
	(mV) = (millivolt)
	(uS) = (microsiemens)
	(nS) = (nanosiemens)
}

PARAMETER {
	onset=0  (ms)
	tau0=0.5 (ms) <1e-3,1e6>
	tau1=150.0 (ms) <1e-3,1e6>
	gmax=0 	 (nS) <0,1e9>
	e=0	 (mV)
}

ASSIGNED {
	v (mV)
	i (nA)
	g (uS)
	factor
	a0
	a1
	K1
	K2
	MGF
}

INITIAL { LOCAL tpeak
	if (tau0/tau1 > 0.9999) {
		tau0 = 0.9999*tau1
	}
	tpeak=tau0*tau1*log(tau0/tau1)/(tau0-tau1)
	factor=1/((1-exp(-tpeak/tau0))-(1-exp(-tpeak/tau1)))
        K1 = 0.08
	K2 = log(K1)/(-29)

}

BREAKPOINT {
	if (gmax) { at_time(onset) }
	g = gmax*cond(t-onset)
	MGF = 1+K1*exp(-K2*v)
	i = 0.001*g*(v - e)/MGF
	
}

FUNCTION cond(x (ms)) { LOCAL temp
	if (x < 0) {
		cond = 0
	}else{
		temp = x/tau0
		if (temp > 10) {
			a0 = 1
		} else {
			a0=1-exp(-temp)
		}
		temp = x/tau1
		if (temp > 10) {
			a1 = 1
		} else {
			a1=1-exp(-temp)
		}
		cond = factor*(a0-a1)
	}
}
