#include<stdio.h>
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void insert(int arr[], int *n, int item, int max_size) {
    if (*n == max_size) {
        printf("Priority queue is full.\n");
        return;
    }

    int i = *n;
    arr[i] = item;
    (*n)++;

    while (i != 0 && arr[(i - 1) / 2] < arr[i]) {
        swap(&arr[i], &arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

int removeHighestPriority(int arr[], int *n, int max_size) {
    if (*n == 0) {
        printf("Priority queue is empty.\n");
        return -1;
    }

    int root = arr[0];

    arr[0] = arr[(*n) - 1];
    (*n)--;

    heapify(arr, *n, 0);

    return root;
}

int main() {
    int max_size = 100;
    int arr[max_size];
    int n = 0;

    int choice, item;
    int i=1;
    while (i==1) {
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
                insert(arr, &n, item, max_size);
                break;
            case 2:
                item = removeHighestPriority(arr, &n, max_size);
                if (item != -1)
                    printf("Removed element with highest priority: %d\n", item);
                break;
            case 3:
                printf("Exiting...\n");
                i=0;
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }

    return 0;
}
