void swap_negmax_last(int size, int a[]){
    int swap_condition = 0;
    int max;
    int count = 0;
    while(count < size){
        if (a[count] < 0){
            swap_condition = 1;
            max = a[count];
            break;
        }
        count++;
    }
    if (swap_condition){
        for (int i = count; i < size; i++){
            if (a[i] < 0){
                if (a[i] > max){
                    max = a[i];
                    count = i;
                }
            }
        }
        int tmp;
        tmp = a[size - 1];
        a[size - 1] = a[count];
        a[count] = tmp;
    }
}