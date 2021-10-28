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
struct node 
{
    phone_add data;
    struct node * pNext;
};
typedef struct node *NODE;
NODE Head()
{
    NODE head;
    head = NULL;
    return head;
}
NODE Khoitao(phone_add getdata)
{
    NODE newnode;
    newnode = (NODE )malloc(sizeof(struct node));
    newnode -> data = getdata;
    newnode ->pNext = NULL; 
    return newnode;
       
}
NODE AddHead(NODE head,phone_add getdata)
{
    NODE tmp = Khoitao(getdata);
    if (head == NULL)
    {
        head = tmp;
    }else
    {
        tmp ->pNext = head;
        head = tmp;
    }
    return head;
    
}
NODE AddTail(NODE head, phone_add getdata)
{
    NODE tmp,p;
    tmp = Khoitao(getdata);
    if (head==NULL)
    {
        head = tmp;
    }
    else
    {
        p = head;
        while (p->pNext != NULL)
        {
            p = p->pNext;
        }
        p ->pNext = tmp;
    }
    return head;
}
void print(NODE head)
{
    if (head == NULL)
    {
        printf("ERROR LIST.");
    }
    for (NODE k = head; k != NULL ;k=k->pNext)
    {
        printf("Name-%s  Phone-%s  Email-%s\n",k->data.name,k->data.phonenum,k->data.email);
    }
    printf("\n");
}

NODE Input()
{
    NODE head = Head();
    int n;
    printf("Number of phone addresss:");
    scanf("%d",&n);
    
    printf("Name phonenumber email:\n");
    fflush(stdin);
    for (int i = 0; i < n; i++)
    {
        phone_add x;
        scanf("%s %s %s",x.name,x.phonenum,x.email);
        head = AddTail(head,x);
    }
    return head;
}
NODE DeleteAt(NODE head, int del_num)
{
    int i=1;
    NODE p = head;
    while (p->pNext->pNext != NULL && i!= del_num)
    {
        p = p ->pNext;
       ++i;
    }
    if (i == del_num)
    {
        p->pNext = p->pNext->pNext;
    }

    return head;
    
}
NODE AddAt(NODE head,int num_add, phone_add getdata)
{
    if (num_add ==0 || head==NULL)
    {
        head = AddHead(head,getdata);
    }else
    {
        int i=1;
        NODE p = head ;
        while (p!= NULL && i!= num_add)
        {
            p = p ->pNext;
            ++i;
        }
        if (i != num_add)
        {
            head = AddTail(head,getdata);
        }else
        {
            NODE tmp = Khoitao(getdata);
            tmp->pNext = p->pNext;
            p->pNext = tmp;
        }
    }
    return head;  
}

NODE DeleteAll(NODE head)
{
    NODE p = head;
    while (p != NULL)
    {
        head = head->pNext;
        free(p);
        p = head;
    }
    return head;
}
int main()
{
    NODE head = Input();
    head = DeleteAt(head,1);
    print(head);
    printf("--------------------\n");
    fflush(stdin);
    phone_add data_temp;
    scanf("%s %s %s",data_temp.name,data_temp.phonenum,data_temp.email);
    head = AddAt(head,2,data_temp);
    print(head);
    printf("--------------------\n");
    head = DeleteAll(head);
    print(head);
}