#include<stdio.h>
#include<stdlib.h>

struct tnode {
	int value;
	struct tnode *next;
}*head = NULL, *curr;

struct tnode *newNode(int x){
	struct tnode *node = (struct tnode*) malloc (sizeof(struct tnode));
	node->value = x;
	node->next = NULL;
	
	return node;
}

void print(){
	curr = head;
	while(curr->next){
		printf("%d -> ", curr->value);
		curr = curr->next;
	}
	
	printf("%d", curr->value);
	puts("");
}

void pushHead(int x){
	// 10 20 30
	// push head 5
	// 5 10 20 30
	
	struct tnode *node = newNode(x);
	node->next = head;
	head = node;
	
	print();
}

void pushTail(int x){
	struct tnode *node = newNode(x);
	
	if(!head){
		head = node;
	}else{
		curr = head;
		
		//bergerak sampai data terakhir
		while(curr->next) curr = curr->next;
		
		curr->next = node;
	}
	
	print();
}

void pushAfter(int x, int key){
	//x = 10, key = 5;
	//1 3 5 7 9
	//1 3 5 10 7 9
	
	struct tnode *node = newNode(x);
	curr = head;
	while(curr && curr->value != key){
		curr = curr->next;
	}
	
	
	if(!curr){
		printf("Key not found !!");
	}else{
		node->next = curr->next;
		curr->next = node;
		print();
	}
	
}

int main(){
	pushHead(10);
	pushHead(5);
	pushTail(15);
	pushTail(20);
	pushHead(1);
	pushTail(25);
	pushAfter(50, 25);
	pushAfter(50, 2);
	pushTail(70);
	return 0;
}
