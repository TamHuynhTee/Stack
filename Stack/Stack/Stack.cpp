#include<stdio.h>
#include<conio.h>
#include<malloc.h>
#include<iostream>
using namespace std;

#define MAX 10

typedef struct Node
{
	int data;
	Node *next;
}node;

typedef struct Stack_of_nodes
{
	int length;
	int capacity;
	node* head;
}Stack;

node* newNode()
{
	node* temp = new node();
	temp->data = 0;
	temp->next = NULL;
	return temp;
}

Stack* initiateStack()
{
	Stack* stack = new Stack();
	stack->length = -1;
	stack->capacity = MAX;
	stack->head = NULL;
	return stack;
}

void stack_Traverse(Stack * stack)
{
	node* p = stack->head;
	printf("Elements in stack: ");
	while (p != NULL)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	cout << endl;
}

bool is_Empty(Stack *stack)
{
	return stack->length == -1;
}

bool is_Full(Stack*stack)
{
	return stack->length == stack->capacity - 1;
}

bool Push(Stack * stack,int x)
{
	node* temp = newNode();
	if (is_Full(stack))
	{
		printf("Overflow confition! Cannot push %d into stack\n", x);
		return false;
	}
	if (is_Empty(stack))
	{
		temp->data = x;
		stack->length++;
		stack->head = temp;
	}
	else
	{
		node* p = newNode();
		p->data = x;
		p->next = stack->head;
		stack->head = p;
		stack->length++;
	}
	return true;
}

bool Pop(Stack * stack)
{
	node* temp = newNode();
	if (is_Empty(stack))
	{
		printf("Stack is empty. Underflow confition!\n");
		return false;
	}
	else
	{
		node *p = new node();
		p = stack->head;
		stack->head = stack->head->next;
		stack->length--;
		delete p;
	}
	return true;
}

int Top(Stack * stack)
{
	return stack->head->data;
}

int Size(Stack * stack)
{
	return stack->length + 1;
}

void Display(Stack * stack)
{
	if (is_Empty(stack))
		printf("Stack is empty.\n");
	else
		printf("The top value is %d, and the size of stack is %d\n", Top(stack), Size(stack));
}

void main()
{
	Stack *stack = initiateStack();
	bool check;
	check = Push(stack, 1);
	check = Push(stack, 5);
	check = Push(stack, 4);
	check = Push(stack, 2);
	check = Push(stack, 6);
	check = Push(stack, 3);
	//check = Pop(stack);
	stack_Traverse(stack);
	//check = Pop(stack);
	//check = Pop(stack);
	Display(stack);
	_getch();
}