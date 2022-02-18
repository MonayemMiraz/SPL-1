#include<iostream>
#include<time.h>
#include<fstream> // used for making my_Sleep 
#include"SPL.h"

using namespace std;



int main()
{
    cout<<RESET;

    showTitle(750000);
    cout<<CLEAR;
    
    showTitle(0);
    char isReady;
    cout<<CYAN;
    cout<<"Are you ready to play? Press (Y) to start  ";
    cout<<RESET;
    cin>>isReady;
    isReady=upperLetter(isReady);
    // cout<<isReady;

    if(!shouldStart(isReady))
    {
        return 0;
    }
    
    selectRandomWord();

}







