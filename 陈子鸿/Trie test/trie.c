#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct node {
	int word;
	struct node* left;
	struct node* right;
};
typedef struct node trie;
typedef struct node* triePtr;
int top = -1;
triePtr stack[1000];

int createTree(triePtr *root) {
	int val;
	scanf("%d", &val);
	if (val <= 0) {
		*root = NULL;
		return 0;
	}
	else {
		*root = (triePtr)malloc(sizeof(trie));
		if (*root) {
			(*root)->word = val;
			printf("请输入%d左孩子：", val);
			createTree(&((*root)->left));
			printf("请输入%d右孩子：", val);
			createTree(&((*root)->right));
		}
	}
	return 0;
}
void preOrder(triePtr root) {
	if (root == NULL)
		return;
	printf("%d ", root->word);
	preOrder(root->left);
	preOrder(root->right);
}
void inOrder(triePtr root) {
	if (root == NULL)
		return;
	inOrder(root->left);
	printf("%d ", root->word);
	inOrder(root->right);
}
void postOrder(triePtr root) {
	if (root == NULL)
		return;
	postOrder(root->left);
	postOrder(root->right);
	printf("%d ", root->word);
}

void push(triePtr s[], triePtr t) {
	s[++top] = t;
}
triePtr pop(triePtr s[]) {
	if (top == -1)
		exit(1);
	return s[top--];
}
void preOrderTravel(triePtr root) {
	triePtr T = root;
	while (T || !(top == -1)) {
		while (T) {
			printf("%d ", T->word);
			push(stack, T);
			T = T->left;
		}
		if (!(top == -1)) {
			T = pop(stack);
			T = T->right;
		}
	}
}
void inOrderTravel(triePtr root) {
	triePtr T = root;
	while (T || !(top == -1)) {
		while (T) {
			push(stack, T);
			T = T->left;
		}
		if (!(top == -1)) {
			T = pop(stack);
			printf("%d ", T->word);
			T = T->right;
		}
	}
}
void postOrderTravel(triePtr root) {//后序遍历二叉树 
	triePtr T = root;
	triePtr pre = NULL;
	while (T || !(top == -1)) {
		while (T) {
			push(stack, T);
			T = T->left;
		}
		if (!(top == -1)) {
			T = pop(stack);
			if (T->right == NULL || T->right == pre) {
				printf("%d ", T->word);
				pre = T;	//pre代表已经遍历过的节点
				T = NULL; //当前结点子节点必定已经遍历完，因此要返回上级结点
			}
			else {
				push(stack, T);
				T = T->right;
			}
		}
	}
}
int main() {
	triePtr tree;
	tree = (triePtr)malloc(sizeof(trie));
	createTree(&tree);
	preOrder(tree);
	puts("");
	preOrderTravel(tree);
	puts("");
	inOrder(tree);
	puts("");
	inOrderTravel(tree);
	puts("");
	postOrder(tree);
	puts(""); 
	postOrderTravel(tree);
	puts("");
	return 0;
}