#include <stdio.h>
#include <stdbool.h>

int main(void){
    unsigned int a, b, c;
    bool condition = 1;
    scanf("%u%u%u", &a, &b, &c);
    if(a + b <= c){
        condition = 0;
    }
    if(a + c <= b){
        condition = 0;
    }
    if(c + b <= a){
        condition = 0;
    }
    if (condition){
        printf("YES");
    } else {
        printf("NO");
    }
    return 0;
}