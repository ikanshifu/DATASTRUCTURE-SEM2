#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

/*
Session 16 - 21 Mar 2024
-Pre-Order: root, left, right(operator akan ditaro dikiri dengan 2 operan mengikuti di belakangnya)
-In-Order: left, root, right
-Post-Order: left, right, root(operator akan ditaro dikanan dengan 2 operan mengikuti di depannya)

Tree Traversal:
-Depth First: Pre-order, in-order, post-order(konsepnya sama kaya prefix, infix, postfix) kaya pake panah
-Breadth First: Per level
-Engga pake operator, biasanya huruf
*/

struct tnode{
	char key;
	struct tnode *left;
	struct tnode *right;
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
	printf("%c ", curr->key);
	if(curr->right!=0)inOrder(curr->right);
}

void preOrder(struct tnode*curr){
	printf("%c ", curr->key);
	if(curr->left!=0)preOrder(curr->left);
	if(curr->right!=0)preOrder(curr->right);
}

void postOrder(struct tnode*curr){
	if(curr->left!=0)postOrder(curr->left);
	if(curr->right!=0)postOrder(curr->right);
	printf("%c ", curr->key);
}

int main(){
	//Level 0
	root = newNode('F');
	//Level 1
	root->left = newNode('B');
	root->right = newNode('G');
	//Level 2
	root->left->left = newNode('A');
	root->left->right = newNode('D');
	root->right->right = newNode('I');
	//Level 3
	root->left->right->left = newNode('C');
	root->left->right->right = newNode('E');
	root->right->right->left = newNode('H');
	
	inOrder(root);
	printf("\n");
	preOrder(root);
	printf("\n");
	postOrder(root);
	printf("\n");
	return 0;
}
