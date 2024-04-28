#include <stdio.h>

unsigned int NOD(unsigned int number, unsigned int check){
    while (number != check){
        if(number > check){
            number -= check;
        } else {
            check -= number;
        }
    }
    return number;
}

int main(void){
    unsigned int num;
    scanf("%u", &num);
    if(num == 1){
        printf("NO");
        return 0;
    }
    if(num == 2){
        printf("YES");
        return 0;
    }
    if( (num & 1) == 0){
        printf("NO");
        return 0;
    }
    for (unsigned int i = 3; i < num; i++){
        if(NOD(num, i) != 1){
            printf("NO");
            return 0;
        }
    }
    printf("YES");
    return 0;
}