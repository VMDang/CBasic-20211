// Task 2
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
struct Stack
{
	int top;
	unsigned data;
	int* array;
};

struct Stack* createStack( unsigned capacity )
{
	struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
	if (!stack)  return NULL;
	stack->top = -1;
	stack->data = capacity;

	stack->array = (int*) malloc(stack->data *
								sizeof(int));
    if(!stack->array) return NULL;
	return stack;
}
int isEmpty(struct Stack* stack)
{
	return stack->top == -1 ;
}
char peek(struct Stack* stack)
{
	return stack->array[stack->top];
}
char pop(struct Stack* stack)
{
	if (!isEmpty(stack))
		return stack->array[stack->top--] ;
	return '$';
}
void push(struct Stack* stack, char op)
{
	stack->array[++stack->top] = op;
}
int isOperand(char ch)
{
	return (ch >= '0' && ch <= '9') ;
}

int Prec(char ch)
{
	switch (ch)
	{
	case '+':
	case '-':
		return 1;

	case '*':
	case '/':
		return 2;

	case '^':
		return 3;
	}
	return -1;
}

void push2(struct Stack* stack, int op)
{
	stack->array[++stack->top] = op;
}

int infixToPostfix(char* exp)
{
	int i, k;
	struct Stack* stack = createStack(strlen(exp));
	if(!stack) 
		return -1 ;

	for (i = 0, k = -1; exp[i]; ++i)
	{
		if (isOperand(exp[i]))
			exp[++k] = exp[i];
		else if (exp[i] == '(')
			push(stack, exp[i]);
		else if (exp[i] == ')')
		{
			while (!isEmpty(stack) && peek(stack) != '(')
				exp[++k] = pop(stack);
			if (!isEmpty(stack) && peek(stack) != '(')
				return -1;			
			else
				pop(stack);
		}
		else 
		{
			while (!isEmpty(stack) &&
				Prec(exp[i]) <= Prec(peek(stack)))
				exp[++k] = pop(stack);
			push(stack, exp[i]);
		}

	}
	while (!isEmpty(stack))
		exp[++k] = pop(stack );

	exp[++k] = '\0';
	printf( "%s", exp );
}

int PostfixtoValue(char *exp)
{
    struct Stack *stack = createStack(strlen(exp));
    int i;
    if(!stack) return -1;
    for ( i = 0; exp[i]; ++i)
    {
        if (exp[i] ==' ')
        {
            continue;
        }
        else if(isdigit(exp[i]))
        {
            int num = 0;
            while (isdigit(exp[i]))
            {
                num = num*10 + (int)(exp[i]-'0');
                i++;
            }
            i--;
            push2(stack,num);
        }    
        else
        {
            int value1 = pop(stack);
            int value2 = pop(stack);
            switch (exp[i])
            {
            case '+' : push2(stack,value2+value1); break;
            case '-' : push2(stack,value2-value1); break;
            case '*' : push2(stack,value2*value1); break;
            case '/' : push2(stack,value2/value1); break;
            }
        }
    }
    return (int)pop(stack);
}

int main()
{
	char exp[50];
    printf("Nhap vao bieu thuc (Infix)>> ");
    scanf("%s",exp);
    printf("Convert '%s' Infix to Postfix >> ",exp);
    infixToPostfix(exp);
	printf("\nConvert '%s' to value >> %d",exp,PostfixtoValue(exp));
	return 0;
}
