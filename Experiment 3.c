#include <stdio.h>
#include <stdlib.h>

void heapify(int arr[], int n, int i);
void heapSort(int arr[], int n);
void quickSort(int arr[], int low, int high);
int partition(int arr[], int low, int high);
int linearSearch(int arr[], int n, int key);
void displaySparseMatrix(int sparse[][3], int nonZeroCount);
void generateFibonacci(int n);
unsigned long long factorial(int n);

int main() {
    int choice;
    int n, i, key;

    do {
        printf("\nMenu:\n");
        printf("1. Heap Sort\n");
        printf("2. Quick Sort\n");
        printf("3. Linear Search\n");
        printf("4. Display Sparse Matrix\n");
        printf("5. Generate Fibonacci Numbers\n");
        printf("6. Calculate Factorial\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                printf("Enter number of elements: ");
                scanf("%d", &n);
                int arr[n];
                printf("Enter %d elements:\n", n);
                for (i = 0; i < n; i++) {
                    scanf("%d", &arr[i]);
                }
                heapSort(arr, n);
                printf("Array after Heap Sort: ");
                for (i = 0; i < n; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n");
                break;
            }
            case 2: {
                printf("Enter number of elements: ");
                scanf("%d", &n);
                int arr[n];
                printf("Enter %d elements:\n", n);
                for (i = 0; i < n; i++) {
                    scanf("%d", &arr[i]);
                }
                quickSort(arr, 0, n - 1);
                printf("Array after Quick Sort: ");
                for (i = 0; i < n; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n");
                break;
            }
            case 3: {
                printf("Enter number of elements: ");
                scanf("%d", &n);
                int arr[n];
                printf("Enter %d elements:\n", n);
                for (i = 0; i < n; i++) {
                    scanf("%d", &arr[i]);
                }
                printf("Enter element to search: ");
                scanf("%d", &key);
                int result = linearSearch(arr, n, key);
                if (result != -1) {
                    printf("Element found at index: %d\n", result);
                } else {
                    printf("Element not found.\n");
                }
                break;
            }
            case 4: {
                int sparse[10][3];
                int nonZeroCount = 0;
                printf("Enter number of non-zero elements: ");
                scanf("%d", &nonZeroCount);
                printf("Enter row, column, and value of each non-zero element:\n");
                for (i = 0; i < nonZeroCount; i++) {
                    scanf("%d %d %d", &sparse[i][0], &sparse[i][1], &sparse[i][2]);
                }
                displaySparseMatrix(sparse, nonZeroCount);
                break;
            }
            case 5: {
                int terms;
                printf("Enter number of terms for Fibonacci series: ");
                scanf("%d", &terms);
                generateFibonacci(terms);
                break;
            }
            case 6: {
                int num;
                printf("Enter a number to calculate factorial: ");
                scanf("%d", &num);
                printf("Factorial of %d is %llu\n", num, factorial(num));
                break;
            }
            case 7:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 7);

    return 0;
}

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }
    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
    for (int i = n - 1; i > 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0);
    }
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}

void displaySparseMatrix(int sparse[][3], int nonZeroCount) {
    printf("Row\tColumn\tValue\n");
    for (int i = 0; i < nonZeroCount; i++) {
        printf("%d\t%d\t%d\n", sparse[i][0], sparse[i][1], sparse[i][2]);
    }
}

void generateFibonacci(int n) {
    int a = 0, b = 1, next;
    printf("Fibonacci Series: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a);
        next = a + b;
        a = b;
        b = next;
    }
    printf("\n");
}

unsigned long long factorial(int n) {
    if (n == 0) return 1;
    return n * factorial(n - 1);
}

