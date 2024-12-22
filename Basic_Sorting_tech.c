#include <stdio.h>

// Function to perform insertion sort Timme complexity: O(n^2)
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];                           //Selecting a Key first then comparing it to others
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];                    //swapping if all conditions are met
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Function to perform selection sort  Timme complexity: O(n^2)
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;                                    //Assumiing one index as mnimum then comparing to to the rest of the array 
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        int temp = arr[min_idx];                                   
        arr[min_idx] = arr[i];                              //swap value with min index and repeat
        arr[i] = temp;
    }
}

// Function to perform bubble sort  Timme complexity: O(n^2)
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {                      //Compare adjacent elements and swapif it satiesfes condition
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, n);

    int arr1[] = {64, 25, 12, 22, 11};
    insertionSort(arr1, n);
    printf("Sorted array with insertion sort: ");
    printArray(arr1, n);

    int arr2[] = {64, 25, 12, 22, 11};
    selectionSort(arr2, n);
    printf("Sorted array with selection sort: ");
    printArray(arr2, n);

    int arr3[] = {64, 25, 12, 22, 11};
    bubbleSort(arr3, n);
    printf("Sorted array with bubble sort: ");
    printArray(arr3, n);

    return 0;
}
