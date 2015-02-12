//
//  BSEulerExplicit.h
//  PricerEDPBS
//
//  Created by  Easy Andre on 12/02/2015.
//  Copyright (c) 2015 Ezechiel Andre. All rights reserved.
//

#ifndef __PricerEDPBS__BSEulerExplicit__
#define __PricerEDPBS__BSEulerExplicit__

#include <stdio.h>
#include "BSDifferencesFinies.h"
#include "PDEImp.h"

class BSEulerExplicit : public BSDifferencesFinies {
protected:
    void calculate_step_sizes();
    void set_initial_conditions();
    void calculate_boundary_conditions();
    void calculate_inner_domain();
    
public:
    BSEulerExplicit(double _x_dom, unsigned long _J,
                    double _t_dom, unsigned long _N,
                    PDEImp* _pde);
    
    void step_march();
};


#endif /* defined(__PricerEDPBS__BSEulerExplicit__) */
