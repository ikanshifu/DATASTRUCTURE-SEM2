#include<stdio.h>
#define MAX 100

int parent[MAX];
int cycle = 0;

void makeSet(int v){
	parent[v] = v;
}

int findSet(int v){
	if(parent[v] == v) return v;
	else return parent[v] = findSet(parent[v]);
}

void UNION(int a, int b){
	a = findSet(a);
	b = findSet(b);
	
	if(a != b) parent[b] = a;
	else cycle++;
}

int main(){
	int C, R;
	scanf("%d %d", &C, &R); getchar();
	
	for(int i=0;i<C;i++){
		makeSet(i);
	}
	
	int a, b;
	for(int i=0;i<R;i++){
		scanf("%d %d", &a, &b); getchar();
		UNION(a, b);
	}
	
	if(cycle == 0) puts("Perfect plan");
	else puts("Cycle detected");
	
	return 0;
}
