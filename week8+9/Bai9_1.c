#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define bool int 
#define MAX 1000
typedef struct 
{
    char name[30];
    char phone[30];
    char email[30];
}Address;

struct TreeNode
{
    Address data;
    struct TreeNode *left;
    struct TreeNode *right;
};
typedef struct TreeNode *tNode;
struct StackNode
{
    struct TreeNode *t;
    struct StackNode *pNext;
};
typedef struct StackNode *sNode;

tNode MakeNode(Address item)
{
    tNode new;
    new = (tNode)malloc(sizeof(struct TreeNode));
    new->data = item;
    new->left = NULL;
    new->right = NULL;
    return new;
}

bool isEmpty(sNode top)
{
    return (top == NULL)? 1 : 0;
}

tNode Pop(sNode *top_ref)
{
    sNode top;
    tNode res;
    if (isEmpty(*top_ref))
    {
        printf("Stack Underflow");
        return NULL;
    }else
    {
        top = *top_ref;
        res = top->t;
        *top_ref = top->pNext;
        free(top);
        return res;
    }
}

void Push(sNode *top_ref,tNode t)
{
    sNode new;
    new = (sNode)malloc(sizeof(struct StackNode));
    if (new == NULL)
    {
        printf("Stack overflow \n");
        return;
    }
    new->t = t;     //push in the data
    new->pNext = (*top_ref);       // link the old list off the new tNode
    (*top_ref) = new;       // move the head to point to the new tNode

}

void inOrder_Stack(tNode root)    // Interactive Inorder traversal using Stack (DFS)
{
    tNode cur = root;
    sNode S = NULL;
    bool done = 0;
    while (!done)
    {
        if(cur != NULL)
        {
            Push(&S,cur);
            cur = cur->left;
        }else
        {
            if (!isEmpty(S))
            {
                cur = Pop(&S);
                printf("%-30s %-30s %-40s\n",cur->data.name,cur->data.phone,cur->data.email);
                cur = cur->right;
            }
            else done = 1;
        }     
    }   
}

void preOrder(tNode root)           //DFS
{
    if(root == NULL) return ;
    printf("%-30s %-30s %-40s\n",root->data.name,root->data.phone,root->data.email);
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(tNode root)            //DFS
{
    if(root == NULL) return ;
    inOrder(root->left);
    printf("%-30s %-30s %-40s\n",root->data.name,root->data.phone,root->data.email);
    inOrder(root->right);
}

void postOrder(tNode root)          //DFS
{
    if(root == NULL) return ;
    postOrder(root->left);
    postOrder(root->right);
    printf("%-30s %-30s %-40s\n",root->data.name,root->data.phone,root->data.email); 
}

int Height(tNode root)               
{
    if(root == NULL) return 0;
    int Rhight = Height(root->right);
    int Lhight = Height(root->left);
    if(Rhight > Lhight) return (Rhight + 1);
    else return (Lhight+1);
}

void printCurrenLevel(tNode root, int height)
{
    if(root == NULL) return;
    if(height == 1)
        printf("%-30s %-30s %-40s\n",root->data.name,root->data.phone,root->data.email);
    else if (height > 1)
    {
        printCurrenLevel(root->left,height-1);
        printCurrenLevel(root->right,height-1);
    }
    
}

void LevelOrder(tNode root)         //BFS donot use Queue 
{
    int height = Height(root);
    for (int i = 1; i <= height; i++)
    {
        printCurrenLevel(root,i);
    }
    
}

tNode *CreatQueue(int *front, int *rear)
{
    tNode *Queue = (tNode *)malloc(sizeof(tNode)*MAX);
    *front = 0;
    *rear = 0;
    return Queue; 
}

void enQueue(tNode *Q,int *rear, tNode new)
{
    Q[*rear] = new;
    (*rear)++;
}

tNode deQueue(tNode *Q, int *front)
{
    (*front)++;
    return Q[*front -1];
}

void LevelOrder_Queue(tNode root)       //BFS traversal use Queue(Setup by array)
{
    int front,rear;
    tNode *Queue = CreatQueue(&front,&rear);
    tNode tmp = root;
    while (tmp)
    {
        printf("%-30s %-30s %-40s\n",tmp->data.name,tmp->data.phone,tmp->data.email);
        if(tmp->left)
            enQueue(Queue,&rear,tmp->left);
        if(tmp->right)
            enQueue(Queue,&rear,tmp->right);
        tmp = deQueue(Queue,&front);
    }
    
}

tNode Insert(tNode root,Address item)
{
    if(root == NULL) return MakeNode(item);
    if (strcmp(root->data.name,item.name)>0)
    {
        root->left = Insert(root->left,item);
    }else if (strcmp(root->data.name,item.name)<0)
    {
        root->right = Insert(root->right,item);
    }
    return root;
    
}

int main()
{
    tNode tree=NULL;
    Address tmp;
    FILE *fi,*fout;
    fi = fopen("input.txt","r");
    fout = fopen("output.txt","w");
    for (int i = 0; i < 15; i++)
    {
        fscanf(fi,"%s %s %s",tmp.name,tmp.phone,tmp.email);
        
        tree = Insert(tree,tmp);
    }
    printf("\n--------------------Height = %d-----------------\n",Height(tree));
    //inOrder(tree);
    //LevelOrder(tree);
    LevelOrder_Queue(tree);
    fclose(fi);
    fclose(fout);
}