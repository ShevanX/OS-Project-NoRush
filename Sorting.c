#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int capacity = 10;
    int n = 0;
    int *arr = malloc(capacity * sizeof(int));
    char line[4096];

    if (!arr) {
        printf("Error: Memory allocation failed.\n");
        return 1;
    }

    printf("Enter integers: ");
    if (!fgets(line, sizeof(line), stdin)) {
        printf("Error: Failed to read input.\n");
        free(arr);
        return 1;
    }

    char *ptr = line;
    char *endptr;
    while (*ptr != '\0' && *ptr != '\n') {
        while (*ptr == ' ' || *ptr == '\t') ptr++;
        if (*ptr == '\0' || *ptr == '\n') break;

        int val = (int)strtol(ptr, &endptr, 10);
        if (endptr == ptr) {
            printf("Error: Invalid input.\n");
            free(arr);
            return 1;
        }

        arr[n++] = val;
        if (n == capacity) {
            capacity *= 2;
            int *temp = realloc(arr, capacity * sizeof(int));
            if (!temp) {
                printf("Error: Memory allocation failed.\n");
                free(arr);
                return 1;
            }
            arr = temp;
        }
        ptr = endptr;
    }

    if (n == 0) {
        printf("Error: No numbers entered.\n");
        free(arr);
        return 1;
    }

    bubbleSort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1) printf(" ");
    }
    printf("\n");

    free(arr);
    return 0;
}