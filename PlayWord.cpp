#include <iostream>
#include <time.h>
#include <fstream>
#include "playword_lib.h"
#include "banglaPlayWord.h"

using namespace std;

int main()
{
    showTitle(0, 1000);
    cout << DOUBLESPACE << "Press (1) to play English PlayWord\nPress (2) to play Bangla PlayWord \n";
    cout << "Enter Your choice : ";
    int choice;
    cin >> choice;
    if (choice == 1)
    {
        PlayWord();
    }
    if (choice == 2)
    {
        BanglaPlayWord();
    }
}