#include<iostream>
#include <time.h> // used for making my_Sleep function

using namespace std;

#define __USE_POSIX199309
#define _POSIX_C_SOURCE 199309L
#define RESET  "\033[0m"
#define RED "\033[41m" 
#define GREEN "\033[42m" 
#define YELLOW "\033[43m" 
#define BOLD "\033[1m"

void my_Sleep(unsigned long ms)
{
    struct timespec ts;
    ts.tv_sec = ms / 1000000ul;            // whole seconds
    ts.tv_nsec = (ms % 1000000ul) * 1000;  // remainder, in nanoseconds
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
int score;

//ffunction for the first screen display
void showTitle(int time)
{

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
my_Sleep(time);

}






int main()
{

    showTitle(750000);
    

}







