#include <stdio.h>

int main(void){
    char first_symbol;
    char next_symbol;
    int count = 0;
    next_symbol = getchar();
    first_symbol = next_symbol;
    count++;
    while (1){
        next_symbol = getchar();
        if (next_symbol == '.'){
            printf("%c%d", first_symbol, count);
            break;
        }
        if (next_symbol == first_symbol){
            count++;
        } else {
            printf("%c%d", first_symbol, count);
            count = 1;
        }
        first_symbol = next_symbol;
    }
    return 0;
}