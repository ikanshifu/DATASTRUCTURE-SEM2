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

int isOperator(int key){
	if(key == '+' || key == '-' || key == '/' || key == '*') return 1;
	return 0;
}

void infix(struct tnode *curr){
	if(isOperator(curr->key)) printf("( ");
	if(curr->left) infix(curr->left);
	printf("%c ", curr->key);
	if(curr->right) infix(curr->right);
	if(isOperator(curr->key)) printf(") ");
}

void prefix(struct tnode *curr){
	printf("%c ", curr->key);
	if(curr->left) prefix(curr->left);
	if(curr->right) prefix(curr->right);
}

void postfix(struct tnode *curr){
	if(curr->left) postfix(curr->left);
	if(curr->right) postfix(curr->right);
	printf("%c ", curr->key);
}

int main(){
	root = newNode('+');
	
	root->left = newNode('*');
	root->right = newNode('-');
	
	root->left->left = newNode('-');
	root->left->right = newNode('+');
	root->right->left = newNode('A');
	root->right->right = newNode('*');
	
	root->left->left->left  = newNode('*');
	root->left->left->right = newNode('7');
	root->left->right->left  = newNode('2');
	root->left->right->right = newNode('7');
	root->right->right->left  = newNode('+');
	root->right->right->right = newNode('B');
	
	root->left->left->left->left  = newNode('5');
	root->left->left->left->right  = newNode('+');
	root->right->right->left->left  = newNode('6');
	root->right->right->left->right  = newNode('8');
	
	root->left->left->left->right->left  = newNode('2');
	root->left->left->left->right->right  = newNode('2');
	
	infix(root);
	puts("");
	
	prefix(root);
	puts("");
	
	postfix(root);
	puts("");
	
	return 0;
}
