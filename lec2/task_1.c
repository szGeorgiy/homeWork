#include <stdio.h>

typedef struct list {
    void *address;
    size_t size;
    char comment[64];
    struct list *next;
} list;

void * findMaxBlock(list *head){
    list *ret_addr = NULL;
    size_t max_size = 0;
    while (1){
        /* Если указатель нулевой закончить цикл */
        if (head == NULL){
            break;
        } else {
        /* Если указатель не нулевой */
            if (head->size > max_size){
                max_size = head->size;
                ret_addr = head->address;
            }
            head = head->next;
        }
    }
    if (max_size == 0){
        return NULL;
    } else {
        return ret_addr;
    }
}

/**
 * Тест функции
 */

// int main (void){
//     void * pointer;
//     list list1 = {.size = 1,
//                     .address = &list1};
//     list list2 = {.size = 2,
//                     .address = &list2};
//     list list3 = {.size = 3,
//                     .address = &list3,
//                     .next = NULL};
//     list1.next = &list2;
//     list2.next = &list3;
//     printf("addres3 = %p\n", &list3);
//     pointer = findMaxBlock(&list1);
//     printf("max pionter %p", pointer);
//     return 0;
// }