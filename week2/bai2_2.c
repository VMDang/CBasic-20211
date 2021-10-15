#include<stdio.h>
#include<stdlib.h>
int main(){
    int n,*p;
    printf("Nhap n:");
    scanf("%d",&n);
    p = (int *)malloc(n*sizeof(int));
    if(p == NULL){
        printf("Cap phat that bai.");
        return 1;
    }
    for(int i=0;i<n;i++){
        scanf("%d",&p[i]);
    }
    printf("In nguoc:\n");
    for(int i=0;i>=0;--i){
        printf("%d ",p[i]);
    }
    free(p);
    return 0;
}