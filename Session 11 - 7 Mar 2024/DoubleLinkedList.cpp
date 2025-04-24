#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
Session 10 - 7 Mar 2024
Double Linked List Review
*/

struct tnode{
	int value;
	struct tnode *next, *prev;
}*head = NULL, *tail = NULL, *curr;

struct tnode *newNode(int x){
	struct tnode *node = (struct tnode*) malloc(sizeof(struct tnode));
	node->value = x;
	node->next = node->prev = NULL;	
}

void print(){
	if(head==NULL){
		printf("No Data!");
	}else{
		curr = head;
		printf("Head: %d, Tail: %d |", head->value, tail->value);
		while(curr){
			printf("%d ", curr->value);
			curr = curr->next;
		}	
	}
	printf("\n");
}

void pushHead(int x){
	struct tnode *node = newNode(x);
	if(head==NULL){
		head = tail = node;
	}else{
		node->next = head;
		head->prev = node;
		head = node;
	}
	print();
}

void pushTail(int x){
	struct tnode *node = newNode(x);
	if(head==NULL){
		head = tail = node;
	}else{
		node->prev = tail;
		tail->next = node;
		tail = node;
	}
	print();
}

void pushAfter(int x,int key){
	struct tnode *node = newNode(x);
	if(head!=NULL){
	 	if(key == tail->value){
			pushTail(x);
		}else{
			curr = head;
			while(curr && curr->value!=key){
				curr= curr->next;
			}
			if(curr){
				node->next = curr->next;
				node->prev = curr;
				curr->next->prev = node;
				curr->next = node;
				print();
			}else{
				puts("No key is found!");
			}
		}
	}else{
		puts("No data available!");
	}
}

void popHead(){
	if(head==NULL){
		puts("No Data!");
	}else{
		curr = head;
		if(head==tail){
			head = tail = NULL;
			free(head);
			free(tail);
		}else{
			head = head->next;
			head->prev = NULL;
		}
		free(curr);
		print();
	}
}

void popTail(){
	if(head==NULL){
		puts("No Data!");
	}else{
		curr = head;
		if(head==tail){
			head = tail = NULL;
			free(head);
			free(tail);
		}else{
			tail = tail->prev;
			tail->next = NULL;
		}
		free(curr);
		print();
	}
}

void popKey(int key){
	if(head==NULL){
		puts("No Data!");
	}else{
		if(key==head->value){
			popHead();
		}else if(key==tail->value){
			popTail();
		}else{
			curr = head;
			while(curr&&curr->value!=key){
				curr = curr->next;
			}
			if(curr){
				curr->prev->next = curr->next;
				curr->next->prev = curr->prev;
				free(curr);
				print();
			}
		}
	}
}

void popAll(){
	while(head){
		popHead();
	}
}

int main(){
	pushHead(10);
	popHead();
	pushHead(20);
	pushHead(30);
	pushHead(40);
	popHead();
	pushHead(50);
	pushHead(60);
	pushTail(25);
	pushAfter(35,30);
	pushTail(60);
	popKey(35);
	popAll();
	return 0;
}
