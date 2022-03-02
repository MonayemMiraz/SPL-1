#include<bits/stdc++.h>
#include<time.h>
#include<fstream>
#include"playword_lib.h"
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
    cout << "Are you ready to play? Press (Y) to start  ";
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

    // for (int i = 0; i < 6; i++)
    // {
    //     randSelectedWord[i]=str[i];
    //     cout << randSelectedWord[i];
    // }
    randSelectedWord[0]=str[0];
    randSelectedWord[1]=str[1];
    randSelectedWord[2]=str[2];
    randSelectedWord[3]=str[3];
    randSelectedWord[4]=str[4];

    for (int i = 0; i < 5; i++)
    {
         randSelectedWord[i]=upperLetter(randSelectedWord[i]);
    }
    

    // cout << randSelectedWord;
    // my_Sleep(10000000);
    
}

void instructions()
{
    
    showTitle(0,1000000);
    cout << DOUBLESPACE;

    cout << CYAN;
    cout << "** Try to guess the word within 6 tries ";
    cout << DOUBLESPACE;

    cout << "** Each guess must be a valid 5 letter word. Hit the enter button to submit ";
    cout << DOUBLESPACE;

    cout << "** After each guess, the color of the tiles will change to show how close your guess was to the word ";
    cout << RESET;
    cout << DOUBLESPACE << endl;

    showTitle(0,10000000);
    cout << RESET;
    cout << DOUBLESPACE;

    cout << CYAN;
    cout << "-> The letter " << RESET;
    cout << GREENletter << "P" << ","<< "y" << "," << "r" << RESET << CYAN <<  " are in the word and in the correct spot ";
    cout << DOUBLESPACE;
    cout << "-> The letter " << RESET;
    cout << YELLOWletter << "l" << "," << "w" << "," << "d" << RESET << CYAN << " are in the word but in the wrong spot ";
    cout << DOUBLESPACE;
    cout << "-> The letter " << RESET;
    cout << REDletter << "a" << "," << "o" << RESET << CYAN << " are not in the word ";
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

void checkTry1()
{
    
    // cout << randSelectedWord;

    for (int i = 0; i < 5; i++)
    {
        tryWord1[i] = upperLetter(tryWord1[i]);
    }

    // cout << tryWord1 << " " << randSelectedWord;
    
    if(tryWord1[0] == randSelectedWord[0] && tryWord1[1] == randSelectedWord[1] && tryWord1[2] == randSelectedWord[2] && tryWord1[3] == randSelectedWord[3] && tryWord1[4] == randSelectedWord[4] )
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
        cout << "You Win!!! The correct word was : ";
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
    
    if(tryWord2[0] == randSelectedWord[0] && tryWord2[1] == randSelectedWord[1] && tryWord2[2] == randSelectedWord[2] && tryWord2[3] == randSelectedWord[3] && tryWord2[4] == randSelectedWord[4] )
    {
        for (int i = 0; i < 5; i++)
        {
            if(tryWord2[i] == randSelectedWord[i])
            {
                cout << GREEN;
                cout << " " << tryWord2[i] << " ";
                cout << RESET;
            }
        }

        cout << DOUBLESPACE;
        dashMatrix(4);
        cout << DOUBLESPACE << CYAN;
        cout << "You Win!!! The correct word was : ";
        cout << RESET ;

        for (int i = 0; i < 5; i++)
        {
            cout << GREEN;
            cout << " " << tryWord2[i] << " ";
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
    
    if(tryWord3[0] == randSelectedWord[0] && tryWord3[1] == randSelectedWord[1] && tryWord3[2] == randSelectedWord[2] && tryWord3[3] == randSelectedWord[3] && tryWord3[4] == randSelectedWord[4] )
    {
        for (int i = 0; i < 5; i++)
        {
            if(tryWord3[i] == randSelectedWord[i])
            {
                cout << GREEN;
                cout << " " << tryWord3[i] << " ";
                cout << RESET;
            }
        }

        cout << DOUBLESPACE;
        dashMatrix(3);
        cout << DOUBLESPACE << CYAN;
        cout << "You Win!!! The correct word was : ";
        cout << RESET ;

        for (int i = 0; i < 5; i++)
        {
            cout << GREEN;
            cout << " " << tryWord3[i] << " ";
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
    
    if(tryWord4[0] == randSelectedWord[0] && tryWord4[1] == randSelectedWord[1] && tryWord4[2] == randSelectedWord[2] && tryWord4[3] == randSelectedWord[3] && tryWord4[4] == randSelectedWord[4] )
    {
        for (int i = 0; i < 5; i++)
        {
            if(tryWord4[i] == randSelectedWord[i])
            {
                cout << GREEN;
                cout << " " << tryWord4[i] << " ";
                cout << RESET;
            }
        }

        cout << DOUBLESPACE;
        dashMatrix(2);
        cout << DOUBLESPACE << CYAN;
        cout << "You Win!!! The correct word was : ";
        cout << RESET ;

        for (int i = 0; i < 5; i++)
        {
            cout << GREEN;
            cout << " " << tryWord4[i] << " ";
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
    
    if(tryWord5[0] == randSelectedWord[0] && tryWord5[1] == randSelectedWord[1] && tryWord5[2] == randSelectedWord[2] && tryWord5[3] == randSelectedWord[3] && tryWord5[4] == randSelectedWord[4] )
    {
        for (int i = 0; i < 5; i++)
        {
            if(tryWord5[i] == randSelectedWord[i])
            {
                cout << GREEN;
                cout << " " << tryWord5[i] << " ";
                cout << RESET;
            }
        }

        cout << DOUBLESPACE;
        dashMatrix(1);
        cout << DOUBLESPACE << CYAN;
        cout << "You Win!!! The correct word was : ";
        cout << RESET ;

        for (int i = 0; i < 5; i++)
        {
            cout << GREEN;
            cout << " " << tryWord5[i] << " ";
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
    
    if(tryWord6[0] == randSelectedWord[0] && tryWord6[1] == randSelectedWord[1] && tryWord6[2] == randSelectedWord[2] && tryWord6[3] == randSelectedWord[3] && tryWord6[4] == randSelectedWord[4] )
    {
        for (int i = 0; i < 5; i++)
        {
            if(tryWord6[i] == randSelectedWord[i])
            {
                cout << GREEN;
                cout << " " << tryWord6[i] << " ";
                cout << RESET;
            }
        }

        cout << DOUBLESPACE;
        cout << DOUBLESPACE << CYAN;
        cout << "You Win!!! The correct word was : ";
        cout << RESET ;

        for (int i = 0; i < 5; i++)
        {
            cout << GREEN;
            cout << " " << tryWord6[i] << " ";
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
        keyboard();
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
        keyboard();
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
        keyboard();
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
        keyboard();
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
        keyboard();
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