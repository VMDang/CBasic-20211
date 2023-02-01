#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct 
{
    char ID[30];
    char name[30];
    float grade;
}student;
struct list
{
    student data;
    struct list *pNext;
};
typedef struct list *Node;
Node MakeNull()
{
    Node head;
    head = NULL;
    return head;
}
Node CreateNode(student std)
{
    Node new;
    new = (Node)malloc(sizeof(struct list));
    new->data = std;
    new->pNext = NULL;
    return new;
}
Node AddStuden(Node head,student std)
{
    Node cur = head;
    Node tmp = CreateNode(std);
    if(head==NULL) head = tmp;
    else
    {
        while (cur->pNext != NULL)
        {
            cur = cur->pNext;
        }
        cur->pNext = tmp;
    }
    return head;
}
Node Input(Node head, FILE *fi)
{
    student std_tmp;
    char str[100];
    int line=0;
    while (fgets(str,100,fi) != NULL)
    {
        line++;
    }
    rewind(fi);
    for (int i = 0; i < line; i++)
    {
        fscanf(fi,"%s %s %f\n",std_tmp.ID,std_tmp.name,&std_tmp.grade);
        head = AddStuden(head,std_tmp);
    }
    return head;
}
void Print(Node head)
{
    if(head == NULL){
        printf("List is Empty.") ;
        return;
    } 
    Node cur = head;
    for (cur; cur != NULL; cur = cur->pNext)
    {
        printf("%s  %-10s %.2f\n",cur->data.ID,cur->data.name,cur->data.grade);
    }
    printf("\n");
}
Node Search_name(Node head, char name[])
{
    Node cur = head;
    if (head == NULL)
    {
        printf("List is Empty");
        return NULL;
    }
    
    while (cur != NULL)
    {
        if (strcmp(cur->data.name,name)==0)
        {
            return cur;
        }
        
        cur = cur->pNext;
    }
    return NULL;
}
Node Search_grade(Node head, float grade)
{
    if (head == NULL)
    {
        printf("List is Empty");
        return head;
    }
    Node cur = head;
    Node tmp, prev;
    if (cur->data.grade == grade)
    {
        head = head->pNext;
        free(cur);
        return head;
    }
    
    while (cur != NULL && cur->data.grade != grade)
    {
        prev = cur;
        cur = cur->pNext;
    }
    
    if (cur != NULL)
    {
       prev->pNext = cur->pNext;
       free(cur);
    }
    
    return head;
}
int main()
{
    FILE *fi;
    fi = fopen("student.txt","r");
    Node Head,tmp;
    Head = MakeNull();
    Head = Input(Head,fi);
    Print(Head);
    int choose;
    float key2;
    char key[30];
    printf("_____________Menu_____________\n");
    printf("1.Search Name\n");
    printf("2.Search Grade\nEnter option >> ");
    scanf("%d",&choose);
    printf("\nKey >> ");
    fflush(stdin);
    switch (choose)
    {
    case 1:
        scanf("%s",key);
        tmp = Search_name(Head,key);
        break;
    case 2:
        scanf("%f",&key2);
        tmp = Search_grade(Head,key2);
        break;
    default:
    printf("Option is unviable");
        break;
    }
    Print(Head);
    // printf("%s  %-10s %.2f\n",tmp->data.ID,tmp->data.name,tmp->data.grade);
    fclose(fi);
}