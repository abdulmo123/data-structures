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
void insert(DynamicArray *arr, int index, int value);
void removeItem(DynamicArray *arr, int index);

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

	// call INSERT method
	insert(&arr, 3, 5);
	insert(&arr, 0, -1);

	// call REMOVE method
	removeItem(&arr, 2);
	removeItem(&arr, 0);
	removeItem(&arr, 4);

	return 0;
}

void init(DynamicArray *arr) {
	arr->size = 0; // can also do: (*arr).size = 0;
	arr->capacity = 4; // can also do: (*arr).capacity = 4;
	arr->data = malloc(arr->capacity * sizeof(int)); // allocate spsace for 4 ints on init

	printf("Initialize the array ...\n");
	for (int i = 0; i < arr->capacity; i++) {
		printf("%d ", arr->data[i]); 
	}
	printf("\n");
}

void push(DynamicArray *arr, int value) {
	// resize array if not enough capacity allocated in memory
	if (arr->size == arr->capacity) {
		int newCapacity = arr->capacity * 2;
		arr->capacity = newCapacity;
		int *newData = realloc(arr->data, newCapacity * sizeof(int));
		if (newData == NULL) {
			return;
		}
		else {
			arr->data = newData;
			printf("Success!. %lu bytes allocated at address %p!\n", arr->capacity * sizeof(int), arr->data);
		};
	}

	arr->data[arr->size] = value;
	arr->size++;

	printf("PUSHING value: {%d} to the END of the array ...\n", value);
	printf("Size = %d\n", arr->size);
	printf("Capacity = %d\n", arr->capacity);
	for (int i = 0; i < arr->capacity; i++) {
		printf("%d ", arr->data[i]);
	}
	printf("\n");
}

void pop(DynamicArray *arr) {
	// realloc to smaller array if capacity too larger (don't want to waste memory)
	if (arr->size * 2 <= arr->capacity) {
		int newCapacity = arr->capacity / 2;
		int *newData = realloc(arr->data, (arr->capacity / 2) * sizeof(int));
		if (newData == NULL) {
			return;
		} else {
			arr->data = newData;
			arr->capacity = newCapacity;
			printf("Success! {%lu} bytes allocated at address: {%p}\n", arr->capacity * sizeof(int), arr->data);
		}
	}

	arr->data[arr->size - 1] = 0;
	arr->size--;

	printf("POPPING from the END of the array ...\n");
	printf("Size = %d\n", arr->size);
	printf("Capacity = %d\n", arr->capacity);
	for (int i = 0; i < arr->capacity; i++) {
		printf("%d ", arr->data[i]);
	}
	printf("\n");
}

int search(DynamicArray *arr, int value) {
	// if array length is 0, nothing to search so value is not found
	if (arr->size == 0) {
		return -1;
	}

	// if value found in array, return it
	for (int i = 0; i < arr->size; i++) {
		if (arr->data[i] == value) {
			printf("Found the value: {%d} at index {%d}!\n", value, i);
			return i;
		}
	}

	// return -1 if value is not found
	printf("Value {%d} not found in array :(\n", value);
	return -1;
}

bool isEmpty(DynamicArray *arr) {
	// returns a 0 (FALSE) or 1 (TRUE) based on if array is empty or not
	printf("Is array empty? %d\n", arr->size == 0);
	return arr->size == 0;
}

void insert(DynamicArray *arr, int index, int value) {
	// check to make sure index is not out of bounds before trying to insert
	if (index > arr->size || index < 0) {
		printf("Index is out of bounds! Cannot INSERT value: {%d} at index: {%d}\n", value, index);
	}

	// realloc to larger capacity in memory
	if (arr->size == arr->capacity) {
		int *newData = realloc(arr->data, (arr->capacity * 2) * sizeof(int));
		if (newData == NULL) {
			return;
		} else {
			arr->capacity = arr->capacity * 2;
			arr->data = newData;
			printf("Success! {%lu} bytes allocated at address: {%p}\n", arr->capacity * sizeof(int), arr->data);
		}
	}

	// shift items to the right up until we reach index
	for (int i = arr->capacity - 1; i > index; i--) {
		arr->data[i] = arr->data[i-1];
	}

	// insert value at index and increment size
	arr->data[index] = value;
	arr->size++;

	printf("INSERTING value: {%d} at index: {%d}...\n", value, index);
	printf("Size = %d\n", arr->size);
	printf("Capacity = %d\n", arr->capacity);
	for (int i = 0; i < arr->capacity; i++) {
		printf("%d ", arr->data[i]);
	}
	printf("\n");
}

void removeItem(DynamicArray *arr, int index) {
	// check to make sure index is not out of bounds before trying to remove
	if (index > arr-> size || index < 0) {
		printf("Index is out of bounds! Cannot REMOVE item at index: {%d}\n", index);
	}

	// realloc to smaller capacity in memory to prevent wasted space in memory
	if (arr->size * 2 <= arr->capacity) {
		int newCapacity = arr->capacity / 2;
		int *newData = realloc(arr->data, newCapacity * sizeof(int));
		if (newData == NULL) {
			return;
		} else {
			arr->data = newData;
			arr->capacity = newCapacity;
			printf("Success! {%lu} bytes allocated at address: {%p}\n", arr->capacity * sizeof(int), arr->data);
		}
	}

	// set to-be-removed item to 0
	arr->data[index] = 0;

	// swap removed item all the way to end of array and then decrement size
	for (int i = index; i < arr->size - 1; i++) {
		int temp = arr->data[i];
		arr->data[i] = arr->data[i+1];
		arr->data[i+1] = temp;
	}
	arr->size--;

	printf("REMOVING item at index: {%d}\n", index);
	printf("Size = %d\n", arr->size);
	printf("Capacity = %d\n", arr->capacity);
	for (int i = 0; i < arr->capacity; i++) {
		printf("%d ", arr->data[i]);
	}
	printf("\n");
}
