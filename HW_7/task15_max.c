#include <stdio.h>

 int max_find(int first){
    static int max;
    int tmp;
    scanf("%d", &tmp);
    max = first;
    if(tmp != 0){
        if(max < tmp){
            max = tmp;
        }
        max_find(max);
    }
    return max;
 }

 int main(void){
    int maximum;
    scanf("%d", &maximum);
    maximum = max_find(maximum);
    printf("%d", maximum);
    return 0;
 }