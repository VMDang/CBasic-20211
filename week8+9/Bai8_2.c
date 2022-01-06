/*Full course binary search tree data struct */
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};
typedef struct node * NodeT;

NodeT MakeNode(int value)
{
    NodeT new;
    new = (NodeT)malloc(sizeof(struct node));
    new->data = value;
    new->left = NULL;
    new->right = NULL;
    return new;
}

void InOrder(NodeT T)
{
    if(T == NULL) return;
    InOrder(T->left);
    printf("%d ",T->data);
    InOrder(T->right);
}

NodeT Insert(NodeT T,int key)
{
    if(T == NULL) return MakeNode(key);
    if (key < T->data)
    {
        T->left = Insert(T->left,key);
    }else if (key > T->data)
    {
        T->right = Insert(T->right,key);
    }
    
    return T;
}

NodeT Search(NodeT T,int key)
{
    if(T == NULL || T->data == key ) 
        return T;
    if(key < T->data)
        return Search(T->left,key);
    if(key > T->data)
        return Search(T->right,key);
}

NodeT minValue(NodeT T)
{
    NodeT cur = T;
    while (cur != NULL && cur->left != NULL)
    {
        cur = cur->left;
    }
    return cur;
}

NodeT DeleteNode(NodeT T,int key)
{
    if(T == NULL) return T;
    if (key < T->data)
    {
        T->left = DeleteNode(T->left,key);
    }
    else if (key > T->data)
    {
        T->right = DeleteNode(T->right,key);
    }
    else
    {
        if (T->left == NULL)
        {
            NodeT tmp = T->right;
            free(T);
            return tmp;
        }else if (T->right == NULL)
        {
            NodeT tmp = T->left;
            free(T);
            return tmp;
        }
        
        NodeT tmp = minValue(T->right);
        T->data = tmp->data;
        T->right = DeleteNode(T->right,tmp->data);
    }
    return T;
}

void FreeTree(NodeT T)
{
    if (T != NULL)
    {
        FreeTree(T->left);
        FreeTree(T->right);
        free(T);
    }
}

int main()
{
    NodeT Tree = NULL;
    printf("-----------Create a binary search tree-----------\n");
    for (int i = 0; i < 10; i++)
    {
        Tree = Insert(Tree,rand());   
    }
    printf("-----------Print tree with inorder------------\n");
    InOrder(Tree);
    printf("\n-----------Insert a element and print tree ------------\n");
    Insert(Tree,1000);
    InOrder(Tree);
    printf("\n-----------Delete a element and print tree ------------\n");
    Tree = DeleteNode(Tree,41);
    InOrder(Tree);
    printf("\n-----------Search a element and print tree ------------\n");
    NodeT tmp = Search(Tree,18467);
    printf("Search = %d \n",tmp->data);
    printf("\n-----------Free and print tree ------------\n");
    FreeTree(Tree);
    InOrder(Tree);
}