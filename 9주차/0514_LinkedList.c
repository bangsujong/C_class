#include <stdio.h>

#define MAX_LIST_SIZE 100

typedef int element;
typedef struct {
	element array[MAX_LIST_SIZE];
	int size;
}ArrayListType;

void  error(char* message) {
	fprintf(stderr, "%s\n", message);
}

init(ArrayListType* L) {
	L->size = 0;
}

int is_full(ArrayListType* L) {
	// if (L->size >= MAX_LIST_SIZE) return 1;
	// else return 0;
	return (L->size == MAX_LIST_SIZE);
}

void insert(ArrayListType* L, int pos, element item) {
	if (!is_full(L) && (pos >= 0) && (pos <= L->size)) {
		for (int i = L->size - 1; i >= pos; i = i - 1) {
			L->array[i + 1] = L->array[i];
		}
		L->array[pos] = item; /// **************
		L->size = L->size + 1;
	}
}

void insert_last(ArrayListType* L, element item) {
	if (L->size == MAX_LIST_SIZE) {
		error("리스트 오버플로우");
	}
	L->array[L->size++] = item;
}

void insert_first(ArrayListType* L, element item) {
	insert(L, 0, item);
}

void clear(ArrayListType* L) {
	init(L);
}

element get_entry(ArrayListType* L, int pos) {
	if (pos > 0 && pos < L->size)
		return L->array[pos];
	else
		error("위치 오류");
}

int get_length(ArrayListType* L) {
	return L->size;
}

int is_empty(ArrayListType* L) {
	return (L->size == 0);
}
void print_list(ArrayListType* L) {
	printf("[LIST]");
	for (int i = 0; i < L->size; i++)
		printf("<%2d> ", L->array[i]);
	printf("\n");
}

element delete(ArrayListType* L, int pos) {
	if (pos < 0 || pos >= L->size)
		error("위치 오류");
	else {
		element item = L->array[pos];
		for (int i = pos; i < (L->size - 1); i++) {
			L->array[i] = L->array[i + 1];
		}
		L->size = L->size - 1;
		return item;
	}
}

int main() {

	ArrayListType list;

	init(&list);
	insert(&list, 0, 10); print_list(&list);
	insert(&list, 0, 20); print_list(&list);
	insert(&list, 0, 30); print_list(&list);
	insert_last(&list, 40); print_list(&list);
	delete(&list, 0); print_list(&list);

}