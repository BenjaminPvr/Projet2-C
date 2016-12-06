#ifndef INSTANCE_H_INCLUDED
#define INSTANCE_H_INCLUDED

typedef struct _Instance
{
    int M;
    int N;

    int *valueP;
    int **dimR;
    int *maxDimB;
}Instance;

void initInstance(Instance *instance);
void readFromFile(FILE *file);

#endif // INSTANCE_H_INCLUDED
