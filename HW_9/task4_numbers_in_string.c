void print_digit(char s[]){
    int freq[10] = {0};
    int count = 0;
    while(1){
        if (s[count] >= '0' && s[count] <= '9'){
            freq[ s[count] - '0']++;
        }
        if(s[count] == '.'){
            break;
        }
        count++;
    }
    for(int i = 0; i < 10; i++){
        if (freq[i] > 0){
            printf("%d %d\n", i, freq[i]);
        }
    }
}