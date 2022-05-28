#include <iostream>
#include <time.h>
#include <fstream>
#include "playword_lib.h"
#include "banglaPlayWord.h"

using namespace std;

// void playAgain(){
    // char playAgainChoice;
    // cout << CYAN << "\nDo you want to play again? (Y/N) : " << RESET;
    // cin >> playAgainChoice;
    // playAgainChoice = upperLetter(playAgainChoice);
    // if(playAgainChoice == 'Y'){
        // goto label;
    // }
    // else{
        // cout << CYAN << "\nThank you for playing!\n" << RESET;
        // exit(0);
    // }
// }

int main()
{

label:\
    
    showTitle(0, 1000);
    cout << DOUBLESPACE << "Press (1) to play English PlayWord\nPress (2) to play Bangla PlayWord \n";
    cout << "Enter Your choice : ";
    int choice;
    cin >> choice;
    cin.ignore();
    if (choice == 1)
    {
        PlayWord();
    }
    if (choice == 2)
    {
        BanglaPlayWord();
    }

    // playAgain();
    char playAgainChoice;
    cout << CYAN << "\nDo you want to play again? (Y/N) : " << RESET;
    cin >> playAgainChoice;
    playAgainChoice = upperLetter(playAgainChoice);
    if(playAgainChoice == 'Y'){
        goto label;
    }
    else{
        cout << CYAN << "\nThanks for playing!\n" << RESET;
        exit(0);
    }
}