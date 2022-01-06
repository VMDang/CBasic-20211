#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct 
{
    char name[30];
    char phone[30];
    char email[40];
}Address;

struct NodeTree
{
    Address data;
    struct NodeTree *left;
    struct NodeTree *right;
};
typedef struct NodeTree *NTree;

NTree MakeNode(Address item)
{   
    NTree new;
    new = (NTree)malloc(sizeof(struct NodeTree));
    new->data = item;
    new->left = NULL;
    new->right = NULL;
    return new;
}

void Inorder(NTree T)
{
    if(T == NULL) return ;
    Inorder(T->left);
    printf("%-30s %-30s %-40s\n",T->data.name,T->data.phone,T->data.email);
    Inorder(T->right);
}

void Inorder_FILEout(NTree T,FILE *fout)
{
    if(T == NULL) return ;
    Inorder_FILEout(T->left,fout);
    fprintf(fout,"%-30s %-30s %-40s\n",T->data.name,T->data.phone,T->data.email);
    Inorder_FILEout(T->right,fout);
}

NTree Insert(NTree T,Address item)
{
    if(T == NULL) return MakeNode(item);
    if (strcmp(T->data.email,item.email) > 0)
    {
        T->left = Insert(T->left,item);
    }else if(strcmp(T->data.email,item.email) < 0)
        T->right = Insert(T->right,item) ;
    return T;
}

NTree Input(NTree T, FILE *fin)
{
    int line=0;
    char str[100];
    Address item;
    while (fgets(str,100,fin) != NULL)
    {
        line++;
    }
    rewind(fin);
    for (int i = 0; i < line; i++)
    {
        fscanf(fin,"%s %s %s",item.name,item.phone,item.email);
        T = Insert(T,item);
    }
    return T;
}

NTree Search(NTree T,char key[])
{
    char *str;
    str = strstr(T->data.email,key);
    if(str == NULL) str = key;
    if(T== NULL || strcmp(T->data.email,str) == 0 ) return T;
    if(strcmp(T->data.email,str) > 0) 
        return Search(T->left,str);
    else if(strcmp(T->data.email,str) < 0)
        return Search(T->right,str);
}

NTree minValue(NTree T)
{
    NTree cur = T;
    while (cur != NULL && cur->left != NULL)
    {
        cur = cur->left;
    }
    return cur;
}

NTree Delete(NTree T, char key[])
{
    char *str;
    str = strstr(T->data.email,key);
    if(str == NULL) str = key;
    if(T == NULL) return T;
    if(strcmp(T->data.email,str) >0)
        T->left = Delete(T->left,key);
    else if(strcmp(T->data.email,str) <0)
            T->right = Delete(T->right,key);
        else
        {
            if(T->left == NULL)
            {
                NTree tmp = T->right;
                free(T);
                return tmp;
            }
            if(T->right == NULL)
            {
                NTree tmp = T->left;
                free(T);
                return tmp;
            }
            NTree tmp = minValue(T->right);
            T->data = tmp->data;
            T->right = Delete(T->right,tmp->data.email);
        }
    return T;  
}

int main()
{
    NTree Tree = NULL;
    FILE *fin, *fout;
    fin = fopen("input.txt","r");
    fout = fopen("output.txt","w+");
    Tree =  Input(Tree,fin);
    Inorder(Tree);
    char str[30];
    printf("------------Search a student------------\nSub or Full email >> ");
    scanf("%s",str);
    NTree tmpSearch = Search(Tree,str);
    printf("%-30s %-30s %-40s\n",tmpSearch->data.name,tmpSearch->data.phone,tmpSearch->data.email);
    fprintf(fout,"Search Result >> %s\t %s\t %s\n",tmpSearch->data.name,tmpSearch->data.phone,tmpSearch->data.email);
    printf("\n------------Delete a student------------\n ");
    Tree = Delete(Tree,str);
    fprintf(fout,"----------------List student after delete -------------\n");
    Inorder_FILEout(Tree,fout);
    Inorder(Tree);
    fclose(fout);
    fclose(fin);
}