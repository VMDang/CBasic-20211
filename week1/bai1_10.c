#include<stdio.h>
void thu_tu_dong(FILE *fin,FILE *fout){
    char str[1000];
    int i=1;
    while (fgets(str,1000,fin)  != NULL)
    {
        fprintf(fout,"%d %s",i,str);
        i++;
    }
    
}
int main(){
    FILE *f1,*f2;
    if((f1=fopen("lab1.txt","r"))==NULL){
        printf("Khong mo duoc file 1.");
        return 1;
    }else if ((f2=fopen("lab1w.txt","a+"))==NULL)
    {
        printf("Khong mo duoc file 2.");
        return 1;
    }else {
        thu_tu_dong(f1,f2);
        fprintf(f2,"\n\n");
        fclose(f2);
        fclose(f1);
    }
    
}