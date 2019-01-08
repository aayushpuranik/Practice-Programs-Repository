#include<Stdio.h>
#include<Stdlib.h>
#include<stdbool.h>

struct Queue{
	int capacity;
	int rear,front;
	int *array;
};

struct Queue *CreateQueue(int capacity){
	struct Queue *q = (struct Queue *)malloc(sizeof(struct Queue));
	if(q == NULL){
		printf("memory issue\n");
		return;
	}
	
	q->capacity = capacity;
	q->front = q->rear = -1;
	q->array = malloc(q->capacity * sizeof(int));
	
	return q;
}

bool IsEmpty(struct Queue *q){
	return q->front == -1 ;
}	

bool IsFull(struct Queue *q){
	return (q->rear + 1) % q->capacity == q->front;
}

int QueueSize(struct Queue *q){
	int size = ((q->rear - q->front)+1)%q->capacity;\
	
	printf("size = %d\n",size);
	return size;
}

void Enqueue(struct Queue *q,int data){
	
	if(IsFull(q)){
		printf("Queue is FULL\n");
	}
	q->rear = (q->rear+1)%q->capacity;
	q->array[q->rear] = data;
	if(q->front == -1){
		q->front = q->rear;
	}
	printf("array[front] = %d\n",20,q->array[q->front]);
	
}

int Dequeue(struct Queue *q){
	int data = 0;
	if(IsEmpty(q)){
		printf("Queue is Empty\n");
		return 0;
	}
	data = q->array[q->front];
	if(q->front == q->rear){
		q->front = q->rear = -1;
	}else{
		q->front = (q->front + 1)%q->capacity;
	}
	return data;
}

int main(){
	struct Queue *q = CreateQueue(5);
	
	Enqueue(q,5);
	printf("QueueSize = %d\n",QueueSize(q));
	printf("Dequeue of :%d\n",Dequeue(q));
	printf("QueueSize = %d\n",QueueSize(q));
	printf("Dequeue of : %d\n",Dequeue(q));
	
	
	return 0;
}