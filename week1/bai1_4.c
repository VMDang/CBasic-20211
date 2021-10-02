#include<stdio.h>
char thay_chu_cai(char s[],char k1,char k2){
	int i;
	for(i=0; s[i] != '\0';++i){
		if(s[i]==k1)
			s[i]=k2;
	}
}    
int main(){
    char str[100],kitu1,kitu2;
	int i;
	printf("Nhap xau:");
	gets(str);
	printf("Nhap 2 ki tu:");
	fseek(stdin,0,SEEK_END);
	scanf("%c %c",&kitu1,&kitu2);
	thay_chu_cai(str,kitu1,kitu2);
	printf("%s",str);
}

	