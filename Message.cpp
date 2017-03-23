/************************************************************
 
 CIS 22B
 HW3: [Design a class called Date. The class should store a date in three integers: month, day, and year. Date will be printed in different following formats by member functions:]
 
 *************************************************************/

#include <iostream>
#include <fstream>
//#include <istream>
#include <string>
#include <sstream>
#include "Message.h"

//#define MESSAGE_H_

using namespace std;

Message :: Message (string name) {
    message = new char[1000];
    string line;
    fstream myfile (name);
    if (myfile.is_open())
    {
        getFileSize(myfile);

        while (! myfile.eof() )
        {
            myfile.getline (message,1000);
            myfile >> message;
            
            length = strlen(message);
            //cout << length << endl;

        }
        myfile.close();
    }
    else cout << "Unable to open file";
    
};

Message :: ~Message()
{
    delete [] message;
}

bool Message :: isEmpty() const
{
 
    if (length > 0)
    {
        //cout << length << endl;
        return false;
        
    }
    else {
        //cout << length << endl;
        return true;
    }

}

void Message :: dump() const
{

    printf("%s",message);

}

void Message :: decode()
{
    //int alphabetLength = 26;
    //char code[alphabetLength];
    //string a = "iztohndbeqrkglmacsvwfuypjx";
    code[ALPHABET_SIZE] = "iztohndbeqrkglmacsvwfuypjx";
    //code = "abcdefghijklmnopqrstuvwxyz";
    const char *clearAlphabet = a.c_str();
    //encryptedAlphabet ="qwertzuiopasdfghjklyxcvbnm";
    string b = "abcdefghijklmnopqrstuvwxyz";
    const char *encryptedAlphabet = b.c_str();
    

    for(int i=0; i< length; i++)
    {
        for(int j=0; j< ALPHABET_SIZE; j++)
        {
            if( message[ i ] == encryptedAlphabet[ j ])
            {
                message[ i ] = clearAlphabet[ j ];
                break;
            }
        }
        
    }
    
    //cout << "\nDecrypted text:\n " << message << endl;
    
    // while(true);//wait
    //char c;
    //cin >> c;
}

void Message :: fixCapitalization ()
{
    int j;
    
    if ( message[0]!= ' ')
         message[0] = toupper(message[0]);
    
    for (int i= 0; i <= 100; i++)
    {
        j = i;
        //check the index with punctuation
        if (message[i] == ','||message[i]=='?'||message[i] == '!' || message[i] == '.')
        {
            j++;
            
            //check the index with space
            if (message[j] == ' ' && message[j-1] != ',')
            {
                //if true, convert next letter to uppercase in a sentence
                message[j+1] = toupper(message[j+1]);
            }
        }
    }
    //cout << message << endl;
}

/**
 Original message:
 ifqkwxcadf ar cei fpoi masif cd cei xkdqirr du pxxnwafm pf pnmdkaceo cd p oirrpmi, teaqe rqkpohnir cei gpcp af ac-oplafm ac sikw gauuaqvnc pfg caoi qdfrvoafm, au fdc xkpqcaqpnnw aoxdrrahni, cd gigvqi cei dkamafpn masif dfnw cei ifqdgig gpcp. afxvcr cd cei pnmdkaceo cwxaqpnnw afsdnsi pggacadfpn riqkic gpcp qpnnig liwr, teaqe xkisifcr cei oirrpmi ukdo hiafm giqdgig-isif au cei pnmdkaceo ar xvhnaqnw lfdtf.
 
 Decoded message:
 Encryption is the name given to the process of applying an algorithm to a message, which scrambles the data in it-making it very difficult and time consuming, if not practically impossible, to deduce the original given only the encoded data. inputs to the algorithm typically involve additional secret data called keys, which prevents the message from being decoded-even if the algorithm is publicly known.
 
 Program ended with exit code: 0
 **/


