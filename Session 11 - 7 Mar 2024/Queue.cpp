#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
Session 11 - 7 Mar 2024
Queue
//Tugas
*/

//Queue adalah data structure yang bersifat linear dan menyimpan datanya secara berurutan
//Dia menerapkan sistem FIFO yaitu First In First Out, artinya yang pertama masuk pasti akan pertama keluar
/*Circular queue lebih efisien karena biasanya queue, ketika kita pop data, maka index data yang dihilangkan akan kosong dan tidak digunakan lagi.
melalui circular queue, maka index yang tadinya kosong bisa digunakan lagi
*/

struct Quasar{
	char patient_name[25];
	int priorityLevel;
	int age;
	char levelName[25];
	struct Quasar *next, *prev;
}*head=NULL, *tail=NULL, *curr;

struct Quasar *newNode(char name[], int level, int age,char lvlName[]){
	struct Quasar *node = (struct Quasar*) malloc(sizeof(struct Quasar));
	strcpy(node->patient_name,name);
	node->priorityLevel = level;
	node->age = age; 
	if(node->priorityLevel == 1){
		strcpy(node->levelName,"Emergency");
	}else if(node->priorityLevel == 2){
		strcpy(node->levelName,"Super VIP");
	}else if(node->priorityLevel == 3){
		strcpy(node->levelName,"VIP");
	}else if(node->priorityLevel == 4){
		strcpy(node->levelName,"Basic");
	}
	node->next = node->prev = NULL;	
}

void print(int num){
	curr = head;
	int i = 0;
	while(curr){
		printf("%d. %-10s|%+28s (%d)\n",i+1, curr->levelName, curr->patient_name, curr->age);
		curr = curr->next;
		i++;
	}
}

int isAlphabet(char name[]) {
    int i = 0;
    while (name[i]) {
        if ((name[i] >= 'A' && name[i] <= 'Z') || (name[i] >= 'a' && name[i] <= 'z')||name[i]==' ') {
            i++;
        } else {
            return 0; // Not an alphabet character
        }
    }
    return 1; // All characters are alphabet characters
}

void pushHead(char name[], int level, int age,char lvlName[]){
	struct Quasar *node = newNode(name,level,age,lvlName);
	if(head==NULL){
		head = tail = node;
	}else{
		node->next = head;
		head->prev = node;
		head = node;
	}
}

void pushTail(char name[], int level, int age,char lvlName[]){
	struct Quasar *node = newNode(name,level,age,lvlName);
	if(head==NULL){
		head = tail = node;
	}else{
		node->prev = tail;
		tail->next = node;
		tail = node;
	}
}

void pushMid(char name[], int level, int age, char lvlName[]) {
    struct Quasar *node = newNode(name, level, age, lvlName);

    if (head == NULL) {
        head = tail = node;
    } else if (head->priorityLevel > level) {
        pushHead(name, level, age, lvlName);
    } else {
        struct Quasar *curr = head;
        while (curr->next && curr->next->priorityLevel < level) {
            curr = curr->next;
        }
        node->next = curr->next;
        node->prev = curr;

        if (curr->next) {
            curr->next->prev = node;
        } else {
            tail = node;
        }

        curr->next = node;
    }
}

void popHead(){
	if(head==NULL){
		puts("No Data!");
	}else{
		curr = head;
		if(head==tail){
			head = tail = NULL;
		}else{
			head = head->next;
			head->prev = NULL;
		}
		free(curr);
	}
}

void popTail(){
	if(head==NULL){
		puts("No Data!");
	}else{
		curr = head;
		if(head==tail){
			head = tail = NULL;
		}else{
			tail = tail->prev;
			tail->next = NULL;
		}
		free(curr);
	}
}

void popAll(){
	while(head){
		popHead();
	}
}

void push(char name[], int level, int age,char lvlName[]){
	struct Quasar *node = newNode(name,level,age,lvlName);
	if(head==NULL){
		pushHead(name,level,age,lvlName);
	}else{
		pushMid(name,level,age,lvlName);
	}
}

void addPatient(int *num){
	int level,age,flag;
	char name[30];
	char lvlName[30];
	do{
		printf("Input Patient Name [1..25]: ");
		scanf(" %[^\n]",name);
		flag = isAlphabet(name);
	}while(strlen(name)<1||strlen(name)>25||flag==0);
	do{
	puts("1. Emergency");	
	puts("2. Super VIP");	
	puts("3. VIP");	
	puts("4. Basic");	
	printf("Select Class[1..4]: ");
	scanf("%d",&level);
	}while(level<1||level>4);
	do{
		printf("Input Age [1..110]: ");
		scanf("%d",&age);
	}while(age<1 || age>110);
	push(name,level,age,lvlName);
	*num+=1;
	puts("Patient added!");
	printf("Press enter to return...\n");getchar();
}

void callPatient(int *num){
	if(*num==0){
		puts("No Patient to be called..");
		printf("Press enter to return...\n");getchar();
	}else{
		curr = head;
		puts("Attention Please!!");
		puts("");
		printf("Patient from %s Room\n",curr->levelName);
		printf("With name %s, %d years\n",curr->patient_name,curr->age);
		puts("Please moving ahead to Aministration Room...");
		popHead();
		*num-=1;
		printf("Press enter to return...\n");getchar();
	}
}

void removeAll(int *num){
	popAll();
	*num=0;
	printf("All patient list has been purge\n");
	printf("Press enter to return...\n");getchar();
}

void exitMenu(){
	printf("Thank you for using Quasar 1.3\n");
}

int main(){
	int choice,num=0;
	do{
		if(num!=0){
			puts("Quasar Hospital Queue");
			puts("------------------------------------------------");
			print(num);
			puts("");
		}
		printf("Patient: %d people(s)\n",num);
		puts("");		
		puts("==================");
		puts("|Quasar Queue 1.3|");
		puts("==================");
		puts("1. Add Patient");	
		puts("2. Call Patient");	
		puts("3. Remove All Patient List");	
		puts("4. Exit");	
		printf("Select[1..4]: ");
		scanf("%d",&choice);
		puts("");
		switch(choice){
			case 1:				
				addPatient(&num);
				getchar();
				system("cls");
				break;
			case 2:
				callPatient(&num);
				getchar();
				system("cls");
				break;
			case 3:
				removeAll(&num);
				getchar();
				system("cls");
				break;
			case 4:
				exitMenu();
				return 0;
		}	
	}while(choice<1 || choice >4 || choice>=1 && choice<=4);
	return 0;
}
