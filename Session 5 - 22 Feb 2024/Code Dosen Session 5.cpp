#include<stdio.h>

struct profile{
	char name[50], address[200];
	int age, height, weight;
};

struct student{
	char nim[11];
	float gpa;
	profile pro;
}student2, st[100];

struct lecture{
	char code[6], level;
	profile pro;
};

int main(){
	student student1;
	
	student1.gpa = 3.75;
	student2.gpa = 4.00;
	student1.pro.height = 170;
	
	for(int i=0;i<5;i++){
		scanf("%s", st[i].nim); getchar();
		scanf("%s", st[i].pro.name); getchar();
		scanf("%f", &st[i].gpa); getchar();
	}
	
	for(int i=0;i<5;i++){
		printf("%s %s %.2f\n", st[i].nim, st[i].name, st[i].gpa);
	}
	
	return 0;
}
