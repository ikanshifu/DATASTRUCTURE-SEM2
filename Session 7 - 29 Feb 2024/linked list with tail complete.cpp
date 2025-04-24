#include<stdio.h>
#include<stdlib.h>

struct tnode {
	int value;
	struct tnode *next;
}*head = NULL, *tail = NULL, *curr, *del;

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
	struct tnode *node = newNode(x);
	
	//jika data pertama, maka akan sebagai head dan tail
	if(!head){
		head = tail = node;
	}else{
		node->next = head;
		head = node;
	}
	
	print();
}

void pushTail(int x){
	struct tnode *node = newNode(x);
	
	//jika data pertama, maka akan sebagai head dan tail
	if(!head){
		head = tail = node;
	}else{
		tail->next = node;
		tail = node;
	}
	
	print();
}

void pushAfter(int x, int key){
	//x = 10, key = 5;
	//1 3 5 7 9
	//1 3 5 10 7 9
	
	if(tail && tail->value == key) pushTail(x);
	else{
		struct tnode *node = newNode(x);
		curr = head;
		while(curr && curr->value != key){
			curr = curr->next;
		}
		
		
		if(!curr){
			printf("Key not found !!\n");
		}else{
			node->next = curr->next;
			curr->next = node;
			print();
		}
	}	
}

void popHead(){
	if(head){
		curr = head;
		head = head->next;
		free(curr);
		print();
	}
}

void popTail(){
	if(tail){
		curr = head;
		//gerak selama next bukan tail
		while(curr->next!=tail){
			curr = curr->next;
		}
		
		tail = curr;
		curr = curr->next;
		free(curr);
		
		tail->next = NULL;
		print();
	}
}

void popKey(int key){
	if(head){
		
		if(head->value == key) popHead();
		else if(tail->value == key) popTail();
		else{
			curr = head;
			
			//gerak selama next bukan key
			while(curr->next && curr->next->value != key){
				curr = curr->next;
			}
			
			if(curr->next){
				del = curr->next;
				curr->next = del->next;
				free(del);
				print();
			}else{
				puts("Key not found!!!");
			}
		}
	}
}

int main(){
	pushHead(10);
	pushHead(5);
	pushTail(15);
	pushTail(20);
	pushHead(1);
	popTail();
	pushTail(25);
	pushAfter(50, 25);
	pushAfter(50, 2);
	pushTail(70);
	pushHead(100);
	popKey(10);
	popKey(100);
	popKey(70);
	pushTail(70);
	pushHead(100);
	return 0;
}
