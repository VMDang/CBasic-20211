#include<stdio.h>
#include<stdlib.h>
int main()
{
    FILE *fout;
    if((fout=fopen("out.txt","w+"))==NULL){
        printf("Khong tao duoc file.");
        return 1;
    }
    int n,*arr;
    int sum=0;
    arr = (int *)malloc(n*sizeof(int));
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
        sum += arr[i];
    }
    for (int  i = n-1; i >=0 ; i--)
    {
        fprintf(fout,"%d ",arr[i]);
    }
    fprintf(fout,"%d",sum);
    fclose(fout);
    free(arr);
    return 0;
    

    
}