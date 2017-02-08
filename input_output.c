//Matthew Puentes Andrew Levy
#include "input_output.h"

int isPunct(char c) {
	char* punct = "!@#$%^&*(){}[]|\\:\";<>?,./_=+";
	for (int i = 0; i < strlen(punct); i++) {
		if (c == punct[i]) {
			return 1;
		}
	}
	return 0;
}

int isSpace(char c) {
	char *spaces = " \t\n\v\f\r\0";
	for (int i = 0; i < strlen(spaces); i++) {
		if (c == spaces[i]) {
			return 1;
		}
	}
	return 0;
}

int isValidChar(char c) {
	char *invalid = "!@#$%^&*(){}|\\:\";\'<>?,./_=+- \t\n\v\f\r\0";
	for (int i = 0; i < strlen(invalid); i++) {
		if (c == invalid[i]) {
			return 0;
		}
	}
	return 1;
}

char toLower(char c) {
	char *upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char *lower = "abcdefghijklmnopqrstuvwxyz";
	for (int i = 0; i < strlen(upper); i++) {
		if (c == upper[i]) {
			return lower[i];
		}
	}
	return c;
}

char *readWord(FILE *inputFile) {
	int reading = 1;
	char* word = "";
	while (reading) {
		char c = getc(inputFile);
		if (isSpace(c))
			reading = 0;
		else if (isPunct(c)) {
			//Ignore it
		} else {
			c = toLower(c);
			char* newWord = malloc(strlen(word) + 2);
			newWord = strcpy(newWord, word);
			newWord[strlen(word)] = c;
			word = newWord;
			if (c == -1) {
				reading = 0;
				break;
			}
		}
	}

	return word;
}

int isValidWord(char *word) {
	if(strlen(word) <= 0){
		return 0;
	}
	for (int i = 0; i < strlen(word); i++) {
		if (isValidChar(word[i])) {
			return 1;
		}
	}
	return 0;
}

char *trimWord(char *word){
	int checking = 1;

	while(checking){
		if(isValidChar(word[0])){
			checking = 0;
			break;
		}
		else{
			for(int j = 0; j < strlen(word)-1; j++){
				word[j] = word[j+1];
				printf("%d\n",word[j+1]);
			}
			word[strlen(word)-1] = '\0';
		}
	}

	for(int i = strlen(word)-1; i >=0; i--){
		if(isValidChar(word[i]))
			break;
		else{
			word[i] = '\0';
		}
	}
	return word;
}

treeItem* readFile(char *fileName, treeItem *root) {
	FILE *inputFile = fopen(fileName, "r");
	if (inputFile == 0) {
		printf("could not open file");
		exit(0);
	}
	while (1) {
		char* word;
		word = readWord(inputFile);
		if (isValidWord(word)) {
			trimWord(word);
			if (word[strlen(word) - 1] == -1) {
				word[strlen(word) - 1] = '\0';
				if(strlen(word)>0)
					root = addItem(root, word);
				break;
			} else {
				root = addItem(root, word);
			}

		}
	}
	fclose(inputFile);
	return root;
}

void outputToFile(treeItem *root, FILE *outputFile){
	printTreeToFile(root, outputFile);
	fprintf(outputFile, "-----------------------\n");
	fprintf(outputFile, "words in file(s): %d\n",countWords(root));
	fprintf(outputFile, "words in file(s) including duplicates: %d\n",countTotalWords(root));
}

void printTreeToFile(treeItem *root, FILE *outputFile){
	if(root != NULL){
		printTreeToFile(root->left, outputFile);
		//printf("\t%d\t%s\n",root->count,root->word);
		fprintf(outputFile, "\t%d\t%s\n",root->count,root->word);
		printTreeToFile(root->right, outputFile);
	}
}
