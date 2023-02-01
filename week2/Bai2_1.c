#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char *my_strcat(char *str1,char *str2)
{
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    char *result;
    result = (char*)malloc((len1+len2+1)*sizeof(char));
    if(result == NULL){
        printf("That bai.");
        return NULL;
    }
    strcpy(result,str1);
    strcpy(result+len1,str2);
    return result;
}
int main(){
    char str1[100],str2[100];
    char *cat_str;
    fflush(stdin);
    gets(str1);
    gets(str2);
    cat_str = my_strcat(str1,str2);
    if(cat_str == NULL){
        printf("That bai.");
        return 1;
    }
    printf("Ket qua\n %s",cat_str);
    free(cat_str);
    return 0;
}