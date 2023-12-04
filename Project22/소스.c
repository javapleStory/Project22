#include <stdio.h>
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
		if (temp.key > h->array[child].key) break;
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

	return 1;
}

