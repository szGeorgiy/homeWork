#include <stdio.h>

int is2pow(int num){
    static int ones_count = 0;
    if(num > 0){
        ones_count += num % 2;
        is2pow(num / 2);
    }
    if(ones_count == 1){
        return 1;
    } else {
        return 0;
    }

}

int main(void){
    int num;
    scanf("%d", &num);
    if (is2pow(num)){
        printf("YES");
    } else {
        printf("NO");
    }
    return 0;
}