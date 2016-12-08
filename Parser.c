#include "Parser.h"

/**
 *@brief cette fonction lit une instance depuis le fichier.
 *@param file fichier dans lequel l'instance doit être lu.
 *@return return the instance.
 */

void readInstanceFromFile(FILE *file)
{
    int N=0;
    int M=0;
    Instance *instance=NULL;


}


/** Reads a line of text from a file until the '\n' character or the End Of File
 * @param file Text file containing the text to read
 * @return The read line into a char* allocated on the heap
 */
char * readLine(FILE * file)
{
    char buffer[1024] = " ";
    char * tempRead;
    char * read = (char*) malloc (1*sizeof(char));
    if (read == NULL)
        exit(-1);
    *read = '\0';


    while (buffer[strlen(buffer) - 1] != '\n')
    {
        /*if its the end of file, returns read*/
        if (fgets(buffer, 1024, file) == NULL)
            return read;

        tempRead = realloc(read, strlen(read) + strlen(buffer) + 1);
        if (tempRead == NULL)
            exit(-1);
        read = tempRead;

        /*concatenates read and the buffer*/
        strcat(read, buffer);
    }
    return read;
}



/** Converts a text line of integers data into an int array allocated on the heap
 * @param file Text file containing the text to read
 * @param numberOfInt Specifies the number of integers to read on the line
 * @return An integer array allocated on the heap
 */
int * intTabFromFile(FILE * file, int numberOfInt)
{
    char * string = readLine(file);
    char * strCursor = string;      /*cursor to read the string*/
    char * strEndNbrCursor;         /*char* for strtol*/
    int counter = 0;                /*counter to check if it has all the required numbers*/
    int * tab = (int*) malloc (numberOfInt * sizeof(int));
    if (tab == NULL)
        exit(-1);

    /*while it detects carriage returns, reads another line*/
    while (*string == '\n')
    {
        free(string);
        string = readLine(file);
        strCursor = string;
    }
    /*while it's not the end of the line or the end of the char* */
    while (*strCursor != '\n' && *strCursor != '\0')
    {
        /*increments the cursor while it does not detects a digit*/
        while (*strCursor < '0' && *strCursor > '9' && *strCursor != '\n' && *strCursor != '\0')
            strCursor++;

        /*if it reached the end of the char* */
        if (*strCursor == '\n' || *strCursor == '\0')
        {
            if (counter != numberOfInt - 1)
                exit(-1);
            else
                return tab;
        }

        /*converts from string to int*/
        tab[counter] = (int) strtol (strCursor, &strEndNbrCursor, 10);
        /*if strEndNbrCursor == strCursor, it means there is an error in strtol*/
        if (strEndNbrCursor == strCursor)
            exit(-1);
        else
            strCursor = strEndNbrCursor;

        counter++;
    }
    /*if it does not get the right number or integers, error*/
    if (counter != numberOfInt)
    {
        printf("Error - wrong numberOfInt");
        exit(-1);
    }
    return tab;
}
