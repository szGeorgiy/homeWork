void sort_even_odd(int n, int a[]){
    int even_mass[n];
    int odd_mass[n];
    int even_count = 0;
    int odd_count = 0;
    int tmp;
    for(int i = 0; i < n; i++){
        if(a[i] % 2 == 0){
            even_mass[even_count] = a[i];
            even_count++;
        } else {
            odd_mass[odd_count] = a[i];
            odd_count++;
        }
    }
    for(int i = 0; i < even_count; i++){
        a[i] = even_mass[i];
    }
    for(int i = 0; i < odd_count; i++){
        a[even_count + i] = odd_mass[i];
    }
}