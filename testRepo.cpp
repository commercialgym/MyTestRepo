/*
* FILE : trying to create a merge conflict
* FILE : changing this line from the branch
* PROJECT : SENG1000 - Focus assignment #7
* PROGRAMMER : Alexia Tu
* FIRST VERSION : 03-21-2024
* DESCRIPTION :
    * Making changes to this project in the branch before merging it into the main branch. Adding even more changes because 
    * I think i did this in the wrong order. When I went to do the pull request the main and the branch were identical, I think
    * that means I have to make changes here again.
*/

#include <stdio.h>
#include <string.h>
#pragma warning(disable: 4996)

const int kNumOfElements = 11;
const unsigned short kBinaryData[kNumOfElements] = { 26946, 24942, 31090, 25632, 29793, 8289, 28518, 8306, 28537, 33141, 39308 };

int main(void)
{
    FILE* pMyTextFile = NULL;
    //check for error with fopen(), simultaneously assigning to pointer
    if ((pMyTextFile = fopen("myTextFile.txt", "w")) == NULL)
    {
        printf("Cannot open to write to myTextFile.txt\n");
        return 0;
    }
    //add first output to text file and check for error, return 0 means success, negative # means failure
    //maybe change to else statement
    if (fprintf(pMyTextFile, "This is line 1\nThis is line 2\n") < 0)
    {
        printf("Can't write line to myTextFile.txt\n");
        return 0;
    }
    //done with this file
    if (fclose(pMyTextFile) != 0)
    {
        printf("Error closing myTextFile.txt\n");
        return 0;
    }

    //now handle binary file, also do i need to declare this pointer as NULL first??
    FILE* pMyEvenDataList = NULL;
    if ((pMyEvenDataList = fopen("myEvenDataList.data", "wb")) == NULL)
    {
        printf("Cannot open to write to myEvenDataList.data");
        return 0;
    }

    //used to text if element to be written to file is an even number
    const unsigned short kEvenNumber = 2;
    //number of elements to append to the file
    const size_t kNumElementsToWrite = 1;

    //write to binary file, only using even numbers from const array
    for (size_t binaryIndex = 0; binaryIndex < kNumOfElements; binaryIndex++)
    {
        if (kBinaryData[binaryIndex] % kEvenNumber == 0)
        {
            //check for error when writing to binary file
            if (fwrite(&kBinaryData[binaryIndex], sizeof(unsigned short), kNumElementsToWrite, pMyEvenDataList) != kNumElementsToWrite)
            {
                printf("Error writing to myEvenDataList.data\n");
                return 0;
            }
        }
    }

    if (fclose(pMyEvenDataList) != 0)
    {
        printf("Error closing myEvenDataList.data\n");
        return 0;
    }


    return 0;
}