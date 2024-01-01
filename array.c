#include <stdio.h>

#define MAX_SIZE 100

// Structure to represent an array
typedef struct {
    int size;
    int items[MAX_SIZE];
} Array;

// Function to initialize an empty array
void array_init(Array *arr, int size) {
    arr->size = size;

    // Initialize all elements to 0
    for (int i = 0; i < size; ++i) {
        arr->items[i] = 0;
    }
}

// Function to get an element from the array at a given index
int array_get(Array *arr, int index) {
    if (index < 0 || index >= arr->size) {
        printf("Index out of bounds.\n");
        return -1;
    }

    return arr->items[index];
}

// Function to set an element in the array at a given index
void array_set(Array *arr, int index, int value) {
    if (index < 0 || index >= arr->size) {
        printf("Index out of bounds. Cannot set value.\n");
        return;
    }

    arr->items[index] = value;
    printf("Set value %d at index %d\n", value, index);
}

// Function to display the elements in the array
void array_display(Array *arr) {
    printf("Array elements: ");
    for (int i = 0; i < arr->size; ++i) {
        printf("%d ", arr->items[i]);
    }
    printf("\n");
}

int main() {
    int arraySize = 5;  // Set your desired array size
    Array myArray;
    array_init(&myArray, arraySize);

    // Set values in the array
    array_set(&myArray, 0, 10);
    array_set(&myArray, 1, 20);
    array_set(&myArray, 2, 30);

    // Display the array
    array_display(&myArray);

    // Get value at a specific index
    int valueAtIndex = array_get(&myArray, 1);
    printf("Value at index 1: %d\n", valueAtIndex);

    return 0;
}
