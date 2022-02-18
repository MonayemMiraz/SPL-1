#include<iostream>
#include<time.h>
#include<fstream> // used for making my_Sleep 
#include"playword_lib.h"

using namespace std;



int main()
{
    cout<<RESET;

    showTitle(750000);
    cout<<CLEAR;
    
    showTitle(0);

    if(!shouldStart())
    {
        return 0;
    }
    
    selectRandomWord();

    instructions();


}







