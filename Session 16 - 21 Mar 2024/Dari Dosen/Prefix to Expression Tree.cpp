#include<stdio.h>
#include<stdlib.h>

struct tnode{
	char key;
	struct tnode *left, *right;
}*root = NULL;

char strPrefix[] = "+*-*5+227+27-A*+68B";
int i = 0;

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

void createTree(struct tnode *curr){
	if(isOperator(strPrefix[i])){
		i++;
		curr->left = newNode(strPrefix[i]);
		createTree(curr->left);
		
		i++;
		curr->right = newNode(strPrefix[i]);
		createTree(curr->right);
	}
}

int main(){
	root = newNode(strPrefix[i]);
	createTree(root);
	
	infix(root);
	puts("");
	
	prefix(root);
	puts("");
	
	postfix(root);
	puts("");
	
	return 0;
}
