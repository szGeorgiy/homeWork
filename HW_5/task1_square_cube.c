#include <stdio.h>

int main(void){
    unsigned int num;
    unsigned int count = 1;
    unsigned int count_2, count_3;
    scanf("%u", &num);
    while(count <= num){
        count_2 = count * count;
        count_3 = count_2 * count;
        printf("%u %u %u\n", count, count_2, count_3);
        count++;
    }
    return 0;
}
