

#ifndef Checking_h
#define Checking_h

#include "BankAccount.h"

class Checking : public BankAccount{
private:
    double charges;
    int maxW; // maximum of free withdrawals per month
    int withdrawals; // number of withdrawals this month
    void applyCharges(); // calculates the monthly charges and subtracts it from the balance
    
public:
    // default: a charge of $0.1 applies after 5 withdrawals per month
    Checking(double amt, int maxW = 5, double charges = 0.1);
    virtual ~Checking();
    void deposit(double amt);  // calls deposit from base class
    void withdraw(double amt); // checks if enough funds before calling withdraw from base class
    void printMonthlyStatement(); // prints monthly statement after calculating the charges to update the balance
};

#endif /* CHECKING_H_ */
