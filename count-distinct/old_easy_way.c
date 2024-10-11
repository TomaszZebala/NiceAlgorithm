int count_elements_old_way(int array[], int size) {
    int unique_count = 0;
    for (int i = 0; i < size; i++) {
        int is_unique = 1;
        for (int j = 0; j < i; j++) {
            if (array[i] == array[j]) {
                is_unique = 0;
                break;
            }
        }
        if (is_unique) {
            unique_count++;
        }
    }
    return unique_count;
}

