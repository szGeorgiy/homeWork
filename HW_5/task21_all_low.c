#include <stdio.h>

int main(void){
    char ch;
    int condition;
    while(1){
        ch = getchar();
        if(ch== '.'){
            break;
        }
        condition = ch >= 'A' && ch <='Z';
        if(condition){
            printf("%c", ch +0x20);
        } else {
            printf("%c", ch);
        }
    }
    return 0;
}