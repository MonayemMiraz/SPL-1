#include <bits/stdc++.h>
#include <time.h>
#include <fstream>
#include "playword_lib.h"
#include "stringMatch.cpp"

using namespace std;

// defining variable
char randSelectedWord[5];
char tryWord1[5];
char tryWord2[5];
char tryWord3[5];
char tryWord4[5];
char tryWord5[5];
char tryWord6[5];
// int score = 0;
char result = 'N';
char Alphabates[26] = {'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P',
                       'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L',
                       'Z', 'X', 'C', 'V', 'B', 'N', 'M'};

char upperLetter(char ch)
{
    if ((int)ch >= 97 && (int)ch <= 122)
    {
        ch = char((int)ch - 32);
    }
    return ch;
}

// void playAgain(){
//     char decision;
//     cout << "\n\nDo you want to play Again ?(Y/N)  ";
//     cin >> decision;
//     decision = upperLetter(decision);
//     if(decision == 'Y'){
//         playwordAgain();
//     }
//     else{
//         exit(0);
//     }
// }

// function for using delay in console for design
void my_Sleep(unsigned long ms)
{
    struct timespec ts;
    ts.tv_sec = ms / 1000000ul;           // seconds
    ts.tv_nsec = (ms % 1000000ul) * 1000; // remainder in nanoseconds
    nanosleep(&ts, NULL);
}

// ffunction for the first screen display
void showTitle(int timeForGap, int timeForClear)
{
    my_Sleep(timeForClear);
    cout << CLEAR;
    cout << "\n\n            ";
    cout << GREEN << BOLD << " P ";
    cout << RESET;
    my_Sleep(timeForGap);

    cout << YELLOW << BOLD << " l ";
    cout << RESET;
    my_Sleep(timeForGap);

    cout << RED << BOLD << " a ";
    cout << RESET;
    my_Sleep(timeForGap);

    cout << GREEN << BOLD << " y ";
    cout << RESET;
    my_Sleep(timeForGap);

    cout << YELLOW << BOLD << " W ";
    cout << RESET;
    my_Sleep(timeForGap);

    cout << RED << BOLD << " o ";
    cout << RESET;
    my_Sleep(timeForGap);

    cout << GREEN << BOLD << " r ";
    cout << RESET;
    my_Sleep(timeForGap);

    cout << YELLOW << BOLD << " d ";
    cout << RESET;
    my_Sleep(timeForGap * 5);

    cout << "\n\n";
}

bool shouldStart()
{
    char isReady;

    cout << CYAN;
    cout << "Are you ready to play? Press ('Y') to start  ";
    cout << RESET;

    cin >> isReady;

    isReady = upperLetter(isReady);
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
    int i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    return i;
}

void selectRandomWord()
{
    int randWord;
    srand(time(NULL));
    randWord = rand() % 336;

    string str;

    ifstream file("Dictionary.txt", ios::in);
    file.seekg(ios::beg);

    for (int i = 1; i <= randWord; i++)
    {
        getline(file, str);
    }

    // cout << randWord<<" "<<str;

    for (int i = 0; i < strLen(str); i++)
    {
        randSelectedWord[i] = str[i];
        // cout << randSelectedWord[i]; // MUST be commented
    }
    // randSelectedWord[0]=str[0];
    // randSelectedWord[1]=str[1];
    // randSelectedWord[2]=str[2];
    // randSelectedWord[3]=str[3];
    // randSelectedWord[4]=str[4];

    for (int i = 0; i < 5; i++)
    {
        randSelectedWord[i] = upperLetter(randSelectedWord[i]);
    }

    // cout << randSelectedWord;
    // my_Sleep(10000000);
}

void instructions()
{

    showTitle(0, 600000);
    cout << DOUBLESPACE;

    cout << CYAN;
    cout << "** Try to guess the word within 6 tries ";
    cout << DOUBLESPACE;

    cout << "** Each guess must be a valid 5 letter word. Hit the enter button to submit ";
    cout << DOUBLESPACE;

    cout << "** After each guess, the color of the tiles will change to show how close your guess was to the word ";
    cout << RESET;
    cout << DOUBLESPACE << endl;

    showTitle(0, 5000000);
    cout << RESET;
    cout << DOUBLESPACE;

    cout << CYAN;
    cout << "-> The letter " << RESET;
    cout << GREEN << " P " << RESET << "," << GREEN << " y " << RESET << "," << GREEN << " r " << RESET << CYAN << " are in the word and in the correct spot ";
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

void clearAllVariable()
{
    for (int i = 0; i < 5; i++)
    {
        randSelectedWord[i]='\0';
        tryWord1[i]='\0';
        tryWord2[i]='\0';
        tryWord3[i]='\0';
        tryWord4[i]='\0';
        tryWord5[i]='\0';
        tryWord6[i]='\0';
    }
    
    result = 'N';
}

void keyboard()
{

    cout << DOUBLESPACE;
    cout << LightCyan;
    cout << " Q "
         << " W "
         << " E "
         << " R "
         << " T "
         << " Y "
         << " U "
         << " I "
         << " O "
         << " P ";
    cout << DOUBLESPACE;
    cout << "  "
         << " A "
         << " S "
         << " D "
         << " F "
         << " G "
         << " H "
         << " J "
         << " K "
         << " L ";
    cout << DOUBLESPACE;
    cout << "     "
         << " Z "
         << " X "
         << " C "
         << " V "
         << " B "
         << " N "
         << " M ";
    cout << DOUBLESPACE;
}

bool rightPosition(char x)
{
    if (rabinKarpCheck(randSelectedWord, x))
    {

        for (int i = 0; i < 5; i++)
        {
            if ((randSelectedWord[i] == x) && (tryWord1[i] == randSelectedWord[i] || tryWord2[i] == randSelectedWord[i] || tryWord3[i] == randSelectedWord[i] || tryWord4[i] == randSelectedWord[i] || tryWord5[i] == randSelectedWord[i] || tryWord6[i] == randSelectedWord[i]))
                return true;
        }
    }
    return false;
}

bool wrongPosition(char x)
{
    bool exist = false, tryexist = false;

    // for (int i = 0; i < 5; i++)
    // {
    //     if (randSelectedWord[i]==x)
    //     {
    //         exist = true;
    //         break;
    //     }
    // }

    exist = rabinKarpCheck(randSelectedWord, x);

    for (int i = 0; i < 5; i++)
    {
        if (tryWord1[i] == x || tryWord2[i] == x || tryWord3[i] == x || tryWord4[i] == x || tryWord5[i] == x || tryWord6[i] == x)
        {
            tryexist = true;
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

void printConditionKyeboard(char x)
{

    if (rightPosition(x))
    {
        cout << GREEN << " " << x << " " << RESET;
    }
    else if (wrongPosition(x))
    {
        cout << YELLOW << " " << x << " " << RESET;
    }
    else if (notPresent(x))
    {
        cout << RED << " " << x << " " << RESET;
    }
    else
    {
        cout << LightCyan << " " << x << " " << RESET;
    }
}

void modKeyboard()
{

    for (int i = 0; i < 10; i++)
    {
        printConditionKyeboard(Alphabates[i]);
    }

    cout << DOUBLESPACE;
    cout << "  ";

    for (int i = 10; i < 19; i++)
    {
        printConditionKyeboard(Alphabates[i]);
    }

    cout << DOUBLESPACE;
    cout << "     ";

    for (int i = 19; i < 26; i++)
    {
        printConditionKyeboard(Alphabates[i]);
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

    // cout << editDistance(tryWord1, randSelectedWord) << "     "<< endl;

    if (editDistance(randSelectedWord, tryWord1) == 0)
    {

        for (int i = 0; i < 5; i++)
        {
            if (tryWord1[i] == randSelectedWord[i])
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
        cout << RESET;

        for (int i = 0; i < 5; i++)
        {
            cout << GREEN;
            cout << " " << tryWord1[i] << " ";
            cout << RESET;
        }

        result = 'Y';
        playAgain();
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
    if (editDistance(randSelectedWord, tryWord2) == 0)
    {

        for (int i = 0; i < 5; i++)
        {
            if (tryWord2[i] == randSelectedWord[i])
            {
                cout << GREEN;
                cout << " " << tryWord2[i] << " ";
                cout << RESET;
            }
        }

        cout << DOUBLESPACE;
        dashMatrix(4);
        cout << DOUBLESPACE << CYAN;
        cout << "You Win!!! The correct word is : ";
        cout << RESET;

        for (int i = 0; i < 5; i++)
        {
            cout << GREEN;
            cout << " " << tryWord2[i] << " ";
            cout << RESET;
        }

        result = 'Y';
        playAgain();
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

    if (editDistance(randSelectedWord, tryWord3) == 0)
    {

        for (int i = 0; i < 5; i++)
        {
            if (tryWord3[i] == randSelectedWord[i])
            {
                cout << GREEN;
                cout << " " << tryWord3[i] << " ";
                cout << RESET;
            }
        }

        cout << DOUBLESPACE;
        dashMatrix(3);
        cout << DOUBLESPACE << CYAN;
        cout << "You Win!!! The correct word is : ";
        cout << RESET;

        for (int i = 0; i < 5; i++)
        {
            cout << GREEN;
            cout << " " << tryWord3[i] << " ";
            cout << RESET;
        }

        result = 'Y';
        playAgain();
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

    if (editDistance(randSelectedWord, tryWord4) == 0)
    {

        for (int i = 0; i < 5; i++)
        {
            if (tryWord4[i] == randSelectedWord[i])
            {
                cout << GREEN;
                cout << " " << tryWord4[i] << " ";
                cout << RESET;
            }
        }

        cout << DOUBLESPACE;
        dashMatrix(2);
        cout << DOUBLESPACE << CYAN;
        cout << "You Win!!! The correct word is : ";
        cout << RESET;

        for (int i = 0; i < 5; i++)
        {
            cout << GREEN;
            cout << " " << tryWord4[i] << " ";
            cout << RESET;
        }

        result = 'Y';
        playAgain();
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

    if (editDistance(randSelectedWord, tryWord5) == 0)
    {

        for (int i = 0; i < 5; i++)
        {
            if (tryWord5[i] == randSelectedWord[i])
            {
                cout << GREEN;
                cout << " " << tryWord5[i] << " ";
                cout << RESET;
            }
        }

        cout << DOUBLESPACE;
        dashMatrix(1);
        cout << DOUBLESPACE << CYAN;
        cout << "You Win!!! The correct word is : ";
        cout << RESET;

        for (int i = 0; i < 5; i++)
        {
            cout << GREEN;
            cout << " " << tryWord5[i] << " ";
            cout << RESET;
        }

        result = 'Y';
        playAgain();
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

    if (editDistance(randSelectedWord, tryWord6) == 0)
    {

        for (int i = 0; i < 5; i++)
        {
            if (tryWord1[i] == randSelectedWord[i])
            {
                cout << GREEN;
                cout << " " << tryWord6[i] << " ";
                cout << RESET;
            }
        }

        cout << DOUBLESPACE;
        dashMatrix(0);
        cout << DOUBLESPACE << CYAN;
        cout << "You Win!!! The correct word is : ";
        cout << RESET;

        for (int i = 0; i < 5; i++)
        {
            cout << GREEN;
            cout << " " << tryWord6[i] << " ";
            cout << RESET;
        }

        result = 'Y';
        playAgain();
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

        cout << DOUBLESPACE;

        cout << "The correct word is : ";
        cout << RESET;

        for (int i = 0; i < 5; i++)
        {
            cout << GREEN;
            cout << " " << randSelectedWord[i] << " ";
            cout << RESET;
        }
    }

    cout << DOUBLESPACE;
    playAgain();
}

void playAgain(){
    char playAgainChoice;
    cout << CYAN << "\nDo you want to play again? (Y/N) : " << RESET;
    cin >> playAgainChoice;
    playAgainChoice = upperLetter(playAgainChoice);
    if(playAgainChoice == 'Y'){
        playwordAgain();
    }
    else{
        cout << CYAN << "\nThank you for playing!\n" << RESET;
        exit(0);
    }
}

void checkTry()
{
    showTitle(0, 5000000);
    dashMatrix(6);
    keyboard();

    // starting guessing
    cout << DOUBLESPACE << LightCyan;
    cout << "Guess : ";
    cin >> tryWord1;
    cout << RESET;

    showTitle(0, 2000000);
    cout << DOUBLESPACE;
    checkTry1();

    if (result == 'N')
    {
        dashMatrix(5);
        cout << DOUBLESPACE << LightCyan;
        modKeyboard();
        cout << "Guess : ";
        cin >> tryWord2;
        cout << RESET;

        cout << CLEAR;
        showTitle(0, 500000);
        cout << endl;
        checkTry1();
        checkTry2();
    }

    if (result == 'N')
    {
        dashMatrix(4);
        cout << DOUBLESPACE << LightCyan;
        modKeyboard();
        cout << "Guess : ";
        cin >> tryWord3;
        cout << RESET;

        cout << CLEAR;
        showTitle(0, 500000);
        cout << endl;
        checkTry1();
        checkTry2();
        checkTry3();
    }

    if (result == 'N')
    {
        dashMatrix(3);
        cout << DOUBLESPACE << LightCyan;
        modKeyboard();
        cout << "Guess : ";
        cin >> tryWord4;
        cout << RESET;

        cout << CLEAR;
        showTitle(0, 500000);
        cout << endl;
        checkTry1();
        checkTry2();
        checkTry3();
        checkTry4();
    }

    if (result == 'N')
    {
        dashMatrix(2);
        cout << DOUBLESPACE << LightCyan;
        modKeyboard();
        cout << "Guess : ";
        cin >> tryWord5;
        cout << RESET;

        cout << CLEAR;
        showTitle(0, 500000);
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
        cout << DOUBLESPACE << LightCyan;
        modKeyboard();
        cout << "Guess : ";
        cin >> tryWord6;
        cout << RESET;

        cout << CLEAR;
        showTitle(0, 500000);
        cout << endl;
        checkTry1();
        checkTry2();
        checkTry3();
        checkTry4();
        checkTry5();
        checkTry6();
    }
}

void playwordAgain(){

    cout << CLEAR;

    clearAllVariable();

    selectRandomWord();

    // instructions();

    checkTry();
}

void PlayWord()
{
    // showTitle(750000, 100000);
    showTitle(0, 1000000);

    // if (!shouldStart())
    // {
    //     exit(0);
    // }

    selectRandomWord();

    instructions();

    checkTry();
}