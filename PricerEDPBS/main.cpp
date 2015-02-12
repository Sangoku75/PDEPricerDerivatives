//
//  main.cpp
//  PDEPricerBS
//
//  Created by  Easy Andre on 06/02/2015.
//  Copyright (c) 2015 Ezechiel Andre. All rights reserved.
//



#include <iostream>
#include "BSPDEImp.h"
#include "BSEulerExplicit.h"
#include "InstrumentFactory.h"
#include "ConsoleInstrumentFactory.h"
#include <cmath>
#include <fstream>

using namespace std;

double BSExplicitDiffAmerican(double price, double strike, double vol, double rate, double div, double T, int N, int M, char type){
    
    int i,j ;
    double dt = T/N;
    double drift = rate - div - 0.5* (vol*vol);
    double dx = vol * sqrt(3*dt/2);
    double pu = (vol*vol*dt)/(2*dx*dx) + (drift*dt)/(2*dx);
    double pm = 1.0 - (vol*vol*dt)/(dx*dx);
    double pd = (vol*vol*dt)/(2*dx*dx) - (drift*dt)/(2*dx);
    double C[200][200];
    double S[200][200];
    double Delta[200][200];
    double Gamma[200][200];
    
    ofstream differencesFinies_out("/Users/Easy/Documents/Pricing Derivatives/PDEPricerBS/PDEPricerBS/fdm.csv", std::ofstream::out);
    
    //Initialize asset prices at maturity
    
    for(j = -M; j<=M; j++){
        S[N][j] = price*exp(j*dx);
    }
    
    if(type =='C'){
        //Calcul du payoff a maturité
        for(j = -M; j<=M; j++){
            C[N][j] = fmax(S[N][j] -  strike, 0);
        }
        
        //Conditions aux bords pour le prix (conditions dirichlet)
        for(i=0; i<N; i++){
            C[i][-M] = 0.0;
            C[i][M] = fmax(S[N][M] -  strike, 0);
        }
        
        for(i=N-1; i>=0; i--)
        {
            for(j=M-1; j>=-(M-1); j--)
            {
                C[i][j] = pu*C[i+1][j+1] + pm*C[i+1][j] + pd*C[i+1][j-1];
                C[i][j] = fmax(S[N][j] -  strike, C[i][j]);
                differencesFinies_out << C[i][j] << " " << i <<  " " << j << endl;
            }
        }
        
    }
    else //if (Put)
    {
        //Conditions aux bords pour le prix (conditions dirichlet)
        for(i=0; i<N; i++){
            C[i][0] = strike;
            C[i][M] = 0;
        }
        
        for(j = -M; j<=M; j++){
            C[N][j] = fmax(strike - S[N][j] , 0);
        }
        
        //Conditions aux bords pour le prix (conditions dirichlet)
        for(i=0; i<N; i++){
            C[i][-M] = strike;
            C[i][M] = fmax(strike - S[N][M] , 0);
        }
        
        
        for(i=N-1; i>=0; i--)
        {
            for(j=M-1; j>=-(M-1); j--)
            {
                C[i][j] = pu*C[i+1][j+1] + pm*C[i+1][j] + pd*C[i+1][j-1];
                C[i][j] = fmax(strike - S[N][j], C[i][j]);
                //Delta [i][j] = (C[i][j+1] - C[i][j])/ (dx) ;
                //Gamma [i][j] = (Delta[i][j+1] - Delta[i][j-1])/ (2*dx) ;
                differencesFinies_out << C[i][j] << " " << i <<  " " << j<< endl;
            }
        }
        
    }
    
    differencesFinies_out.close();
    
    return C[0][0];
    
}

InstrumentFactory* GetInstrumentFactory()
{
    return new ConsoleInstrumentFactory;
}


int main(int argc, const char * argv[]) {
    
    //    double T = 3.00;    // One year until expiry
    //
    //    // FDM discretisation parameters
    //    double x_dom = 100.0;       // Spot goes from [0.0, 1.0]
    //    unsigned long J = 100;
    //    double t_dom = T;         // Time period as for the option
    //    unsigned long N = 100;
    //
    //
    //        //Test Instrument //
    //    InstrumentFactory* myFactory = GetInstrumentFactory();
    //    Option* myOption = myFactory ->CreateOption();
    //
    //    cout << "1) European or 2) American style: ";
    //    int exStyle = 1; cin >> exStyle;
    //
    //
    //
    //    // Create the PDE and FDM objects
    //    BSPDEImp* bs_pde = new BSPDEImp(*myOption);
    //
    //    BSEulerExplicit DiffFiniesMethods_Euler = BSEulerExplicit(x_dom, J,t_dom, N,bs_pde);
    //
    //    // Run the FDM solver
    //    DiffFiniesMethods_Euler.step_march();
    //
    //    // Delete the PDE, PayOff and Option objects
    //    delete bs_pde;
    //    delete myOption;
    
    double p = BSExplicitDiffAmerican(50, 50, 0.20, 0.06, 0.0, 1.0, 4, 5, 'C');
    
    cout << "le prix du call americain est : " << p <<endl;
    
    return 0;
    
}
