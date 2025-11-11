# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h> // I did not know bool needed a library LOL

typedef struct {
	int *data; // points to the start of a block of memory that stores multiple ints
	int size; // current # of items in the arr/list
	int capacity; // max # of items (before resizing occurs)

} DynamicArray;

void init(DynamicArray *arr);
void push(DynamicArray *arr, int capacity);
void pop (DynamicArray *arr);
int search(DynamicArray *arr, int value);
bool isEmpty(DynamicArray *arr);

int main() {
	DynamicArray arr;

	// call init method
	init(&arr);
	printf("Data = %p\n", arr.data);
	printf("Size = %d\n", arr.size);
	printf("Capacity = %d\n", arr.capacity);

	// call isEmpty method
	isEmpty(&arr);
	// call PUSH method :)
	//push(&arr, 4);
	for (int i = 0; i < 16; i++) {
		int r = rand() % 20;
		push(&arr, r);
	}

	// call POP method
	for (int i = 0; i < 10; i++) {
		pop(&arr);
	}

	// call SEARCH method
	search(&arr, 6);
	search(&arr, 15);
	search(&arr, 9);
	search(&arr, 13);

	return 0;
}

void init(DynamicArray *arr) {
	arr->size = 0; // can also do: (*arr).size = 0;
	arr->capacity = 4; // can also do: (*arr).capacity = 4;
	arr->data = malloc(arr->capacity * sizeof(int)); // allocate spsace for 4 ints on init

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

	printf("After PUSHING ...\n");
	printf("Size = %d\n", arr->size);
	printf("Capacity = %d\n", arr->capacity);
	for (int i = 0; i < arr-> capacity; i++) {
		printf("%d ", arr->data[i]);
	}
	printf("\n");
}

void pop(DynamicArray *arr) {
	// todo: check if size is less than capacity / 2 ---> realloc smaller arr
	// do i need to actually 'remove' the values? or just set to 0 and reduce size
	if (arr->size * 2 <= arr->capacity) {
		// todo: realloc smaller arr
		int *newData = realloc(arr->data, (arr->capacity / 2) * sizeof(int));
		if (newData == NULL) {
			printf("NOOOO!!");
			return;
		} else {
			arr->data = newData;
			printf("YAAAAAAAAAY!!!");
		}
	}

	arr->data[arr->size - 1] = 0;
	arr->size--;

	printf("After POPPING ...\n");
	printf("Size = %d\n", arr->size);
	printf("Capacity = %d\n", arr->capacity);
	for (int i = 0; i < arr->capacity; i++) {
		printf("%d ", arr->data[i]);
	}
	printf("\n");
}

int search(DynamicArray *arr, int value) {
	if (arr->size == 0) {
		return -1;
	}

	for (int i = 0; i < arr->size; i++) {
		if (arr->data[i] == value) {
			printf("Found the value: {%d} at index {%d}!!!\n", value, i);
			return i;
		}
	}

	printf("Value {%d} not found in array :(\n", value);
	return -1;
}

bool isEmpty(DynamicArray *arr) {
	printf("Is array empty? %d\n", arr->size == 0);
	return arr->size == 0;
}
