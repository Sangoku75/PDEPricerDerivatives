//
//  ConsoleInstrumentFactory.h
//  PricerEDPBS
//
//  Created by  Easy Andre on 12/02/2015.
//  Copyright (c) 2015 Ezechiel Andre. All rights reserved.
//

#ifndef PricerEDPBS_ConsoleInstrumentFactory_h
#define PricerEDPBS_ConsoleInstrumentFactory_h


#include "InstrumentFactory.h"
#include "OneFactorPayoff.h"

using namespace std;

class ConsoleInstrumentFactory : public InstrumentFactory{
public:
    
    Option* CreateOption() const
    {
        
        double dr;		// Interest rate
        double dsig;	// Volatility
        double dK;		// Strike price
        double dT;		// Expiry date
        double db;		// Cost of carry
        double dSMax;	// Far field boundary
        
        cout << "Interest rate: ";
        cin >> dr;
        
        cout << "Volatility: ";
        cin >> dsig;
        
        cout << "Strike Price: ";
        cin >> dK;
        dSMax = 4.0 * dK;		// Magic Number for stability PDE !!!!
        
        cout << "Expiry: ";
        cin >> dT;
        
        
        cout << "Option premium: ";
        cin >> db;
        
        Option* result = new Option;
        
        cout << "Payoff 1) Call, 2) Put: ";
        int ans;
        cin >> ans;
        if (ans == 1)
        {
            result-> type = 'C';
            (*result).OptionPayoff = 	OneFactorPayoff(dK, MyCallPayoffFN);
        }
        else
        {
            result-> type = 'P';
            (*result).OptionPayoff = OneFactorPayoff(dK, MyPutPayoffFN);
        }
        
        result->r	= dr;
        result->sig = dsig;
        result->K	= dK;
        result->T	= dT;
        result->b	= db;
        result->SMax = dSMax;
        
        return result;
        
    }
};



#endif
