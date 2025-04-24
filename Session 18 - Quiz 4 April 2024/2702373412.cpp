#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/*
NIM: 2702373412
Nama: Clive Clay Irawan
*/

struct Data{
	char songTitle[25];
	char artistName[25];
	char songDuration[8];
	struct Data *next, *prev;	
}*head = NULL, *tail = NULL, *curr, *del;

char title[25],artist[25],duration[8],deleteTitle[25],find[25];

struct Data *newNode(char title[], char artist[], char duration[]){
	struct Data *node = (struct Data*)malloc(sizeof(struct Data));
	strcpy(node->songTitle,title);
	strcpy(node->artistName,artist);
	strcpy(node->songDuration,duration);
	node->next = NULL;
	node->prev = NULL;
}

void showPlaylist(){
	if(head==NULL){
		printf("Playlist is empty.\n");
	}else{
		curr = head;
		printf("Playlist:\n");
		while(curr){
			printf("Title: %s | Artist: %s | Duration: %s\n",curr->songTitle,curr->artistName,curr->songDuration);
			curr = curr->next;
		}
	}
}

void pushHead(char title[], char artist[], char duration[]){
	struct Data *node = newNode(title, artist, duration);
	if(head==NULL){
		head = tail = node;
	}else{
		node->next = head;
		node->prev = NULL;
		head ->prev = node;
		head = node;
	}
}

void insertSong(char title[], char artist[], char duration[]){
	struct Data *node = newNode(title, artist, duration);
	if(head==NULL){
		head = tail = node;
	}else{
		node->next = NULL;
		node->prev = tail;
		tail ->next = node;
		tail = node;
	}
}

void insertAfter(char find[],char title[], char artist[], char duration[]){
	struct Data *node = newNode(title, artist, duration);
	if(head==NULL){
		puts("No data available!");
	}else{
		if(strcmp(tail->songTitle,find)==0){
			printf("Song '%s' inserted after '%s'.\n",node->songTitle,tail->songTitle);
			insertSong(title, artist, duration);
		}else{
			curr = head;
			while(curr && strcmp(curr->songTitle,find)!=0){
				curr=curr->next;
			}
			if(curr){
				printf("Song '%s' inserted after '%s'.\n",node->songTitle,curr->songTitle);
				node->next = curr->next;
				node->prev = curr;
				curr->next->prev = node;
				curr->next = node;
			}else{
				printf("Song '%s' not found!\n",find);
			}
		}
	}
}

void insertBefore(char find[],char title[], char artist[], char duration[]){
	struct Data *node = newNode(title, artist, duration);
	if(head==NULL){
		puts("No data available!");
	}else{
		if(strcmp(head->songTitle,find)==0){
			printf("Song '%s' inserted before '%s'.\n",node->songTitle,head->songTitle);
			pushHead(title, artist, duration);
		}else{
			curr = head;
			while(curr && strcmp(curr->songTitle,find)!=0){
				curr=curr->next;
			}
			if(curr){
				printf("Song '%s' inserted before '%s'.\n",node->songTitle,curr->songTitle);
				node->next = curr;
				node->prev = curr->prev;
				curr->prev->next = node;
				curr->prev = node;
			}else{
				printf("Song '%s' not found!\n",find);
			}
		}
	}
}

void popHead(){
	if(head==NULL){
		puts("There is no Data!");
	}else if(head==tail){
		head = tail = NULL;
		free(head);
		free(tail);
	}else{
		curr = head;
		head = curr->next;
		head ->prev = NULL;
		free(curr);
	}
}

void popTail(){
	if(head==NULL){
		puts("There is no Data!");
	}else if(head==tail){
		head = tail = NULL;
		free(head);
		free(tail);
	}else{
		curr = tail;
		tail = curr->prev;
		tail -> next = NULL;
		free(curr);
	}
}

void removeSong(char deleteTitle[]){
	if(head==NULL){
		puts("There is no Data!");
	}else if(head==tail){
		printf("Song '%s' removed from the playlist.\n",head->songTitle);
		head = tail = NULL;
		free(head);
		free(tail);
	}else{
		if(strcmp(head->songTitle,deleteTitle)==0){
			printf("Song '%s' removed from the playlist.\n",deleteTitle);
			popHead();
		}else if(strcmp(tail->songTitle,deleteTitle)==0){
			printf("Song '%s' removed from the playlist.\n",deleteTitle);
			popTail();
		}else{
			curr = head;
			while(curr&&strcmp(curr->songTitle,deleteTitle)!=0){
				curr = curr->next;
			}
			if(curr){
				printf("Song '%s' removed from the playlist.\n",deleteTitle);
				curr->next->prev = curr->prev;
				curr -> prev-> next = curr->next;
				free(curr);	
			}else{
				printf("Song '%s' not found!\n",deleteTitle);
			}
		}
	}
}

void clearPlaylist(){
	while(head){
		popHead();
	}
	printf("Playlist cleared.\n");
}

int main(){
	insertSong("Song Title 1","Artist 1","03:30");
	insertSong("Song Title 2","Artist 2","04:15");
	insertSong("Song Title 3","Artist 3","02:50");
	insertSong("Song Title 4","Artist 4","05:00");
	
	showPlaylist();
	
	insertAfter("Song Title 2","Song Title 2.5","Artist 2.5","01:45");
	insertBefore("Song Title 4","Song Title 3.5","Artist 3.5","02:30");
	
	showPlaylist();
	
	removeSong("Song Title 2.5");
	removeSong("Song Title 4");
	
	showPlaylist();
	
	clearPlaylist();
	
	showPlaylist();
	
	return 0;
}
