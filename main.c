//Matthew Puentes Andrew Levy
#include"main.h"
int main(int argc, char *argv[]) {
	if (argc < 2) {
		printf("Please input at least 2 arguments");
	}
	treeItem *root = NULL;
	for (int i = 2; i < argc; i++) {
		root = readFile(argv[i], root);
	}
	FILE *output = fopen(argv[1], "w");
	outputToFile(root, output);
	fclose(output);
	deleteTree(root);
	return 0;
}
