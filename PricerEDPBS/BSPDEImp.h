//
//  BSPDEImp.h
//  PricerEDPBS
//
//  Created by  Easy Andre on 12/02/2015.
//  Copyright (c) 2015 Ezechiel Andre. All rights reserved.
//

#ifndef __PricerEDPBS__BSPDEImp__
#define __PricerEDPBS__BSPDEImp__

#include <stdio.h>
#include "PDEImp.h"
#include "Option.h"

// Black-Scholes PDE
class BSPDEImp : public PDEImp {
public:
    Option* opt;
    BSPDEImp(Option& option);
    
    double diffusion(double x, double t) const;
    double convection(double x, double t) const;
    double zeroterm(double x, double t) const;
    double RHS(double x, double t)  const;
    
    double BCL(double t, double x) const;
    double BCR(double t, double x) const;
    double IC(double x) const;
};



#endif /* defined(__PricerEDPBS__BSPDEImp__) */
