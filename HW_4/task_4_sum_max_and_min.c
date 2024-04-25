#include <stdio.h>

int main(void){
    int n1, n2, n3, n4, n5;
    int max = 0, min = 0, sum = 0;
    scanf("%d%d%d%d%d", &n1, &n2, &n3, &n4, &n5);
    
    max = n1 > n2 ? n1 : n2;
    max = max > n3 ? max : n3;
    max = max > n4 ? max : n4;
    max = max > n5 ? max : n5;
    
    min = n1 < n2 ? n1 : n2;
    min = min < n3 ? min : n3;
    min = min < n4 ? min : n4;
    min = min < n5 ? min : n5;

    sum = min + max;
    printf("%d", sum);
    return 0;
}