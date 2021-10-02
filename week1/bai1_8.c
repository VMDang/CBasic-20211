#include<stdio.h>
int main()
{
    FILE *f1,*f2;
    if((f1 =fopen("lab1.txt","r"))==NULL){
        printf("Khong mo duoc file 1");
        return 1;
    }else if((f2=fopen("lab1w.txt","w+"))==NULL){
        printf("Khong mo duoc file 2");
        return 1;
    }else{
        int i=0;
        char str[100];
        fgets(str,100,f1);
        while (str[i] !='\0')
        {
            if(str[i]>='a' && str[i]<='z'){
                str[i] = str[i] - 32;
            }
            if(str[i]>='A' && str[i]<='Z'){
                str[i] = str[i] + 32;
            }
            i++;
        }
        fputs(f2,"%s",str);
        fclose(f2);
        fclose(f1);
    }
    return 0;
}