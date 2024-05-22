#include <stdio.h>

void frequency_digits_10(int* mass){
    char digit;
    while (1){
        digit = getchar();
        if (digit >= '0' && digit <= '9'){
            mass[ digit - '0']++;
        } else {
            break;
        }
    }
    
}

int main(void){
    int frequency[10] = {};
    frequency_digits_10(frequency);
    for(int i = 0; i < 10; i++){
        if (frequency[i] > 0){
            printf("%d %d\n", i, frequency[i]);
        }
    }
    return 0;
}