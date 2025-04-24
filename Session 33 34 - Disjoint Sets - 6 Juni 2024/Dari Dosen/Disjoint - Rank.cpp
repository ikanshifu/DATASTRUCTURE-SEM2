#include<stdio.h>
#define MAX 5

int parent[MAX];
int rank[MAX];

void print(){
	printf("Parent: ");
	for(int i=0;i<MAX;i++){
		printf("%d ", parent[i]);
	}
	printf("Rank: ");
	for(int i=0;i<MAX;i++){
		printf("%d ", rank[i]);
	}
	puts("\n");
}

void makeSet(int v){
	parent[v] = v;
	rank[v] = 0;
	print();
}

int findSet(int v){
	if(parent[v] == v) return v;
	else return findSet(parent[v]);
}

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void UNION(int a, int b){
	a = findSet(a);
	b = findSet(b);
	
	if(a != b){
		if(rank[a] < rank[b]) swap(&a, &b);
		
		parent[b] = a;
		
		if(rank[a] == rank[b]) rank[a]++;
	}
	print();
}

int main(){
	for(int i=0;i<MAX;i++){
		makeSet(i);
	}
	
	UNION(4,3);
	UNION(2,1);
	UNION(3,1);
	UNION(0,1);
	
	return 0;
}
