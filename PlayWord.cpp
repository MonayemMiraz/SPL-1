#include<iostream>
#include <time.h> // used for making my_Sleep 

using namespace std;


#define CLEAR "\e[1;1H\e[2J"
#define RESET  "\033[0m"
#define RED "\033[41m" 
#define GREEN "\033[42m" 
#define YELLOW "\033[43m" 
#define CYAN "\033[36m"
#define BOLD "\033[1m"


//function for converting all letter into uppercase
char upperLetter(char ch){
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


// this is the randomly selected word
char randSelectedWord[5];

// here guessWord is the word that the user is trying to guess
// A user can only guess 6 times
char tryWord1[5];
char tryWord2[5];
char tryWord3[5];
char tryWord4[5];
char tryWord5[5];
char tryWord6[5];

//score storing variables
int score=0;

//ffunction for the first screen display
void showTitle(int time)
{
    cout<<"\n\n          ";
    cout<<GREEN<<BOLD<<" P ";
    cout<<RESET;
    my_Sleep(time);

    cout<<YELLOW<<BOLD<<" l ";
    cout<<RESET;
    my_Sleep(time);

    cout<<RED<<BOLD<<" a ";
    cout<<RESET;
    my_Sleep(time);

    cout<<GREEN<<BOLD<<" y ";
    cout<<RESET;
    my_Sleep(time);

    cout<<YELLOW<<BOLD<<" W ";
    cout<<RESET;
    my_Sleep(time);

    cout<<RED<<BOLD<<" o ";
    cout<<RESET;
    my_Sleep(time);

    cout<<GREEN<<BOLD<<" r ";
    cout<<RESET;
    my_Sleep(time);

    cout<<YELLOW<<BOLD<<" d ";
    cout<<RESET;
    my_Sleep(time*5);

    cout<<"\n\n";
    

}

bool shouldStart(char isReady)
{
    if (isReady == 'Y')
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
}





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

    if(!shouldStart(isReady)){
        return 0;
    }
    

}







