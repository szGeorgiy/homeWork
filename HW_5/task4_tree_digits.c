#include <stdio.h>

int main(void){
    unsigned int num;
    scanf("%u", &num);
    if (num>= 100 && num <=999){
        printf("YES");
    } else {
        printf("NO");
    }
    return 0;
}