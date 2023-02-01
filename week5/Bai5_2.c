#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct 
{
    char name[50];
    char phone[50];
    char email[50];
}Address;

typedef struct 
{
    Address data[10];
    int front, rear;
}Queue;

void MakeNull(Queue *Q)
{
    Q->front = -1;
    Q->rear = -1;
}
int IsEmpty(Queue Q)
{
    return Q.front== -1;
}

int IsFull(Queue Q)
{
    return (Q.rear-Q.front+1)%10 == 0;
}

void EnQueue(Queue *Q, Address x )
{
    if (!IsFull(*Q))
    {
       if (IsEmpty(*Q))
       {
           Q->front=0;
       }
       Q->rear = (Q->rear+1)%10;
       Q->data[Q->rear] = x;
    }
    else printf("Queue is Full");
}

void DeQueue(Queue *Q)
{
    if (!IsEmpty(*Q))
    {
        if (Q->front == Q->rear)
        {
            MakeNull(Q);
        }
        else Q->front = (Q->front+1)%10;
    }
    else printf("Queue is empty.");
}

Address Front(Queue Q)
{
    return Q.data[Q.front];   
}
int main()
{
    Queue Q ;
    MakeNull(&Q);
    FILE *f;
    char str[100];
    f = fopen("input.txt","r");
    int line=0;
    Address tmp;
    Address getdata;
    while (fgets(str,100,f) != NULL)
    {
        line++;
    }
    rewind(f);
    for (int i = 0; i < line; i++)
    {
        fscanf(f,"%s %s %s\n",tmp.name,tmp.phone,tmp.email);
        if (IsFull(Q))
        {
            getdata = Front(Q);
            printf("%s %s %s\n",getdata.name,getdata.phone,getdata.email);
            DeQueue(&Q);
            EnQueue(&Q,tmp);
        }else EnQueue(&Q,tmp);
    }
    
    fclose(f);
}