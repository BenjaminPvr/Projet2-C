#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    const char * nomFichier = NULL;
    int numCodage = 0;
    int numMethode = 0;

    nomFichier = argv[0];
    numCodage = atoi(argv[1]);
    numMethode = atoi(argv[2]);

    return 0;
}
