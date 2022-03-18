#include<bits/stdc++.h>
#include<time.h>
#include<fstream>
#include"playword_lib.h"
#include "stringMatch.cpp"

using namespace std;

//defining variable
char randSelectedWord[5];
char tryWord1[5];
char tryWord2[5];
char tryWord3[5];
char tryWord4[5];
char tryWord5[5];
char tryWord6[5];
int  score=0;
char result='N';

char upperLetter(char ch)
{
    if ((int)ch >= 97 && (int)ch <= 122 )
    {   
        ch = char((int)ch-32);
    }
    return ch;
}


//function for using delay in console for design
void my_Sleep(unsigned long ms)
{
    struct timespec ts;
    ts.tv_sec = ms / 1000000ul;            // seconds
    ts.tv_nsec = (ms % 1000000ul) * 1000;  // remainder in nanoseconds
    nanosleep(&ts, NULL);
}


//ffunction for the first screen display
void showTitle(int timeForGap,int timeForClear )
{   
    my_Sleep(timeForClear);
    cout << CLEAR;
    cout << "\n\n            ";
    cout << GREEN<<BOLD<<" P ";
    cout << RESET;
    my_Sleep(timeForGap);

    cout << YELLOW<<BOLD<<" l ";
    cout << RESET;
    my_Sleep(timeForGap);

    cout << RED<<BOLD<<" a ";
    cout << RESET;
    my_Sleep(timeForGap);

    cout << GREEN<<BOLD<<" y ";
    cout << RESET;
    my_Sleep(timeForGap);

    cout << YELLOW<<BOLD<<" W ";
    cout << RESET;
    my_Sleep(timeForGap);

    cout << RED<<BOLD<<" o ";
    cout << RESET;
    my_Sleep(timeForGap);

    cout << GREEN<<BOLD<<" r ";
    cout << RESET;
    my_Sleep(timeForGap);

    cout << YELLOW<<BOLD<<" d ";
    cout << RESET;
    my_Sleep(timeForGap*5);

    cout << "\n\n";
    

}

bool shouldStart()
{
    char isReady;
    
    cout << CYAN;
    cout << "Are you ready to play? Press ('Y') to start  ";
    cout << RESET;
    
    cin>>isReady;
    
    isReady=upperLetter(isReady);
    // cout << isReady;

    if (isReady == 'Y')
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
}

int strLen(std::string str)
{
    int i=0;
    while(str[i]!='\0')
    {
        i++;
    }
    return i;
}

void selectRandomWord()
{   
    int randWord;
    srand(time(NULL));
    randWord=rand()%336;

    string str;

    ifstream file("Dictionary.txt",ios::in);
    file.seekg(ios::beg);

    for (int i = 1; i <= randWord; i++)
    {
        getline(file,str);
    }

    // cout << randWord<<" "<<str;

    for (int i = 0; i < strLen(str); i++)
    {
        randSelectedWord[i]=str[i];
        cout << randSelectedWord[i];
    }
    // randSelectedWord[0]=str[0];
    // randSelectedWord[1]=str[1];
    // randSelectedWord[2]=str[2];
    // randSelectedWord[3]=str[3];
    // randSelectedWord[4]=str[4];

    for (int i = 0; i < 5; i++)
    {
         randSelectedWord[i]=upperLetter(randSelectedWord[i]);
    }
    

    // cout << randSelectedWord;
    // my_Sleep(10000000);
    
}

void instructions()
{
    
    showTitle(0,600000);
    cout << DOUBLESPACE;

    cout << CYAN;
    cout << "** Try to guess the word within 6 tries ";
    cout << DOUBLESPACE;

    cout << "** Each guess must be a valid 5 letter word. Hit the enter button to submit ";
    cout << DOUBLESPACE;

    cout << "** After each guess, the color of the tiles will change to show how close your guess was to the word ";
    cout << RESET;
    cout << DOUBLESPACE << endl;

    showTitle(0,5000000);
    cout << RESET;
    cout << DOUBLESPACE;

    cout << CYAN;
    cout << "-> The letter " << RESET;
    cout << GREEN << " P " << RESET << "," << GREEN <<  " y " << RESET << "," << GREEN << " r " << RESET << CYAN <<  " are in the word and in the correct spot ";
    cout << DOUBLESPACE;
    cout << "-> The letter " << RESET;
    cout << YELLOW << " l " << RESET << "," << YELLOW << " w " << RESET << "," << YELLOW << " d " << RESET << CYAN << " are in the word but in the wrong spot ";
    cout << DOUBLESPACE;
    cout << "-> The letter " << RESET;
    cout << RED << " a " << RESET << "," << RED << " o " << RESET << CYAN << " are not in the word ";
    cout << RESET;
    cout << DOUBLESPACE << DOUBLESPACE;
    my_Sleep(5000000);

}

void dashMatrix(int n)
{
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < 5; j++)
      {
        cout << " _ ";
      }
      cout << DOUBLESPACE;
    }

}

void keyboard()
{

  cout << DOUBLESPACE;
  cout << LightCyan;
  cout << " Q " << " W " << " E " << " R " << " T " << " Y " << " U " << " I " << " O " << " P ";
  cout << DOUBLESPACE;
  cout << "  " << " A " << " S " << " D " << " F " << " G " << " H " << " J " << " K " << " L ";
  cout << DOUBLESPACE;
  cout << "     " << " Z " << " X " << " C " << " V " << " B " << " N " << " M ";
  cout << DOUBLESPACE;

}


bool rightPosition(char x)
{
    for (int i = 0; i < 5; i++)
    {
        if((randSelectedWord[i]==x) && (tryWord1[i]==randSelectedWord[i] || tryWord2[i]==randSelectedWord[i] || tryWord3[i]==randSelectedWord[i] || tryWord4[i]==randSelectedWord[i] || tryWord5[i]==randSelectedWord[i] || tryWord6[i]==randSelectedWord[i]) )
            return true;
    }
    return false;
    
}

bool wrongPosition(char x)
{
    bool exist=false,tryexist=false;

    for (int i = 0; i < 5; i++)
    {
        if (randSelectedWord[i]==x)
        {
            exist = true;
            break;
        }
    }

    for (int i = 0; i < 5; i++)
    {
        if (tryWord1[i] == x || tryWord2[i] == x || tryWord3[i] == x || tryWord4[i] == x || tryWord5[i] == x || tryWord6[i] == x)
        {
            tryexist=true;
            break;
        }      
    }

    return (exist && tryexist);
}



bool notPresent(char x)
{
    bool notExist = true, tryExist = false;
    
    for (int i = 0; i < 5; i++)
    {
        if (randSelectedWord[i] == x)
        {
            notExist = false;
        }
    }

    for (int i = 0; i < 5; i++)
    {
        if (tryWord1[i] == x || tryWord2[i] == x || tryWord3[i] == x || tryWord4[i] == x || tryWord5[i] == x || tryWord6[i] == x)
        {
            tryExist = true;
        }
    }
    
    return (notExist && tryExist);
}

void modKeyboard()
{
    if (rightPosition('Q'))
    {
        cout << GREEN << " Q " << RESET;
    }
    else if (wrongPosition('Q'))
    {
        cout << YELLOW << " Q " << RESET;
    }
    else if (notPresent('Q'))
    {
        cout << RED << " Q " << RESET;
    }
    else
    {
        cout << LightCyan << " Q " << RESET;
    }

    if (rightPosition('W'))
    {
        cout << GREEN << " W " << RESET;
    }
    else if (wrongPosition('W'))
    {
        cout << YELLOW << " W " << RESET;
    }
    else if (notPresent('W'))
    {
        cout << RED << " W " << RESET;
    }
    else
    {
        cout << LightCyan << " W " << RESET;
    }

    if (rightPosition('E'))
    {
        cout << GREEN << " E " << RESET;
    }
    else if (wrongPosition('E'))
    {
        cout << YELLOW << " E " << RESET;
    }
    else if (notPresent('E'))
    {
        cout << RED << " E " << RESET;
    }
    else
    {
        cout << LightCyan << " E " << RESET;
    }

    if (rightPosition('R'))
    {
        cout << GREEN << " R " << RESET;
    }
    else if (wrongPosition('R'))
    {
        cout << YELLOW << " R " << RESET;
    }
    else if (notPresent('R'))
    {
        cout << RED << " R " << RESET;
    }
    else
    {
        cout << LightCyan << " R " << RESET;
    }

    if (rightPosition('T'))
    {
        cout << GREEN << " T " << RESET;
    }
    else if (wrongPosition('T'))
    {
        cout << YELLOW << " T " << RESET;
    }
    else if (notPresent('T'))
    {
        cout << RED << " T " << RESET;
    }
    else
    {
        cout << LightCyan << " T " << RESET;
    }

    if (rightPosition('Y'))
    {
        cout << GREEN << " Y " << RESET;
    }
    else if (wrongPosition('Y'))
    {
        cout << YELLOW << " Y " << RESET;
    }
    else if (notPresent('Y'))
    {
        cout << RED << " Y " << RESET;
    }
    else
    {
        cout << LightCyan << " Y " << RESET;
    }

    if (rightPosition('U'))
    {
        cout << GREEN << " U " << RESET;
    }
    else if (wrongPosition('U'))
    {
        cout << YELLOW << " U " << RESET;
    }
    else if (notPresent('U'))
    {
        cout << RED << " U " << RESET;
    }
    else
    {
        cout << LightCyan << " U " << RESET;
    }

    if (rightPosition('I'))
    {
        cout << GREEN << " I " << RESET;
    }
    else if (wrongPosition('I'))
    {
        cout << YELLOW << " I " << RESET;
    }
    else if (notPresent('I'))
    {
        cout << RED << " I " << RESET;
    }
    else
    {
        cout << LightCyan << " I " << RESET;
    }

    if (rightPosition('O'))
    {
        cout << GREEN << " O " << RESET;
    }
    else if (wrongPosition('O'))
    {
        cout << YELLOW << " O " << RESET;
    }
    else if (notPresent('O'))
    {
        cout << RED << " O " << RESET;
    }
    else
    {
        cout << LightCyan << " O " << RESET;
    }

    if (rightPosition('P'))
    {
        cout << GREEN << " P " << RESET;
    }
    else if (wrongPosition('P'))
    {
        cout << YELLOW << " P " << RESET;
    }
    else if (notPresent('P'))
    {
        cout << RED << " P " << RESET;
    }
    else
    {
        cout << LightCyan << " P " << RESET;
    }

    cout << DOUBLESPACE;
    cout << "  ";

    if (rightPosition('A'))
    {
        cout << GREEN << " A " << RESET;
    }
    else if (wrongPosition('A'))
    {
        cout << YELLOW << " A " << RESET;
    }
    else if (notPresent('A'))
    {
        cout << RED << " A " << RESET;
    }
    else
    {
        cout << LightCyan << " A " << RESET;
    }

    if (rightPosition('S'))
    {
        cout << GREEN << " S " << RESET;
    }
    else if (wrongPosition('S'))
    {
        cout << YELLOW << " S " << RESET;
    }
    else if (notPresent('S'))
    {
        cout << RED << " S " << RESET;
    }
    else
    {
        cout << LightCyan << " S " << RESET;
    }

    if (rightPosition('D'))
    {
        cout << GREEN << " D " << RESET;
    }
    else if (wrongPosition('D'))
    {
        cout << YELLOW << " D " << RESET;
    }
    else if (notPresent('D'))
    {
        cout << RED << " D " << RESET;
    }
    else
    {
        cout << LightCyan << " D " << RESET;
    }

    if (rightPosition('F'))
    {
        cout << GREEN << " F " << RESET;
    }
    else if (wrongPosition('F'))
    {
        cout << YELLOW << " F " << RESET;
    }
    else if (notPresent('F'))
    {
        cout << RED << " F " << RESET;
    }
    else
    {
        cout << LightCyan << " F " << RESET;
    }

    if (rightPosition('G'))
    {
        cout << GREEN << " G " << RESET;
    }
    else if (wrongPosition('G'))
    {
        cout << YELLOW << " G " << RESET;
    }
    else if (notPresent('G'))
    {
        cout << RED << " G " << RESET;
    }
    else
    {
        cout << LightCyan << " G " << RESET;
    }

    if (rightPosition('H'))
    {
        cout << GREEN << " H " << RESET;
    }
    else if (wrongPosition('H'))
    {
        cout << YELLOW << " H " << RESET;
    }
    else if (notPresent('H'))
    {
        cout << RED << " H " << RESET;
    }
    else
    {
        cout << LightCyan << " H " << RESET;
    
    }
    if (rightPosition('J'))
    {
        cout << GREEN << " J " << RESET;
    }
    else if (wrongPosition('J'))
    {
        cout << YELLOW << " J " << RESET;
    }
    else if (notPresent('J'))
    {
        cout << RED << " J " << RESET;
    }
    else
    {
        cout << LightCyan << " J " << RESET;
    }

    if (rightPosition('K'))
    {
        cout << GREEN << " K " << RESET;
    }
    else if (wrongPosition('K'))
    {
        cout << YELLOW << " K " << RESET;
    }
    else if (notPresent('K'))
    {
        cout << RED << " K " << RESET;
    }
    else
    {
        cout << LightCyan << " K " << RESET;
    }

    if (rightPosition('L'))
    {
        cout << GREEN << " L " << RESET;
    }
    else if (wrongPosition('L'))
    {
        cout << YELLOW << " L " << RESET;
    }
    else if (notPresent('L'))
    {
        cout << RED << " L " << RESET;
    }
    else
    {
        cout << LightCyan << " L " << RESET;
    }

    cout << DOUBLESPACE;
    cout << "     ";

    if (rightPosition('Z'))
    {
        cout << GREEN << " Z " << RESET;
    }
    else if (wrongPosition('Z'))
    {
        cout << YELLOW << " Z " << RESET;
    }
    else if (notPresent('Z'))
    {
        cout << RED << " Z " << RESET;
    }
    else
    {
        cout << LightCyan << " Z " << RESET;
    }

    if (rightPosition('X'))
    {
        cout << GREEN << " X " << RESET;
    }
    else if (wrongPosition('X'))
    {
        cout << YELLOW << " X " << RESET;
    }
    else if (notPresent('X'))
    {
        cout << RED << " X " << RESET;
    }
    else
    {
        cout << LightCyan << " X " << RESET;
    }

    if (rightPosition('C'))
    {
        cout << GREEN << " C " << RESET;
    }
    else if (wrongPosition('C'))
    {
        cout << YELLOW << " C " << RESET;
    }
    else if (notPresent('C'))
    {
        cout << RED << " C " << RESET;
    }
    else
    {
        cout << LightCyan << " C " << RESET;
    }

    if (rightPosition('V'))
    {
        cout << GREEN << " V " << RESET;
    }
    else if (wrongPosition('V'))
    {
        cout << YELLOW << " V " << RESET;
    }
    else if (notPresent('V'))
    {
        cout << RED << " V " << RESET;
    }
    else
    {
        cout << LightCyan << " V " << RESET;
    }

    if (rightPosition('B'))
    {
        cout << GREEN << " B " << RESET;
    }
    else if (wrongPosition('B'))
    {
        cout << YELLOW << " B " << RESET;
    }
    else if (notPresent('B'))
    {
        cout << RED << " B " << RESET;
    }
    else
    {
        cout << LightCyan << " B " << RESET;
    }

    if (rightPosition('N'))
    {
        cout << GREEN << " N " << RESET;
    }
    else if (wrongPosition('N'))
    {
        cout << YELLOW << " N " << RESET;
    }
    else if (notPresent('N'))
    {
        cout << RED << " N " << RESET;
    }
    else
    {
        cout << LightCyan << " N " << RESET;
    }

    if (rightPosition('M'))
    {
        cout << GREEN << " M " << RESET;
    }
    else if (wrongPosition('M'))
    {
        cout << YELLOW << " M " << RESET;
    }
    else if (notPresent('M'))
    {
        cout << RED << " M " << RESET;
    }
    else
    {
        cout << LightCyan << " M " << RESET;
    }
    
    cout << DOUBLESPACE;
}


void checkTry1()
{
    
    // cout << randSelectedWord;

    for (int i = 0; i < 5; i++)
    {
        tryWord1[i] = upperLetter(tryWord1[i]);
    }

    // cout << tryWord1 << " " << randSelectedWord;
    
    // if(tryWord1[0] == randSelectedWord[0] && tryWord1[1] == randSelectedWord[1] && tryWord1[2] == randSelectedWord[2] && tryWord1[3] == randSelectedWord[3] && tryWord1[4] == randSelectedWord[4] )
    // {
    //     for (int i = 0; i < 5; i++)
    //     {
    //         if(tryWord1[i] == randSelectedWord[i])
    //         {
    //             cout << GREEN;
    //             cout << " " << tryWord1[i] << " ";
    //             cout << RESET;
    //         }
    //     }
    if(editDistance(randSelectedWord,tryWord1)==0)
    {

        for (int i = 0; i < 5; i++)
        {
            if(tryWord1[i] == randSelectedWord[i])
            {
                 cout << GREEN;
                 cout << " " << tryWord1[i] << " ";
                 cout << RESET;
            }
        }

        cout << DOUBLESPACE;
        dashMatrix(5);
        cout << DOUBLESPACE << CYAN;
        cout << "You Win!!! The correct word is : ";
        cout << RESET ;

        for (int i = 0; i < 5; i++)
        {
            cout << GREEN;
            cout << " " << tryWord1[i] << " ";
            cout << RESET;
        }

        result = 'Y';
    }
    else
    {
        for (int i = 0; i < 5; i++)
        {
            if (tryWord1[i] == randSelectedWord[i])
            {
                cout << GREEN;
                cout << " " << tryWord1[i] << " ";
                cout << RESET;
            }
            else if ((tryWord1[i] != randSelectedWord[i]) && (tryWord1[i] == randSelectedWord[0] || tryWord1[i] == randSelectedWord[1] || tryWord1[i] == randSelectedWord[2] || tryWord1[i] == randSelectedWord[3] || tryWord1[i] == randSelectedWord[4]))
            {
                cout << YELLOW;
                cout << " " << tryWord1[i] << " ";
                cout << RESET;
            }
            else 
            {
                cout << RED;
                cout << " " << tryWord1[i] << " ";
                cout << RESET;
            }
        }
    }

    cout << DOUBLESPACE;
    // dashMatrix(5);
    // cout << randSelectedWord;

}

void checkTry2()
{
    for (int i = 0; i < 5; i++)
    {
        tryWord2[i] = upperLetter(tryWord2[i]);
    }

    // cout << tryWord2 << " " << randSelectedWord;
    
    // if(tryWord2[0] == randSelectedWord[0] && tryWord2[1] == randSelectedWord[1] && tryWord2[2] == randSelectedWord[2] && tryWord2[3] == randSelectedWord[3] && tryWord2[4] == randSelectedWord[4] )
    // {
    //     for (int i = 0; i < 5; i++)
    //     {
    //         if(tryWord2[i] == randSelectedWord[i])
    //         {
    //             cout << GREEN;
    //             cout << " " << tryWord2[i] << " ";
    //             cout << RESET;
    //         }
    //     }
    if(editDistance(randSelectedWord,tryWord1)==0)
    {

        for (int i = 0; i < 5; i++)
        {
            if(tryWord1[i] == randSelectedWord[i])
            {
                 cout << GREEN;
                 cout << " " << tryWord1[i] << " ";
                 cout << RESET;
            }
        }

        cout << DOUBLESPACE;
        dashMatrix(4);
        cout << DOUBLESPACE << CYAN;
        cout << "You Win!!! The correct word is : ";
        cout << RESET ;

        for (int i = 0; i < 5; i++)
        {
            cout << GREEN;
            cout << " " << tryWord1[i] << " ";
            cout << RESET;
        }

        result = 'Y';
    }
    
    else
    {
        for (int i = 0; i < 5; i++)
        {
            if (tryWord2[i] == randSelectedWord[i])
            {
                cout << GREEN;
                cout << " " << tryWord2[i] << " ";
                cout << RESET;
            }
            else if ((tryWord2[i] != randSelectedWord[i]) && (tryWord2[i] == randSelectedWord[0] || tryWord2[i] == randSelectedWord[1] || tryWord2[i] == randSelectedWord[2] || tryWord2[i] == randSelectedWord[3] || tryWord2[i] == randSelectedWord[4]))
            {
                cout << YELLOW;
                cout << " " << tryWord2[i] << " ";
                cout << RESET;
            }
            else 
            {
                cout << RED;
                cout << " " << tryWord2[i] << " ";
                cout << RESET;
            }
        }
    }
    cout << DOUBLESPACE;
}

void checkTry3()
{
    for (int i = 0; i < 5; i++)
    {
        tryWord3[i] = upperLetter(tryWord3[i]);
    }

    // cout << tryWord3 << " " << randSelectedWord;
    
    if(editDistance(randSelectedWord,tryWord1)==0)
    {

        for (int i = 0; i < 5; i++)
        {
            if(tryWord1[i] == randSelectedWord[i])
            {
                 cout << GREEN;
                 cout << " " << tryWord1[i] << " ";
                 cout << RESET;
            }
        }

        cout << DOUBLESPACE;
        dashMatrix(3);
        cout << DOUBLESPACE << CYAN;
        cout << "You Win!!! The correct word is : ";
        cout << RESET ;

        for (int i = 0; i < 5; i++)
        {
            cout << GREEN;
            cout << " " << tryWord1[i] << " ";
            cout << RESET;
        }

        result = 'Y';
    }
    else
    {
        for (int i = 0; i < 5; i++)
        {
            if (tryWord3[i] == randSelectedWord[i])
            {
                cout << GREEN;
                cout << " " << tryWord3[i] << " ";
                cout << RESET;
            }
            else if ((tryWord3[i] != randSelectedWord[i]) && (tryWord3[i] == randSelectedWord[0] || tryWord3[i] == randSelectedWord[1] || tryWord3[i] == randSelectedWord[2] || tryWord3[i] == randSelectedWord[3] || tryWord3[i] == randSelectedWord[4]))
            {
                cout << YELLOW;
                cout << " " << tryWord3[i] << " ";
                cout << RESET;
            }
            else 
            {
                cout << RED;
                cout << " " << tryWord3[i] << " ";
                cout << RESET;
            }
        }
    }
    cout << DOUBLESPACE;
}

void checkTry4()
{
    for (int i = 0; i < 5; i++)
    {
        tryWord4[i] = upperLetter(tryWord4[i]);
    }

    // cout << tryWord4 << " " << randSelectedWord;
    
    if(editDistance(randSelectedWord,tryWord1)==0)
    {

        for (int i = 0; i < 5; i++)
        {
            if(tryWord1[i] == randSelectedWord[i])
            {
                 cout << GREEN;
                 cout << " " << tryWord1[i] << " ";
                 cout << RESET;
            }
        }

        cout << DOUBLESPACE;
        dashMatrix(2);
        cout << DOUBLESPACE << CYAN;
        cout << "You Win!!! The correct word is : ";
        cout << RESET ;

        for (int i = 0; i < 5; i++)
        {
            cout << GREEN;
            cout << " " << tryWord1[i] << " ";
            cout << RESET;
        }

        result = 'Y';
    }
    else
    {
        for (int i = 0; i < 5; i++)
        {
            if (tryWord4[i] == randSelectedWord[i])
            {
                cout << GREEN;
                cout << " " << tryWord4[i] << " ";
                cout << RESET;
            }
            else if ((tryWord4[i] != randSelectedWord[i]) && (tryWord4[i] == randSelectedWord[0] || tryWord4[i] == randSelectedWord[1] || tryWord4[i] == randSelectedWord[2] || tryWord4[i] == randSelectedWord[3] || tryWord4[i] == randSelectedWord[4]))
            {
                cout << YELLOW;
                cout << " " << tryWord4[i] << " ";
                cout << RESET;
            }
            else 
            {
                cout << RED;
                cout << " " << tryWord4[i] << " ";
                cout << RESET;
            }
        }
    }
    cout << DOUBLESPACE;
}

void checkTry5()
{
    for (int i = 0; i < 5; i++)
    {
        tryWord5[i] = upperLetter(tryWord5[i]);
    }

    // cout << tryWord5 << " " << randSelectedWord;
    
    if(editDistance(randSelectedWord,tryWord1)==0)
    {

        for (int i = 0; i < 5; i++)
        {
            if(tryWord1[i] == randSelectedWord[i])
            {
                 cout << GREEN;
                 cout << " " << tryWord1[i] << " ";
                 cout << RESET;
            }
        }

        cout << DOUBLESPACE;
        dashMatrix(1);
        cout << DOUBLESPACE << CYAN;
        cout << "You Win!!! The correct word is : ";
        cout << RESET ;

        for (int i = 0; i < 5; i++)
        {
            cout << GREEN;
            cout << " " << tryWord1[i] << " ";
            cout << RESET;
        }

        result = 'Y';
    }
    else
    {
        for (int i = 0; i < 5; i++)
        {
            if (tryWord5[i] == randSelectedWord[i])
            {
                cout << GREEN;
                cout << " " << tryWord5[i] << " ";
                cout << RESET;
            }
            else if ((tryWord5[i] != randSelectedWord[i]) && (tryWord5[i] == randSelectedWord[0] || tryWord5[i] == randSelectedWord[1] || tryWord5[i] == randSelectedWord[2] || tryWord5[i] == randSelectedWord[3] || tryWord5[i] == randSelectedWord[4]))
            {
                cout << YELLOW;
                cout << " " << tryWord5[i] << " ";
                cout << RESET;
            }
            else 
            {
                cout << RED;
                cout << " " << tryWord5[i] << " ";
                cout << RESET;
            }
        }
    }
    cout << DOUBLESPACE;
}

void checkTry6()
{
    for (int i = 0; i < 5; i++)
    {
        tryWord6[i] = upperLetter(tryWord6[i]);
    }

    // cout << tryWord6 << " " << randSelectedWord;
    
    if(editDistance(randSelectedWord,tryWord1)==0)
    {

        for (int i = 0; i < 5; i++)
        {
            if(tryWord1[i] == randSelectedWord[i])
            {
                 cout << GREEN;
                 cout << " " << tryWord1[i] << " ";
                 cout << RESET;
            }
        }

        cout << DOUBLESPACE;
        dashMatrix(5);
        cout << DOUBLESPACE << CYAN;
        cout << "You Win!!! The correct word is : ";
        cout << RESET ;

        for (int i = 0; i < 5; i++)
        {
            cout << GREEN;
            cout << " " << tryWord1[i] << " ";
            cout << RESET;
        }

        result = 'Y';
    }
    else
    {
        for (int i = 0; i < 5; i++)
        {
            if (tryWord6[i] == randSelectedWord[i])
            {
                cout << GREEN;
                cout << " " << tryWord6[i] << " ";
                cout << RESET;
            }
            else if ((tryWord6[i] != randSelectedWord[i]) && (tryWord6[i] == randSelectedWord[0] || tryWord6[i] == randSelectedWord[1] || tryWord6[i] == randSelectedWord[2] || tryWord6[i] == randSelectedWord[3] || tryWord6[i] == randSelectedWord[4]))
            {
                cout << YELLOW;
                cout << " " << tryWord6[i] << " ";
                cout << RESET;
            }
            else 
            {
                cout << RED;
                cout << " " << tryWord6[i] << " ";
                cout << RESET;
            }
        }
    }
    cout << DOUBLESPACE;
}

void checkTry()
{
    showTitle(0,5000000);
    dashMatrix(6);
    keyboard();
    
    //starting guessing
    cout << DOUBLESPACE<<LightCyan;
    cout << "Guess : ";
    cin >> tryWord1;
    cout << RESET;

    showTitle(0,2000000);
    cout << DOUBLESPACE;
    checkTry1();

    if (result == 'N')
    {
        dashMatrix(5);
        cout << DOUBLESPACE<<LightCyan;
        modKeyboard();
        cout << "Guess : ";
        cin >> tryWord2;
        cout << RESET;

        cout << CLEAR;
        showTitle(0,500000);
        cout << endl;
        checkTry1();
        checkTry2();

    }

    if (result == 'N')
    {
        dashMatrix(4);
        cout << DOUBLESPACE<<LightCyan;
        modKeyboard();
        cout << "Guess : ";
        cin >> tryWord3;
        cout << RESET;

        cout << CLEAR;
        showTitle(0,500000);
        cout << endl;
        checkTry1();
        checkTry2();
        checkTry3();

    }

    if (result == 'N')
    {
        dashMatrix(3);
        cout << DOUBLESPACE<<LightCyan;
        modKeyboard();
        cout << "Guess : ";
        cin >> tryWord4;
        cout << RESET;

        cout << CLEAR;
        showTitle(0,500000);
        cout << endl;
        checkTry1();
        checkTry2();
        checkTry3();
        checkTry4();

    }
    
    if (result == 'N')
    {
        dashMatrix(2);
        cout << DOUBLESPACE<<LightCyan;
        modKeyboard();
        cout << "Guess : ";
        cin >> tryWord5;
        cout << RESET;

        cout << CLEAR;
        showTitle(0,500000);
        cout << endl;
        checkTry1();
        checkTry2();
        checkTry3();
        checkTry4();
        checkTry5();

    }

    if (result == 'N')
    {
        dashMatrix(1);
        cout << DOUBLESPACE<<LightCyan;
        modKeyboard();
        cout << "Guess : ";
        cin >> tryWord6;
        cout << RESET;

        cout << CLEAR;
        showTitle(0,500000);
        cout << endl;
        checkTry1();
        checkTry2();
        checkTry3();
        checkTry4();
        checkTry5();
        checkTry6();
    }

}

void PlayWord()
{
    showTitle(750000,100000);
    showTitle(0,1000000);

    if(!shouldStart())
    {
        exit(0);
    }
    
    selectRandomWord();

    instructions();

    checkTry();
}