#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#define arraySize 15
#define countArraySize 30

void printArray(int* array, int arrayLength)
{
    for (int i = 0; i < arrayLength; ++i)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int sortedMassive(int* array, int arrayLength)
{
    qsort(array, 0, arrayLength - 1);
    int mostFrequentNumber = array[0];
    int counter = 1;
    int maxCounter = 1;
    for (int i = 0; i < arrayLength - 1; ++i)
    {
        if (array[i] == array[i + 1])
        {
            ++counter;
            if (counter > maxCounter)
            {
                mostFrequentNumber = array[i];
                maxCounter = counter;
            }
        }
        else
        {
            counter = 1;
        }
    }

    return mostFrequentNumber;
}

bool test()
{
    int array[15] = { 7, 1, 23, 42, 14, 6, 3, 13, 19, 11, 8, 28, 15, 11, 16 };
    qsort(array, 0, 14);
    if (sortedMassive(array, 15) == 10)
    {
        return true;
    }
    return false;
}

void main()
{
    if (test())
    {
        printf("TEST PASSED!\n");
    }
    else
    {
        printf("TEST FAILED!\n");
        return;
    }
    int array[arraySize] = { 0 };

    srand(time(0));
    for (int i = 0; i < arraySize; ++i)
    {
        array[i] = rand() % countArraySize;
    }
    printf("Your array: ");
    printArray(array, arraySize);

    printf("The most frequent number in the array is %d", sortedMassive(array, arraySize));
}
