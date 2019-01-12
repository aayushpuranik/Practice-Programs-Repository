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
	return ((q->capacity - q->front + q->rear) % q->capacity)+1;
}

void Enqueue(struct Queue *q,int data){
	
	if(IsFull(q)){
		printf("Queue is FULL\n");
	}else{
		q->rear = (q->rear+1)%q->capacity;
		q->array[q->rear] = data;
		if(q->front == -1){
			q->front = q->rear;
		}
		printf("rear = %d, array[rear] = %d\n",q->rear,q->array[q->rear]);
	}
}

int Dequeue(struct Queue *q){
	int data = 0;
	if(IsEmpty(q)){
		printf("Queue is Empty\n");
		return;
	}
	data = q->array[q->front];
	if(q->front == q->rear){
		q->front = q->rear = -1;
	}else{
		q->front = ((q->front+1)%q->capacity);
	}
	return data;
}

void traverse(struct Queue *q){
	int index = 0;
	int front = q->front;
	
	if(IsEmpty(q)){
		printf("Queue is empty\n");
		return;
	}
	
	if(q->front <= q->rear){
		while(front <= q->rear){
			printf("Data:%d\n",q->array[front]);
			front++;
		}
	}
	else{
		printf("Other condition\n");
		front = q->front;
		while(front < q->capacity){
			printf("data : %d\n",q->array[front]);
			front++;
		}
		front = 0;
		while(front <= q->rear){
			printf("data : %d\n",q->array[front]);
			front++;
		}
	}
}

int main(){
	struct Queue *q = CreateQueue(5);
	
	Enqueue(q,5);
	Enqueue(q,55);
	Enqueue(q,65);
	Enqueue(q,75);
	
	printf("QueueSize = %d\n",QueueSize(q));
	printf("Dequeue of :%d\n",Dequeue(q));
	printf("QueueSize = %d\n",QueueSize(q));
	printf("Dequeue of : %d\n",Dequeue(q));
	printf("Queue size = %d\n",QueueSize(q));
	
	printf("\n traversing \n");
	printf("front = %d, rear = %d\n",q->front,q->rear);
	traverse(q);
	
	printf("\n Enqueue \n");
	Enqueue(q,85);
	Enqueue(q,15);
	Enqueue(q,25);
	Enqueue(q,35);
	Enqueue(q,45);
	printf("QueueSize = %d\n",QueueSize(q));
	Enqueue(q,55);
	printf("QueueSize = %d\n",QueueSize(q));
	
	printf("\n traversing \n");
	traverse(q);
	
	printf("Dequeue of :%d\n",Dequeue(q));
	printf("QueueSize = %d\n",QueueSize(q));
	
	printf("Dequeue of :%d\n",Dequeue(q));
	printf("QueueSize = %d\n",QueueSize(q));
	
	printf("Dequeue of :%d\n",Dequeue(q));
	printf("QueueSize = %d\n",QueueSize(q));
	
	printf("\nq->front = %d\n\n",q->front);
	
	printf("Dequeue of :%d\n",Dequeue(q));
	printf("QueueSize = %d\n",QueueSize(q));
	
	printf("\nq->front = %d\n\n",q->front);
	printf("Dequeue of :%d\n",Dequeue(q));
	printf("QueueSize = %d\n",QueueSize(q));
	
	printf("\n traversing \n");
	traverse(q);
	
	
	return 0;
}