#include <stdio.h>

struct list{
   char word[20];
   struct list *next;
};

void add_to_list(char *word, struct list *point);



int main(void){
    char text[9999] = {0};
    int count = 0;
    char tmp;
    struct list my_list = {0};
    /* Читаем с потока */
    while (1){
        scanf("%c", &tmp);
        if (tmp == '.'){
            break;
        }
        text[count] = tmp;
        count++;
    }
    
    return 0;
}