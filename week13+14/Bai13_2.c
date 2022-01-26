#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE_CHAR 256

int max(int a, int b)
{
    return (a>b)?a:b;
}

void badCharHeuristic(char *str, int size,int badchar[SIZE_CHAR])
{
    int i;
    for (i = 0; i < SIZE_CHAR; i++)
    {
        badchar[i] = -1;
    }
    for ( i = 0; i < size; i++)
    {
        badchar[(int)str[i]] = i;
    }
    
}

void BoyerMoore_SearchString(char *text, char *pattern)
{
    int m = strlen(pattern);
    int n = strlen(text);
    int badchar[SIZE_CHAR];
    badCharHeuristic(pattern,m,badchar);
    int s = 0;
    while (s<= (n-m))
    {
        int j= m-1;
        while (j>=0 && pattern[j]==text[s+j])
        {
            j--;
        }
        if (j<0)
        {
            printf("\n Pattern occurs at shift = %d",s);
            s += (s+m < n)? m-badchar[text[s+m]]:1;
        }else
        {
            s += max(1,j-badchar[text[s+j]]);
        }
    }
    
}

int main()
{
    char text[2000] ;
    for (int i = 0; i < 2000; i++)
    {
        text[i] = (char)(rand()%5+97);
    }
    printf("%s\n",text);
    char pattern[] = "cde";
    BoyerMoore_SearchString(text,pattern);
}