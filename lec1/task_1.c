#include <stdio.h>

int main(void){
    int num_count;
    int max_num;
    int max_count = 0;
    int tmp;
    scanf ("%d", &num_count);
    scanf ("%d", &max_num);
    max_count++;
    for (int i = 1; i < num_count; i++){
        scanf("%d", &tmp);
        if (tmp == max_num){
            max_count++;
        }
        if (tmp > max_num){
            max_num = tmp;
            max_count = 1;
        }
    }
    printf("%d", max_count);
    return 0;
}