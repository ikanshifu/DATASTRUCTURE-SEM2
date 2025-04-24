#include<stdio.h>
#include<stdlib.h>

struct tnode{
	int key;
	struct tnode *left, *right;
}*root = NULL;

struct tnode *newNode(int key){
	struct tnode *node = (struct tnode*) malloc (sizeof(struct tnode));
	node->key = key;
	node->left = node->right = NULL;
}

void inorder(struct tnode *curr){
	if(curr->left) inorder(curr->left);
	printf("%d ", curr->key);
	if(curr->right) inorder(curr->right);
}

void insert(struct tnode *curr, int key){
	if(!root) root = newNode(key);
	else{
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
	if(!curr) printf("| Key %d not found\n", key);
	else{
		if(key == curr->key) printf("| Key %d has found\n", key);
		else if(key < curr->key){
			printf("Left ");
			find(curr->left, key);
		}else{
			printf("Right ");
			find(curr->right, key);
		}
	}
}

void del(struct tnode *curr, struct tnode *parent){
	if(!curr->left && !curr->right){
		if(!parent) root = NULL;
		else{
			if(curr == parent->left) parent->left = NULL;
			else if (curr == parent->right) parent->right = NULL;
		}
		free(curr);
	}else if(curr->left && !curr->right){
		if(!parent) root = curr->left;
		else{
			if(curr == parent->left) parent->left = curr->left;
			else if (curr == parent->right) parent->right = curr->left;
		}
		free(curr);
	}else if(!curr->left && curr->right){
		if(!parent) root = curr->right;
		else{
			if(curr == parent->left) parent->left = curr->right;
			else if (curr == parent->right) parent->right = curr->right;
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
		if(key == curr->key) break;
		parent = curr;
		curr = key < curr->key ? curr->left : curr->right;
	}
	
	if(!curr) printf("Key %d not found\n", key);
	else{
		del(curr, parent);
	}
}

int main(){
	find(root, 98);
	
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
	
	find(root, 10);
	find(root, 98);
	find(root, 56);
	
	inorder(root);
	puts("");
	
	findDel(23);
	inorder(root);
	puts("");
	findDel(56);
	inorder(root);
	puts("");
	findDel(2);
	inorder(root);
	puts("");
	findDel(45);
	inorder(root);
	puts("");
	findDel(10);
	inorder(root);
	puts("");
	
	
	return 0;
}
