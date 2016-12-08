#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Instance.h"


char * readLine(FILE * file);
int * intTabFromFile(FILE * file, int numberOfInt);
void readInstanceFromFile(FILE *file);

#endif // PARSER_H_INCLUDED
