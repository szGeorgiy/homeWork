#include <stdio.h>

char Cesar(char simbol, int shift){
    char ret = simbol;
    if (ret >= 'a' && ret <= 'z'){
        ret -= 'a';
        ret += shift;
        ret %= 26;
        ret += 'a';
    }
    if (ret >= 'A' && ret <= 'Z'){
        ret -= 'A';
        ret += shift;
        ret %= 26;
        ret += 'A';
    }
    return ret;
}

int main(void){
    int shift;
    scanf("%d", &shift);
    char tmp;
    scanf("%c", &tmp);
    while (1){
        scanf("%c", &tmp);
        printf("%c", Cesar(tmp, shift));
        if(tmp == '.'){
            break;
        }
    }
    printf("\n%x", 'z');
    return 0;
}