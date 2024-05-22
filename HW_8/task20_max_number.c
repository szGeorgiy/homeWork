#include <stdio.h>

int main(void){
    int number;
    int result = 0;
    int mass[10] = {0};
    int tmp;
    scanf("%d", &number);
    while(number > 0){
        tmp = number % 10;
        mass[tmp]++;
        number /= 10;
    }
    for(int i = 9; i >= 0; i--){
        while(mass[i]){
            result += i;
            result *= 10;
            mass[i]--;
        }
    }
    result /= 10;
    printf("%d", result);
    return 0;
}