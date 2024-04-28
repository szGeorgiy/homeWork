#include <stdio.h>

int main(void){
    char ch, ch_tmp = 0;
    int count = 0;
    while( (ch = getchar()) != '\n'){
        if(ch == ' '){
            if( (ch_tmp & 1) == 0){
                count++;
            }
        }
        ch_tmp = ch;
    }
    printf("%d", count);
    return 0;
}