#include <stdio.h>

int main(void){
    char ch;
    int count = 0;
    while( (ch = getchar()) != '\n'){
        if(ch == ' '){
            count++;
        }
    }
    printf("%d", count);
    return 0;
}