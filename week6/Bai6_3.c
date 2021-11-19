#include<stdio.h>
#include<stdlib.h>
int counter=0;
int binary_search(int arr[],int key,int Low,int High)
{
    if(Low > High) return -1;
    counter++;
    int Mid = (Low + High)/2;   
    if (arr[Mid] == key)
    {
        return Mid;
    }else if (key < arr[Mid])
    {
        return binary_search(arr,key,Low,Mid-1);
    }else return binary_search(arr,key,Mid+1,High);
    
    return -1;
}
int main()
{
    int arr[100];
    int tmp;
    for (int i = 0; i < 100; i++)
    {
        arr[i] = rand();
        printf("%d ",arr[i]);
    }
    for (int i = 0; i < 100; i++)
    {
        for (int j = i+1; j < 100; j++)
        {
            if (arr[i] > arr[j])
            {
                tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }
    printf("----------------\n");
    int key;
    scanf("%d",&key);
    int search = binary_search(arr,key,0,99);
    if (search ==-1 )
    {
        printf("Not found");
    }
    else printf("%d\n",search);
    printf("%d\n",counter);
}