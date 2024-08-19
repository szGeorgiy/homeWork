#include <stdio.h>

int main(void){
    unsigned int count;
    unsigned int unic = 0;
    unsigned int tmp;
    scanf("%u", &count);
    while (count){
        scanf("%u", &tmp);
        unic ^= tmp;
        count--;
    }
    printf("%u", unic);
    return 0;
}