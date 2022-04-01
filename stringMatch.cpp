#include "stringMatch.h"
#include <bits/stdc++.h>

using namespace std;

#define d 26
#define q 13

bool rabinKarpCheck(char txt[], char letter)
{
    int M = 1;
    int N = 5;
    int i, j;
    int p = 0;
    int t = 0;
    int h = 1;
    char pat[1];
    pat[0] = letter;
    for (i = 0; i < M - 1; i++)
    {
        h = (h * d) % q;
    }

    for (i = 0; i < M; i++)
    {
        p = (d * p + pat[i]) % q;
        t = (d * t + txt[i]) % q;
    }

    for (i = 0; i <= N - M; i++)
    {
        if (p == t)
        {
            bool flag = true;
            for (j = 0; j < M; j++)
            {
                if (txt[i + j] != pat[j])
                {
                    flag = false;
                    break;
                }
                if (flag)
                {
                    return true;
                }
            }

            // if (j == M)
            // {
            //     return true;
            // }
            // else
            // {
            //     return false;
            // }
        }

        if (i < N - M)
        {
            t = (d * (t - txt[i] * h) + txt[i + M]) % q;
            if (t < 0)
                t = (t + q);
        }
    }
    return false;
}

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