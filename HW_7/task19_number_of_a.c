#include <stdio.h>

int acounter(void){
    static int ret = 0;
    char ch;
    ch = getchar();
    if (ch != '.'){
        acounter();
    }
    if (ch == 'a'){
        ret++;
    }
    return ret;
}

int main(void){
    int num;
    num = acounter();
    printf("%d", num);
    return 0;
}