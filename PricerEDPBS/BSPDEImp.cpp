//
//  BSPDEImp.cpp
//  PricerEDPBS
//
//  Created by  Easy Andre on 12/02/2015.
//  Copyright (c) 2015 Ezechiel Andre. All rights reserved.
//

#include "BSPDEImp.h"
#include <stdio.h>
#include <math.h>
#include "OneFactorPayoff.h"
#include "Instrument.h"
#include "Option.h"

BSPDEImp::BSPDEImp(Option& option)
{
    opt = &option;
}

double BSPDEImp::diffusion(double x, double t) const
{ // simulates diffusion
    
    double v = (opt -> sig); // volatility
    
    return 0.5 * v * v * x * x;
    
}

double BSPDEImp::convection(double x, double t) const
{ // simulates drift
    
    
    return (opt -> r) * x; // r == interest rate
}

double BSPDEImp::zeroterm(double x, double t) const	// Coefficient of zero derivative
{
    return - (opt -> r);
}

double BSPDEImp::RHS(double x, double t) const		// Inhomogeneous forcing term
{
    return 0.0;
}

// Boundary and initial conditions
double BSPDEImp::BCL(double t, double x) const					// Left hand boundary condition
{
    
    if (opt->type == 'C')
    {
        return 0.0;	//C
    }
    else
    {
        return (opt->K) * ::exp(- (opt->r) * ((opt->T) - t)); // P
    }
    
}

double BSPDEImp::BCR(double t, double x) const					// Right hand boundary condition
{
    if (opt->type == 'C')
    {
        return opt->SMax; // Max number
    }
    else
    {
        return 0.0; //P
    }
}

double BSPDEImp::IC(double x) const					// Initial condition
{
    return (*opt).OptionPayoff.payoff(x);
}


