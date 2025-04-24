#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Data{
	int value;
	struct Data *next, *prev;
}*head == NULL, *tail == NULL, *curr, *del;

struct Data *newNode(int x){
	struct Data *node = (struct Data*)malloc(sizeof(struct Data));
	node->value = x;
	node->prev=node->next=NULL;
}

void print(){
	if(head==NULL){
		printf("No Data Available\n");
	}else{
		curr = head;
		puts("Value: ")
		while(curr){
			printf(" %d",curr->value);
			curr = curr->next;
		}
		puts("");
	}
}

//int isAlpha(char name[]){
//	int i = 0;
//	while(name[i]){
//		if((name[i]>='A'&&name[i]<='Z')||(name[i]>='a'&&name[i]<='b')||(name[i]==' ')){
//			i++;
//		}else{
//			return 0;
//		}
//	}
//	return 1;
//}

void pushHead(int x){
	struct Data *node = newNode(x);
	if(head==NULL){
		head=tail=node;
	}else{
		node->next = head;
		node->prev = NULL;
		head->prev = node;
		head = node;
	}
}

void pushTail(int x){
	struct Data *node = newNode(x);
	if(head==NULL){
		head=tail=node;
	}else{
		node->prev = tail;
		node->next = NULL;
		tail->next = node;
		tail = node;
	}
}

void pushMid(int x){
	struct Data *node = newNode(x);
	if(head==NULL){
		head=tail=node;
	}else if(head->value > x){
		pushHead(x);
	}else{
		curr = head;
		while(curr && curr->next->value<x){
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
	if(head==NULL){
		puts("No data!");
	}else{
		if(tail->value==key){
			pushTail(x);
		}else{
			curr = head;
			while(curr&&curr->value!=key){
				curr = curr->next;
			}
			if(curr){
				node->next = curr->next;
				node->prev = curr;
				curr->next->prev = node;
				curr->next = node;
			}else{
				puts("Key not found!");
			}
		}
	}
}

void pushBefore(int x, int key){
	struct Data *node = newNode(x);
	if(head==NULL){
		puts("No data!");
	}else{
		if(head->value==key){
			pushHead(x);
		}else{
			curr = head;
			while(curr&&curr->value!=key){
				curr = curr->next;
			}
			if(curr){
				node->next = curr;
				node->prev = curr->prev;
				curr->prev->next = node;
				curr->prev = node;
			}else{
				puts("Key not found!");
			}
		}
	}
}

void popHead(){
	if(head==NULL){
		puts("There is no data!")
	}else{
		if(head==tail){
			head = tail = NULL;
			free(head);
			free(tail);
		}else{
			curr = head;
			head = curr->next;
			head->prev = NULL;
			free(curr);
		}
	}
}

void popTail(){
	if(head==NULL){
		puts("There is no data!")
	}else{
		if(head==tail){
			head = tail = NULL;
			free(head);
			free(tail);
		}else{
			curr = tail;
			tail = curr->prev;
			tail->next = NULL;
			free(curr);
		}
	}
}

void popKey(int key){
	if(head->value == key){
		popHead();
	}else if(tail->value==key){
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
		}
		
	}
}

void popAll(){
	while(head){
		popHead();
	}
}

int main(){
	
	
	
	return 0;
}
