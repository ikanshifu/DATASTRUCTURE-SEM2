#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

/*
Session 15 - 21 Mar 2024
Tree and Binary Tree

-Tree bersifat non-linear sehingga bentuknya hierarki
-Root node:Node paling atas
-Edge: Garis menyambung 2 node
-Leaf node: engga punya anak,biasanya paling bawah
-Sibling: kalau punya parent yang sama
-Path: sequence consecutive jalur
-Ancestor node: punya keturunan
-Descendant node: keturunannya
-Binary Tree: tree yang paling banyak 2 anak doang
-Depth: length path dari root ke node itu(depth root itu 0)
-Height: Jumlah node/tinggi
-Jumlah maksimum node di setiap level tergantung level berapa, rumusnya 2^k, k itu levelnya
-Jumlah maksimum node di keseluruhan binary tree rumusnya 2^h+1 - 1(h itu height)
-Minimum height 2 log n
-Maxmimum heihgt n - 1
-Left child 2p+1
-Right child 2p+2
-Parent (p-1)/2
*/

/*
Jenis-jenis Binary Tree
-Perfect: setiap level lengkap dan sama
-Complete: engga ada yang bolong
-Skewed: 1 anak untuk setiap root
-Balanced: 
*/

/*
-Prefix: root, left, right(operator akan ditaro dikiri dengan 2 operan mengikuti di belakangnya)
-Infix: left, root, right
-Postfix: left, right, root(operator akan ditaro dikanan dengan 2 operan mengikuti di depannya)
*/

/*
Tree Traversal:
-Depth First: Pre-order, in-order, post-order(konsepnya sama kaya prefix, infix, postfix) kaya pake panah
-Breadth First: Per level
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

int main(){
	//Level 0
	root = newNode('+');
	//Level 1
	root->left = newNode('*');
	root->right = newNode('-');
	//Level 2
	root->left->left = newNode('-');
	root->left->right = newNode('+');
	root->right->left = newNode('A');
	root->right->right = newNode('*');
	//Level 3
	root->left->left->left = newNode('*');
	root->left->left->right = newNode('7');
	root->left->right->left = newNode('2');
	root->left->right->right = newNode('7');
	root->right->right->left = newNode('+');
	root->right->right->right = newNode('B');
	//Level 4
	root->left->left->left->left = newNode('5');
	root->left->left->left->right = newNode('+');
	root->right->right->left->left = newNode('6');
	root->right->right->left->right = newNode('8');
	//Level 5
	root->left->left->left->right->left = newNode('2');
	root->left->left->left->right->right = newNode('2');
	
	infix(root);
	printf("\n");
	prefix(root);
	printf("\n");
	postfix(root);
	printf("\n");
	
	return 0;
}
