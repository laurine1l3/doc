//
//  Savings.cpp
//  Lab5

#include <stdio.h>
#include <iostream>
#include <sstream>

#include "Savings.h"

using namespace std;

double interest;

Savings :: Savings(double amt, double inRate) : BankAccount(amt){

    interestRate = inRate;
}

Savings :: ~Savings()
{
      interest = 0;
    
}

void Savings :: deposit (double amt) {
    
    BankAccount::deposit(amt);
    
}

void Savings :: withdraw(double amt){
    
    
    if(balance - amt > 0){
        
        BankAccount::withdraw(amt);
        
    }
    else {
        cout << "Your account does not have enough money" << endl;
    }

}


void Savings :: applyInterest(){
    

         interest = (balance*interestRate);

         balance += interest;
 
}

void Savings :: printMonthlyStatement() {
    applyInterest();
    cout << "Interest Rate        : " << interestRate << endl;
    cout << "Interest Amount      : $ " << interest << endl;
    cout << "Your saving balance  : $ " << balance << endl;
    //cout << balance + interest;
}
