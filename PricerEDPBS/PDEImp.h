//
//  PDEImp.h
//  PricerEDPBS
//
//  Created by  Easy Andre on 12/02/2015.
//  Copyright (c) 2015 Ezechiel Andre. All rights reserved.
//

#ifndef PricerEDPBS_PDEImp_h
#define PricerEDPBS_PDEImp_h

#include <stdio.h>

class PDEImp
{
    
public:
    
    
    // Coefficients de l'EDP second ordre parabolique
    virtual double diffusion(double x, double t) const = 0; // Coefficient of second derivative
    
    virtual double convection(double x, double t) const	= 0; // Coefficient of first derivative
    
    virtual double zeroterm(double x, double t) const = 0;	// Coefficient of zero derivative
    
    
    virtual double RHS(double x, double t) const = 0;		// Inhomogeneous forcing term
    
    
    // Conditions initiales et conditions aux limites
    virtual double BCL(double t, double x) const = 0;			// Left hand boundary condition
    
    
    virtual double BCR(double t, double x) const = 0;		// Right hand boundary condition
    
    virtual double IC(double x) const = 0;		// Initial condition
    
    
};


#endif
