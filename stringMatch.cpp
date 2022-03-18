#include "stringMatch.h"
#include <bits/stdc++.h>

using namespace std;

// int edTable[5][5] = {0};

int editDistance(string str1, string str2)
{
    int edTable[5][5] = {0};
    for (int i = 1; i <= 5; i++)
    {
        edTable[0][i] = i;
    }
    for (int i = 1; i <= 5; i++)
    {
        edTable[i][0] = i;
    }
    for (int i = 1; i <= 5; i++)
    {
        for (int j = 1; j <= 5; j++)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                edTable[i][j] = edTable[i - 1][j - 1];
                // track[i][j]=DIAGONAL;
            }
            else
            {
                int minimum = min(edTable[i - 1][j], min(edTable[i][j - 1], edTable[i - 1][j - 1]));
                edTable[i][j] = 1 + minimum;
                // if(minimum==edTable[i-1][j]){
                //     // track[i][j]= LEFT;
                // }
                // else if(minimum==edTable[i][j-1]){
                //     // track[i][j]= UP;
                // }
                // else{
                //     // track[i][j]= DIAGONAL;
                // }
            }
        }
    }
    return edTable[5][5];
}

// bool rabin_karp()


