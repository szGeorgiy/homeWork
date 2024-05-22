void sort_array(int size, int a[]){
    int tmp = a[0];
    for(int i = 0; i < size; i++){
        for(int j = 0; j <size; j++)
            if(a[i] < a[j]){
                tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
    }
}