//
// Created by Xiangkui Guo on 2/16/20.
//
#include <stdio.h>
#include <omp.h>
int main()
{
    omp_set_num_threads(5);
    #pragma omp parallel
    {
        printf("thread %d of %d, hello world\n",omp_get_thread_num(),omp_get_num_threads());
    }
}