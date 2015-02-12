//
//  InstrumentFactory.h
//  PricerEDPBS
//
//  Created by  Easy Andre on 12/02/2015.
//  Copyright (c) 2015 Ezechiel Andre. All rights reserved.
//

#ifndef PricerEDPBS_InstrumentFactory_h
#define PricerEDPBS_InstrumentFactory_h

#include <iostream>
#include "Option.h"
#include "OneFactorPayoff.h"

class InstrumentFactory{
    public :
    virtual Option* CreateOption() const = 0;
    
};


#endif
