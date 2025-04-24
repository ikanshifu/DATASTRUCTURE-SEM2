#include<stdio.h>
#include<string.h>

const int tableSize = 10;

struct tdata{
	char key[5];
	int step;
}h[tableSize];

void init(){
	for(int i=0;i<tableSize;i++){
		strcpy(h[i].key, "NULL");
	}
}

void view(){
	for(int i=0;i<tableSize;i++){
		if(strcmp(h[i].key, "NULL") == 0) printf("[%d] NULL\n", i);
		else printf("[%d] %-5s | %d step(s)\n", i, h[i].key, h[i].step);
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
	int h1 = key % tableSize;
	int h2 = (key % (tableSize-1)) != 0 ? key % (tableSize-1) : key % (tableSize-2);
	int step = 0, idx;
	
	do{
		idx = (h1 + step * h2) % tableSize;
		step++;
	}while(strcmp(h[idx].key,"NULL") != 0);
	
	strcpy(h[idx].key, strKey);
	h[idx].step = step;
}

int main(){
	init();
	printf("Table Size: 10, Insert ABCH, HCBA, G, F, Q, Z\n");
	insert("ABCH");
	insert("HCBA");
	insert("G");
	insert("F");
	insert("Q");
	insert("Z");
	view();
	return 0;
}
