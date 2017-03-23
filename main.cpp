#include <iostream>
#include "magicSquare.h"

using namespace std;



int main()
{
    const int MaxSize = 3;
    //int ROW, COLUMN = 0;
    int square[MaxSize][MaxSize]; 
    
    intputSquare(square, MaxSize);
    
    bool isMagicSquare = checkMagicSquare(& square[0][0], MaxSize);
    
    printSquare(square, MaxSize);
    
    DisplayResult(isMagicSquare);
    

    return 0;
    
}


/** This is the output

 
 Enter matrix :
 4
 9
 2
 3
 5
 7
 8
 1
 6
 
 Entered matrix is :
 
	4	9	2
 
	3	5	7
 
	8	1	6
 This is a Magic square
 Program ended with exit code: 0
**/

