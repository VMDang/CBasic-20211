#include<stdio.h>
int main(){
    int arr1[100],arr2[100];
    int n,dem=0;
    scanf("%d");
    for(int i=0;i<n;i++){
        scanf("%d",&arr1[i]);
    }
    for(int i=0;i<n;i++){
        scanf("%d",&arr2[i]);
    }
    for(int i=0;i<n;i++){
        if(arr1[i]==arr2[i]){
            dem++;
        }
    }
    if(dem==n){
        return 1;
    }else    return 0;
}