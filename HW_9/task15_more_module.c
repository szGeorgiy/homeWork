int count_bigger_abs(int n, int a[]){
    int ret = 0;
    int max_positive = a[0];
    for(int i = 0; i < n; i++){
        if (a[i] > max_positive){
            max_positive = a[i];
        }
    }
    for(int i = 0; i < n; i++){
        if (a[i] < 0){
            if (a[i] * -1 > max_positive){
                ret++;
            }
        }
    }
    return ret;
}