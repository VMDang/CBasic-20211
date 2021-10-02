#include<stdio.h>
int main()
{
    FILE *p1,*p2;
    if((p1 =fopen("lab1.txt","r"))==NULL){
        printf("Khong mo duoc file 1");
        return 1;
    }else if((p2=fopen("lab1w.txt","w+"))==NULL){
        printf("Khong mo duoc file 2");
        return 1;
    }else{
        char str[100];
        fgets(str,100,p1);
        fputs(str,p2);
        fclose(p2);
        fclose(p1);
    }
    return 0;
}