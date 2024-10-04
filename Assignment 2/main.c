// CODE: include necessary library(s)

// Utility functions
void printArray(int arr[], int n);


// Test the sorting algorithms
int main() {
    int arr[] = {64, -134, -5, 0, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    int testArr[n];
    
    // Bubble Sort
    memcpy(testArr, arr, n * sizeof(int));
    printf("Original array: ");
    printArray(testArr, n);
    bubbleSort(testArr, n);
    printf("Bubble sorted array: ");
    printArray(testArr, n);

    // CODE: do the same test cases for Insertion Sort, Merge Sort, Heap Sort, Counting Sort
    // You will submit main.c, and your project will be marked based on main.c as well
    
    return 0;
}

// Helper functions
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

