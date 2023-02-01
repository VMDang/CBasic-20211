#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct 
{
    char name[30];
    char phone[30];
    char email[40];
}Address;
int Search_Name(Address data[], int size, char name[])
{
    for (int i = 0; i < size ; i++)
    {
        if (strcmp(data[i].name,name)==0)
        {
            return i;
        }
    }
    return -1;
}
int Search_Phonenumber(Address data[], int size, char phone[])
{
    for (int i = 0; i < size ; i++)
    {
        if (strcmp(data[i].phone,phone)==0 )
        {
            return i;
        }
    }
    return -1;
}
int Search_Email(Address data[], int size, char email[])
{
    for (int i = 0; i < size ; i++)
    {
        if (strcmp(data[i].email,email)==0 )
        {
            return i;
        }
    }
    return -1;
}
int main()
{
    Address *data;
    data = (Address *)malloc(100*sizeof(Address));
    FILE *in,*out;
    in = fopen("input.txt","r");
    out = fopen("student.txt","a");
    for (int i = 0; i < 10; i++)
    {
        fscanf(in,"%s %s %s",data[i].name,data[i].phone,data[i].email);
    }
    int choose;
    char str[40];
    int search;
    printf("Options search Student Address:\n");
    printf("1. Name\n");
    printf("2. Phone Number\n");
    printf("3. Email\n>> ");
    scanf("%d",&choose);
    printf("Enter string >> ");
    fflush(stdin);
    scanf("%s",str);
    switch (choose)
    {
    case 1:
        search = Search_Name(data,10,str);
        break;
    case 2:
        search = Search_Phonenumber(data,10,str);
        break;
    case 3: 
        search = Search_Email(data,10,str);
        break;
    default: printf("Error");
        break;
    }
   if (search != -1)
   {
        printf("%s %s %s\n",data[search].name,data[search].phone,data[search].email);
    fprintf(out,"%s %s %s\n",data[search].name,data[search].phone,data[search].email);
   }else printf("Search Fail.");
    fclose(out);
    fclose(in);
    free(data);
}