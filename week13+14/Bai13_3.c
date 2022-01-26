#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void computeLPSArray(char *pattern,int M, int *lps)
{
    int len = 0;
    lps[0] = 0;
    int i = 1;
    while (i<M)
    {
        if (pattern[i]==pattern[len])
        {
            len++;
            lps[i] = len;
            i++;
        }else
        {
            if (len!=0)
            {
                len = lps[len-1];
            }else
            {
                lps[i] = 0;
                i++;
            }
        }  
    }
}

void KMP_SearchString(char *pattern, char *text)
{
    int M = strlen(pattern);
    int N = strlen(text);
    int lps[M];
    computeLPSArray(pattern,M,lps);

    int i=0,j=0;
    while (i<N)
    {
        if (pattern[j]==text[i])
        {
            j++;
            i++;
        }
        if (j==M)
        {
            printf("Found pattern at index %d\n",i-j);
            j = lps[j-1];
        }
        else if (i<N && pattern[j] != text[i])
        {
            if(j!=0)    
                j = lps[j-1];
            else i++;
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
    KMP_SearchString(pattern,text);
}