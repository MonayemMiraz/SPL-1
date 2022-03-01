#pragma
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

// this is the randomly selected word
extern char randSelectedWord[5];

// here guessWord is the word that the user is trying to guess
// A user can only guess 6 times
extern char tryWord1[5];
extern char tryWord2[5];
extern char tryWord3[5];
extern char tryWord4[5];
extern char tryWord5[5];
extern char tryWord6[5];

//score storing variables
extern int score;


char upperLetter(char ch);
void my_Sleep(unsigned long ms);
void showTitle(int time);
bool shouldStart();
void selectRandomWord();
int strLen(std::string str);
void instructions();
void dashMatrix(int n);