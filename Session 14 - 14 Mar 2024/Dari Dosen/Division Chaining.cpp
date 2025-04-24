#include<stdio.h>
#include<string.h>
#include<stdlib.h>

const int tableSize = 10;

struct tdata{
	char key[5];
	int step;
	int keyNumber;
	struct tdata *next;
}*h[tableSize], *curr;

void init(){
	for(int i=0;i<tableSize;i++){
		h[i] = NULL;
	}
}

void view(){
	for(int i=0;i<tableSize;i++){
		curr = h[i];
		
		printf("[%d]", i);
		
		while(curr){
			// (*h[i]).key == h[i]->key
			if(curr == h[i]) printf(" %s(%d)", curr->key, curr->keyNumber);
			else printf(" -> %s (%d)", curr->key, curr->keyNumber);
			
			curr = curr->next;
		}
		
		puts("");
	}
}

int hashing(char strKey[5]){
	int key = 0;
	
	//add up ASCII values of all the characters in the string.
	for(int i=0;strKey[i]!='\0';i++){
		key += strKey[i];
	}
	
	return key;
}

void insert(char strKey[5]){
	//division
	int key = hashing(strKey);
	int idx = key % tableSize;
	
	struct tdata *node = (struct tdata*) malloc(sizeof(struct tdata));
	node->next = NULL;
	strcpy(node->key, strKey);
	node->keyNumber = key;
	
	if(h[idx]){
		curr = h[idx];
		
		while(curr->next) curr = curr->next;
		
		curr->next = node;
	}else{
		h[idx] = node;
	}
}

int main(){
	init();
	insert("ABCH");
	insert("ABCD");
	insert("CDBA");
	insert("BCAD");
	insert("BBBB");
	insert("AAAA");
	view();
	return 0;
}
