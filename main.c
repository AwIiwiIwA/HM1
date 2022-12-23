#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdint.h>
#include "avl.h"
#include "insert.h"


void swap(int *a, int *b) // function to swap elements
{
    int t = *a;
    *a = *b;
    *b = t;
}


int partition(int array[], int low, int high) // function to find the partition position
{
    int pivot = array[high];
    int i = (low - 1);
    
    for (int j = low; j < high; j++) 
    {
        if (array[j] <= pivot) 
        {
            i++; 
            swap(&array[i], &array[j]); // swap element at i with element at j
        }
    }

    
    swap(&array[i + 1], &array[high]); // swap the pivot element with the greater element at i
    return (i + 1);
}

int getArrayIntervalSize(int low, int high)
{
    return high - low + 1;
}

void quickInsertionSort(int array[], int low, int high, int threshold) 
{
    if (low < high)
    {
        // find the pivot element such that
        // elements smaller than pivot are on left of pivot
        // elements greater than pivot are on right of pivot
        int pi = partition(array, low, high);

        if (getArrayIntervalSize(low, pi - 1) < threshold)
        {
            insertionSort(array, low, pi - 1);
        }
        else 
        {
            quickInsertionSort(array, low, pi - 1, threshold);  // recursive call on the left of pivot
        }

        if (getArrayIntervalSize(pi + 1, high) < threshold)
        {
            insertionSort(array, pi + 1, high);
        }
        else 
        {
            quickInsertionSort(array, pi + 1, high, threshold); // recursive call on the right of pivot
        }
    }
}

void printArray(int array[], int size)
{
    for (int i = 0; i < size; ++i) 
    {
        printf("%d  ", array[i]);
    }
    printf("\n");
}


void task_1(int array[], int n)
{
    printf("Task 1 Begin: \n");
    if (n > 1)
    {
        quickInsertionSort(array, 0, n - 1, 10);
    }
    printArray(array, n);
    printf("Task 1 End \n\n");
}

void task_2()
{
    printf("Task 2 Begin: \n");

    srand((unsigned int)time(NULL));   // Initialization, should only be called once.

    int n;
    int k;

    printf("Input first number, please:");
    scanf_s("%d", &n);

    printf("Input second number, please:");
    scanf_s("%d", &k);

    printf("First number is: %d\n", n);
    printf("Second number is: %d\n", k);


    struct Node *root = NULL;

    for (int i = 0; i < n; i++) 
    { 
        srand((unsigned int)time(NULL));
        int r = rand();
        root = insertNode(root, r);
    }
    
    for (int i = 0; i < k; i++)         //k*log(n)
    { 
        srand((unsigned int)time(NULL));
        int r = rand();

        uint32_t randomNumber = r;

        printf("\nElement: %d\n", randomNumber);

        struct Node* found = searchNode(root, randomNumber);

        if(found != NULL) 
        {
            printf("Found element in source array: %d\n", found->key);
        }
    }

    printf("Task 2 End \n\n");

}


int main() {


    int arr[] = {40, 50, 30, 40, 50, 30, 30, 114, 52, 55, 234, 552, 234, 5263, 2524, 24, 24, 42, 2, 24, 4, 56, 47, 3235,
                 6262, 73, 42, 63, 74, 38, 3, 4347, 23, 234, 6235, 344, 747374, 37, 3, 34, 44, 4, 4, 4, 436, 7, 83, 5,
                 6, 4, 34, 3, 346, 7, 455, 6, 6, 556, 564, 6, 4, 435, 34, 435, 4545, 45, 4, 545, 45, 45, 6, 475, 74, 47,
                 47, 47, 8, 7, 6262, 6, 2626, 33, 555, 3, 633, 53, 355, 7, 788};

    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Size of array %d\n", n);

    //Task 1
    task_1(arr, n);

    //Task 2
    task_2(); 
}