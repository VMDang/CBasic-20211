#include<stdio.h>
#include<stdlib.h>
#define MAX 50
typedef struct 
{
    char name[30];
    char phone[30];
    char email[30];
}Address;

typedef struct 
{
    Address data[MAX];
    int top;
}StackType ;
int empty(StackType stack)
{
    return stack.top==0;
}
void Intialize(StackType *stack)
{
    (*stack).top=0;
}
int full(StackType stack)
{
    return stack.top==MAX;
}
void push(StackType *stack,Address element )
{
    if (full(*stack))
    {
        printf("stack overflow");
    }else (*stack).data[(*stack).top++] = element;
    
}
Address pop(StackType *stack)
{
    if (empty(*stack))
    {
       printf("Stack unoverflow");
    }else return (*stack).data[--(*stack).top];
    
}
int main()
{
    StackType stack;
    char str[100];
    FILE *in,*out;
    int line=0;
    in = fopen("input.txt","r");
    out = fopen("output.txt","w");
    while (fgets(str,100,in) != NULL)
    {
        line++;
    }
    rewind(in);
    // Push
    for (int i = 0; i <line; i++)
    {
        Address data;
        fscanf(in,"%s %s %s",data.name,data.phone,data.email);
        push(&stack,data);
    }
    // pop
    Address print;
    for (int i = 0; i < line; i++)
    {
        print = pop(&stack);
        fprintf(out,"%s %s %s\n",print.name,print.phone,print.email);
    }
    
    fclose(out);
    fclose(in);
}