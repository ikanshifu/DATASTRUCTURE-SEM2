#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
//Session 30 - 5 Juni 2024
//Heaps: Complete Binary Tree(anaknya harus 2, engga boleh 1) yang memiliki rank yang menentukan prioritas
//Min-Heaps: root akan selalu lebih kecil dibanding anak-anaknya
//Max-Heaps: root akan selalu lebih besar dibanding anak-anaknya

//Max Heap atau Min Heap Operations
/*Insert(dari kiri kekanan): insertion node baru akan muncul pada node terakhir yang kosong.
setelah diinsert, kita melakukan upheap dimana node akan dibandingkan dengan parent, 
lalu bertukar*/
/*Delete-Min or Delete-Max: Hapus root lalu lakukan downheap dimana parent akan 
dibandingnkan dengan anak-anaknya lalu bertukar
*/
#define SIZE 50

struct Number{
	int value;
	int root;
	int position;
}tree[SIZE];

int numExist(int insert){
	for(int i = 1;i<SIZE;i++){
		if(insert == tree[i].value){
			return i;
		}	
	}
	return -1;
}

void add(int insert){
	for(int i = 1;i<SIZE;i++){
		if(tree[i].value==NULL){
			tree[i].value = insert;
			break;
		}
	}
}

void remove(int del){
	printf("delete\n");
}

int main(){
	for(int i = 1;i<SIZE;i++){
		tree[i].value = NULL;
		tree[i].root = 0;
	}
	int insert;
	do{
		switch(insert){
			case 0:
		}
		if(tree[0].root=0){
			printf("-- there is no data --\n");
			printf("----------------------\n");
		}else{
			printf("----------------------\n");
		}
		printf("Input number to add/ delete-min (0 for exit): ");
		scanf("%d",&insert);getchar();
		int position = numExist(insert);
		if(insert == 0){
			return 0;	
		}
		if(position == -1){
			printf("add : %d\n",insert);
			add(insert);	
		}else if(position!=-1&&tree[position].root==0){
			printf("%d is wrong number.\n",insert);
		}else if(position==0){
			printf("delete-min : %d\n",insert);
			remove(insert);
		}
		printf("%d\n",insert);
//		for(int i = 1;i<SIZE;i++){
//			printf("%d",tree[i].value);
//		}	
	}while(insert<0&&insert>10000000000);		
	return 0;
}
