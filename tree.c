//Matthew Puentes Andrew Levy
#include"tree.h"

treeItem *addItem(treeItem *root, char *word) {
	if (root == NULL) {
		root = malloc(sizeof(treeItem));
		char *c = malloc(strlen(word) + 1);
		root->word = strcpy(c, word);
		root->count = 1;
		root->left = root->right = NULL;
		return root;
	}

	int c = strcmp(word, root->word);
	if (c == 0)
		root->count++;
	else if (c < 0)
		root->left = addItem(root->left, word);
	else
		root->right = addItem(root->right, word);
	return root;
}

treeItem *findItem(treeItem *root, char *word) {
	if (root == NULL)
		return NULL;

	int c = strcmp(word, root->word);
	if (c == 0)
		return root;
	else if (c < 0)
		return findItem(root->left, word);
	else
		return findItem(root->right, word);
}

int countWords(treeItem *root) {
	if (root != NULL) {
		return 1 + countWords(root->left) + countWords(root->right);
	}
	return 0;
}

int countTotalWords(treeItem *root) {
	if (root != NULL) {
		return root->count + countTotalWords(root->left)
				+ countTotalWords(root->right);
	}
	return 0;
}

void deleteTree(treeItem *root) {
	if (root != NULL) {
		deleteTree(root->left);
		deleteTree(root->right);
		free(root);
	}
}
