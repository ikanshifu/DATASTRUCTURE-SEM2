#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
DS Lec - Session 4 - 22 Feb 2024
Pointer and Array Review
*/

void swap(int *x,int *y){
	int temp = *x;
	*x = *y;
	*y = temp;	
}


int main(){
	//Pointer	
	//Fungsi pointer adalah menunjuk ke alamat dari integer
	int a=10,*ptr_a,**pptr_a;
	ptr_a = &a;//pointer, menunjuk ke alamat integer
	pptr_a = &ptr_a;//pointer to pointer, menunjuk ke alamat pointer sebelumnya
	scanf("%d", &a);
	printf("a: %d, &a: %d\n",a,&a);
	printf("ptr_a: %d, *ptr_a: %d, &ptr_a: %d\n",ptr_a,*ptr_a,&ptr_a);
	printf("pptr_a: %d, *pptr_a: %d, **pptr_a: %d, &pptr_a:%d\n",pptr_a,*pptr_a,**pptr_a,&pptr_a);

	int x = 20, y = 30;
	swap(&x,&y);
	printf("x=%d, y=%d\n",x,y);
	return 0;
}
