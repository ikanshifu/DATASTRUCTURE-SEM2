#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct song{
	char songTitle[101];
	char songArtist[101];
	char songDuration[11];
	song *next, *prev;
}*head = NULL, *tail=NULL,*curr,*del;


song* create(char* title, char* artist, char* duration){
	song temp = (song*)malloc(sizeof(song));
	strcpy(temp->songArtist, artist);
	strcpy(temp->songDuration, duration);
	strcpy(temp->songTitle, title);
	temp->next = NULL;
	temp->prev = NULL;
	return temp;
}

void insertSong(char* title, char* artist, char* duration){
	song* temp = create(title, artist, duration);
	if(head == NULL){
		head = temp;
		tail = temp;
	}
	else{
		tail->next = temp;
		temp->prev = tail;
		tail = temp;
	}
}

song* searchSong(char* key){
	song *temp = head;
	if(!head){
		printf("Playlist Empty!\n");
	}
	else while(temp){
		if(strcmp(key, temp->songTitle)==0){
			return temp;
		}
		temp = temp->next;
	}
	return NULL;	
}

void remove(char* key){
	song* temp = searchSong(key);
	if(temp){
		if(head==tail){
			head = NULL;
			tail = NULL;
			free(head);
		}
		else if(temp==head){
			song *right = temp->next;
			head = right;
			right->prev = NULL;
			free(temp);
		}
		else if(temp==tail){
			song *left = temp->prev;
			left->next = NULL;
			tail = left;
			free(temp);
		}
		else{
			song* right = temp->next;
			song* left = temp->prev;
			right->prev = left;
			left->next = right;
			free(temp);	
		}
	}
}

void removeSong(char* key){
	remove(key);
	printf("Song '%s' removed from playlist.\n", key);
}

void showPlaylist(){
	song *temp = head;
	if(!temp){
		printf("Playlist Empty!\n");
	}
	else{
		printf("Playlist: \n");
		while(temp){
			printf("Title: %s | Artist: %s | Duration: %s\n", temp->songTitle, temp->songArtist, temp->songDuration);
			temp = temp->next;
		}
	}
}

void clearPlaylist(){
	song *temp = head;
	while(temp){
		remove(temp->songTitle);
		temp = temp->next;
	}
	printf("Playlist Cleared!\n");
}

void insertAfter(char* prevName, char* title, char* artist, char* duration){
	song *temp = create(title, artist, duration);
	song *prevSong = searchSong(prevName);
	if(prevSong==tail){
		tail->next = temp;
		temp->prev = tail;
		tail = temp;
	}
	else{
		temp->next = prevSong->next;
		prevSong->next->prev = temp;
		temp->prev = prevSong;
		prevSong->next = temp;
	}
	printf("Song '%s' inserted after '%s'.\n", title, prevName);
}

void insertBefore(char* nextName, char* title, char* artist, char* duration){
	song *temp = create(title, artist, duration);
	song *nextSong = searchSong(nextName);
	if(nextSong==head){
		temp->next = head;
		head->prev = temp;
		head = temp;
	}
	else{
		temp->next=nextSong;
		temp->prev=nextSong->prev;
		nextSong->prev->next=temp;
		nextSong->prev=temp;
	}
	printf("Song '%s' inserted before '%s'.\n", title, nextName);
}

int main(){
	insertSong("Song Title 1", "Artist 1", "03:30");
	insertSong("Song Title 2", "Artist 2", "04:15");
	insertSong("Song Title 3", "Artist 3", "02:50");
	insertSong("Song Title 4", "Artist 4", "05:00");

	showPlaylist();
	
	insertAfter("Song Title 2", "Song Title 2.5", "Artist 2.5", "01:45");
	insertBefore("Song Title 4", "Song Title 3.5", "Artist 3.5", "02:30");
	
	showPlaylist();
	
	removeSong("Song Title 2.5");
	removeSong("Song Title 4");
	
	showPlaylist();
	
	clearPlaylist();
	
	showPlaylist();
	return 0;
}
