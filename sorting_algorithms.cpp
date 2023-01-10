#include <iostream>
using namespace std;

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int start, int end)
{
    int pivot = arr[end];
    int i = (start - 1);

    for (int j = start; j <= end - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[end]);
    return (i + 1);
}


void quickSort(int arr[], int start, int end)
{
    if (start < end) {
        int pivot_index = partition(arr, start, end);

        quickSort(arr, start, pivot_index - 1);
        quickSort(arr, pivot_index + 1, end);
    }
}


void insertionSort(int arr[], int size)
{
    int i, key, j;
    for (i = 1; i < size; i++)
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


int main()
{
    int arr[5] = { 15, 9, 12, 3, 2 };
    int arr_cpy[5] = { 15, 9, 12, 3, 2 };


    insertionSort(arr, 5);

    for (int i = 0; i < 5; i++)
        cout << arr[i] << " ";
    cout << endl;


    for (int i = 0; i < 5; i++)
        arr[i] = arr_cpy[i];
    cout << endl;


    quickSort(arr, 0, 4);


    for (int i = 0; i < 5; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
