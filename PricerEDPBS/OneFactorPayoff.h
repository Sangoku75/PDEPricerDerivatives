//
//  OneFactorPayoff.h
//  PricerEDPBS
//
//  Created by  Easy Andre on 12/02/2015.
//  Copyright (c) 2015 Ezechiel Andre. All rights reserved.
//

#ifndef __PricerEDPBS__OneFactorPayoff__
#define __PricerEDPBS__OneFactorPayoff__

#include <stdio.h>

// Fonctions codées en dur (utiles)
double MyCallPayoffFN(double K, double S);
double MyPutPayoffFN(double K, double S) ;

class OneFactorPayoff{
private:
    double K;
    double (*payoffFN)(double K, double S);
    
public:
    // Constructeurs et destructeur
    OneFactorPayoff();
    OneFactorPayoff(double strike, double (*pay)(double K, double S));// Default constructor
    OneFactorPayoff(const OneFactorPayoff& source);		// Copy constructeur
    virtual ~OneFactorPayoff();					// Destructeur
    
    // Operateur surcharge
    OneFactorPayoff& operator = (const OneFactorPayoff& source);	// Assignment operator
    
    double payoff(double S) const; // Pour un prix spot donné
};


#endif /* defined(__PricerEDPBS__OneFactorPayoff__) */
