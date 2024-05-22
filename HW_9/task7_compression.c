int compression(int a[], int b[], int N){
    int b_count = 0;
    int tmp = 0;
    int repeet_count = 1;
    if(a[0] == 1){
        b[0] = 0;
        b_count++;
    }
    tmp = a[0];
    for(int i = 1; i < N; i++){
        if(a[i] != tmp){
            b[b_count] = repeet_count;
            b_count++;
            repeet_count = 1;
            tmp = a[i];
        } else {
            repeet_count++;
        }
    }
    b[b_count] = repeet_count;
    b_count++;
    return b_count;
}