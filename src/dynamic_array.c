# include <stdio.h>

typedef struct {
	int *data; // points to the start of a block of memory that stores multiple ints
	int size; // current # of items in the arr/list
	int capacity; // max # of items (before resizing occurs)

} DynamicArray;

void init(DynamicArray *arr);

int main() {
	DynamicArray arr;
	init(&arr);
	printf("Data = %p\n", arr.data);
	printf("Size = %d\n", arr.size);
	printf("Capacity = %d\n", arr.capacity);
	printf("Hello World!\n");
	return 0;
}

void init(DynamicArray *arr) {
	arr->data = NULL;
	arr->size = 0;
	arr->capacity = 4;

//	printf("Data = %p\n", arr->data);
//	printf("Size = %d\n", arr->size);
//	printf("Capacity = %d\n", arr->capacity);

}
