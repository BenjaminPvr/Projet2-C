#include "instance.h"
#include "Error.h"

/**
 *@brief Cette fonction initialise une instance de manière à ce qu'elle soit prête à être utilisée.
 *@param  instance l'instance à initialisée.
 *@warning Cette fonction doit être utilisée avant d'utiliser une instance .
 */

void initInstance(Instance *instance,const int N,const int M)
{
    instance->N=N;
    instance->M=M;

    instance->valueP=(double *)malloc(N*sizeof(double));
    if(instance->valueP==NULL)
        fatalError("Error : Allocation failed !");

    instance->dimR=(double **)malloc(M*sizeof(double));
    if(instance->dimR==NULL)
        fatalError("Error : Allocation failed !");

    instance->maxDimB=(double *)malloc(M*sizeof(double));
    if(instance->maxDimB==NULL)
        fatalError("Error : Allocation failed !");
}



