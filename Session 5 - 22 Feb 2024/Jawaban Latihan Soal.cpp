#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Kekurangan:
-Seharusnya engga perlu input berapa student
-Belum ada saringan karakter di string(pake if character <0 atau character>9
-Belum bisa update list
*/

struct Data{
	char nim[11];//Untuk Update-an pake temp nim lalu searching
	int foot;
	int inch;
	float cm;
}student[100];

void swap(Data *a, Data *b){
	Data temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int low, int high){
	int pivotIdx = high;
	int i = low-1;
	for(int j = low; j<high;j++){
		if(student[j].cm<student[pivotIdx].cm){
			i++;
			swap(&student[i],&student[j]);
		}else if(student[j].cm==student[pivotIdx].cm){
			if(strcmp(student[j].nim,student[pivotIdx].nim)<0){
				i++;
				swap(&student[i],&student[j]);
			}
		}
	}
	i++;
	swap(&student[i],&student[pivotIdx]);
	return i;	
}

void quickSort(int low, int high){
	if(low>=high){
		return;
	}
	int pi = partition(low,high);
	quickSort(low, pi-1);
	quickSort(pi+1,high);
}

void linearSearch(){
	
}

void addHeight(int *n){
	for(int i = 0;i<*n;i++){
		int flag = 0;
		do{
			printf("Input NIM [must be 10 numeric characters]: ");
			scanf("%s", student[i].nim);getchar();
			for(int j = 1;j<=strlen(student[i].nim);j++){
				if(student[i].nim[j]<'0'||student[i].nim[j]>'9'){
					flag = 1;
					break;
				}
			}
		}while(strlen(student[i].nim)<10||strlen(student[i].nim)>10&&flag==0);
		do{
			printf("Input foot [0-7]: ");
			scanf("%d", &student[i].foot);	
		}while(student[i].foot<0||student[i].foot>7);
		do{
			printf("Input inch [0-11]: ");
			scanf("%d", &student[i].inch);
		}while(student[i].inch<0||student[i].inch>11);
		student[i].cm = ((student[i].foot*12)+student[i].inch)*2.54;
		printf("%s Height Inserted\n",student[i].nim);
	}
	printf("Press enter to return...\n");getchar();
}

void printHeight(int *n){
	quickSort(0,*n-1);
	if(*n>0){
		for(int i = 0; i<*n; i++){		
			printf("%s %d'%d'' %.2fcm\n",student[i].nim,student[i].foot,student[i].inch,student[i].cm);
		}
		printf("Press enter to return...\n");
		getchar();
	}else{
		printf("No data\n");
		printf("Press enter to return...\n");
		getchar();
	}
}

void exitMenu(){
	printf("Thank you for using this program!\n");
}

int main(){
	int choice;
	int n=0;//number of students
	do{
		printf("================\n");
		printf("|Height Manager|\n");
		printf("================\n");
		printf("1) Add New Height\n");	
		printf("2) Print All Height\n");	
		printf("3) Exit\n");	
		printf("Choose Option[1-3]: ");
		scanf("%d",&choice);
		system("cls");
		switch(choice){
			case 1:				
				printf("How many students?\n>> ");
				scanf("%d",&n);
				addHeight(&n);
				getchar();
				system("cls");
				break;
			case 2:
				printHeight(&n);
				getchar();
				system("cls");
				break;
			case 3:
				exitMenu();
				return 0;
		}	
	}while(choice<1 || choice >3 || choice>=1 && choice<=3);
	return 0;
}
