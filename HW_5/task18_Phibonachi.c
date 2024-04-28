#include <stdio.h>

int main(void){
    unsigned int count;
    unsigned int p_num1 = 1, p_num2 = 0, tmp;
    scanf("%u", &count);
    printf("%u", p_num1);
    if(count == 1){
        return 0;
    }
    for(int i = 1; i < count; i++){
        printf(" %u", p_num1+p_num2);
        tmp = p_num1;
        p_num1 += p_num2;
        p_num2 = tmp;
    }
    return 0;
}