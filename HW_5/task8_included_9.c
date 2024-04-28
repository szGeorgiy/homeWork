#include <stdio.h>

int main(void){
    int num;
    int counter = 0;
    scanf("%d", &num);
    while(num > 0){
        if (num % 10 == 9){
            counter++;
        }
        num /= 10;
    }
    if (counter == 1){
        printf("YES");
    } else {
        printf("NO");
    }
    return 0;
}