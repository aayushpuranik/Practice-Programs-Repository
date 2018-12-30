#include<Stdio.h>
#include<Stdlib.h>
#include<limits.h>

struct stack{
	int top;
	int capacity;
	int *array;
};

struct stack *CreateStack(int capacity){
	struct stack *s = (struct stack *)malloc(sizeof(struct stack));
	if(!s){
		printf("memory issue");
		return;
	}
	
	s->capacity = capacity;
	s->top = -1;
	s->array = malloc(s->capacity * sizeof(int));
	if(!s->array){
		printf("s->array is NULL");
		return NULL;
	}
	return s;
}

int isEmpty(struct stack *s){
	return (s->top == -1);
}

int isFull(struct stack *s){
	return s->top == s->capacity-1;
}

void push(struct stack *s,int item){
	if(isFull(s)){
		printf("stack is full");
		return;
	}
	s->array[++s->top] = item;
}

int pop(struct stack *s){
	if(isEmpty(s)){
		printf("stack is empty\n");
		return;
	}
	return s->array[s->top--];
}

int peek(struct stack *s){
	if(isEmpty(s)){
		printf("List is empty");
		return
		;
	}
	return s->array[s->top];
}

int main(){
	struct stack *s = CreateStack(10);
	push(s,10);
	push(s,20);
	push(s,50);
	push(s,30);
	push(s,110);
	push(s,210);
	push(s,501);
	push(s,310);
	push(s,225);
	push(s,999);
	push(s,400);
	printf("\n");
	printf("top is %d\n",peek(s));
	
	printf("poped item is %d\n",pop(s));
	printf("poped item is %d\n",pop(s));
	printf("poped item is %d\n",pop(s));
	printf("poped item is %d\n",pop(s));
	printf("poped item is %d\n",pop(s));
	printf("poped item is %d\n",pop(s));
	printf("poped item is %d\n",pop(s));
	printf("poped item is %d\n",pop(s));
	printf("poped item is %d\n",pop(s));
	printf("poped item is %d\n",pop(s));
	printf("poped item is %d\n",pop(s));
	
	return 0;
}