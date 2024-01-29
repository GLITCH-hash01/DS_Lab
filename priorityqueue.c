#include <stdio.h>

#define MAX_SIZE 100

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to perform heapify operation
void heapify(int arr[], int n, int i) {
    int largest = i;  // Initialize largest as root
    int left = 2 * i + 1;  // Left child
    int right = 2 * i + 2;  // Right child

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // If right child is larger than largest so far
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If largest is not root
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

// Function to insert an element into the priority queue
void insert(int arr[], int *n, int item) {
    if (*n == MAX_SIZE) {
        printf("Priority queue is full.\n");
        return;
    }

    // Insert the new element at the end
    int i = *n;
    arr[i] = item;
    (*n)++;

    // Fix the heap property if violated
    while (i != 0 && arr[(i - 1) / 2] < arr[i]) {
        swap(&arr[i], &arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Function to remove the element with highest priority from the priority queue
int removeHighestPriority(int arr[], int *n) {
    if (*n == 0) {
        printf("Priority queue is empty.\n");
        return -1;
    }

    // Store the root element (highest priority)
    int root = arr[0];

    // Replace the root with the last element
    arr[0] = arr[(*n) - 1];
    (*n)--;

    // Fix the heap property if violated
    heapify(arr, *n, 0);

    return root;
}

int main() {
    int arr[MAX_SIZE];
    int n = 0;  // Current size of the priority queue

    int choice, item;

    while (1) {
        printf("Priority Queue Operations:\n");
        printf("1. Insert\n");
        printf("2. Remove Highest Priority\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d", &item);
                insert(arr, &n, item);
                break;
            case 2:
                item = removeHighestPriority(arr, &n);
                if (item != -1)
                    printf("Removed element with highest priority: %d\n", item);
                break;
            case 3:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
