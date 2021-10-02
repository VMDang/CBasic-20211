#include<stdio.h>
#include<string.h>
void so_ki_tu(FILE *fin,FILE *fout){
    char str[1000];
    while (fgets(str,1000,fin) !=NULL)
    {
        fprintf(fout,"%d %s",strlen(str),str);     
    }
    
}
int main(){
    FILE *f1,*f2;
    if((f1=fopen("lab1.txt","r"))==NULL){
        printf("Khong mo duoc file 1.");
        return 1;
    }else if((f2=fopen("lab1w.txt","a+"))==NULL){
        printf("Khong mo duoc file 2.");
        return 1;
    }else{
        so_ki_tu(f1,f2);
        fprintf(f2,"\n\n");
        fclose(f2);
        fclose(f1);
    }
}