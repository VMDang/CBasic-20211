#include<stdio.h>
void xoaptumang(int n,int arr[],int j){
    for(j;j<n;j++){
        arr[j] = arr[j+1];
    }
}
int main(){
    int n,arr[100];
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(arr[i] == arr[j]  && i!=j ){
                xoaptumang(n,arr,j);
                n--;
            }
        }
    }
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}