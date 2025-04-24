#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//DS Session 8 - 29 Feb 2024
//Double Link List
//2702373412 - Clive Clay Irawan

struct tnode{
	int value;
	struct tnode *next,*prev;
}*head = NULL, *tail = NULL,*curr,*del;

struct tnode *newNode(int x){
	struct tnode *node = (struct tnode*)malloc(sizeof(struct tnode));
	node->value = x;
	node->next = NULL;
	node->prev = NULL;
	return node;
}

void print(){
	if(head == NULL){
		puts("There is no data!");
	}else{
		curr = head;
		while(curr->next){
			printf("%d -> ", curr->value);
			curr = curr->next;
		}
		printf("%d\n",curr->value);
	}
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

	if(head == NULL){
		head = tail = node;
	}else{
		tail->next = node;
		node->prev = tail;
		tail = node;
	}
	print();
}

void pushAfter(int x, int key){
	struct tnode *node = newNode(x);
	if(head == NULL){
		head = tail = node;
		puts("Tidak ada angka dalam list!");
	}else if(tail && tail->value == key){
		pushTail(x);	
	}else{
		curr = head;
		while(curr&&curr->value!=key){
			curr = curr->next;
		}
		if(curr==NULL){
			puts("Key not found!!");
		}else{
			node->next = curr->next;
			curr->next->prev = node;
			curr->next = node;
			node->prev = node;
			print();
		}
	}
}

void popHead(){
	if(!head){
		return;
	}else if(head==tail){
		head = tail = NULL;
		free(head);
		free(tail);
	}else{
		curr = head;
		head = curr->next;
		head->prev = NULL;
		free(curr);
		print();
	}
}

void popTail(){
	if(!tail){
		return;
	}else if(tail==head){
		head = tail = NULL;
		free(head);
		free(tail);
	}else{
		curr = tail;
		tail = curr->prev;
		tail->next = NULL;
		free(curr);
		print();
	}
}

void popKey(int key){
	if(!head){
		return;
	}else if(head==tail){
		head = tail = NULL;
		free(head);
		free(tail);
	}else if(head->value==key){
		popHead();
	}else if(tail->value==key){
		popTail();
	}else{
		if(head->value == key){
			popHead();
		}else if(tail->value == key){
			popTail();
		}else{
			curr = head;
			while(curr->next&&curr->next->value !=key){
				curr = curr->next;
			}
			if(curr->next){//sama kaya(curr->next!=NULL)
				del = curr->next;
				curr->next = del->next;
				del ->next-> prev = curr;
				del ->next = NULL;
				del ->prev = NULL;
				del = NULL;
				free(del);
				print();
			}else{
				puts("Key not found!");
			}
		}
	}
}

int main(){	
	pushHead(10);
	pushHead(20);
	pushHead(30);
	pushHead(40);
	pushTail(64);
	pushTail(74);
	pushAfter(29,40);
	pushAfter(10,100);
	popHead();
	popTail();
	popKey(64);
	return 0;
}


