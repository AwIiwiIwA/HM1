// Function to sort an array using insertion sort
void insertionSort(int arr[], int low, int high)
{
    if (low >= high) 
    {
        return;
    }

    int i, key, j;
    for (i = low + 1; i <= high; i++) 
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) 
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
