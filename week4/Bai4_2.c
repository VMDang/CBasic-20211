#include<stdio.h>
#include<stdlib.h>
struct node
{
    char c;
    struct node *pNext;
};
typedef struct node *NODE;
NODE CreatHead()
{
    NODE head;
    head = NULL;
    return head;
}
NODE CreatNode( char data)
{
    NODE new;
    new = (NODE)malloc(sizeof(struct node));
    new->c = data;
    new->pNext = NULL;
    return new;
}
NODE AddHead(NODE head,char c)
{
    NODE tmp = CreatNode(c);
    if (tmp == NULL)
    {
        return tmp;
    }else
    {
        tmp->pNext = head;
        head = tmp;
    }
    return head;
}

NODE input()
{
    NODE head = CreatHead();
    char c;
    printf("Nhap vao phep toan (dung khi gap x):\n");
    do
    {
    scanf("%c",&c);
    if (c>='1' && c<='9')
    {
       printf("%c ",c);
    }else if (c =='+' || c=='-' || c=='*' || c=='/')
    {
        head = AddHead(head,c);
    }
    } while (c!= 'x');
    return head;
}
void In(NODE head)
{
    for (NODE i = head; i != NULL; i=i->pNext)
    {
       printf("%c ",i->c);
    }
    printf("\n");
}
int main()
{
    NODE head = input();
    In(head);
}