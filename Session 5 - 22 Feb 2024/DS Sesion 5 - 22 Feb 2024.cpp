#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
DS Lec - Session 5 - 22 Feb 2024
Introduction to Data Structures
*/

struct Class{
	char name[105];
	int nim;
	float gpa;
}student[10];


int main(){
	int n;
	printf("How many students?\n==> ");
	scanf("%d",&n);
	for(int i = 0;i<n;i++){	
		printf("Nama: ");
		scanf("%s", student[i].name);getchar();
		printf("NIM: ");
		scanf("%d", &student[i].nim);
		printf("GPA: ");
		scanf("%f", &student[i].gpa);
	}
	
	for(int i = 0; i<n; i++){
		printf("Student %d\n",i+1);		
		printf("Nama: %s\nNIM: %d\nGPA: %.2f\n",student[i].name,student[i].nim,student[i].gpa);
	}
	return 0;
}
