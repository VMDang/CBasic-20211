#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct 
{
    char Name[20];
    char Phone[20];
    char Email[50];
}Address;

struct node
{
    Address Data;
    struct node *pNext;
};
typedef struct node *NodeList;
typedef struct 
{
    NodeList Front;
    NodeList Rear;
}Queue;

NodeList CreatNodeList(Address Add)
{
    NodeList new;
    new = (NodeList )malloc(sizeof(struct node));
    new->Data = Add;
    new->pNext = NULL;
    return new;
}

NodeList AddStudent(NodeList Head, NodeList Add)           // Add Tail
{
    NodeList cur,prev = NULL;
    if(Head == NULL) return Add;
    if (strcmp(Add->Data.Name,Head->Data.Name) < 0)
    {
        Add->pNext = Head;
        return Add;
    }
    cur = Head;
    while (cur != NULL && strcmp(Add->Data.Name,cur->Data.Name) > 0 )
    {
        prev = cur;
        cur = cur->pNext;
    }
    prev->pNext = Add;
    Add->pNext = cur;
    return Head;
}

NodeList FindMiddle(NodeList Head, NodeList Tail)
{
    if(Head == NULL)
        return NULL;
    NodeList slow = Head;
    NodeList fast = Head->pNext;
    while (fast != Tail)
    {
        fast= fast->pNext;
        if (fast != Tail)
        {
            slow = slow->pNext;
            fast = fast->pNext;
        }
    }
    return slow;
}

NodeList serchOrganizing(NodeList Head, char key[])
{
    NodeList start = Head;
    NodeList last = NULL;
    do
    {
        NodeList Mid = FindMiddle(start,last);
        if(Mid == NULL) return NULL;
        if(strcmp(Mid->Data.Name,key) == 0)
        {
            return Mid;
        }else if (strcmp(Mid->Data.Name,key) < 0)
        {
            start = Mid->pNext;
        }else last = Mid;
        
    } while (last == NULL || last != start);
    return NULL;
}

void useLinkedList(FILE *in, FILE *out)
{
    int count;
    NodeList Head = NULL ;
    NodeList add;
    Address tmp;
    printf("Number of student ? ");  scanf("%d",&count);
    for (int i = 0; i < count; i++)
    {
       fscanf(in,"%s %s %s",tmp.Name,tmp.Phone,tmp.Email);
       add = CreatNodeList(tmp);
       Head = AddStudent(Head,add);
    }
    for (NodeList i = Head; i != NULL ; i = i->pNext)
    {
        printf("%-20s %-20s %-50s\n",i->Data.Name,i->Data.Phone,i->Data.Email);
    }
    char key[20];
    printf("Search a name >> "); scanf("%s",key);
    add = serchOrganizing(Head,key);
    if (add != NULL)
    {
        printf("%-20s %-20s %-50s\n",add->Data.Name,add->Data.Phone,add->Data.Email);
        fprintf(out,"%-20s %-20s %-50s\n",add->Data.Name,add->Data.Phone,add->Data.Email);
    }else printf("Name error!");
    printf("-----------------\n");
}

int searchBinary(Address Data[],char key[], int Low, int High)
{
    if(Low > High ) return -1;
    int Mid = (Low + High)/2;
    if (strcmp(Data[Mid].Name,key) == 0)
    {
        return Mid;
    }else if (strcmp(Data[Mid].Name,key) > 0)
    {
        return searchBinary(Data,key,Low,Mid-1);
    }else
    {
        return searchBinary(Data,key,Mid+1,High);
    }
    return -1;
}

void useArray(FILE *in, FILE *out)
{
    int count;
    char key[20];
    Address swap;
    Address Data[100];
    printf("Number of student >> "); scanf("%d",&count);
    for (int i = 0; i < count; i++)
    {
        fscanf(in,"%s %s %s",Data[i].Name,Data[i].Phone,Data[i].Email);
    }
    for (int i = 0; i < count; i++)
    {
        for (int j = i+1; j < count; j++)
        {
            if (strcmp(Data[i].Name, Data[j].Name) > 0)
            {
                swap = Data[i] ;
                Data[i] = Data[j];
                Data[j] = swap;
            } 
        }
    }
    printf("Search a name >> "); scanf("%s",key);
    int search = searchBinary(Data,key,0,count-1);
    if (search != -1)
    {
        printf("%-20s %-20s %-50s\n",Data[search].Name,Data[search].Phone,Data[search].Email);
        fprintf(out,"%-20s %-20s %-50s\n",Data[search].Name,Data[search].Phone,Data[search].Email);
    }else printf("Name error!");
}

void MakeNullQueue(Queue *Q)
{
    NodeList Head;
    Head = (NodeList )malloc(sizeof(struct node));
    Head->pNext = NULL;
    Q->Front = Head;
    Q->Rear = Head;
}

void EnQueue(Queue *Q, Address Add)
{
    Q->Rear->pNext = (NodeList)malloc(sizeof(struct node));
    Q->Rear = Q->Rear->pNext;
    Q->Rear->Data = Add;
    Q->Rear->pNext = NULL; 
}

NodeList searchQueue(Queue *Q,char key[])
{
    NodeList find = Q->Rear ;
    while (find != NULL)
    {
        if (strcmp(find->Data.Name,key) == 0)
        {
            return find;
        }
        find = find->pNext;
    }
    return NULL;
}

NodeList Front(Queue *Q)
{
    NodeList tmp;
    if (Q->Front != Q->Rear)
    {
        tmp = Q->Front;
    }else printf("No pop Front\n");
    Q->Front = Q->Front->pNext;
    return tmp;
}

void useQueue(FILE *in, FILE *out)
{
    Queue Q;
    MakeNullQueue(&Q);
    int count;
    char key[20];
    NodeList pop;
    Address tmp;
    printf("Number of student >> "); scanf("%d",&count);
    for (int i = 0; i < count; i++)
    {
        fscanf(in,"%s %s %s",tmp.Name,tmp.Phone,tmp.Email);
        if (i<10)
        {
            EnQueue(&Q,tmp);
        }else {
            pop = Front(&Q);
            printf("%-20s %-20s %-50s\n",pop->Data.Name,pop->Data.Phone,pop->Data.Email);
            fprintf(out,"%-20s %-20s %-50s\n",pop->Data.Name,pop->Data.Phone,pop->Data.Email);
            EnQueue(&Q,tmp);
        }
        
    }
    // printf("Search a name >> "); scanf("%s",key);
    // Add = searchQueue(&Q,key);
    // if (Add != NULL)
    // {
    //     printf("%-20s %-20s %-50s\n",tmp.Name,tmp.Phone,tmp.Email);
    // }else printf("Name error!\n");
    printf("------------------\n");
    for (NodeList i = Q.Front->pNext; i != NULL; i=i->pNext)
    {
        printf("%-20s %-20s %-50s\n",i->Data.Name,i->Data.Phone,i->Data.Email);
    }
    
}
int main()
{
    FILE *in,*out;
    in = fopen("input.txt","r");
    out = fopen("output.txt","w");
    if (in== NULL || out==NULL)
    {
        printf("Open file Fail.");
    }
    //useArray(in,out);
    useLinkedList(in,out);
    //useQueue(in,out);
    fclose(out);
    fclose(in);
}