/************************************************************
 
 CIS 22B
 HW3: [Design a class called Date. The class should store a date in three integers: month, day, and year. Date will be printed in different following formats by member functions:]
 
 Author: [Lok Yin Cheng]
 Date:[2017-01-26]
 *************************************************************/

#include <iostream>
#include "Header.h"

using namespace std;

int main() {
    
    //Declare variable
    int mn, dy, yr;
    
    //prompt user for the input for month, date and year
    do {
        cout<<"Please enter Month:";
        cin>> mn;
    } while (mn<1 || mn>12); // entered month can't be less than 1 or greater than 12
    
    do {
        cout<<"Please enter Date:";
        cin>> dy;
    } while (dy<1 || dy>31); // entered date can't be less than 1 or greater than 31
    
    do {
        cout<<"Please enter Year:";
        cin>> yr;
    } while (yr<0); // entered year can't be less than 0
    
    //passing data into the member functions
    Date newDate(mn, dy, yr);
    
    //Display the formatted date
    newDate.getDate1();
    newDate.getDate2();
    newDate.getDate3();
    
    cin.ignore();
    //cin.get();
    return 0;
}//main
/////////////////


/**
 Please enter Month:12
 Please enter Date:25
 Please enter Year:2014
 12/25/2014
 December 25,2014
 December 25 2014
 Program ended with exit code: 0
**/
