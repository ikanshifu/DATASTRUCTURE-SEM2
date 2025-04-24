#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

#define MAX 100
int parent[MAX];
int minimum = 0;

//Using Union
int find_set(int x){
	if(x == parent[x]){
		return x;
	}
	return parent[x] = find_set(parent[x]);
}

void union_set(int a, int b){
	a = find_set(a);
	b = find_set(b);
	if(a!=b){
		parent[b] = a;
	}
}

void make_set(int x){
	parent[x] = x;
}

int main(){									
	int C,R,a,b;
	scanf("%d %d", &C, &R);
	for(int i = 0; i<C;i++){
		make_set(i);
	}																																																																																																																														
	for(int i = 0; i<R;i++){
		scanf("%d %d",&a,&b);
		union_set(a,b);	
	}
	
	for(int i = 0;i<C;i++){
		if(parent[i]==i)minimum++;
	}
	printf("Minimum bus needed: %d\n",minimum);
	return 0;
}
