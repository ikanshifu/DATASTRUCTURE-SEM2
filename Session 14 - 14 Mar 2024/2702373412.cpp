#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int tableSize = 11;

struct Data{
	int key;
	int steps;
}h[tableSize];

void initial(){
	for(int i=0;i<tableSize;i++){
		h[i].key = -1;
	}
}

void view(){
	for(int i = 0;i<tableSize;i++){
		if(h[i].key==-1){
			printf("[%d] NULL\n", i,h[i].key);
		}else{		
			printf("[%d] %d | %d steps(s)\n", i,h[i].key,h[i].steps);
		}
	}
}

void insert(int key){
	int idx = key%tableSize, step = 1,j = 1, size2 = key%(tableSize-2);
	
	while(h[idx].key != -1){
		idx = (idx+j*size2)%tableSize;
		step++;
		j+=1;
	}
	h[idx].key = key;
	h[idx].steps = step;
}

int main(){
	initial();
	insert(27);
	insert(72);
	insert(63);
	insert(42);
	insert(36);
	insert(18);
	insert(29);
	insert(101);
	view();
	
	return 0;
}
