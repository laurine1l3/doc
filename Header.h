
#ifndef Header_h
#define Header_h
#include <iostream>
#include <string>

using namespace std;

class Date {
    
    //Declare variable
    int mn, dy, yr;
public:
    Date (int month, int day, int year)
    {
        Date::mn = month;
        Date::dy = day;
        Date::yr = year;
    };
    void getDate1();
    void getDate2();
    void getDate3();
};

//The list of month name
string monthName[12] = {"January","Febuary","March","April","May","June","July","August","September","October","November","December"};

void Date::getDate1()
{
    cout << mn << "/" << dy << "/" << yr << endl;
}//getData1

void Date::getDate2()
{
    cout << monthName[mn-1] << " " << dy << "," << yr << endl;
}//getData2

void Date::getDate3()
{
    cout << monthName[mn-1] << " " << dy << " " << yr << endl;
}//getData3


#endif /* Header_h */

