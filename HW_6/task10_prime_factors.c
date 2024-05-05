#include <stdio.h>

unsigned int NOD(unsigned int num, unsigned int divider){
    while (num > 0){
        // printf("num = %u divider = %u\n", num, divider);
        if (num > divider){
            num -= divider;
        }
        if (num < divider){
            divider -= num;
        }
        if (num == divider){
            return num;
        }
    }
}

unsigned int print_simple(unsigned int num){
    unsigned int count = 2;
    unsigned int tmp;
    while (1){
        tmp = NOD(num, count);
        if (tmp != 1){
            num /= count;
            printf("%u", tmp);
            break;
        } else {
            count++;
        }
    }
    while (num > 1){
        tmp = NOD(num, count);
        if (tmp != 1){
            num /= count;
            printf(" %u", tmp);
        } else {
            count++;
        }
    }
    return count;
}

int main(void){
    unsigned int number;
    scanf("%u", &number);
    print_simple(number);
    return 0;
}