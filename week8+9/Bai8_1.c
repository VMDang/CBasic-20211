#include<stdio.h>
#include<string.h>
#include <stdlib.h>
struct Tnode
{
    char c;
    struct Tnode *left;
    struct Tnode *right;
};
typedef struct Tnode treeNode;
// Tạo 1 nút trên cây
treeNode *makeTreeNode(char c)
{
    treeNode *new = NULL;
    new = (treeNode *)malloc(sizeof(treeNode));
    if (new == NULL)
    {
        printf("Out of memory\n");
        return NULL;
    }
    else
    {
        new->left = NULL;
        new->right = NULL;
        new->c = c;
    }
    return new;   
}

// Đếm số Node trên cây
int countNode(treeNode *T)
{
    if(T==NULL) return 0;
    int ld = countNode(T->left);
    int rd = countNode(T->right);
    return 1 + ld + rd;
}

treeNode *LeftChild(treeNode *T)
{
    if(T != NULL) return T->left;
    else return NULL;
}
treeNode *RightChild(treeNode *T)
{
    if(T != NULL) return T->right;
    else return NULL;
}
// Check nút lá trên cây
int IsLeaf(treeNode *T)
{
    if(T == NULL) return 0;
    else
    {
        return  (LeftChild(T)== NULL && RightChild(T) ==NULL);    
    }
}

// Đếm độ sâu cây nhị phân
int depth(treeNode *T)
{
    if(T == NULL) return 0;
    int ld = depth(T->left);
    int rd = depth(T->right);
    if(ld > rd) return 1 + ld;
    else return 1+rd;
    // return 1 + (ld > rd ? ld : rd);
}

// Loại bỏ cây
void freeTree(treeNode *T)
{
    if(T==NULL) return;
    freeTree(T->left);
    freeTree(T->right);
    free(T);
    return;
}

// Duyệt theo thứ tự trước NLR
void PreOrder(treeNode *T)
{
    if(T == NULL) return;
    printf("%c",T->c);
    PreOrder(T->left);
    PreOrder(T->right);
}
// Duyệt theo thứ tự giữa LNR
void InOrder(treeNode *T)
{
    if(T == NULL) return;
    if (T->left != NULL && T->right != NULL)
    {
    printf("(");
    InOrder(T->left);
    printf("%c",T->c);
    InOrder(T->right);
    printf(")");
    }else
    {
    InOrder(T->left);
    printf("%c",T->c);
    InOrder(T->right);
    }
    
}
// Duyệt theo thứ tự sau LRN
void PostOrder(treeNode *T)
{
    if(T == NULL) return;
    PostOrder(T->left);
    PostOrder(T->right);
    printf("%c",T->c);
}

treeNode *AddLeft(treeNode *T, char c)
{
    treeNode *new,*p;
    new = makeTreeNode(c);
    if(T == NULL) return new;
    else
    {
        treeNode *Lnode = T;
        while (Lnode->left != NULL)
        {
            Lnode = Lnode->left;
        }
        Lnode->left = new;
    }
    return new;
    
}
treeNode *AddRight(treeNode *T, char c)
{
    treeNode *new,*p;
    new = makeTreeNode(c);
    if(T == NULL) return new;
    else
    {
        treeNode *Lnode = T;
        while (Lnode->right != NULL)
        {
            Lnode = Lnode->right;
        }
        Lnode->right= new;
    }
    return new;
    
}
/*
void InputTree(treeNode *T)
{
    char c;
    char choose;
    do
    {   
        printf("Choose LeftChild or RightChild or return Parent >> ");
        scanf("%c",&choose);
        scanf("%c",&c);
        switch (choose)
        {
        case 'L': case 'l':
            AddLeft(T,c);
            break;
        case 'R': case 'r':
            AddRight(T,c);
            break;
         case 'P': case 'p':

            break;
        }

    } while (choose = 'x' && c ='x' );
    
}
*/
// Nối 2 câu với nút gốc V
treeNode *Creat2SubTree(treeNode *Tl,treeNode *Tr,char c)
{
    treeNode *T;
    T = (treeNode *)malloc(sizeof(treeNode));
    T->left = Tl;
    T->right = Tr;
    T->c = c;
}

int countLeaf(treeNode *T)
{
    if (T== NULL )
    {
        return 0; 
    }
    
    if (T->left == NULL && T->right == NULL)
    {
        return 1;
    }
    int LeafLeft = countLeaf(T->left);
    int LeafRight = countLeaf(T->right);
    return LeafLeft + LeafRight;
}

int main()
{
    treeNode *T;
    T = makeTreeNode('+');
    treeNode *T2 = AddLeft(T,'!');
    treeNode *T3 = AddRight(T,'/');
    treeNode *T4 = AddLeft(T2,'a');
    treeNode *T5 = AddLeft(T3,'-');
    treeNode *T6 = AddRight(T3,'d');
    treeNode *T7 = AddLeft(T5,'b');
    treeNode *T8 = AddRight(T5,'c');
    InOrder(T);
    printf("\nNode %d and Leaf %d \n",countNode(T), countLeaf(T));
}