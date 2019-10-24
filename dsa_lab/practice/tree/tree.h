#include <stdio.h>
#include <stdlib.h>

#pragma once

typedef struct node* nodeptr;
struct node {
	int data;
	nodeptr lst;
	nodeptr rst;
};

nodeptr getNode(int data) {
	nodeptr newnode = (nodeptr) malloc(sizeof(nodeptr));
	if (data != -1) {
		newnode->data = data;
		newnode->lst = NULL;
		newnode->rst = NULL;
	}
	else newnode = NULL;
	return newnode;
}

nodeptr createBT(nodeptr* root) {
	printf("Enter l1,r2: ");
	int newdata;
	int direction;
	scanf("%d", &direction);
	if (direction == 1) {
		printf("Enter data for left: ");
		scanf("%d", &newdata);
		nodeptr newnode = getNode(newdata);
		(*root)->lst = newnode;
		createBT(&newnode);
		printf("Enter data for right: ");
		scanf("%d", &newdata);
		newnode = getNode(newdata);
		(*root)->rst = newnode;
		createBT(&newnode);
	}
	else if (direction == 2) {
		printf("Enter data for right: ");
		scanf("%d", &newdata);
		nodeptr newnode = getNode(newdata);
		(*root)->rst = newnode;
		createBT(&newnode);
		printf("Enter data for left: ");
		scanf("%d", &newdata);
		newnode = getNode(newdata);
		(*root)->lst = newnode;
		createBT(&newnode);
	}
	else if (direction == -1) {
		return NULL;
	}
}

void inorderR(nodeptr root) {
	if (root==NULL) return;
	inorderR(root->lst);
	printf("%d ", root->data);
	inorderR(root->rst);
}

void postorderR(nodeptr root) {
	if (root==NULL) return;
	postorderR(root->lst);
	postorderR(root->rst);
	printf("%d ", root->data);
}

void preorderR(nodeptr root) {
	if (root==NULL) return;
	printf("%d ", root->data);
	preorderR(root->lst);
	preorderR(root->rst);
}

