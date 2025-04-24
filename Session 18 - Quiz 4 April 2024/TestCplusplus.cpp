#include<iostream>
#include<cstring>
#include<cstdlib>

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
		std::cout<<"Playlist is empty."<<"\n";
	}else{
		curr = head;
		std::cout<<"Playlist:"<<"\n";
		while(curr){
			std::cout<<"Title: "<<curr->songTitle<<" | "<<"Artist: "<<curr->artistName<<" | "<<"Duration: "<<curr->songDuration<<"\n";
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
		std::cout<<"No data available!"<<"\n";
	}else{
		if(strcmp(tail->songTitle,find)==0){
			std::cout<<"Song "<<"'"<<node->songTitle<<"'"<<" inserted after "<<"'"<<tail->songTitle<<"'."<<"\n";
			insertSong(title, artist, duration);
		}else{
			curr = head;
			while(curr && strcmp(curr->songTitle,find)!=0){
				curr=curr->next;
			}
			if(curr){
				std::cout<<"Song "<<"'"<<node->songTitle<<"'"<<" inserted after "<<"'"<<curr->songTitle<<"'."<<"\n";
				node->next = curr->next;
				node->prev = curr;
				curr->next->prev = node;
				curr->next = node;
			}else{
				std::cout<<"Song "<<"'"<<find<<"'"<<" not found!"<<std::endl;
			}
		}
	}
}

void insertBefore(char find[],char title[], char artist[], char duration[]){
	struct Data *node = newNode(title, artist, duration);
	if(head==NULL){
		std::cout<<"No data available!"<<"\n";
	}else{
		if(strcmp(head->songTitle,find)==0){
			std::cout<<"Song "<<"'"<<node->songTitle<<"'"<<" inserted before "<<"'"<<head->songTitle<<"'."<<"\n";
			pushHead(title, artist, duration);
		}else{
			curr = head;
			while(curr && strcmp(curr->songTitle,find)!=0){
				curr=curr->next;
			}
			if(curr){
				std::cout<<"Song "<<"'"<<node->songTitle<<"'"<<" inserted before "<<"'"<<curr->songTitle<<"'."<<"\n";
				node->next = curr;
				node->prev = curr->prev;
				curr->prev->next = node;
				curr->prev = node;
			}else{
				std::cout<<"Song "<<"'"<<find<<"'"<<" not found!"<<"\n";
			}
		}
	}
}

void popHead(){
	if(head==NULL){
		std::cout<<"There is no Data!"<<std::endl;
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
		std::cout<<"There is no Data!"<<std::endl;
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
		std::cout<<"There is no Data!"<<std::endl;
	}else if(head==tail){
		std::cout<<"Song "<<"'"<<deleteTitle<<"'"<<" removed from the playlist."<<"\n";
		head = tail = NULL;
		free(head);
		free(tail);
	}else{
		if(strcmp(head->songTitle,deleteTitle)==0){
			std::cout<<"Song "<<"'"<<deleteTitle<<"'"<<" removed from the playlist."<<"\n";
			popHead();
		}else if(strcmp(tail->songTitle,deleteTitle)==0){
			std::cout<<"Song "<<"'"<<deleteTitle<<"'"<<" removed from the playlist."<<"\n";
			popTail();
		}else{
			curr = head;
			while(curr&&strcmp(curr->songTitle,deleteTitle)!=0){
				curr = curr->next;
			}
			if(curr){
				std::cout<<"Song "<<"'"<<deleteTitle<<"'"<<" removed from the playlist."<<"\n";
				curr->next->prev = curr->prev;
				curr -> prev-> next = curr->next;
				free(curr);	
			}else{
				std::cout<<"Song "<<"'"<<deleteTitle<<"'"<<" not found!"<<std::endl;
			}
		}
	}
}

void clearPlaylist(){
	while(head){
		popHead();
	}
	std::cout<<"Playlist cleared."<<std::endl;
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
