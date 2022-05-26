#pragma
#include<bits/stdc++.h>
#include<string.h>
using namespace std;

#define CLEAR "\e[1;1H\e[2J"
#define RESET  "\033[0m"
#define RED "\033[41m"
#define REDletter "\033[31m" 
#define GREEN "\033[42m" 
#define GREENletter "\033[32m" 
#define YELLOW "\033[43m" 
#define YELLOWletter "\033[33m" 
#define CYAN "\033[36m"
#define BOLD "\033[1m"
#define DOUBLESPACE "\n\n"
#define LightCyan  "\033[96m"

extern string randSelectedBnWord;

extern string tryBnWord1;
extern string tryBnWord2;
extern string tryBnWord3;
extern string tryBnWord4;



void selectRandBnWord();
void banglaInstructions();
void checkBnTry();
void chechBnTry1();
void chechBnTry2();
void chechBnTry3();
void chechBnTry4();
void BanglaPlayWord();