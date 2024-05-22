int sum_between_ab(int from, int to, int size, int a[]){
    int ret = 0;
    if (from > to){
        int tmp = from;
        from = to;
        to = tmp;
    }
    for (int i = 0; i < size; i++){
        if (a[i] >= from && a[i] <= to){
            ret += a[i];
        }
    }
    return ret;
}