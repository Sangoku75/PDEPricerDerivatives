//
//  OneFactorPayoff.cpp
//  PricerEDPBS
//
//  Created by  Easy Andre on 12/02/2015.
//  Copyright (c) 2015 Ezechiel Andre. All rights reserved.
//

#ifndef __PricerEDPBS__OneFactorPayOff_h__
#define __PricerEDPBS__OneFactorPayOff_h__

#include "OneFactorPayoff.h"

// Codé en dur, Fonctions PayOff Call et Put Européens
double MyCallPayoffFN(double K, double S)
{
    if (S > K)
        return (S - K);
    
    return 0.0;
    
}

double MyPutPayoffFN(double K, double S)
{
    // max (K-S, 0)
    if (K > S)
        return (K - S);
    
    return 0.0;
    
}

// Constructeurs et destructeur
OneFactorPayoff::OneFactorPayoff()
{ // Default constructor
    
    K = 0.0;
    payoffFN = 0;
}
OneFactorPayoff::OneFactorPayoff(double strike, double (*pay)(double K, double S))
{ // Default constructor
    
    K = strike;
    payoffFN = pay;
}

OneFactorPayoff::OneFactorPayoff(const OneFactorPayoff& source)
{ // Copy constructor
    
    K = source.K;
    payoffFN = source.payoffFN;
}

OneFactorPayoff:: ~OneFactorPayoff()
{ // Destructor
}

// Surcharge operateur
OneFactorPayoff& OneFactorPayoff::operator = (const OneFactorPayoff& source)
{ // Assignment operator
    
    if (this == &source)
        return *this;
    
    K = source.K;
    payoffFN = source.payoffFN;
    
    return *this;
}

// Not a pure virtual OneFactorPayoff function anymore
double OneFactorPayoff::payoff(double S) const
{ // For a given spot price
    
    
    return payoffFN(K, S);	// DELEGATE a la strategie
}

#endif
