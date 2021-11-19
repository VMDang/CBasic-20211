#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int count=0;
typedef struct 
{
    char name[30];
    char phone[30];
    char email[40];
}Address;
int Binary_SearchName(Address data[], char key[],int Low, int High)
{
    if(Low > High ) return -1;
    int Mid = (Low + High)/2;
    count++;
    if (strcmp(data[Mid].name,key)==0)
    {
        return Mid;
    }else if (strcmp(data[Mid].name,key) > 0)
    {
        return Binary_SearchName(data,key,Low,Mid-1);
    }else return Binary_SearchName(data,key,Mid+1,High);
    return -1;
}
int main()
{
    Address *data;
    data = (Address *)malloc(100*sizeof(Address));
    FILE *in,*out;
    in = fopen("input.txt","r");
    out = fopen("output.txt","a");
    for (int i = 0; i < 10; i++)
    {
        fscanf(in,"%s %s %s",data[i].name,data[i].phone,data[i].email);
    }
    Address swap;
    for (int i = 0; i < 10; i++)
    {
        for (int j = i+1;  j< 10; j++)
        {
            if (strcmp(data[i].name,data[j].name) >0 )
        {
            swap = data[i];
            data[i] = data[j];
            data[j] = swap;
        }
        }
    }
    char key[40];
    printf("Search Name >> ");
    fflush(stdin);
    scanf("%s",key);
    int search = Binary_SearchName(data,key,0,9);
    if (search==-1)
    {
        printf("%d ",count);
        printf("Error");
    }else
    {
         printf("%s %s %s\n",data[search].name,data[search].phone,data[search].email);
        fprintf(out,"%s %s %s\n",data[search].name,data[search].phone,data[search].email);
    }
    
    fclose(out);
    fclose(in);
    free(data);
}