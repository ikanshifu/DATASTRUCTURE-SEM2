#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


struct Data{
	int key;
	int height;
	struct Data *left, *right;
}*root = NULL,*curr;

struct Data *newNode(int x){
	struct Data *node = (struct Data*)malloc(sizeof(struct Data));
	node->key = x;
	node->height = 1;
	node->left = NULL;
	node->right = NULL;
	
	return node;
}

void insert(int x){
	struct Data *node = newNode(x);
	if(!root){
		root = node;
	}else{
		curr = root;
		while(curr){
			if(x<curr->key){
				if(!curr->left){
					curr->left = node;
				}else{
					curr = curr->left;
				}
			}else if(x>curr->key){
				if(!curr->right){
					curr->right = node;
				}else{
					curr = curr->right;
				}
			}
		}	
	}
}

/*
	if(node->key<root->key){
			if(root->left == NULL){
				root->left = node;
				if(root->right == NULL){
					root->height++;
				}			
			}else{
				insert(root->left,node->key);	
				if(root->left == NULL){
					root->height++;
				}
			}
		}else if(node->key>root->key){
			if(root->right == NULL){
				root->right = node;		
			}else{
				insert(root->right,node->key);
			}
		}
*/

void deleteNode(int del){
	return;
}

int findNum(int find){
	curr = root;
	while(curr){
		if(curr->key==find){
			int max;
			curr = curr->left;
			while(!curr->right){
				max = curr->key;
			}
			return 	max;
		}else if(find<curr->key){
			curr = curr->left;	
		}else if(find>curr->key){
			curr = curr->right;
		}
	}
	return -1;
}

//void inOrder(struct Data *node){
//	inOrder(node->left);
//	printf("%d",node->key);
//	inOrder(node->right);
//}

int main(){
	int N;
	scanf("%d", &N);
	int arr[N];
	for(int i = 0;i<N;i++){
		scanf("%d", &arr[i]);
		insert(arr[i]);
	}
	int Q;
	scanf("%d", &Q);
	int t[Q];
	char choice;
	for(int i = 0;i<Q;i++){
		scanf("%d %c",&t[i],&choice);
		if(choice == 'I'){
			insert(t[i]);
		}else if(choice == 'D'){
			deleteNode(t[i]);
		}else if(choice == 'P'){
			int pre = findNum(t[i]);
			printf("%d\n",pre);
		}
	}
	return 0;
}
