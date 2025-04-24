#include<stdio.h>
#include<math.h>

int total = 0;
int data[100];

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void print(){
	if(total == 0) puts("-- there is no data --");
	else{
		int level = 0, max = 1;
		
		for(int i = 1 ; i <= total ; i++){
			printf("%d ", data[i]);
			if(max == pow(2, level) && i!=total){
				level++;
				max = 0;
				puts("");
			}
			max++;
		}
		puts("");
	}	
	puts("----------------------");
}

void add(int x){
	total++;
	data[total] = x;
	int idx = total;
	
	//upheap
	while(idx/2 && data[idx] < data[idx/2]){
		swap(&data[idx], &data[idx/2]);
		idx /= 2;
	}
}

void downheap(int idx){
	int low = idx;
	
	if(idx*2 <= total && data[idx*2] < data[low]) low = idx*2;
	if(idx*2+1 <= total && data[idx*2+1] < data[low]) low = idx*2+1;
	
	if(low == idx) return;
	swap(&data[idx], &data[low]);
	downheap(low);
}

void extractMin(){
	data[1] = data[total];
	total--;
	downheap(1);
}

int checkNum(int x){
	if(data[1] == x) return -1; //del
	
	for(int i = 1 ; i <= total ; i++){
		if(data[i] == x) return 0; //wrong
	}
	return 1; //add
}

int main(){
	int input = -1;
	
	while(input != 0){
		print();
		printf("Input number to add/delete-min (0 for exit): ");
		scanf("%d", &input);
		getchar();
		
		int c = checkNum(input);
		if(c == -1){
			printf("delete-min : %d\n", input);
			extractMin();
		}else if(c == 0){
			printf("%d is wrong number\n", input);
		}else{
			printf("add : %d\n", input);
			add(input);
		}
	}
	puts("program exit");
	return 0;
}
