#include <stdio.h>

int main(void){
    int open_count = 0;
    int close_count = 0;
    char c;
    int condition = 1;
    while(1){
        c = getchar();
        if(c == '.' || c == '\n'){
            break;
        }
        if(c == '('){
            open_count++;
        }
        if(c == ')'){
            close_count++;
        }
        if(close_count > open_count){
            condition = 0;
        }
    }
    if (open_count != close_count){
        condition = 0;
    }
    if(condition){
        printf("YES");
    } else {
        printf("NO");
    }
    return 0;
}