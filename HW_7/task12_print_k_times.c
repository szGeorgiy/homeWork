#include <stdio.h>

int main(void){
    int num;
    int tmp = 1;
    int count = 1;
    scanf("%d", &num);
    for(int i = 0; i < num; i++){
        printf("%d ", tmp);
        if(tmp == count){
            tmp+=1;
            count = 1;
        } else{
            count++;
        }           
    }
    return 0;
}