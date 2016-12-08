#include "Error.h"

void fatalError(const char *message)
{
    printf("\n%s",message);
    exit(-1);
}

