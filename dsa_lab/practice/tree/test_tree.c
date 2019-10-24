#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "levelorder.h"
#include "tree_iter.h"

int main() {
	nodeptr root = getNode(0);
	createBT(&root);
	inorderR(root);
	printf("InOrder \n");
	preorderR(root);
	printf("PreOrder \n");
	postorderR(root);
	printf("PostOrder\n");
	initQ();
	levelorderR(root);
	printf("LevelOrder\n");
	printf("\n-----Iterative Calls-----");
	initStack();
	printf("\n");
	inorderI(root);
	printf("InOrder \n");
	preorderI(root);
	printf("PreOrder \n");
	postorderI(root);
	printf("PostOrder \n");
}
