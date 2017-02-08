#ifndef INPUT_OUTPUT_H_
#define INPUT_OUTPUT_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"tree.h"

treeItem *readFile(char *fileName, treeItem *root);

void outputToFile(treeItem *root, FILE *outputFile);

void printTreeToFile(treeItem *root, FILE *outputFile);

#endif/* INPUT_OUTPUT_H_ */
