#include <stdlib.h>

#define MAX_SET_SIZE 100

double random_double() {
    return (double)rand() / (double)RAND_MAX;
}


void delete_from_set(int set[], int *size, int value){
    for (int i = 0; i < *size; ++i) {
        if (set[i] == value){
            for (int j = i; j < *size-1; ++j) {
                set[j] = set[j+1];
            }
            (*size)--;
            break;
        }
    }
}

void add_to_set(int set[], int *size, int value){
    if(*size < MAX_SET_SIZE){
        set[*size] = value;
        (*size)++;
    }
}

double count_distinct_new_sol(int list[], int n, int thresh){
    double p = 1.0;
    int seen[MAX_SET_SIZE];
    int seen_size = 0;

    for (int i = 0; i < n; ++i) {
        int value = list[i];
        delete_from_set(seen, &seen_size, value);

        if(random_double()<p){
            add_to_set(seen, &seen_size, value);
        }

        if (seen_size >= thresh){
            int new_seen_size = 0;
            for (int j = 0; j < seen_size; ++j) {
                if(random_double() < 0.5){
                    seen[new_seen_size]=seen[j];
                    new_seen_size++;
                }
            }
            seen_size = new_seen_size;
            p *= 0.5;
        }
    }
    return (double)seen_size / p;
}

