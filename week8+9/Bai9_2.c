#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct 
{
    int count;
    char *word;
}Element;

struct TreeNode
{
    Element data;
    struct TreeNode *left;
    struct TreeNode *right;
};
typedef struct TreeNode *tNode;

tNode MakeNode(Element item)
{
    tNode new;
    new = (tNode)malloc(sizeof(struct TreeNode));
    new->data = item;
    new->left = NULL;
    new->right = NULL;
}

tNode Insert(tNode root, Element item)
{
    if(root == NULL) return MakeNode(item);
    if (strcmp(root->data.word,item.word)==0)
    {
        root->data.count++;
        return root;
    }
    if(strcmp(root->data.word,item.word)>0)
        root->left = Insert(root->left,item);
    else if(strcmp(root->data.word,item.word)<0)
            root->right = Insert(root->right,item); 
    return root;
}

void InOrder(tNode root)
{
    if(root == NULL) return;
    InOrder(root->left);
    printf("%-5s ----------- %d\n",root->data.word,root->data.count);
    InOrder(root->right);
}

int main()
{
    tNode tree= NULL;
    char str[50];
    gets(str);
    Element tmp;
    char *p ;
    p = strtok(str," ");
    tmp.word = p;
    tmp.count =1;
    tree = Insert(tree,tmp);
    while (p != NULL)
    {
        p = strtok(NULL," ");
        if(p != NULL){
            tmp.word = p;
            tmp.count = 1;
            tree = Insert(tree,tmp);
        }
    }
    printf("\n---------------------------\n");
    InOrder(tree);
}