#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//DS Session 7 - 29 Feb 2024
//Single Link List

/*
Teori

1.Linked list memiliki sesuatu bernama node(mirip seperti elemen) yang memiliki 2 filed/tempat, 1 untuk valuenya dan 1 lagi untuk alamat dari node selanjutnya
2.Berbeda seperti array yang harus reserve memory(kalau 100 brarti ya 100 bisa dipake), kalau linked list sifatnya dynamix, artinya hanya reserve memory yang perlu(time effiecient)
3.Jika kita pushTail maka head tidak akan begerak, jika kita pushHead maka tail tidak akan bergerak 
*/

struct tnode{
	int value;
	struct tnode *next;
}*head = NULL, *tail,*curr,*del;//head = pointer yang menunjuk ke elemen pertama di linked list

struct tnode *newNode(int x){
	struct tnode *node = (struct tnode*)malloc(sizeof(struct tnode));
	node->value = x;
	node->next = NULL;
	return node;
}

void print(){
	curr = head;
	while(curr->next){
		printf("%d -> ", curr->value);
		curr = curr->next;//curr->next itu data selanjutnya(dia sebenernya pointer tapi bisa dianggap sebagai data kedua)
	}
	printf("%d",curr->value);
	puts("");
}

void pushHead(int x){
	struct tnode *node = newNode(x);
	if(head==NULL){
		head = tail = node;
	}else{
	node->next = head;
	head = node;
	}
	print();
}

void pushTail(int x){
	struct tnode *node = newNode(x);

	if(head == NULL){//bisa ditulis(!head)
		head = tail = node;
	}else{
		tail->next = node;
		tail = node;
		/*
		Alternatif:
		curr = head;
		while(curr->next){
			curr = curr->next;
		}
		curr->next = node;
		curr = node;
		yang ini dipake kalau misalnya kita engga buat tail
		*/
	}
	print();
//bisa pake while(curr->next != NULL){}
}

void pushMid(int value){
	struct tnode *node = newNode(value);
	if(head == NULL){
		head = tail = node;
		puts("Tidak ada angka dalam list!");
	}else if(value<=head->value){
		node->next = head;
		head = node;
	}else{
		curr = head;
		while(curr->next!=NULL && value<curr->next->value){
			curr = curr->next;
		}
		node->next = curr->next;
		curr->next = node;
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
		while(curr &&curr->value!=key){
			curr = curr->next;
		}
		if(curr==NULL){
			puts("Key not found!!");
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
		while(curr->next!=tail){//current akan terus berjalan hingga node sebelum tail
			curr = curr->next;
		}
		tail = curr;//ketika sudah berada di node sebelum tail, tail akan diubah menjadi current
		curr = curr->next;//ketika tail sudah berpindah, curr akan berpindah ke node selanjutnya yang tadinya merupakan tail
		free(curr);
		tail->next = NULL;
		print();
	}
}

void popKey(int key){
	if(head){//sama kaya (head != NULL)
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
	popHead();
	pushHead(40);
	pushHead(50);
	pushTail(100);
	pushAfter(25,20);
//	pushMid(55);
	popHead();
	popTail();
	popKey(20);
	return 0;
}


