#include <stdio.h>

void printf_sequence(int start_num, int stop_num){
    if(start_num == stop_num){
        printf("%d", stop_num);
    } else {
        printf("%d ", start_num);
        if(start_num > stop_num){
            start_num--;
        } else {
            start_num++;
        }
        printf_sequence(start_num, stop_num);
    }
}

int main(void){
    int start_num, stop_num;
    scanf("%d%d", &start_num, &stop_num);
    printf_sequence(start_num, stop_num);
    return 0;
}