#include<iostream>
#include<time.h>
#include<fstream> // used for making my_Sleep 
#include"playword_lib.h"

using namespace std;



int main()
{
    
    showTitle(750000,100000);
    showTitle(0,1000000);

    if(!shouldStart())
    {
        return 0;
    }
    
    selectRandomWord();

    instructions();
    
    dashMatrix(6);
    keyboard();



}







