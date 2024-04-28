#include <stdio.h>

int main(void){
    unsigned int num;
    unsigned int tmp;
    int ch_count = 0;
    int nch_count = 0;
    scanf("%u", &num);
    while(num > 0){
        tmp = (num % 10) & 1;
        if (tmp){
            nch_count++;
        } else {
            ch_count++;
        }
        num /= 10;
    }
    printf("%d %d", ch_count, nch_count);
    return 0;
}