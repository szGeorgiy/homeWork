#include <stdio.h>

char to_high(char character){
    if (character >= 'a' && character <= 'z'){
        character -= 0x20;
    }
    return character;
}

int main(void){
    char simbol;
    while (1){
        simbol = getchar();
        if (simbol == '.'){
            break;
        }
        printf("%c", to_high(simbol));
    }
    return 0;
}