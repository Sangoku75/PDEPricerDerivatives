//
//  Option.h
//  PricerEDPBS
//
//  Created by  Easy Andre on 12/02/2015.
//  Copyright (c) 2015 Ezechiel Andre. All rights reserved.
//

#ifndef PricerEDPBS_Option_h
#define PricerEDPBS_Option_h

#include "Instrument.h"
#include "OneFactorPayoff.h"
#include <iostream>


class Option : public Instrument {
    public :        // Option Parameters
    double r;		// Interest rate
    double sig;		// Volatility
    double K;		// Strike price
    double T;		// Expiry date
    double b;		// Cost of carry
    double SMax;	// Far field condition
    char type;		// Call or put
    OneFactorPayoff OptionPayoff; //PayOff
    
    Option(){
        
    }
    
};


#endif
