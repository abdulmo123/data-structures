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
//	arr->size = 4;
	// todo: check if size = capacity, if so -- reallocate memory to expand array
	// todo: will probably need to copy over values too?
	if (arr->size == arr->capacity) {
		int newCapacity = arr->capacity * 2;
		// todo: add logic for array realloc here ...
//		arr->capacity = newCapacity;
//		arr->data = realloc(newCapacity * sizeof(int));
//		printf("New capacity bro! %d\n", arr->capacity);
	}

	int i = 0;
	while (i < arr->size) {
		i++;
	}

	arr->data[i] = value;
	arr->size++;

	printf("Aftering adding ...\n");
	printf("Size = %d\n", arr->size);
	printf("Capacity = %d\n", arr->capacity);
	for (int i = 0; i < arr-> capacity; i++) {
		printf("%d ", arr->data[i]);
	}
}
