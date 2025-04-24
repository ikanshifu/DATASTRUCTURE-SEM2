#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int tableSize = 11;

struct Data{
	int key;
	int steps;
	char str[25];
}h[tableSize];

void initial(){
	for(int i=0;i<tableSize;i++){
		h[i].key = -1;
	}
}

void view(){
	for(int i = 0;i<tableSize;i++){
		curr = h[i];
		printf("[%d]",i);
		
		while(curr){
			if(curr == h[i]){
				printf(" %s",h[i]->str);
			}else{
				printf("-")
			}
			curr = curr->next;
		}	
	}
}

void insert(char str[]){
	int key = hashing(strKey);
	int idx = 
}

int main(){
	initial();
	insert("apple");
	insert("C");
	insert("car");
	insert("tree");
	insert("banana");
	insert("zoo");
	view();
	
	return 0;
}
