#include<stdio.h>
int main(){
    char str[100];
    printf("The output for the input line:");
    // fflush(stdin);
    gets(str);
    int i=0;
    int  count[26]={0};
    while (str[i] != '\0')
    {
        if(str[i]>='a' && str[i]<='z'){
            count[str[i]-97]++;
        }
        // if(str[i]>='A' && str[i]<='Z'){
        //     count[str[i]-65]++;
        // }
        i++;
    }
    for(i=0;i<26;i++){
        if(count[i] !=0){
            printf("The letter '%c' appears %d time(s) \n",i+97,count[i]);
        }
    }
    
}