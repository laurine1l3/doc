//
//  Checking.cpp
//  Lab5

#include <stdio.h>
#include <iostream>
#include <sstream>
#include <math.h>

#include "Checking.h"

using namespace std;

int monthlyCharges;

Checking :: Checking(double amt, int maxW, double charges) : BankAccount( amt){
    withdrawals = 0;
}

Checking :: ~Checking()
{
    
    
}

void Checking :: deposit (double amt) {
    
    BankAccount::deposit(amt);
}

void Checking :: withdraw(double amt){
   
    
    if(balance - amt > 0){
        
        BankAccount::withdraw(amt);
        withdrawals ++;
    }
    else {
        cout << "Your account does not have enough money" << endl;
    }
}

void Checking :: applyCharges(){
        
    if (withdrawals <= maxW){
        monthlyCharges = 0;
        
    }
    else {
        monthlyCharges = ceil(withdrawals/maxW)* charges;
    }
    
    
    balance -= monthlyCharges;

}

void Checking :: printMonthlyStatement() {
    applyCharges();
    cout << "Number of withdrawls :   " << withdrawals << endl;
    cout << "Monthly charges      : $ " << monthlyCharges << endl;
    cout << "Your checking balance: $ " << balance << endl;
}
