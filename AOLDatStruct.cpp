#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*AOL Data Structure
	Name: Clive Clay Irawan
	NIM: 2702373412
	Class: LL01
	Goal: Make a program that stores slangs in the dictionary using a Trie
*/

struct Slang {
  	char character;
 	char wordDescription[105];
  	struct Slang* children[26]; // Assuming only lowercase alphabets
	bool isEndOfWord;
}*curr,*root;

//Function: to create a new node
struct Slang* newNode(char character, const char* description) {
  struct Slang* node = (struct Slang*)malloc(sizeof(struct Slang));
  node->character = character;
  for (int i = 0; i < 26; i++) {
    node->children[i] = NULL;
  }
  strcpy(node->wordDescription,description);
  node->isEndOfWord = false;
  return node;
}

//Function: word validation when inserting word
int isAlphabetWord(char check[]){
	int i = 0;
	while(check[i]){
		if((check[i]>='A'&&check[i]<='Z')||(check[i]>='a'&&check[i]<='z')){
			i++;
		}else{
			return 1;
		}
	}
	return 0;
}

//Function: word validation when inserting a description
int isAlphabetDesc(char check[]){
	int i = 0, spaces = 0;
	while(check[i]){
		if(check[i]==' '){
			spaces++;
			i++;
		}else{
			i++;
		}
	}
	return spaces;
}

//Function: to insert a word into the Trie
void insert(struct Slang* root, char word[], char description[]) {
  int length = strlen(word);
  curr = root;
  for (int i = 0; i < length; i++) {
    int index = word[i] - 'a';
    if (!curr->children[index]) {
      curr->children[index] = newNode(word[i],description);
    }
    curr = curr->children[index];
  }
  curr->isEndOfWord = true;
}

//Function: to search for a word in the Trie
void search(struct Slang* root, char find[]) {
  int length = strlen(find);
  curr = root;
  for (int i = 0; i < length; i++) {
    int index = find[i] - 'a';
    if(!curr->children[index]){
      printf("There is no word \"%s\" in the dictionary.\n", find);
      return;
    }
    curr = curr->children[index];
	}
	if(curr->isEndOfWord){
    	printf("Slang Word : %s\n", find);
		printf("Description : %s\n", curr->wordDescription);
 	}else{
    	printf("There is no word \"%s\" in the dictionary.\n", find);
	}
}

//Function: To print all the words in the Trie
void printAll(struct Slang* root, char word[], int *index) {
  if (root->isEndOfWord) {
    printf("%d. %s\n", *index, word);
    *index+=1;
  }
  for (int i = 0; i < 26; i++) {
    if (root->children[i]) {
      word[strlen(word)] = root->children[i]->character;
      word[strlen(word) + 1] = '\0';
      printAll(root->children[i], word, index);
      word[strlen(word) - 1] = '\0';
    }
  }
}

//Function: To check if a word has been inserted before
bool doesWordExist(struct Slang* root, char word[]) {
  int length = strlen(word);
  curr = root;
  for (int i = 0; i < length; i++) {
    int index = word[i] - 'a';
    if (!curr->children[index]) {
      return false; 
    }
    curr = curr->children[index];
  }
  return curr->isEndOfWord;
}

//Function: To check if a prefix exist in the Trie
bool searchPrefix(struct Slang* root, char prefix[]) {
  int length = strlen(prefix);
  curr = root;
  for (int i = 0; i < length; i++) {
    int index = prefix[i] - 'a';
    if (!curr->children[index]) {
      return false;
    }
    curr = curr->children[index];
  }
  return true;
}

//Function: To print all the words beginnning in a prefix
void printByPrefix(struct Slang* root, char* prefix, int height, int* index) {
  if (root->isEndOfWord) {
    prefix[height] = '\0';
    printf("%d. %s\n", *index, prefix);
    (*index)++;
  }
  for (int i = 0; i < 26; i++) {
    if (root->children[i]) {
      prefix[height] = i + 'a';
      printByPrefix(root->children[i], prefix, height + 1, index);
    }
  }
}
//Function: the insert song menu
void releaseSongMenu(){
	char word[25],description[105];
	int flag, spaces,update=0;
	do{
		printf("Input a new slang word[Must be more than 1 characters and contain no space]: ");
		scanf(" %[^\n]",&word);
		flag = isAlphabetWord(word);
	}while(strlen(word)<=1||flag!=0);
	do{
		printf("Input a new slang word description[Must be more than 2 words]: ");
		scanf(" %[^\n]",&description);
		spaces = isAlphabetDesc(description);
	}while(spaces<=2);
	printf("\n");
	if(doesWordExist(root, word)){
		update = 1;
	}
	getchar();
	if(update==1){
		strcpy(curr->wordDescription,description);
		printf("Successfully updated a slang word.\n");
		printf("Press enter to continue...\n");	
	}else{
		insert(root, word, description);			
		printf("Successfully released new slang word.\n");
		printf("Press enter to continue...\n");
	}
	getchar();
}

//Function: To search song menu
void searchSong(){
	char find[25];
	int flag;
	do{
		printf("Input a slang word to be searched [Must be more than 1 characters and contain no space]: ");
		scanf(" %[^\n]",&find);
		flag = isAlphabetWord(find);
	}while(strlen(find)<=1||flag!=0);
	printf("\n");
	search(root, find);getchar();
	printf("\n");
	printf("Press enter to continue...\n");
	getchar();
}

//Function: to view words starting with a prefix
void viewByPrefix(){
	char prefix[25];
	int flag;
	do{
		printf("Input a prefix to be searched[Must be at least 1 characters and contain no space]: ");
		scanf(" %[^\n]",&prefix);getchar();
		flag = isAlphabetWord(prefix);	
	}while(strlen(prefix)<1||flag!=0);
	printf("\n");
	if(searchPrefix(root, prefix)){
		printf("Words starts with \"%s\":\n",prefix);
		int index = 1;
		printByPrefix(curr, prefix, strlen(prefix), &index);
	}else{
		printf("There is no prefix \"%s\" in the dictionary.\n",prefix);
	}
	printf("\n");
	printf("Press enter to continue...\n");
	getchar();
}

//Function: to check if the node is empty
bool isNodeEmpty(struct Slang* node) {
  if (node->isEndOfWord) {
    return false;
  }
  for (int i = 0; i < 26; i++) {
    if (node->children[i]) {
      return false;
    }
  }
  return true;
}

//Function: to print all the words in the Trie
void viewAll(){
	char word[25] = "";
	int index = 1;
	if(isNodeEmpty(root)){
		printf("There is no slang word yet in the dictionary\n");
	}else{
		printf("List of all slang words in the dictionary:\n");
		printAll(root,word,&index);
		printf("\n");
	}
	printf("Press enter to continue...\n");
	getchar();
}

void exitMenu(){
	printf("Thank you... Have a nice day :)\n");
	printf("Press any key to exit...\n");
}

int main() {
 	root = newNode('\0',"");
	int choice;
	do{
		printf("Boogle\n");
		printf("\n");
		printf("1. Release a new slang word\n");
		printf("2. Search a slang word\n");
		printf("3. View all slang words starting with a certain prefix word\n");
		printf("4. View all slang words\n");
		printf("5. Exit\n");
		printf("Choose[1..5]: ");
		scanf("%d",&choice);
		getchar();
		system("cls");
		switch(choice){
			case 1:
				releaseSongMenu();
				system("cls");
				break;
			case 2:
				searchSong();
				system("cls");
				break;
			case 3:
				viewByPrefix();
				system("cls");
				break;
			case 4:
				viewAll();
				system("cls");
				break;
			case 5:
				exitMenu();
				return 0;
		}
	}while(choice<1||choice>5||choice>=1&&choice<=5);
  return 0;
}
