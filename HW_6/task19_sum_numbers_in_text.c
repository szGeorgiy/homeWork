#include <stdio.h>

int digit_to_num(char character){
    int ret;
    ret = character - 0x30;
    return ret;
}

int main(void){
    char character;
    int sum = 0;
    while(1){
        character = getchar();
        if( character == '.'){
            break;
        }
        if( character >= '0' && character <= '9'){
            sum += digit_to_num(character);
        }
    }
    printf("%d", sum);
    return 0;
}