#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct 
{
    char place[50];
    char people[50];
    char description[100];
}ToDoList;
 
struct node
{
    ToDoList data;
    struct node *pNext;
};
typedef struct node *NODE ;
typedef struct 
{
    NODE Front;
    NODE Rear;
}Queue;

void MakeNull(Queue *Q)
{
    NODE Head;
    Head = (NODE)malloc(sizeof(struct node));
    Head->pNext = NULL;
    Q->Front = Head;
    Q->Rear = Head;
}

int IsEmpty(Queue Q)
{
    return Q.Front == Q.Rear;
}

void Enqueue(Queue *Q, ToDoList x)
{
    Q->Rear->pNext = (NODE)malloc(sizeof(struct node));
    Q->Rear = Q->Rear->pNext;
    Q->Rear->data = x;
    Q->Rear->pNext = NULL;
}

void DeQueue(Queue *Q)
{
    if (!IsEmpty(*Q))
    {
        NODE T;
        T = Q->Front;
        Q->Front = Q->Front->pNext;
        free(T);
    }else printf("Queue is empty.\n");
    
}
void DeleteAll(Queue *Q)
{
    NODE cur = Q->Front;
    if (!IsEmpty(*Q))
    {
        while (cur != NULL)
        {
          Q->Front=  Q->Front->pNext;
          free(cur);
          cur = Q->Front;
        }
    }
    else printf("Queue is empty. No Delete all\n");
}
void PrintAll(Queue Q)
{
    NODE ptr;
    if (!IsEmpty(Q))
    {
        for (ptr = Q.Front->pNext  ; ptr != NULL; ptr= ptr->pNext)
        {
            printf("Place: %s People: %s Description: %s \n",ptr->data.place,ptr->data.people,ptr->data.description);
        }
        printf("\n");
    }
    else printf("Queue is empty. No Print all\n");
}
NODE Front(Queue Q)
{
    NODE tmp;
    if (!IsEmpty(Q))
    {
        tmp = Q.Front;
    }
    else printf("No pop Front\n");
    return tmp;
}
void Input(Queue *Q)
{
    int dem=0;
    ToDoList getdata;
    while (dem !=3)
    {
       scanf("%s%s%s",getdata.place,getdata.people,getdata.description);
       Enqueue(Q,getdata);
       dem++;
    }
}
int main()
{
   Queue Q;
   MakeNull(&Q);
   printf("----------------Done makenull----------------\n");
   Input(&Q);
   printf("----------------Done Input----------------\n");
   PrintAll(Q);
   printf("----------------Done Print----------------\n");
   printf("----------------Pop Front----------------\n");
   NODE tmp = Front(Q);
   printf("%s %s %s\n",tmp->data.place,tmp->data.people,tmp->data.description);
   printf("----------------DeQueue Front----------------\n");
   DeQueue(&Q);
    printf("----------------Print after DeQueue----------------\n");
   PrintAll(Q);
    printf("----------------Delete All----------------\n");
    DeleteAll(&Q);
    printf("----------------Print after DeleteAll----------------\n");
    PrintAll(Q);
    printf("----------------Done----------------\n");
}