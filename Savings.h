
/*
 * Savings.h
 *
 *  Created on: Feb 21, 2017
 *      Author: hellenpacheco
 */

#ifndef Savings_h
#define Savings_h

#include "BankAccount.h"

class Savings : public BankAccount {
private:
    double interestRate;
    void applyInterest();  // calculates the monthly interest and adds it to the balance
    
public:
    Savings(double amt, double intRate = 0.01);
    virtual ~Savings();
    void deposit(double amt);    // calls deposit from base class
    void withdraw(double amt);   // checks if enough funds before calling withdraw from base class
    void printMonthlyStatement(); // prints monthly statement after calculating the interest to update the balance
};

#endif /* SAVINGS_H_ */
