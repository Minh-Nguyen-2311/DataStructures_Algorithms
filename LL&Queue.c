/*There are several types of linked list: singly linked list, doubly linked list, circular linked list*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct SinglyNode{
	int data;
	SinglyNode *next; //pointer to next node
};

struct DoublyNode{
	int data;
	Node* next; //pointer to next node
	Node* prev; //pointer to previous node
};

struct GenericNode{
	void *data; //can be used to store any data
	struct GenericNode *next;
};

struct Queue{
	struct SinglyNode *front, *rear; //initialize a queue with front and rear
}

struct SinglyNode *NewNode(int* data);
struct Queue *NewQueue();

void enQueue(struct Queue *q, int* data);
void deQueue(struct Queue *q, int* data);

bool checkQueueState(struct Queue *q);

struct SinglyNode *NewNode(int* data){
	struct SinglyNode *node = (struct SinglyNode*)malloc(sizeof(struct SinglyNode));
	if(node == NULL){
		return NULL;
	}
	node->data = data;
	node->next = NULL;
	return node;
}

struct Queue *NewQueue(){
	struct Queue *queue = (struct Queue*)malloc(sizeof(struct Queue));
	queue->front = queue->rear = NULL;
	return queue;
}

void enQueue(struct Queue *q, int* data){
	struct SinglyNode *temp = NewNode(data);
	if(temp == NULL)
		return;
	if(q->rear == NULL){
		q->front = q->rear = temp;
		return;
	}
	q->rear->next = temp;
	q->rear = temp;
}

void deQueue(struct Queue *q, int* data){
	struct SinglyNode * temp = q->front;
	if(q->front == NULL)
		q->rear = NULL;
		return;
	q->front = q->front->next; //store previous front and move current front 1 node ahead
	free(temp);
}

bool checkQueueState(struct Queue *q){
	if(q->front == NULL && q->rear == NULL){
		return True;
	}
	return False;
}



