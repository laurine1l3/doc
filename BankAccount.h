

/*
 * BankAccount.h
 *
 *  Created on: Feb 21, 2017
 *      Author: hellenpacheco
 */

#ifndef BankAccount_h
#define BankAccount_h

#include <iostream>

class BankAccount {
protected:
    double balance;
public:
    BankAccount(double startingBalance)
    { balance = startingBalance; }
    
    virtual ~BankAccount() {}
    
    virtual void deposit(double amt)
    { balance += amt; }
    
    virtual void withdraw(double amt)
    { balance -= amt; }
    
    virtual void printMonthlyStatement() = 0; // pure virtual function
};

#endif /* BANKACCOUNT_H_ */
