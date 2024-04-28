#include <stdio.h>

int main(void){
    unsigned int num;
    int counters[10] = {0};
    int condition = 0;
    unsigned int tmp;
    scanf("%u", &num);
    while(num > 0){
        tmp = num % 10;
        counters[tmp]++;
        num /= 10;
    }
    for(int i = 0; i < 10; i++){
        if(counters[i] > 1){
            condition = 1;
            break;
        }
    }
    if(condition){
        printf("YES");
    } else {
        printf("NO");
    }
    return 0;
}