#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Data{
	char nim[15];//Untuk Update-an pake temp nim lalu searching
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

void linearSearch(int size, char temp[], int *flag, int *target){
	if(size!=1){
		for(int i = 0;i<size;i++){
			if(strcmp(student[i].nim,temp)==0){
				*flag = 1;
				*target = i;
				break;
			}
		}	
	}
}

int numberChecker(char nim[15]){
	for(int i=0;nim[i]!='\0';i++){
		if(nim[i] < '0' || nim[i] > '9'){
			return 0;
		}
	}
	return 1;
}

void addHeight(int *n){
	int flag = 0,target=0,num = *n;
	char temp[15];
	do{
		printf("Input NIM [must be 10 numeric characters]: ");
		scanf("%s", temp);getchar();
	}while(strlen(temp)!=10||!numberChecker(temp));
	strcpy(student[num].nim,temp);
	linearSearch(num+1,temp,&flag,&target);
	if(flag==0){
		do{
			printf("Input foot [0-7]: ");
			scanf("%d", &student[num].foot);	
		}while(student[num].foot<0||student[num].foot>7);
		do{
			printf("Input inch [0-11]: ");
			scanf("%d", &student[num].inch);
		}while(student[num].inch<0||student[num].inch>11);
		student[num].cm = ((student[num].foot*12)+student[num].inch)*2.54;
		printf("%s Height Inserted\n",student[num].nim);
		*n+=1;
		printf("Press enter to return...\n");getchar();
	}else if(flag==1){
		do{
			printf("Input foot [0-7]: ");
			scanf("%d", &student[target].foot);	
		}while(student[target].foot<0||student[target].foot>7);
		do{
			printf("Input inch [0-11]: ");
			scanf("%d", &student[target].inch);
		}while(student[target].inch<0||student[target].inch>11);
		student[target].cm = ((student[target].foot*12)+student[target].inch)*2.54;
		printf("%s Height Updated\n",student[target].nim);
		printf("Press enter to return...\n");getchar();
	}
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
	int n=0;//number of initial students
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
