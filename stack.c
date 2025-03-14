#include <stdio.h>
#include <stdlib.h>


#define MAX 5

struct Stack
{
	int top;
       int array[MAX];	
};

struct Stack *create_stack()
{
	struct Stack *nu=malloc(sizeof(struct Stack));
	if(nu==NULL)
	{
		printf("memory not allocated\n");
		return NULL;
	}
	nu->top = -1;
	return nu;
}

int full_stack(struct Stack *stack)
{
	return stack->top==MAX-1;
}

int empty_stack(struct Stack *stack)
{
	return stack->top==-1;
}

void push(struct Stack *stack,int data)
{
	if(full_stack(stack))
	{
		printf("stack is over flow\n");	
		return ;
	}
	printf("func:%s\n",__func__);
	stack->array[++stack->top]=data;
}

int peek(struct Stack *stack)
{
	return stack->array[stack->top];
}

int pop(struct Stack *stack)
{
	return stack->array[stack->top--];
}
int main()
{
	struct Stack *stack;
	stack=create_stack();
	push(stack,10);
	push(stack,20);
	push(stack,30);
	push(stack,40);
	push(stack,50);

	printf("top of the stack:%d\n",peek(stack));
	printf("pop of the stack:%d\n",pop(stack));

	printf("top of the stack:%d\n",peek(stack));	
}
