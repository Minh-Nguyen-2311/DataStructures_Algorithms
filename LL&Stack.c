#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

struct Node{
	int data;
	struct Node *next;
};

struct Stack{
	Node* head;
}

struct Node* NewNode(int new_data){
	Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	if(newNode == NULL)
		return NULL;
	newNode->data = new_data;
	newNode->next = NULL;
	return newNode;
}

void InitiateStack(Stack* stack){
	stack->head = NULL;
}

bool isStackEmpty(Stack* stack){
	if(stack->head == NULL){
		return True; 
	}
	return False;
}

void push(Stack* stack, int new_data){
	Node *newNode = NewNode(new_data);
	if(newNode == NULL)
		return; //Stack overflow
	newNode->next = stack->head; //Link the new node to current top node
	stack->head = newNode; //Update the top
}

void pop(Stack* stack){
	if(isStackEmpty(stack))
		return;
	else{
		Node *temp = stack->head;
		stack->head = stack->head->next; //Update the top
		free(temp);
	}
}