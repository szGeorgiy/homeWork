int count_between(int from, int to, int size, int a[]){
    int ret = 0;
    for (int i = 0; i < size; i++){
        if (a[i] >= from && a[i] <= to){
            ret++;
        }
    }
    return ret;
}