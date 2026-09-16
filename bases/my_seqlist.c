#include "my_seqlist.h"

#define DEFAULT_CAP 72

SeqList *seqlist_create(int init_capacity) {
    if (init_capacity <= 0) init_capacity = DEFAULT_CAP;

    SeqList *list = malloc(sizeof(SeqList));
    if (!list) return NULL;

    list->data = malloc(sizeof(int) * init_capacity);
    if (!list->data) { free(list); return NULL; }

    list->size = 0;
    list->capacity = init_capacity;

    return list;
}

void seqlist_free(SeqList *list) {
    if (!list) return;
    free(list->data);
    free(list);
}
static int ensure_capacity(SeqList *list) {
    if (list->size < list->capacity) return 1;   

    int new_cap = list->capacity * 2;
    int *new_data = realloc(list->data, sizeof(int) * new_cap);
    if (!new_data) return 0;

    list->data = new_data;
    list->capacity = new_cap;
    return 1;


}
int seqlist_push_back(SeqList *list, int value) {
    if (!ensure_capacity(list)) return 0;
    list->data[list->size++] = value;
    return 1;
}

int seqlist_insert(SeqList *list, int pos, int value) {
    if (pos < 0 || pos > list->size) return 0;  
    if (!ensure_capacity(list)) return 0;

    for (int i = list->size; i > pos; i--)
        list->data[i] = list->data[i - 1];

    list->data[pos] = value;
    list->size++;
    return 1;
}

int seqlist_delete(SeqList *list, int pos) {
    if (pos < 0 || pos >= list->size) return 0;  

    for (int i = pos; i < list->size - 1; i++)
        list->data[i] = list->data[i + 1];

    list->size--;
    return 1;
}

int seqlist_delete_value(SeqList *list, int value) {

    int pos = seqlist_find(list, value);
    if (pos == -1) return 0;
    return seqlist_delete(list, pos);

}
int seqlist_get(SeqList *list, int pos, int *out) {
    if (pos < 0 || pos >= list->size) return 0;
    if (out) *out = list->data[pos];
    return 1;
}

int seqlist_set(SeqList *list, int pos, int value) {
    if (pos < 0 || pos >= list->size) return 0;
    list->data[pos] = value;
    return 1;
}

int seqlist_find(SeqList *list, int value) {
    for (int i = 0; i < list->size; i++)
        if (list->data[i] == value) return i;
    return -1;
}

int seqlist_size(SeqList *list)  
{ 
    return list->size; 
}
int seqlist_empty(SeqList *list) 
{
    return list->size == 0; 
}

/* ---------- 打印 ---------- */
void seqlist_print(SeqList *list) {
    printf("[");
    for (int i = 0; i < list->size; i++) {
        printf("%d", list->data[i]);
        if (i < list->size - 1) printf(", ");
    }
    printf("]  size=%d, cap=%d\n", list->size, list->capacity);
}