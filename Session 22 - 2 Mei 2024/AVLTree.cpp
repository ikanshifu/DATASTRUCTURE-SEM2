#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Session 22 - 2 Mei 2024
//AVL Tree

/*Konsep: 
-AVL tree dinamain dari 2 penemunya G.M. Adelson-Veleskii dan E.M. Landis(hence the name AVL)
-Mudahnnya, AVL itu self-balancing tree yang dimana setiap node ada nyimpen informasi yang namanya balance factor(bisa 0, 1 atau -1)
-Height/Tinggi dari sebuah node ditentukan dari jumlah nodenya.
-Tinggi 1 leaf adalah 1 
-Height: tinggi maximum dari anak-anaknya(cari tinggi anak paling besar) trus + 1
-Balance factor: perbedaan tinggi antara left subtree dan right subtree maximum 1, height anak kiri-height anak kanan
*/


//Operations:
/*
a.Insert: sifatnya sama kaya BST, tapi setelah insert nanti posisinya di rearrange
	Rebalancing: Find the deepest node
	Ada 4 case:
	Single Rotation:
	1.LL(right rotation): root akan jadi right child dari yang sebelum left childnya. Right child dari root baru(yang tadinya left child) akan pindah jadi left child  root baru
	2.RR(left rotation): root akan jadi left child dari yang sebelum right childnya. Left child dari root baru(yang tadinya right child) akan pindah jadi right child root lama
	Double Rotation
	3.RL: Lakukan LL(right rot) di anaknya, abis itu left rot
	4.LR: Lakukan RR(left rot) di anaknya,  abis itu right rot 
b.Delete: sama kaya BST tapi abis itu rebalancing
*/

struct Data{
	char key;
	int height;
	struct Data *left, *right;
}*root = NULL,*temp;

struct Data *newNode(int key){
	struct Data *node = (struct Data*)malloc(sizeof(struct Data));
	node->key = key;
	node->height = 1;
	node->left = node->right = NULL;
	
	return node;
}

void inOrder(struct Data *node){
	if(node){
		inOrder(node->left);
		printf("%c(%d) ", node->key, node->height);
		inOrder(node->right);	
	}
}
int max(int a,int b){
	if(a>b) return a;
	else return b;
}

int height(struct Data *node){
	if(!node) return 0;
	else return node->height;
}

int getBalance(struct Data *node){
	if(!node)return 0;
	else return height(node->left) - height(node->right);
}

struct Data *rightRotation(struct Data *T){
	struct Data *S = T->left;
	struct Data *B = S->right;
	
	S->right = T;
	T->left = B;
	
	T->height = 1 + max(height(T->left),height(T->right));
	S->height = 1 + max(height(S->left),height(S->right));
	return S;
	
}

struct Data *leftRotation(struct Data *T){
	struct Data *S = T->right;
	struct Data *B = S->left;
	
	S->left = T;
	T->right = B;
	
	T->height = 1 + max(height(T->left),height(T->right));
	S->height = 1 + max(height(S->left),height(S->right));
	
	return S;
}

struct Data *rebalance(struct Data *node){
	int balance = getBalance(node);
	
	if(balance>1&&getBalance(node->left)>=0){//LL
		return rightRotation(node);
	}else if(balance<-1&&getBalance(node->right)<=0){//RR
		return leftRotation(node);
	}else if(balance>1&&getBalance(node->left)<0){//LR
		node->left = leftRotation(node->left);
		return rightRotation(node);
	}else if(balance<-1 && getBalance(node->right)>0){//RL
		node->right = rightRotation(node->left);
		return leftRotation(node);
	}
}

struct Data *insert(struct Data *node, char key){
	if(!node) return newNode(key);
	else if(key<node->key)node->left = insert(node->left,key);
	else if(key>node->key)node->right = insert(node->right,key);
	else return node;
	
	node->height = 1 + max(height(node->left), height(node->right));
	return rebalance(node);
}

struct Data *del(struct Data *node, char key){
	if(!node) printf("Key not found!\n");
	else if(key<node->key)node->left = del(node->left,key);
	else if(key>node->key)node->right = del(node->right,key);
	else{
		if(!node->left){
			temp = node;
			node = node->right;
			free(temp);
			return node;
		}else if(!node->right){
			temp = node;
			node = node ->left;
			free(temp);
			return node;
		}else{
			temp = node->left;
			while(temp->right){
				temp = temp->right;
			}
			node->key = temp->key;
			node->left = del(node->left, temp->key);	
		}
	}
	node->height = 1 + max(height(node->left), height(node->right));
	return rebalance(node);
}

int main(){
	root = insert(root, 'S');
	root = insert(root, 'O');
	root = insert(root, 'F');
	root = insert(root, 'T');
	root = insert(root, 'W');
	root = insert(root, 'A');
	root = insert(root, 'R');
	root = insert(root, 'E');
	inOrder(root);
	return 0;
}
