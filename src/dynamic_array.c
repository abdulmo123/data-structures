# include <stdio.h>
# include <stdlib.h>

typedef struct {
	int *data; // points to the start of a block of memory that stores multiple ints
	int size; // current # of items in the arr/list
	int capacity; // max # of items (before resizing occurs)

} DynamicArray;

void init(DynamicArray *arr);
void push(DynamicArray *arr, int capacity);

int main() {
	DynamicArray arr;

	// call init method
	init(&arr);
	printf("Data = %p\n", arr.data);
	printf("Size = %d\n", arr.size);
	printf("Capacity = %d\n", arr.capacity);

	// call add method :)
	push(&arr, 4);
	push(&arr, 1);
	push(&arr, 3);
	push(&arr, 5);
	push(&arr, 2);
	push(&arr, 8);
	push(&arr, 6);
	push(&arr, 0);
	push(&arr, 9);
	push(&arr, 7);
	push(&arr, 2);
	push(&arr, 8);
	push(&arr, 6);
	push(&arr, 0);
	push(&arr, 9);
	push(&arr, 7);
	printf("Hello World!\n");
	return 0;
}

void init(DynamicArray *arr) {
	arr->size = 0; // can also do: (*arr).size = 0;
	arr->capacity = 4; // can also do: (*arr).capacity = 4;
	arr->data = (int*) malloc(arr->capacity * sizeof(int)); // allocate spsace for 4 ints on init

	printf("Init array ...");
	for (int i = 0; i < arr->capacity; i++) {
		printf("%d ", arr->data[i]); 
	}
	printf("\n");
}

void push(DynamicArray *arr, int value) {
	if (arr->size == arr->capacity) {
		int newCapacity = arr->capacity * 2;
		arr->capacity = newCapacity;
		int *newData = realloc(arr->data, newCapacity * sizeof(int));
		if (newData == NULL) {
			printf("Failed. Unable to resize memory");
			return;
		}
		else {
			printf("Success!. %lu bytes allocated at address %p!\n", arr->capacity * sizeof(int), newData);
			arr->data = newData;
		}
		printf("New capacity yay! :) %d\n", arr->capacity);
	}

	arr->data[arr->size] = value;
	arr->size++;

	printf("Aftering adding ...\n");
	printf("Size = %d\n", arr->size);
	printf("Capacity = %d\n", arr->capacity);
	for (int i = 0; i < arr-> capacity; i++) {
		printf("%d ", arr->data[i]);
	}
	printf("\n");
}
