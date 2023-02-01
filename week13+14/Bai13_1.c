#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Navie_SearchStr(char *pattern, char *text)
{
    int m = strlen(pattern);
    int n = strlen(text);
    for (int i = 0; i <= n-m; i++)
    {
        int j;
        for (j = 0; j < m; j++)
        {
            if (text[i+j] != pattern[j])
                break;
        }   
        if (j==m)
        printf("The pattern found index: %d\n",i);
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
    Navie_SearchStr(pattern,text);

    
}