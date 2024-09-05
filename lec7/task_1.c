/*
Задача 7-1-Отсортировать слова
Дана строка, состоящая из английских букв и пробелов. В конце строки символ точка. Все слова разделены одним пробелом. Необходимо составить из слов односвязный список и упорядочить по алфавиту. Список необходимо удалить в конце программы. Для сравнение строк можно использовать strcmp. Необходимо использовать данную структуры организации списка.
struct list {
   char word[20];
   struct list *next;
 }


Необходимо реализовать односвязный список и обслуживающие его функции. add_to_list swap_elements print_list delete_list
Формат ввода:
Строка из английских символов 'a'-'z' и пробелов. В конце строки символ '.'. Длинна строки не более 1000 символов.
Формат вывода:
Упорядоченные по алфавиту слова.

Пример №1
Данные на входе:		efg abcd zzz.
Данные на выходе:	abcd efg zzz
Пример №2
Данные на входе:		fffff kkkkkk a.
Данные на выходе:	a fffff kkkkkk
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct list {
    char word[20];
    struct list *next;
};

// Функция для добавления слова в список
void add_to_list(struct list **head, const char *word) {
    struct list *new_node = (struct list *)malloc(sizeof(struct list));
    strncpy(new_node->word, word, 20);  // Копируем слово
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;  // Если список пуст, то новый элемент становится головой
    } else {
        struct list *current = *head;

        // Ищем место для нового слова
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;  // Добавляем в конец списка
    }
}

// Функция для сортировки списка по алфавиту
void swap_elements(struct list *a, struct list *b) {
    char temp[20];
    strncpy(temp, a->word, 20);
    strncpy(a->word, b->word, 20);
    strncpy(b->word, temp, 20);
}

void sort_list(struct list *head) {
    if (head == NULL) return;

    struct list *i, *j;
    for (i = head; i != NULL; i = i->next) {
        for (j = head; j->next != NULL; j = j->next) {
            if (strcmp(j->word, j->next->word) > 0) {
                swap_elements(j, j->next);
            }
        }
    }
}

// Функция для печати списка
void print_list(struct list *head) {
    struct list *current = head;
    while (current != NULL) {
        printf("%s ", current->word);
        current = current->next;
    }
    printf("\n");
}

// Функция для освобождения памяти списка
void delete_list(struct list **head) {
    struct list *current = *head;
    struct list *next_node;
    while (current != NULL) {
        next_node = current->next;
        free(current);
        current = next_node;
    }
    *head = NULL;
}

int main() {
    char input[1000];
    struct list *word_list = NULL;

    // Считываем строку
    fgets(input, sizeof(input), stdin);

    // Убираем точку в конце строки и обрабатываем слова
    char *token = strtok(input, " .");
    while (token != NULL) {
        add_to_list(&word_list, token);
        token = strtok(NULL, " .");
    }

    // Сортируем список и выводим его
    sort_list(word_list);
    print_list(word_list);

    // Освобождаем память
    delete_list(&word_list);
    
    return 0;
}