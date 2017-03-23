//
//  magicSquare.h
//  HW
//


#ifndef magicSquare_h
#define magicSquare_h

using namespace std;

const int ROW = 0, COLUMN = 0;

/**
const int MaxSize = 3;

class MagicSquare{
private:

    int square[MaxSize][MaxSize];
    bool isMagicSquare;

    int Row;
    int Col;
    int Square[Bound][Bound];
    int** magicArray;
    int rowSum;
    int colSum;
    int diagSum;
    int xPos;
    int yPos;

    
public:
    MagicSquare(){Maxsize = 3; Row = 0; Col = 0; Square[SquareSize][SquareSize];}
    MagicSquare(int Size){SquareSize = Size; Current = 1; Row = 0; Col = 0; Square[SquareSize][SquareSize];}
    void SetSquareSize(int Size); // Can set square size if use default constructor
    int GetSquareSize();
    void Magic(); // makes our board and fills with magic square
    void Print(); // print board
     **/

    //void intputSquare (int square[][3], int MaxSize);
    //bool checkMagicSquare (int* square, int MaxSize);
    //void printSquare(int square, int MaxSize);
    //void DisplayResult(isMagicSquare);

    
bool checkMagicSquare (int* square, int size)
{
    int sum = 0,
    sum1 = 0,
    sum2 = 0,
    sum3 = 0,
    sum4 = 0,
    flag = 1;
    
    //For first rows
    for (int ROW = 0; ROW < size; ROW++)
    {
        //cout << ROW;
        sum += square [ROW];
        //cout << sum;
    }
    
    //For Rows, column, diagonal
    for(int ROW = 0; ROW < size; ROW++)
    {
        for (int COLUMN = 0; COLUMN < size; COLUMN++)
        {
            //sum for rows
            sum1 += square [ROW * size + COLUMN];
            //sum for Columns
            sum2 += square [COLUMN * size + ROW];
            //Sum for diagonal elements
            if(ROW == COLUMN)
            {
                //left
                sum3 += square [ROW * size + COLUMN];
            }
            if(ROW + COLUMN + 1 == size)
            {
                //right
                sum4 += square [ROW * size + COLUMN];
            }
        }
        if(sum != sum1)//break immediately
        {
            flag = 0;
            break;
        }
        sum1 = 0;
        sum2 = 0;
    }
    if(sum != sum3 || sum != sum4)
    {
        flag = 0;
    }
    
    return flag;
    
}
void DisplayResult (bool isMagicSquare)
{
    if(isMagicSquare == 1)
        cout << "This is a Magic square" << endl;
    else
        cout << "This is not a Magic square" << endl;
}

void intputSquare (int square[][3], int size)
{
    cout << "\nEnter matrix : " << endl;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++)
            //scanf("%d", &matrix[ROW][COLUMN]);
            cin >> square[i][j];
    }
}

void printSquare (int square[][3], int size)
{
    
    cout << "\nEntered matrix is : \n";
    for (int row = 0; row < size; row++) {
        cout << "\n";
        for (int column = 0; column < size; column++) {
            cout <<  "\t" << square[row][column];
        }
        cout << "\n";
    }
}


#endif /* magicSquare_h */
