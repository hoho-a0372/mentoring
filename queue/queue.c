#include <stdio.h>

#define MAX_QUEUE_SIZE 100

int data[MAX_QUEUE_SIZE];
int front;
int rear;

void init_queue(){
	front = rear = 1;
}
int is_empty(){
	return (front == rear);
}
int is_full(){
	return ((rear+1) % MAX_QUEUE_SIZE) == front;
}
int size(){
	return (rear-front+MAX_QUEUE_SIZE)%MAX_QUEUE_SIZE;
}

void enqueue(int x){
	if(!is_full()){
		rear = (rear+1) % MAX_QUEUE_SIZE; 
		data[rear] = x;
	}
}

int dequeue(){
	if(!is_empty()){
		front = (front+1) % MAX_QUEUE_SIZE;
		return data[front];
	}
	else return -1;
}
int main(){
	init_queue( );

	for(int i=1; i < 100; i++){
		enqueue( i );
		enqueue( i );
		printf("[%d]dequeue() --> %d\n", i, dequeue()); 
		printf("[%d]dequeue() --> %d\n", i, dequeue()); 
	}
/*
	init_queue( );

	for(int i=1; i < 10; i++)
		enqueue( i );
	printf("선형큐 enqueue 9회\n"); 

	printf("\tdequeue() --> %d\n", dequeue()); 
	printf("\tdequeue() --> %d\n", dequeue()); 
	printf("\tdequeue() --> %d\n", dequeue()); 
	printf("선형큐 dequeue 3회\n");
*/
}
