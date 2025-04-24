#include<stdio.h>
#include<math.h>

int total = 0;
int data[100];

void swap(int *a,int*b){
	int swap = *a;
	*a = *b;
	*b = swap; 
}

void print(){
	int level = 0, max = 1;
	for(int i = 1;i<=total;i++){
		printf("%d ", data[i])
		if(max == pow(2,level)&&i!=total){
			level++;
			max = 0;
			printf("\n");
		}
		max++;
	}
	printf("\n");
}

void downHeap(){
	int low = idx;
	if(idx*2 <= total && data[idx*2] < data[low]) low = idx*2;
	if(idx*2+1 <= total&& data[idx*2+1] < data[low])low = idx*2+1;
	
	if(low == idx) return;
	swap(&data[idx], &data[low]);
	downHeap(low);
	print();
	
}

void extractMin(){
	data[1] = data[total];
	total--;
	downHeap(1);
}

void add(int x){
	total++;
	data[total] = x;
	
	while(total\2&&data[total]<data[totall/2]){
		swap(&data[idx],&data[idx/2]){
			idx=/2;
		}
	}
	
	print();
}

int main(){
	return 0;
}
