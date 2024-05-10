#include <stdio.h>

void revers_print(){
    char character;
    character = getchar();
    if(character != '.'){
        revers_print();
        printf("%c", character);
    }
}

int main(void){
    revers_print();
    return 0;
}