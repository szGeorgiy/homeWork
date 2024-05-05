#include <stdio.h>

int is_digit(char character){
    if(character >= '0' && character <= '9'){
        return 1;
    }
    return 0;
}

int main(void){
    int count = 0;
    char character;
    while (1){
        character = getchar();
        if(character == '.'){
            printf("%d", count);
            break;
        }
        if(is_digit(character)){
            count++;
        }
    }
    return 0;
}