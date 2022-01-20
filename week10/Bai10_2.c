#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct 
{
    char name[30];
    char phone[30];
    char email[40];
}Address;

void swap(Address *x, Address *y)
{
    Address tmp;
    tmp = *x;
    *x = *y;
    *y = tmp;
}

void Heapfy(Address data[],int n, int i)
{
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    if (l<n && strcmp(data[l].name,data[largest].name)>0)
    {
        largest = l;
    }
    if (r<n && strcmp(data[r].name,data[largest].name)>0)
    {
        largest = r;
    }
    if (largest != i)
    {
        swap(&data[i],&data[largest]);
        Heapfy(data,n,largest);
    }
    
}

void HeapSort(Address data[],int n)
{
    for (int i = n/2-1; i >=0 ; i--)
    {
        Heapfy(data,n,i);
    }
    for (int i = n-1; i >0; i--)
    {
        swap(&data[0],&data[i]);
        Heapfy(data,i,0);
    }
    
}

void DeleteRoot(Address data[],int &n)
{
    Address lastElement = data[n-1];
    data[0] = lastElement; // replace;
    n =n-1;                   // Delete lastElement
    Heapfy(data,n,0);
}

void PrintHeap(Address data[],int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%-30s %-30s %-40s\n",data[i].name,data[i].phone,data[i].email);
    }
}

void insertNode(Address data[], int &n, Address key)
{
    n = n+1;
    data[n-1] = key;
    Heapfy(data,n,n-1);
}
int main()
{
    Address data[100];
    Address tmp;
    int n;
    FILE *fi,*fout;
    fi = fopen("input.txt","r");
    fout = fopen("output.txt","w+");
    printf("Number of address >> "); scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        fscanf(fi,"%s %s %s",data[i].name,data[i].phone,data[i].email);
    }
    HeapSort(data,n);
    PrintHeap(data,n);
    for (int i = 0; i < n; i++)
    {
       fprintf(fout,"%-30s %-30s %-40s\n",data[i].name,data[i].phone,data[i].email);
    }
    DeleteRoot(data,n);
    printf("\n-------------Deleted First Address (Root)---------\n");
    HeapSort(data,n);
    PrintHeap(data,n);
    printf("\n-------------Add a Address ---------\n");
    printf("Address: Name Phone Email >> ");
    scanf("%s %s %s",tmp.name,tmp.phone,tmp.email);
    insertNode(data,n,tmp);
    HeapSort(data,n);
    PrintHeap(data,n);
    fclose(fi);
    fclose(fout);
}