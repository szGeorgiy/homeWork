#include <stdio.h>

int main(void){
    int n1, n2, n3;
    scanf("%d%d%d", &n1, &n2, &n3);
    if (n1 < n2){
        if(n2 < n3){
            printf("YES");
            return 0;
        }
    }
    printf("NO");
    return 0;
}