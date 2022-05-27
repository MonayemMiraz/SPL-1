#include <bits/stdc++.h>
#include <time.h>
#include <fstream>
#include "banglaPlayWord.h"

using namespace std;

string randSelectedBnWord;
string tryBnWord1;
string tryBnWord2;
string tryBnWord3;
string tryBnWord4;
string mstr[3];

char BnResult = 'N';

void my_BnSleep(unsigned long ms)
{
    struct timespec ts;
    ts.tv_sec = ms / 1000000ul;           // seconds
    ts.tv_nsec = (ms % 1000000ul) * 1000; // remainder in nanoseconds
    nanosleep(&ts, NULL);
}

// ffunction for the first screen display
void showBnTitle(int timeForGap, int timeForClear)
{
    my_BnSleep(timeForClear);
    cout << CLEAR;
    cout << "\n\n            ";
    cout << GREEN << BOLD << " P ";
    cout << RESET;
    my_BnSleep(timeForGap);

    cout << YELLOW << BOLD << " l ";
    cout << RESET;
    my_BnSleep(timeForGap);

    cout << RED << BOLD << " a ";
    cout << RESET;
    my_BnSleep(timeForGap);

    cout << GREEN << BOLD << " y ";
    cout << RESET;
    my_BnSleep(timeForGap);

    cout << YELLOW << BOLD << " W ";
    cout << RESET;
    my_BnSleep(timeForGap);

    cout << RED << BOLD << " o ";
    cout << RESET;
    my_BnSleep(timeForGap);

    cout << GREEN << BOLD << " r ";
    cout << RESET;
    my_BnSleep(timeForGap);

    cout << YELLOW << BOLD << " d ";
    cout << RESET;
    my_BnSleep(timeForGap * 5);

    cout << "\n\n";
}

void dashBnMatrix(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << " _ ";
        }
        cout << DOUBLESPACE;
    }
}

void selectRandBnWord()
{
    int randWord;
    srand(time(NULL));
    randWord = rand() % 91;

    cout <<" " << endl;
    // //------------------------------------------------------------------------
    // cout << "HOise??" << endl;
    string str;

    ifstream file("Bangla_Dictionary.txt", ios::in);
    file.seekg(ios::beg);

    for (int i = 1; i <= randWord; i++)
    {
        getline(file, str);
    }

    randSelectedBnWord = str;
    //------------------------------------------------------------------------
    // cout << "HOise??";
    string temp;
    temp = randSelectedBnWord.substr(3,9);
    mstr[0] = randSelectedBnWord.substr(0, 3);
    mstr[1] = temp.substr(0, 3);
    mstr[2] = randSelectedBnWord.substr(6, 9);
}

void banglaInstructions()
{
    cout << "Some intructions later";
    cout << DOUBLESPACE;
    my_BnSleep(5000000);
}

void checkBnTry1()
{
    string str1[3],temp;
    temp = tryBnWord1.substr(3,9);
    str1[0] = tryBnWord1.substr(0, 3);
    str1[1] = temp.substr(0, 3);
    str1[2] = tryBnWord1.substr(6, 9);

    if (tryBnWord1 == randSelectedBnWord)
    {
        cout << GREEN;
        cout << " " << str1[0] << "  " << str1[1] << "  " << str1[2] << " ";
        cout << RESET;
        cout << DOUBLESPACE;
        dashBnMatrix(3);
        cout << DOUBLESPACE << CYAN;
        cout << " আপনি সঠিক অনুমান করেছেন । ";
        cout << GREEN;
        cout << " " << str1[0] << "  " << str1[1] << "  " << str1[2] << " ";
        cout << RESET;
        BnResult = 'Y';
    }
    else
    {
        for (int i = 0; i < 3; i++)
        {
            if (str1[i] == mstr[i])
            {
                cout << GREEN;
                cout << " " << str1[i] << " ";
                cout << RESET;
            }
            else if ((str1[i] != mstr[i]) && (str1[i] == mstr[0] || str1[i] == mstr[1] || str1[i] == mstr[2]))
            {
                cout << YELLOW;
                cout << " " << str1[i] << " ";
                cout << RESET;
            }
            else
            {
                cout << RED;
                cout << " " << str1[i] << " ";
                cout << RESET;
            }
        }
    }
    cout << DOUBLESPACE;
}

void checkBnTry2()
{
    string str2[3],temp;
    temp = tryBnWord2.substr(3,9);
    str2[0] = tryBnWord2.substr(0, 3);
    str2[1] = temp.substr(0,3);
    str2[2] = tryBnWord2.substr(6, 9);

    if (tryBnWord2 == randSelectedBnWord)
    {
        cout << GREEN;
        cout << " " << str2[0] << "  " << str2[1] << "  " << str2[2] << " ";
        cout << RESET;
        cout << DOUBLESPACE;
        dashBnMatrix(2);
        cout << DOUBLESPACE << CYAN;
        cout << " আপনি সঠিক অনুমান করেছেন । ";
        cout << GREEN;
        cout << " " << str2[0] << "  " << str2[1] << "  " << str2[2] << " ";
        cout << RESET;
        BnResult = 'Y';
    }
    else
    {
        for (int i = 0; i < 3; i++)
        {
            if (str2[i] == mstr[i])
            {
                cout << GREEN;
                cout << " " << str2[i] << " ";
                cout << RESET;
            }
            else if ((str2[i] != mstr[i]) && (str2[i] == mstr[0] || str2[i] == mstr[1] || str2[i] == mstr[2]))
            {
                cout << YELLOW;
                cout << " " << str2[i] << " ";
                cout << RESET;
            }
            else
            {
                cout << RED;
                cout << " " << str2[i] << " ";
                cout << RESET;
            }
        }
    }
    cout << DOUBLESPACE;
}

void checkBnTry3()
{
    string str3[3],temp;
    temp = tryBnWord3.substr(3,9);
    str3[0] = tryBnWord3.substr(0, 3);
    str3[1] = temp.substr(0, 3);
    str3[2] = tryBnWord3.substr(6, 9);

    if (tryBnWord3 == randSelectedBnWord)
    {
        cout << GREEN;
        cout << " " << str3[0] << "  " << str3[1] << "  " << str3[2] << " ";
        cout << RESET;
        cout << DOUBLESPACE;
        dashBnMatrix(1);
        cout << DOUBLESPACE << CYAN;
        cout << " আপনি সঠিক অনুমান করেছেন । ";
        cout << GREEN;
        cout << " " << str3[0] << "  " << str3[1] << "  " << str3[2] << " ";
        cout << RESET;
        BnResult = 'Y';
    }
    else
    {
        for (int i = 0; i < 3; i++)
        {
            if (str3[i] == mstr[i])
            {
                cout << GREEN;
                cout << " " << str3[i] << " ";
                cout << RESET;
            }
            else if ((str3[i] != mstr[i]) && (str3[i] == mstr[0] || str3[i] == mstr[1] || str3[i] == mstr[2]))
            {
                cout << YELLOW;
                cout << " " << str3[i] << " ";
                cout << RESET;
            }
            else
            {
                cout << RED;
                cout << " " << str3[i] << " ";
                cout << RESET;
            }
        }
    }
    cout << DOUBLESPACE;
}

void checkBnTry4()
{
    string str4[3],temp;
    temp = tryBnWord4.substr(3,9);
    str4[0] = tryBnWord4.substr(0, 3);
    str4[1] = temp.substr(0, 3);
    str4[2] = tryBnWord4.substr(6, 9);

    if (tryBnWord4 == randSelectedBnWord)
    {
        cout << GREEN;
        cout << " " << str4[0] << "  " << str4[1] << "  " << str4[2] << " ";
        cout << RESET;
        cout << DOUBLESPACE;
        dashBnMatrix(0);
        cout << DOUBLESPACE << CYAN;
        cout << " আপনি সঠিক অনুমান করেছেন । ";
        cout << GREEN;
        cout << " " << str4[0] << "  " << str4[1] << "  " << str4[2] << " ";
        cout << RESET;
        BnResult = 'Y';
    }
    else
    {
        for (int i = 0; i < 3; i++)
        {
            if (str4[i] == mstr[i])
            {
                cout << GREEN;
                cout << " " << str4[i] << " ";
                cout << RESET;
            }
            else if ((str4[i] != mstr[i]) && (str4[i] == mstr[0] || str4[i] == mstr[1] || str4[i] == mstr[2]))
            {
                cout << YELLOW;
                cout << " " << str4[i] << " ";
                cout << RESET;
            }
            else
            {
                cout << RED;
                cout << " " << str4[i] << " ";
                cout << RESET;
            }
        }

        cout << DOUBLESPACE;

        cout << "সঠিক শব্দটি হচ্ছে  : ";
        cout << RESET;

        for (int i = 0; i < 3; i++)
        {
            cout << GREEN;
            cout << " " << mstr[i] << " ";
            cout << RESET;
        }
    }

    cout << DOUBLESPACE;
}

void checkBnTry()
{

    showBnTitle(0, 500);
    dashBnMatrix(4);

    cout << DOUBLESPACE << LightCyan;
    cout << "অনুমান করুন : ";
    cin >> tryBnWord1;
    cout << RESET;

    cout << CLEAR;
    showBnTitle(0, 500000);
    cout << DOUBLESPACE;
    checkBnTry1();

    if (BnResult == 'N')
    {
        dashBnMatrix(3);
        cout << DOUBLESPACE << LightCyan;
        cout << "অনুমান করুন : ";
        cin >> tryBnWord2;
        cout << RESET;

        cout << CLEAR;
        showBnTitle(0, 500000);
        cout << endl;
        checkBnTry1();
        checkBnTry2();
    }

    if (BnResult == 'N')
    {
        dashBnMatrix(2);
        cout << DOUBLESPACE << LightCyan;
        cout << "অনুমান করুন : ";
        cin >> tryBnWord3;
        cout << RESET;

        cout << CLEAR;
        showBnTitle(0, 500000);
        cout << endl;
        checkBnTry1();
        checkBnTry2();
        checkBnTry3();
    }

    if (BnResult == 'N')
    {
        dashBnMatrix(1);
        cout << DOUBLESPACE << LightCyan;
        cout << "অনুমান করুন : ";
        cin >> tryBnWord4;
        cout << RESET;

        cout << CLEAR;
        showBnTitle(0, 500000);
        cout << endl;
        checkBnTry1();
        checkBnTry2();
        checkBnTry3();
        checkBnTry4();
    }
}

void BanglaPlayWord()
{
    showBnTitle(0, 1000000);

    // if (!shouldStart())
    // {
    //     exit(0);
    // }

    selectRandBnWord();
    banglaInstructions();
    checkBnTry();
}