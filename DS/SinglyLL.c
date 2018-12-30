#include<Stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node* next;
};
struct Node *head;

void insert(int data, int position){
	struct Node *p,*q,*new;
	int pos = 0;
	new = (struct Node*)malloc(sizeof(struct Node));
	
	if(new == NULL){
		printf("Memory Issue\n");
		return;
	}
	new->data = data;
	new->next = NULL;
	
	if(position == 1 || head == NULL || position<0){
		new->next = head;
		head = new;
	}
	else{
		p = head;
		while(pos < position && p != NULL){
			pos++;
			q = p;
			p = p->next;
		}
		q->next = new;
		new->next = p;
	}
}

void delete(int position){
	struct Node *p,*q;
	int pos = 1;
	
	if(head == NULL){
		printf("singly linked list is empty\n");
		return;
	}
	
	p = head;
	if(position == 1){
		head = head->next;
		p->next = NULL;
		free(p);
	}
	else{
		while(pos < position && p != NULL){
			pos++;
			q = p;
			p = p->next;
		}
		
		if(p==NULL || position<0){
			printf("position does not exist.\n");
			return;
		}
		q->next = p->next;
		p->next = NULL;
		free(p);
	}
}

void traverse(){
	struct Node *p;
	p = head;
	
	while(p != NULL){
		printf("data is : %d\n",p->data);
		p = p->next;
	}
}

void main(){
	insert(10,6);
	insert(29,2);
	insert(40,5);
	insert(50,-1);
	insert(100,100);
	
	traverse();
	printf("\n");
	delete(2);
	traverse();
	printf("\n");
	delete(6);
	traverse();
	printf("\n");
	delete(1);
	traverse();
	printf("\n");
	delete(1);
	delete(2);
	delete(1);
	delete(1);
	traverse();
}