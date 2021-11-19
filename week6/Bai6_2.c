#include<stdio.h>

int LinearSentinelSearch(int arr[],int size, int x)
{
    int k=0;
    arr[size] = x;
    while (arr[k] != x)
    {
       k++;
    }
    return k+1;
}
int main()
{
    int arr[10];
    int x;
    for (int i = 0; i < 10; i++)
    {
        scanf("%d",&arr[i]);
    }
    scanf("%d",&x);
    printf("Vi tri phan tu %d la : %d",x,LinearSentinelSearch(arr,10,x));
}