#include <stdio.h>

typedef struct list {
    void *address;
    size_t size;
    char comment[64];
    struct list *next;
} list;

size_t totalMemoryUsage(list *head){
    size_t size = 0;
    while (head != NULL){
        size += head->size;
        head = head->next;
    }
    if (size == 0){
        return 0;
    } else {
        return size;
    }
}

/**
 * Тест функции
 */

int main (void){
    size_t mem;
    list list1 = {.size = 1,
                    .address = &list1};
    list list2 = {.size = 2,
                    .address = &list2};
    list list3 = {.size = 3,
                    .address = &list3,
                    .next = NULL};
    list1.next = &list2;
    list2.next = &list3;
    mem = totalMemoryUsage(&list1);
    printf("Memory = %lu\n", mem);
    return 0;
}