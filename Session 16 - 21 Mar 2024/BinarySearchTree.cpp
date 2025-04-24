#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

/*
Session 16 - 21 Mar 2024
Binary Search Tree

Konsepnya: leaf kiri akan lebih kecil dari parentnya sedangkan leaf kanan lebih besar dari parentnya

Operations: 
1.Find();
2.Insert();
3.Delete();

Delete Cases:
-Case 1:
-Case 2:
-Case 3:
*/

struct tnode{
	int key;
	struct tnode *left, *right;
	struct tnode *parent;
}*root = NULL,*curr;

struct tnode *newNode(char key){
	struct tnode *node = (struct tnode*) malloc(sizeof(struct tnode));
	node->key = key;
	node->left = node->right = NULL;	
}

int isOperator(int key){
	if(key == '+' || key == '-' || key == '/' || key == '*') return 1;
	return 0;
}

void inOrder(struct tnode*curr){
	if(curr->left!=0)inOrder(curr->left);
	printf("%d ", curr->key);
	if(curr->right!=0)inOrder(curr->right);
}

void preOrder(struct tnode*curr){
	printf("%d ", curr->key);
	if(curr->left!=0)preOrder(curr->left);
	if(curr->right!=0)preOrder(curr->right);
}

void postOrder(struct tnode*curr){
	if(curr->left!=0)postOrder(curr->left);
	if(curr->right!=0)postOrder(curr->right);
	printf("%d ", curr->key);
}

void insert(struct tnode *curr, int key){
	if(!root){
		root = newNode(key);	
	}else{
		if(key == curr->key) printf("Key %d is duplicate\n", key);
		else if(key < curr->key){
			if(!curr->left) curr->left = newNode(key);
			else insert(curr->left, key);
		}else{
			if(!curr->right) curr->right = newNode(key);
			else insert(curr->right, key);
		}
	}
}

void find(struct tnode *curr, int key){
	if(!curr){
		printf("Key %d is not found\n",key);
	}else{
		if(key==curr->key){
			printf("Key %d has been found\n",key);
		}else if(key<curr->key){
			printf("Left ");
			find(curr->left,key);
		}else{
			printf("Right ");
			find(curr->right,key);
		}
	}
}

void del(struct tnode *curr, struct tnode *parent){
	if(!curr->left && !curr->right){
		if(!parent){
			root == NULL;
		}else{
			if(curr == parent->left){
				parent->left = NULL;
			}else if(curr == parent->right){
				parent->right = NULL;
			}
		}
		free(curr);
	}else if(curr->left && !curr->right){
		if(!parent){
			root = curr->left;
		}else{
			if(curr == parent->left){
				parent->left = curr->left;
			}else if(curr == parent->right){
				parent -> right = curr->left;
			}
		}
		free(curr);
	}else if(!curr->left && curr->right){
		if(!parent){
			root = curr->right;
		}else{
			if(curr == parent->left){
				parent->left = curr->right;
			}else if(curr == parent->right){
				parent -> right = curr->right;
			}
		}
		free(curr);
	}else{
		struct tnode *pre = curr->left;
		struct tnode *preParent = curr;
		
		while(pre->right){
			preParent = pre;
			pre = pre->right;
		}
		
		int key = pre->key;
		del(pre, preParent);
		curr->key = key;
	}
}

void findDel(int key){
	struct tnode *parent = NULL;
	struct tnode *curr = root;
	while(curr){
		if(key==curr->key){
			break;
		}
		parent = curr;
		curr = key < curr->key ? curr->left : curr->right;
	}
	if(!curr){
		printf("Key %d is not found\n",key);
	}else{
		del(curr,parent);
	}
}

int main(){
	insert(root, 98);
	insert(root, 2);
	insert(root, 48);
	insert(root, 12);
	insert(root, 56);
	insert(root, 32);
	insert(root, 4);
	insert(root, 67);
	insert(root, 23);
	insert(root, 87);
	insert(root, 23);
	insert(root, 55);
	insert(root, 46);
	insert(root, 21);
	insert(root, 39);
	insert(root, 45);
	insert(root, 54);
	insert(root, 63);
	
	findDel(23);
	printf("\n");
	findDel(56);
	printf("\n");
	findDel(2);
	printf("\n");
	findDel(45);
	printf("\n");
	
	inOrder(root);
	printf("\n");
	
	return 0;
}
