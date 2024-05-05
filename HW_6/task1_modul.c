#include <stdio.h>

unsigned int modul(int num){
    unsigned int res;
    if (num >= 0){
        res = num;
    } else {
        res = num * -1;
    }
    return res;
}

int main(void){
    int in_num;
    unsigned int res;
    scanf("%d", &in_num);
    res = modul(in_num);
    printf("%u", res);
    return 0;
}