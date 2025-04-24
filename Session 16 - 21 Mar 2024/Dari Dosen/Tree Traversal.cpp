#include<stdio.h>
#include<stdlib.h>

struct tnode{
	char key;
	struct tnode *left, *right;
}*root = NULL;

struct tnode *newNode(char key){
	struct tnode *node = (struct tnode*) malloc (sizeof(struct tnode));
	node->key = key;
	node->left = node->right  = NULL;
}

void inorder(struct tnode *curr){
	if(curr->left) inorder(curr->left);
	printf("%c ", curr->key);
	if(curr->right) inorder(curr->right);
}

void preorder(struct tnode *curr){
	printf("%c ", curr->key);
	if(curr->left) preorder(curr->left);
	if(curr->right) preorder(curr->right);
}

void postorder(struct tnode *curr){
	if(curr->left) postorder(curr->left);
	if(curr->right) postorder(curr->right);
	printf("%c ", curr->key);
}

int main(){
	root = newNode('F');
	
	root->left = newNode('B');
	root->right = newNode('G');
	
	root->left->left = newNode('A');
	root->left->right = newNode('D');
	root->right->right = newNode('I');
	
	root->left->right->left  = newNode('C');
	root->left->right->right = newNode('E');
	root->right->right->left  = newNode('H');
	
	inorder(root);
	puts("");
	
	preorder(root);
	puts("");
	
	postorder(root);
	puts("");
	
	return 0;
}
