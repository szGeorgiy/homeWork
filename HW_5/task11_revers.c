#include <stdio.h>

int main(void){
    unsigned int num;
    unsigned int rev[8];
    int count = 0;
    scanf("%u", &num);
    if(num == 0){
        printf("0");
        return 0;
    }
    while(num > 0){
        rev[count] = num % 10;
        num /= 10;
        count++;
    }
    for(int i = 0; i < count; i++){
        printf("%u", rev[i]);
    }
    return 0;
}