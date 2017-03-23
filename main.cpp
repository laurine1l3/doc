//
//  main.cpp
//  Lab5
//
//  Created by Cheng, Laurine(AWF) on 3/5/17.
//  Copyright © 2017 Cheng, Laurine(AWF). All rights reserved.
//

#include <iostream>
#include "Checking.h"
#include "Savings.h"

using namespace std;

int main(){
    
    Checking checkAcct(1000,3,0.2);
    Savings saveAcct(2000);
    
    saveAcct.withdraw(100);
    checkAcct.withdraw(150);
    //checkAcct.deposit(100);
    //checkAcct.withdraw(10);
    //checkAcct.applyCharges();

    
    
    checkAcct.printMonthlyStatement();
    
    saveAcct.printMonthlyStatement();
    
}

