#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 100
#define MAX_VALUE 100
#define THRESH_SIZE 20

double count_distinct_new_sol(int list[], int n, int thresh);
int count_elements_old_way(int array[], int size);


void generate_random_array(int array[], int size, int max_value) {
    for (int i = 0; i < size; i++) {
        array[i] = rand() % max_value;
    }
}


int main() {
    srand(time(0));

    int array[ARRAY_SIZE];

    generate_random_array(array, ARRAY_SIZE, MAX_VALUE);

    int count_old_way = count_elements_old_way(array, ARRAY_SIZE);
    double count_new_sol = count_distinct_new_sol(array, ARRAY_SIZE, THRESH_SIZE);

    printf("Dokladna ilosc elementow: %d\n", count_old_way);
    printf("Oszacowana ilosc elementow: %f\n", count_new_sol);

    return 0;
}
