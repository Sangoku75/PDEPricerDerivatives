//
//  BSDifferencesFinies.h
//  PricerEDPBS
//
//  Created by  Easy Andre on 12/02/2015.
//  Copyright (c) 2015 Ezechiel Andre. All rights reserved.
//

#ifndef PricerEDPBS_BSDifferencesFinies_h
#define PricerEDPBS_BSDifferencesFinies_h

#include <stdio.h>
#include "PDEImp.h"
#include <vector>

// Methode de differences finies - Classe Base abstraite
class BSDifferencesFinies {
protected:
    PDEImp* pde;
    
    // Space discretisation
    double x_dom;      // Spatial extent [0.0, x_dom]
    unsigned long J;   // Number of spatial differencing points
    double dx;         // Spatial step size (calculated from above)
    std::vector<double> x_values;  // Stores the coordinates of the x dimension
    
    // Time discretisation
    double t_dom;      // Temporal extent [0.0, t_dom]
    unsigned long N;   // Number of temporal differencing points
    double dt;         // Temporal step size (calculated from above)
    
    // Time-marching
    double prev_t, cur_t;   // Current and previous times
    
    // Differencing coefficients
    double alpha, beta, gamma;
    
    // Storage
    std::vector<double> new_result;   // New solution (becomes N+1)
    std::vector<double> old_result;   // Old solution (becomes N)
    
    // Constructor
    BSDifferencesFinies(double _x_dom, unsigned long _J,
                        double _t_dom, unsigned long _N,
                        PDEImp* _pde);
    
    // Override these virtual methods in derived classes for
    
    virtual void calculate_step_sizes() = 0;
    virtual void set_initial_conditions() = 0;
    virtual void calculate_boundary_conditions() = 0;
    virtual void calculate_inner_domain() = 0;
    
public:
    // Carry out the actual time-stepping
    virtual void step_march() = 0;
};


#endif
