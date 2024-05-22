#include <stdio.h>

int main(void){
    int min;
    int max;
    int tmp;
    float calc_sum;
    long int real_sum = 0;
    int count = 1;
    int missing_number;
    scanf("%d", &tmp);
    min = tmp;
    max = tmp;
    real_sum += tmp;
    while (1){
        scanf("%d", &tmp);
        if (tmp == 0){
            break;
        }
        if (tmp > max){
            max = tmp;
        }
        if (tmp < min){
            min = tmp;
        }
        count++;
        real_sum += tmp;
    }
    count++;
    calc_sum = (min + max) * count  / 2.0;
    missing_number = (int) (calc_sum - real_sum);
    printf("%d", missing_number);
    return 0;   
}