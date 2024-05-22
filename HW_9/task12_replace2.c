void change_max_min(int size, int a[]){
    int min = a[0];
    int min_place = 0;
    int max = a[0];
    int max_place = 0;
    int tmp;
    int count = 1;
    while (count < size){
        if (a[count] < min){
            min = a[count];
            min_place = count;
        }
        if (a[count] > max){
            max = a[count];
            max_place = count;
        }
        count++;
    }
    tmp = a[min_place];
    a[min_place] = a[max_place];
    a[max_place] = tmp;
}