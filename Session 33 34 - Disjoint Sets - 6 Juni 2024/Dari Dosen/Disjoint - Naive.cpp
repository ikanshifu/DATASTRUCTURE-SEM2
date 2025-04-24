#include<stdio.h>
#define MAX 100

int parent[MAX];


void print(){
	for(int i=0;i<MAX;i++){
		printf("%d ", parent[i]);
	}
	puts("");
}

void makeSet(int v){
	parent[v] = v;
	print();
}

int findSet(int v){
	if(parent[v] == v) return v;
	else return findSet(parent[v]);
}

void UNION(int a, int b){
	a = findSet(a);
	b = findSet(b);
	
	if(a != b) parent[b] = a;
	print();
}

int main(){
	for(int i=0;i<MAX;i++){
		makeSet(i);
	}
	/*
	UNION(4,3);
	UNION(2,1);
	UNION(3,1);
	UNION(1,0);
	*/
	
	for(int i=0;i<MAX-1;i++){
		UNION(i+1,i);
	}
	
	return 0;
}
