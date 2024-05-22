#include <stdio.h>

int main(void){
    int mass[5] = {0};
    float middle = 0;
    for(int i = 0; i < 5; i++){
        scanf("%d", &mass[i]);
        middle += mass[i];
    }
    middle /= 5;
    printf("%.3f", middle);
    return 0;
}