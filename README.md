# EvtBToD4pi-EvtGen-Model

This is a fork of [event generator (EvtGen) repository](https://github.com/alisw/EVTGEN). 

# Description
New model `EvtBToD4pi` is included in the project. It is a complex model taking into account
various resonant structures in $4 \pi$ system of the process $B^0 \to D^- \pi^+ \pi^+ \pi^- \pi^0$. 
Model has 11 parameters describing connections between different resonant amplitudes.

Parameter 1,2: $B \to D \rho(2S)$ coupling and phase relative to $B \to D \rho$

Parameter 3,4: $\omega \pi$ coupling and phase

Parameter 5,6 : $a_1(1260) \pi$ coupling and phase

Parameter 7,8: $\rho\rho$ coupling and phase

Parameter 9,10: $\rho f_0(980)$ coupling and phase

Parameter 11 (optional): Majority value in the acceptance-rejection method which is used in EvtGen

The model is tested in the test sub-directory. 
The decay file `exampleFiles/B2D4pi.DEC` contains the decay example 
demonstrating a complex amplitude with $\omega \pi$ and $a_1(1260)\pi$ terms 
interfering with zero relative phase. 

Parameters 1,2 are fixed on values measured by [Belle Collaboration](https://journals.aps.org/prd/abstract/10.1103/PhysRevD.92.012013)

Parameter 5 is fixed on value extracted from different $e^+e^-$ and $\tau \to 4\pi$ measurements. 

Running the script `./do_B2D4pi` will generate decays from B2D4pi.DEC file.
ROOT file `B2D4pi.root` is created with three histograms of invariant masses of 
two pions in the final system. 
