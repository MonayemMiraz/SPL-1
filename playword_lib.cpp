#include<bits/stdc++.h>
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
    cout << "\n\n          ";
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

    for (int i = 0; i < strLen(str); i++)
    {
        randSelectedWord[i]=str[i];
        // cout << randSelectedWord[i];
    }
    
}

void instructions()
{
    
    showTitle(0,1000000);
    cout << DOUBLESPACE;

    cout << CYAN;
    cout << "Try to guess the word within 6 tries ";
    cout << DOUBLESPACE;

    cout << "Each guess must be a valid 5 letter word. Hit the enter button to submit ";
    cout << DOUBLESPACE;

    cout << "After each guess, the color of the tiles will change to show how close your guess was to the word ";
    cout << RESET;
    cout << DOUBLESPACE << endl;

    showTitle(0,10000000);
    cout << RESET;
    cout << DOUBLESPACE;

    cout << CYAN;
    cout << "The letter " << RESET;
    cout << GREENletter << "P" << ","<< "y" << "," << "r" << RESET << CYAN <<  " are in the word and in the correct spot ";
    cout << DOUBLESPACE;
    cout << "The letter " << RESET;
    cout << YELLOWletter << "l" << "," << "w" << "," << "d" << RESET << CYAN << " are in the word but in the wrong spot ";
    cout << DOUBLESPACE;
    cout << "The letter " << RESET;
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