#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct tdata{
	char nim[11];
	int foot, inch;
	float height;
}data[100];

int idx = 0;

void cls(){
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
}

int checkNim (char nim[11]){
	for(int i=0;i<idx;i++){
		if(strcmp(data[i].nim, nim) == 0) return i;
	}
	return idx;
}

int len(char nim[11]){
	int len = 0;
	for(int i=0;nim[i]!='\0';i++){
		len++;
	}
	return len;
}

int isDigit(char nim[11]){
	for(int i=0;nim[i]!='\0';i++){
		if(nim[i] < '0' || nim[i] > '9'){
			return 0;
		}
	}
	return 1;
}

void swap (struct tdata *a, struct tdata *b){
	struct tdata temp = *a;
	*a = *b;
	*b = temp;
}

void sort(){
	for(int i=0;i<idx;i++){
		for(int j=i+1;j<idx;j++){
			if(data[j].height < data[i].height || (data[j].height == data[i].height && strcmp(data[j].nim, data[i].nim) < 0)){
				swap(&data[i], &data[j]);
			}
		}
	}
}

void insert(){
	char nimTemp[11];
	float foot, inch;
	
	do{
		printf("Input NIM [must be 10 numeric characters]: ");
		scanf("%[^\n]", nimTemp); getchar();
	}while(len(nimTemp) != 10 || !isDigit(nimTemp));
	int currIdx = checkNim(nimTemp);
	strcpy(data[currIdx].nim, nimTemp);
	
	do{
		printf("Input foot [0-7]: ");
		scanf("%d", &data[currIdx].foot); getchar();
	}while(data[currIdx].foot < 0 || data[currIdx].foot > 7);
	
	do{
		printf("Input inch [0-11]: ");
		scanf("%d", &data[currIdx].inch); getchar();
	}while(data[currIdx].inch < 0 || data[currIdx].inch > 11);
	
	data[currIdx].height = (data[currIdx].foot * 12 + data[currIdx].inch) * 2.54;
	
	if(currIdx == idx){
		printf("%s Height Inserted\n", nimTemp);
		idx++;
	}
	else printf("%s Height Updated\n", nimTemp);
	
	sort();
	getchar();
}

int menu(){
	int choice;
	do{
		cls();
		printf("1. Insert/Update\n");
		printf("2. View\n");
		printf("3. Exit\n");
		printf("Choice: ");
		
		scanf("%d", &choice); getchar();
	}while(choice < 1 || choice > 3);
	return choice;
}

void view(){
	cls();
	if(idx != 0){
		for(int i=0;i<idx;i++){
			printf("%s %d\" %d\' %.2fcm\n", data[i].nim, data[i].foot, data[i].inch, data[i].height);
		}
	}else printf("No Data");
	
	getchar();
}

int main(){
	int ch;
	do{
		ch = menu();
		switch(ch){
			case 1:
				insert();
				break;
			case 2:
				view();
				break;
		};
	}while(ch != 3);
}
