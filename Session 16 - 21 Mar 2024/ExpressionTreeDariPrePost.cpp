#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

/*
Session 16 - 21 Mar 2024
Traversal Tree and Expression Tree 
Dibuat dari prefix dan postfix
*/


char strPrefix[] = "+*-*5+227+27-A*+68B";
char strPostfix[]  = "522+*7-27+*A68+B*-+";
int i = 0, j = strlen(strPostfix)-1;

struct tnode{
	char key;
	struct tnode *left;
	struct tnode *right;
	struct tnode *parent;
}*rootPre = NULL,*rootPost = NULL,*curr;

struct tnode *newNode(char key){
	struct tnode *node = (struct tnode*) malloc(sizeof(struct tnode));
	node->key = key;
	node->left = node->right = NULL;	
}

int isOperator(int key){
	if(key == '+' || key == '-' || key == '/' || key == '*') return 1;
	return 0;
}

void infix(struct tnode*curr){
	if(isOperator(curr->key)) printf("( ");
	if(curr->left!=0)infix(curr->left);
	printf("%c ", curr->key);
	if(curr->right!=0)infix(curr->right);
	if(isOperator(curr->key)) printf(") ");
}

void prefix(struct tnode*curr){
	printf("%c ", curr->key);
	if(curr->left!=0)prefix(curr->left);
	if(curr->right!=0)prefix(curr->right);
}

void postfix(struct tnode*curr){
	if(curr->left!=0)postfix(curr->left);
	if(curr->right!=0)postfix(curr->right);
	printf("%c ", curr->key);
}

void createTreePrefix(struct tnode *curr){
	if(isOperator(strPrefix[i])){
		i++;
		curr->left = newNode(strPrefix[i]);
		createTreePrefix(curr->left);
		
		i++;
		curr->right = newNode(strPrefix[i]);
		createTreePrefix(curr->right);
	}
}

void createTreePostfix(struct tnode *curr){
	if(isOperator(strPostfix[j])){
		j--;
		curr->right = newNode(strPostfix[j]);
		createTreePostfix(curr->right);
		
		j--;
		curr->left = newNode(strPostfix[j]);
		createTreePostfix(curr->left);
	}
}

int main(){
	rootPre = newNode(strPrefix[i]);
	rootPost = newNode(strPostfix[i]);
	
	createTreePrefix(rootPre);
	createTreePostfix(rootPost);
	puts("From PreFix");
	infix(rootPre);
	printf("\n");
	prefix(rootPre);
	printf("\n");
	postfix(rootPre);
	printf("\n\n");
	
	puts("From PostFix");
	infix(rootPost);
	printf("\n");
	prefix(rootPost);
	printf("\n");
	postfix(rootPost);
	printf("\n");
	
	return 0;
}
