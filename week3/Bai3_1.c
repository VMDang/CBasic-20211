#include<stdio.h>
#include<stdlib.h>
// Khai báo cấu trúc địa chỉ đt
typedef struct 
{
   char name[30];
   char phonenum[20];
   char email[50];
}phone_add;

// Khai báo cấu trúc node
typedef struct node 
{
    phone_add data;
    struct node * pNext;
}NODE;
// Khai báo LIST
typedef struct 
{
    NODE *root;       
    NODE *cur;         
}LIST;
// Hàm khởi tạo danh sách
NODE *Khoitao(LIST *li)
{
    li->root = NULL;
    li->cur = NULL;
}
int main()
{
    int n;
    printf("Number of phone addresss:");
    scanf("%d",&n);
    NODE *new;
    new = (NODE *)malloc(sizeof(NODE)*n);
    new ->data;
    new ->pNext = NULL;
    free(new);
}