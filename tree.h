#ifndef TREE_H_
#define TREE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct TreeItem{
	char* word;
	int count;
	struct TreeItem *left, *right;
};

typedef struct TreeItem treeItem;

treeItem *addItem(treeItem *root, char *word);

treeItem *findItem(treeItem *root, char *word);

int countWords(treeItem *root);

int countTotalWords(treeItem *root);


void deleteTree(treeItem *root);

#endif/* TREE_H_ */
