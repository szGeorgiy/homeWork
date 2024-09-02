/*
В программе описана структура для хранения двоичного дерева:
typedef struct tree {
 int key;
    struct tree *left, *right;
} tree;

Необходимо реализовать функцию, которая печатает вид дерева сверху. Функция должна строго соответствовать прототипу: void btUpView(tree *root)
В качестве ответа загрузите только одну функцию void btUpView(tree *root)
Пример №1
Данные на входе:	

       10
      /   \
     5     15
    / \   /  \
   3   7 13   18
  /   /
 1   6
Данные на выходе:	1 3 5 10 15 18
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct tree {
    int key;
    struct tree *left, *right;
} tree;



void btUpView(tree *root) {
    int left_mass[100] = {0};
    int left_count = 0;
    int right_mass[100] = {0};
    int right_count = 0;
    tree *tmp = root;
    // printf("master %d\n", tmp->key);
    while (1){
        if (tmp->left == NULL){
            left_mass[left_count] = tmp->key;
            left_count++;
            break;
        }
        left_mass[left_count] = tmp->key;
        tmp = tmp->left;
        left_count++;
    }
    tmp = root->right;
    while (1){
        if (tmp->right == NULL){
            right_mass[right_count] = tmp->key;
            right_count++;
            break;
        }
        right_mass[right_count] = tmp->key;
        tmp = tmp->right;
        right_count++;
    }

    for (int i = left_count - 1; i >= 0; i--){
        printf("%d ", left_mass[i]);
    }
    for (int i = 0; i < right_count; i++){
        printf("%d ", right_mass[i]);
    }
}

int main() {
    // Создание дерева
    tree *root = (tree *)malloc(sizeof(tree));
    root->key = 10;
    root->left = (tree *)malloc(sizeof(tree));
    root->left->key = 5;
    root->left->left = (tree *)malloc(sizeof(tree));
    root->left->left->key = 3;
    root->left->left->left = (tree *)malloc(sizeof(tree));
    root->left->left->left->key = 1;
    root->left->left->left->left =NULL;
    root->left->left->left->right =NULL;
    root->left->right = (tree *)malloc(sizeof(tree));
    root->left->right->key = 7;
    root->left->right->right = NULL;
    root->left->right->left = (tree *)malloc(sizeof(tree));
    root->left->right->left->key = 6;
    root->left->right->left->left = NULL;
    root->left->right->left->right = NULL;
    root->right = (tree *)malloc(sizeof(tree));
    root->right->key = 15;
    root->right->left = (tree *)malloc(sizeof(tree));
    root->right->left->key = 13;
    root->right->left->left = NULL;
    root->right->left->right = NULL;
    root->right->right = (tree *)malloc(sizeof(tree));
    root->right->right->key = 18;
    root->right->right->left = NULL;
    root->right->right->right = NULL;

    btUpView(root);
    printf("\n");

    free(root->right->right);
    free(root->right->left);
    free(root->right);
    free(root->left->right->left);
    free(root->left->right);
    free(root->left->left->left);
    free(root->left->left);
    free(root->left);
    free(root);

    return 0;
}
