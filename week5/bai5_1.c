#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_LENGTH 50
typedef struct 
{
    char name[50];
    char phone[50];
    char email[50];
}Address;

typedef struct 
{
    Address data[MAX_LENGTH];
    int Front, Rear;
}Queue;

void MakeNull_Queue(Queue *Q)
{
    Q->Front= -1;
    Q->Rear = -1;
}

int Empty_Queue(Queue Q)
{
    return Q.Front==-1;
}

int Full_Queue(Queue Q)
{
    return (Q.Rear-Q.Front+1)%MAX_LENGTH ==0 ;
}

void EnQueue(Queue *Q, Address x)
{
    if (!Full_Queue(*Q))
    {
        if (Empty_Queue(*Q))
        {
            Q->Front=0;
        }
        Q->Rear = (Q->Rear+1)%MAX_LENGTH;
        Q->data[Q->Rear] = x; 
    }
    else printf("Queue is full !");
}

void DeQueue(Queue *Q)
{
    if (!Empty_Queue(*Q))
    {
        if (Q->Front == Q->Rear)
        {
            MakeNull_Queue(Q);
        }
        else Q->Front = (Q->Front+1)%MAX_LENGTH;  
    }
    else printf("Queue is empty!");
}

Address Front(Queue Q)
{
    return Q.data[Q.Front];
}
int main()
{
    Queue Q;
    MakeNull_Queue(&Q);
    FILE *in,*out;
    in = fopen("input.txt","r");
    out = fopen("output.txt","w");
    int line=0;
    char str[150];
    Address data;
    while (fgets(str,150,in) != NULL)
    {
        line++;
    }
    rewind(in);
    for (int i = 0; i < line; i++)
    {
       fscanf(in,"%s %s %s",data.name,data.phone,data.email);
       EnQueue(&Q,data);
    }
    Address getdata;
    for (int i = 0; i < line; i++)
    {
        getdata = Front(Q);
        DeQueue(&Q);
        fprintf(out,"%s %s %s\n",getdata.name,getdata.phone,getdata.email);
    }
    
    fclose(out);
    fclose(in);
}