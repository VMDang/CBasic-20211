#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct 
{
    char name[30];
    char phone[30];
    char email[40];
}Address;

struct LinkedList
{
    Address data;
    struct LinkedList *pNext;
};
typedef struct LinkedList * nodeLL;

nodeLL H;
nodeLL sorted;

void swap(Address *a,Address *b)
{
    Address tmp =  *a;
    *a = *b;
    *b = tmp;
}

void InsertionSort_Array(Address data[], int length)
{
    Address key;
    for (int i = 1; i <length ; i++)
    {
        key = data[i];
        int j = i-1;
        while (j>=0 && strcmp(data[j].name,key.name)>0)
        {
            data[j+1] = data[j];
            j--;
        }
        data[j+1] = key;
    }
}

void SelectionSort_Array(Address data[], int length)
{
    int min;
    for (int i = 0; i < length-1; i++)
    {
        min = i;
        for (int j = i+1; j < length; j++)
        {
            if (strcmp(data[min].name,data[j].name) >0)
            {
                min = j;
            }   
        }
        swap(&data[min],&data[i]);
    }
    
}

void Print(Address data[], int length,FILE *out)
{
    for (int i = 0; i < length; i++)
    {
        printf("%-30s %-30s %-40s\n",data[i].name,data[i].phone,data[i].email);
        fprintf(out,"%-30s %-30s %-40s\n",data[i].name,data[i].phone,data[i].email);
    }
    
}

nodeLL MakeNode(Address item)
{
    nodeLL new;
    new = (nodeLL)malloc(sizeof(struct LinkedList));
    new->data = item;
    new->pNext = NULL;
    return new;
}

void SelectionSort_LinkedList(nodeLL head)
{
    nodeLL tmp = head;
    while (tmp != NULL)
    {
        nodeLL min = tmp;
        nodeLL r = tmp->pNext;
        while (r != NULL)
        {
            if (strcmp(min->data.name,r->data.name)>0)
            {
                min = r;
            }
            r = r->pNext;
        }
        Address x= tmp->data;
        tmp->data = min->data;
        min->data = x;
        tmp = tmp->pNext;
    }
    
}

void sortedInsert(nodeLL new)
{
    if (sorted == NULL || strcmp(sorted->data.name,new->data.name)>=0)
    {
        new->pNext = sorted;
        sorted = new;
    }
    else
    {
        nodeLL cur = sorted;
        while (cur->pNext != NULL && strcmp(cur->pNext->data.name,new->data.name)<0)
        {
            cur = cur->pNext;
        }
        new->pNext = cur->pNext;
        cur->pNext = new;
    }
    
}

void InsertionSort_LinkedList(nodeLL head)
{
    sorted = NULL;
    nodeLL cur= head;
    while (cur != NULL)
    {
        nodeLL next = cur->pNext;
        sortedInsert(cur);
        cur = next;
    }
    head = sorted;
}

nodeLL AddTail(nodeLL head,Address item)
{
    if(head == NULL) return MakeNode(item);
    nodeLL cur = head;
    nodeLL tmp = MakeNode(item);
    while (cur->pNext != NULL)
    {
        cur = cur->pNext;
    }
    cur->pNext = tmp;
    return head;
}
 
void PrintLinkedList(nodeLL head,FILE *out)
{
    for (nodeLL i = head; i != NULL; i = i->pNext)
    {
        printf("%-30s %-30s %-40s\n",i->data.name,i->data.phone,i->data.email);
        fprintf(out,"%-30s %-30s %-40s\n",i->data.name,i->data.phone,i->data.email);
    }
    
}

int main()
{
    nodeLL head= NULL;
    int numberadd;
    Address data[100],tmp;
    FILE *fi,*fout;
    fi = fopen("input.txt","r");
    fout = fopen("output.txt","w+");
    H = NULL;
    printf("How many address >> "); scanf("%d",&numberadd);
    for (int i = 0; i < numberadd; i++)
    {
        //fscanf(fi,"%s %s %s",data[i].name,data[i].phone,data[i].email);
        fscanf(fi,"%s %s %s",tmp.name,tmp.phone,tmp.email);
        head = AddTail(head,tmp);
    }
    //SelectionSort_LinkedList(head);
    //InsertionSort_LinkedList(head);
    //PrintLinkedList(head);

    //InsertionSort_Array(data,numberadd);
    //electionSort_Array(data,numberadd);
    //Print(data,numberadd);
    fclose(fout);
    fclose(fi);
}