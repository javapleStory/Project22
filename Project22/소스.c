#include <stdio.h>
#include <stdlib.h>
#define Max_Element 200

typedef struct {
	int key;
}element;

typedef struct {
	element array[Max_Element];
	int size;
}HeapType;

void insert_max_heap(HeapType* h, element item)
{
	int i = ++(h->size);

	while (i != 1 && (item.key > h->array[i / 2].key))
	{
		h->array[i].key = h->array[i / 2].key;
		i = i / 2;
	}

	h->array[i].key = item.key;
}

element delete_max_heap(HeapType* h)
{
	element item, temp;
	int parent, child;

	temp = h->array[(h->size)--];
	item.key = h->array[1].key;
	parent = 1;
	child = 2;

	while (child <= h->size)
	{
		if ((h->array[child + 1].key > h->array[child].key) && child < h->size)
		{
			child++;
		}
		if (temp.key >= h->array[child].key) break;
		parent = child;
		child = 2 * child;
	}
	h->array[parent] = temp;
	return item;
}

void init_heap(HeapType* h)
{
	h->size = 0;
}

void heap_sort(element a[], int n)
{
	HeapType* heap = (HeapType*)malloc(sizeof(HeapType));
	init_heap(heap);

	for(int i = 0; i < n; i++) insert_max_heap(heap, a[i]);
	for (int i = n - 1; i >= 0; i--) a[i] = delete_max_heap(heap);
	for (int i = 0; i < n; i++)
	{
		printf("< %d > ", a[i].key);
	}
	printf("\n");

	free(heap);
}

int main(void)
{
	element e1 = { 10 }, e2 = { 5 }, e3 = { 30 };
	element e4, e5, e6;
	HeapType h;

	init_heap(&h);

	insert_max_heap(&h, e1);
	for (int i = 1; i < 4; i++)
	{
		printf("%d ", h.array[i].key);
	}
	printf("\n");

	insert_max_heap(&h, e2);
	for (int i = 1; i < 4; i++)
	{
		printf("%d ", h.array[i].key);
	}
	printf("\n");

	insert_max_heap(&h, e3);
	for (int i = 1; i < 4; i++)
	{
		printf("%d ", h.array[i].key);
	}
	printf("\n");

	e4 = delete_max_heap(&h);
	printf("< %d > ", e4.key);
	e5 = delete_max_heap(&h);
	printf("< %d > ", e5.key);
	e6 = delete_max_heap(&h);
	printf("< %d > ", e6.key);
	printf("\n");


	int size = 12;
	element a[12] = { 5,8,7,6,10,21,18,12,4,6,1,5 };
	heap_sort(a, size);

	return 1;
}

