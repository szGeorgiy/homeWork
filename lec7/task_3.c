#include <stdio.h>
#include <stddef.h>

typedef int datatype;

typedef struct tree {
    datatype key;
    struct tree *left, *right;
    struct tree *parent; //ссылка на родителя
} tree;

tree *findBrother(tree *root, int key) {
    if (root == NULL){
        return NULL;
    }

    tree *tmp = NULL;
    tree *stack[256];
    int top = -1;

    stack[++top] = root;
    while (top >= 0) {
        tree *node = stack[top--];
        if (node->key == key) {
            tmp = node;
            break;
        }
        if (node->right){
            stack[++top] = node->right;
        }
        if (node->left) {
            stack[++top] = node->left;
        }
    }
    if (tmp == NULL) {
        return NULL;
    }

    if (tmp->parent == NULL) {
        return NULL;
    }
    tree *parent = tmp->parent;
    if (parent->left == tmp) {
        return parent->right;
    } else {
        return parent->left;
    }
}