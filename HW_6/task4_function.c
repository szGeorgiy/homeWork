#include <stdio.h>

int function (int num){
    int res;
    if (num >= 2){
        res = num * num + 4 * num + 5;
    } 
    if (num < -2){
        res = 4;
    }
    if (num >= -2 && num < 2) {
        res = num * num;
    }
    return res;
}

int main(void){
    int num, result;
    scanf("%d", &num);
    result = function(num);
    while (num != 0){
        scanf("%d", &num);
        result = result > function(num) ? result : function(num); 
    }
    printf("%d", result);
    return 0;
}