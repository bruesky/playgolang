#include <iostream>
#include <time.h>
#include <math.h>
#include <omp.h>

void testCase(int t);

int main() {
    for (int i = 1; i < 11; ++i) {
        testCase(i);
    }

    return 0;
}

void testCase(int t){
    int n = 10000000, i = 0,thread_count;
    int* arr = (int*)malloc(n* sizeof(int));
    int* arrLog = (int*)malloc(n* sizeof(int));
    clock_t clock_timer;
    double wall_timer;
    for (i = 0; i < n; i++) {
        arr[i] = i;
    }

    clock_timer = clock();
    wall_timer = omp_get_wtime();
    omp_set_num_threads(t);
    #pragma omp parallel for
    for (i = 0; i  < n; i++) {
        thread_count = omp_get_num_threads();

//        printf("%d from thread %d of %d\n",i, my_rank, thread_count);
        arrLog[i] = log(arr[i]);
    }
    printf("total thread num: %d and time on clock: %f and  time on wall:%f\n",(double) (clock() - clock_timer) / CLOCKS_PER_SEC,thread_count,omp_get_wtime() - wall_timer);


    free(arr);
    free(arrLog);
}
