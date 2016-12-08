#ifndef INSTANCE_H_INCLUDED
#define INSTANCE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef struct _Instance
{
    int M;
    int N;
    int number;

    int *valueP;
    int **dimR;
    int *maxDimB;

    const char *name;


}Instance;

void initInstance(Instance *instance,const int M,const int N);

#endif // INSTANCE_H_INCLUDED
