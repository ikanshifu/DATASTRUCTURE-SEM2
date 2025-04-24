#include<stdio.h>

const int tableSize = 10;

struct tdata{
	int key, step;
}h[tableSize];

void init(){
	for(int i=0;i<tableSize;i++){
		h[i].key = -1;
	}
}

void view(){
	for(int i=0;i<tableSize;i++){
		if(h[i].key == -1) printf("[%d] NULL\n", i);
		else printf("[%d] %d | %d step(s)\n", i, h[i].key, h[i].step);
	}
}

void insert(int key){
	//division
	int idx = key % tableSize, step=1;
	
	while(h[idx].key != -1){
		//linear probing
		idx = (idx+1)%tableSize;
		step++;
	}
	
	h[idx].key = key;
	h[idx].step = step;
}

int main(){
	init();
	insert(1);
	insert(2);
	insert(3);
	insert(4);
	insert(5);
	insert(15);
	insert(25);
	insert(35);
	insert(24);
	insert(23);
	view();
	return 0;
}
