#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct 
{
    char Name[20];
    char Phone[20];
    char Email[50];
}Address;

void swap(Address *a, Address *b)
{
    Address tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

int PartitionR(Address list[], int L, int R)
{
    int i = L;
    int j = R+1;
    Address p = list[L];
    while (i<j)
    {
        i++;
        while ((i<=R) && (strcmp(list[i].Name,p.Name)<=0)) i++;
        j--;
        while((j>=L) && (strcmp(list[j].Name,p.Name)>0)) j--;
        swap(&list[i],&list[j]);
    }
    swap(&list[i],&list[j]);
    swap(&list[j],&list[L]);
    return j;
}

void quickSort(Address list[], int L, int R)
{
    int pivot;
    if (L < R)
    {
       pivot = PartitionR(list,L,R);
       if(L<pivot) quickSort(list,L,pivot-1);
       if(R > pivot) quickSort(list,pivot+1,R);
    }
    
}

void merge(Address data[],int l, int m, int r)
{
    int i,j,k;
    int n1 = m-l +1;
    int n2 = r-m;
    Address L[n1], R[n2];
    for ( i = 0; i < n1; i++)
    {
        L[i] = data[l+i];
    }
    for ( j = 0; j < n2; j++)
    {
        R[j] = data[m+1+j];
    }
    i = 0;
    j = 0;
    k = l;
    while (i<n1 && j<n2)
    {
        if (strcmp(L[i].Name,R[j].Name)<=0)
        {
            data[k]  = L[i];
            i++;
        }
        else
        {
            data[k] = R[j];
            j++; 
        }
        k++;
    }
    while (i<n1)
    {
        data[k] = L[i];
        i++;
        k++;
    }
    while (j<n2)
    {
        data[i] = R[j];
        j++;
        k++;
    }
}

void mergeSort(Address data[], int l, int r)
{
    if (l<r)
    {
        int m = l +(r-l)/2;
        mergeSort(data,l,m);
        mergeSort(data,m+1,r);

        merge(data,l,m,r);
    }
    
}

void Print(Address list[])
{
    for (int i = 0; i < 10; i++)
    {
        printf("%-20s %-20s %-0s\n",list[i].Name,list[i].Phone,list[i].Email);
    }
}

int main()
{
    Address list[10];
    FILE *in, *out;
    in = fopen("input.txt","r");
    out = fopen("output.txt","w+");
    for (int i = 0; i < 10; i++)
    {
        fscanf(in, "%s %s %s",list[i].Name,list[i].Phone,list[i].Email);
    }
    //quickSort(list,0,9);
    mergeSort(list,0,9);
    Print(list);
    for (int i = 0; i < 10; i++)
    {
        fprintf(out, "%-30s %-30s %-40s\n",list[i].Name,list[i].Phone,list[i].Email);
    }
    fclose(out);
    fclose(in);
}