#include <stdio.h>

int NOD(int num, int divider){
    while (num > 0){
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

int main(void){
    int mass[7] = {0};
    int number;
    int tmp;
    scanf("%d", &number);
    for(int i = 2; i < number + 1; i++){
        for(int j = 2; j < 10; j++){
            if(i % j == 0){
                mass[j-2]++;
            }
        }
    }
    for(int j = 2; j < 10; j++){
        printf("%d %d\n", j, mass[j - 2]);
    }
    return 0;
}