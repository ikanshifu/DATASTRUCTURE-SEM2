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
		if(h[i].key==-1){
			printf("[%d] NULL\n", i);
		}else{		
			printf("[%d] %-8s | %d steps(s)\n", i,h[i].str,h[i].steps);
		}
	}
}

void insert(char str[]){
	int idx, step = 1,j = 1, key = 0;
	int length = strlen(str);
	for(int i = 0; i<length;i++){
		key += str[i];
	}
	idx = key%tableSize;
	int size2 = key%(tableSize-2);
	
	while(h[idx].key !=-1){
		idx = (idx+j*size2)%tableSize;
		step++;
		j+=1;
	}
	h[idx].key = key;
	h[idx].steps = step;
	strcpy(h[idx].str, str);
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
