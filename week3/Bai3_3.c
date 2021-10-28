#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//Cau truc sinh vien
typedef struct 
{
    char ID[15];
    char name[30];
    int grade;
}student;
// Cau truc Node Linked List
struct node
{
    student std_data;
    struct node *pNext;
};
typedef struct node *NODE;
// Cau truc node hoan chinh
NODE CreatNode(student data)
{
    NODE head ;
    head = (NODE)malloc(sizeof(struct node));
    head->std_data = data;
    head->pNext = NULL;
    return head;
}
// Tao nut Head
NODE CreatHead()
{
    NODE head;
    head->pNext= NULL;
    return head;
}
// 
NODE AddStudent(NODE head,NODE add)
{
    NODE cur_std,prev_std=NULL;
    if (head ==NULL)
    {
       return add;
    }
    if (add->std_data.grade > head->std_data.grade)
    {
        add->pNext = head;
        return add;
    }
    cur_std = head;
    while (cur_std != NULL && add->std_data.grade < cur_std->std_data.grade)
    {
        prev_std = cur_std;
        cur_std = cur_std->pNext;
    }
    prev_std->pNext = add;
    add->pNext = cur_std;
    return head;
}    
// Nhap du lieu
NODE INPUT() 
{
    NODE head= NULL;
    NODE add;
    printf("How many student ? ");
    int n;
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
       student st;
       scanf("%s %s %d",st.ID,st.name,&st.grade);
       add = CreatNode(st);
       head = AddStudent(head,add);
    }
    return head;
}
// In ket qua
void print(NODE head)
{
    for (NODE i = head; i != NULL; i=i->pNext)
    {
        printf("ID-%s Name-%s Grade-%d\n",i->std_data.ID,i->std_data.name,i->std_data.grade);
    }
    printf("\n");
}
// Chen 1 sinh vien vao danh sach
NODE AddAt(NODE head,student data)
{
    NODE tmp;
    tmp = CreatNode(data);
    if (head == NULL)
    {
       return tmp; 
    }
    if (tmp->std_data.grade > head->std_data.grade)
    {
        tmp->pNext = head;
        return tmp;
    }
    NODE prev_std=NULL;
    NODE cur_std= head;
    while (cur_std != NULL && tmp->std_data.grade < cur_std->std_data.grade)
    {
        prev_std = cur_std;
        cur_std = cur_std->pNext;
    }
    prev_std->pNext = tmp;
    tmp ->pNext = cur_std;
    return head;
}
// Tim sinh vien dua theo ID
NODE find_student_ID(NODE head, char id[])
{
    NODE find = head;
    while (find != NULL)
    {
        if (strcmp(find->std_data.ID,id) ==0)
        {
            return find;
        }
        find = find->pNext;
        
    }
    return NULL;
}
// Xoa 1 sinh vien
NODE Delete_ID(NODE head, char id[])
{
    if (head ==NULL)
    {
       return head;
    }
    NODE cur = head;
    NODE prev;
    if (strcmp(cur->std_data.ID,id)==0)
    {
        head = head->pNext;
        free(cur);
        return head;
    }
    while (cur != NULL && strcmp(cur->std_data.ID,id)!=0)
    {
        prev = cur;
        cur = cur->pNext;
    }
    if (cur !=NULL)
    {
        prev->pNext = cur->pNext;
        free(cur);
    }
    return head;
}

NODE DeleteAll(NODE head)
{
    NODE cur = head;
    while (cur != NULL )
    {
        head = head->pNext;
        free(cur);
        cur = head;
    }
    return head;
}
int main()
{
    NODE head;
    NODE node_tmp;
    student data_tmp;
    head = INPUT();
    print(head);
    printf("---------Add a student to list----------\n");
    scanf("%s %s %d",data_tmp.ID,data_tmp.name,&data_tmp.grade);
    head = AddAt(head,data_tmp);
    print(head);
    printf("---------Find a student from list----------\n");
    scanf("%s",data_tmp.ID);
    node_tmp = find_student_ID(head,data_tmp.ID);
    if (node_tmp == NULL )
        printf("ID is not valid.\n");
    else 
        printf("ID-%s Name-%s Grade-%d\n",node_tmp->std_data.ID,node_tmp->std_data.name,node_tmp->std_data.grade);
    printf("---------Delete a student from list----------\n");
    scanf("%s",data_tmp.ID);
    head = Delete_ID(head,data_tmp.ID);
    print(head);
    printf("---------Delete all list----------\n");
    head = DeleteAll(head);
    print(head);
    return 0;
}