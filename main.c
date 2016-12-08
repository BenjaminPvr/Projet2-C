#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#include "Parser.h"
#include "Error.h"

#define NB_INSTANCE 30


static void openFile(FILE *file,const char *fileName);
static void writeExit(FILE *file,Instance *instance,const double duration);


int main(int argc, char *argv[])
{
    const char * fileName = NULL;
    int numCodage = 0;
    int numMethod = 0;

    FILE *instanceFile = NULL;
    FILE *exitFile=NULL;


    time_t timerBegin=0;
    time_t timerEnd=0;
    /*
    fileName = argv[1];
    numCodage = atoi(argv[2]);
    numMethod = atoi(argv[3]);
    */

    fileName="fichier.txt";
    numCodage=1;
    numMethod=2;

    printf("File name :%s\n",fileName);
    printf("Codage Number :%d\n",numCodage);
    printf("Method Number :%d\n",numMethod);

    openFile(instanceFile,fileName);

    int i;
    for(i=0;i<NB_INSTANCE;++i)
    {
      Instance *instance=NULL;
      timerBegin=time(NULL);
      Sleep(2000); /* Ici sera readInstance */
      timerEnd=time(NULL);
      printf("%f\n",difftime(timerEnd,timerBegin));
      writeExit(exitFile,instance,difftime(timerEnd,timerBegin));
    }

    fclose(instanceFile);
    fclose(exitFile);

    return 0;
}


void openFile(FILE *file,const char *fileName)
{
    file=fopen(fileName,"a+");
    if(file==NULL)
        fatalError("Error Cannot open this file !");
}

void writeExit(FILE *file,Instance *instance,const double duration)
{

    file=fopen("sortie.txt","a");
    if(file==NULL)
        fatalError("Error : Cannot open this file !");

    fputs(instance->name,file);
    /*fputs(instance->number);*/
    fclose(file);

}
