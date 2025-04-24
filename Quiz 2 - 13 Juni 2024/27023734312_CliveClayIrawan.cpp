#include<stdio.h>
#include<stdlib.h>

struct Data{
	int key;
	int height;
	struct Data *left, *right;
}*root = NULL, *curr;

//Quiz 2 - 13 Juni 2024
//2702373412-Clive Clay Irawan

struct Data *newNode(int key){
	struct Data *node = (struct Data*) malloc(sizeof(struct Data));
	node->key = key;
	node->height = 1;
	node->left = node->right = NULL;
	
	return node;
}

int max(int a, int b){
	if(a>b) return a;
	else return b;
}

int height(struct Data *node){
	if(!node) return 0;
	else return node->height;
}

int getBalance(struct Data *node){
	if(!node) return 0;
	else return height(node->left) - height(node->right);
}

struct Data *rightRotation(struct Data *T){
	struct Data *S = T->left;
	struct Data *B = S->right;
	
	S->right = T;
	T->left = B;
	
	T->height = 1 + max(height(T->left), height(T->right));
	S->height = 1 + max(height(S->left), height(S->right));
	
	return S;
}

struct Data *leftRotation(struct Data *T){
	struct Data *S = T->right;
	struct Data *B = S->left;
	
	S->left = T;
	T->right = B;
	
	T->height = 1 + max(height(T->left), height(T->right));
	S->height = 1 + max(height(S->left), height(S->right));
	
	return S;
}

struct Data *rebalance(struct Data *node){
	int balance = getBalance(node);
	
	if(balance > 1 && getBalance(node->left) >= 0){
		return rightRotation(node);
	}else if(balance < -1 && getBalance(node->right) <= 0){
		return leftRotation(node);
	}else if(balance >1 && getBalance(node->left) < 0){
		node->left = leftRotation(node->left);
		return rightRotation(node);
	}else if(balance < -1 && getBalance(node->right) > 0){
		node->right = rightRotation(node->right);
		return leftRotation(node);
	}
	
	return node;
}

void insert(struct Data *node, int key){
	struct Data *neNode = newNode(key);
	if(!node){
		return newNode(key);	
	} 
	else if(key < node->key) node->left = insert(node->left, key);
	else if(key > node->key) node->right = insert(node->right, key);
	else return node;
	
	node->height = 1 + max(height(node->left), height(node->right));
	return rebalance(node);
}

void deleteNode(struct Data *node, char key){
	if(key < node->key){
	node->left = deleteNode(node->left, key);	
	}
	else if(key > node->key) node->right = deleteNode(node->right, key);
	else{
		if(!node->left){
			curr = node;
			node = node->right;
			free(curr);
			return node;
		}else if (!node->right){
			curr = node;
			node = node->left;
			free(curr);
			return node;
		}else{
			curr = node->left;
			
			while(curr->right){
				curr = curr->right;
			}
			
			node->key = curr->key;
			node->left = deleteNode(node->left, curr->key);
		}
	}
	
	node->height = 1 + max(height(node->left), height(node->right));
	return rebalance(node);
}

int findPre(int keys){
	struct Data *curr = root;
	struct Data *parent = NULL;
	while(curr){
		if(keys==curr->key){
			break;
		}
		parent=curr;
		if(keys<curr->key){
			curr = curr->left;
		}else{
			curr = curr->right;
		}
	}
	if(curr!=NULL){
		struct Data *pre = curr->left;
		struct Data *preParent = curr;
		while(pre->right){
		preParent = pre;
		pre = pre->right;
	}
	return pre->key;
	}else{
		printf("-1\n");
	}
}

int main(){
	int N;
	scanf("%d", &N);
	int arr[N];
	for(int i = 0;i<N;i++){
		scanf("%d", &arr[i]);
		root = insert(root, arr[i]);
	}
	int Q;
	scanf("%d", &Q);
	int t[Q];
	char choice;
	for(int i = 0;i<Q;i++){
		scanf("%c %d",&choice,&t[i]);
		if(choice == 'I'){
			insert(root, t[i]);
		}else if(choice == 'D'){
			deleteNode(root, t[i]);
		}else if(choice == 'P'){
			int pre = findPre(t[i]);
			printf("%d\n",pre);
		}
	}
	return 0;
}
