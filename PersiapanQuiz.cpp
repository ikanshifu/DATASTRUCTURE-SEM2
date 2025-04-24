#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Data{
	int value;
	struct Data *next, *prev;
}*head = NULL, *tail = NULL, *curr;

struct Data *newNode(int x){
	struct Data *node = (struct Data*) malloc(sizeof(struct Data));
	node->value = x;
	node->next = node->prev = NULL;
}

void printAll(){
	if(head==NULL){
		printf("There is no Data!");
	}else{
		curr = head;
		printf("Value :");
		while(curr){
			printf(" %d", curr->value);
			curr = curr->next;
		}
	}
	puts("");
}

void pushHead(int x){
	struct Data *node = newNode(x);
	if(head == NULL){
		head = tail = node;
	}else{
		node->next = head;
		head->prev = node;
		head = node;	
	}
}

void pushTail(int x){
	struct Data *node = newNode(x);
	if(head == NULL){
		head = tail = node;
	}else{
		node->prev = tail;
		tail->next = node;
		tail = node;
	}
}

void pushMid(int x){
	struct Data *node = newNode(x);
	if(head == NULL){
		head = tail = node;
	}else if(head->value > x){
		pushHead(x);
	}else{
		curr = head;
		while(curr&&curr->next->value<x){
			curr = curr->next;
		}
		node->next = curr->next;
		node->prev = curr;
		if(curr->next){
			curr->next->prev = node;
		}else{
			tail = node;
		}
		curr->next = node;
	}
}

void pushAfter(int x, int key){
	struct Data *node = newNode(x);
	if(head != NULL){
		if(key==tail->value){
			pushTail(x);
		}else{
			curr = head;
			while(curr && curr->value!=key){
				curr = curr->next;
			}
			if(curr){
				node->next = curr->next;
				node->prev = curr;
				curr->next->prev = node;
				curr->next = node;
			}else{
				puts("Key is not found!");
			}
		}
	}else{
		puts("No Data Found!");
	}
}

void pushBefore(int x,int key){
	struct Data *node = newNode(x);
	if(head != NULL){
		if(key==head->value){
			pushHead(x);
		}else{
			curr = head;
			while(curr && curr->value!=key){
				curr = curr->next;
			}
			if(curr){
				node->next = curr;
				node->prev = curr->prev;
				curr->prev->next = node;
				curr->prev = node;
			}else{
				puts("Key is not found!");
			}
		}
	}else{
		puts("No Data Found!");
	}
}

void popHead(){
	if(head==NULL){
		puts("There is no Data!");
	}else{
		if(head==tail){
			head = tail = NULL;
			free(head);
			free(tail);
		}else{
			curr=head;
			head = curr->next;
			head->prev = NULL;
			free(curr);
		}
	}
}

void popTail(){
	if(head==NULL){
		puts("There is no Data!");
	}else{
		if(head==tail){
			head = tail = NULL;
			free(head);
			free(tail);
		}else{
			curr=tail;
			tail = curr->prev;
			tail->next = NULL;
			free(curr);
		}
	}
}

void popKey(int key){
	if(head==NULL){
		puts("Key not found!");
	}else{
		if(head->value == key){
			popHead();
		}else if(tail->value == key){
			popTail();
		}else{
			curr = head;
			while(curr&&curr->value!=key){
				curr = curr->next;
			}
			if(curr){
				curr->next->prev = curr->prev;
				curr->prev->next = curr->next;
				free(curr);
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
	pushHead(20);
	pushHead(30);
	pushHead(40);
	pushTail(5);
	pushAfter(45,40);
	pushAfter(7,10);
	pushBefore(25,30);
	pushMid(21);
	popTail();
	popHead();
	popKey(25);
	printAll();
	return 0;
}
