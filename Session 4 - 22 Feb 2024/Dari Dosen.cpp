#include<stdio.h>

void swap(int *x, int *y){
	int temp = *x;
	*x = *y;
	*y = temp;
	printf("x: %d, y: %d\n", *x, *y);
}

int main(){
	int x, *px, **ppx, y=5;
	
	x = 10;
	px = &x;
	ppx = &px;
	
	*px = 20;
	px = &y;
	
	printf("x: %d, &x: %d\n", x, &x);
	printf("y: %d, &y: %d\n", y, &y);
	printf("px: %d, *px: %d, &px: %d\n", px, *px, &px);
	printf("ppx: %d, *ppx: %d, **ppx: %d, &ppx: %d\n", ppx, *ppx, **ppx, &ppx);
	
	int a = 20, b = 10;
	
	swap(&a, &b);
	printf("a: %d, b: %d\n", a, b);
	
	
	int c = 20, d = 10;
	swap(&c, &d);
	printf("c: %d, d: %d\n", c, d);
}
