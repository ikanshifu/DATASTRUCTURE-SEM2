#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct tnode{
	char key;
	struct tnode *left, *right;
}*root = NULL;

char strPostfix[] = "522+*7-27+*A68+B*-+";
int i = strlen(strPostfix) - 1;

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
	if(isOperator(strPostfix[i])){
		i--;
		curr->right = newNode(strPostfix[i]);
		createTree(curr->right);
		
		i--;
		curr->left = newNode(strPostfix[i]);
		createTree(curr->left);
	}
}

int main(){
	root = newNode(strPostfix[i]);
	createTree(root);
	
	infix(root);
	puts("");
	
	prefix(root);
	puts("");
	
	postfix(root);
	puts("");
	
	return 0;
}
