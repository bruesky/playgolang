//
// Created by Xiangkui Guo on 2/16/20.
//

#include <omp.h>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<long> merge(const vector<long>& left, const vector<long>& right, int threads)
{
    vector<long> result;
    result.resize(left.size()+left.size());
    unsigned left_it = 0, right_it = 0;
    int thread_count;
    clock_t clock_timer;
    double wall_timer;
    clock_timer = clock();
    wall_timer = omp_get_wtime();
    omp_set_num_threads(threads);
    #pragma omp parallel for
    for (left_it = 0; left_it < left.size();left_it++){
        thread_count = omp_get_num_threads();
        #pragma omp parallel for
        for (right_it = 0; right_it < right.size(); ++right_it) {
            if (left[left_it] <= right[right_it]) {
                result[left_it + right_it] = left[left_it];
            }
        }
    }

    #pragma omp parallel for
    for (right_it = 0; right_it < right.size();right_it++){
        #pragma omp parallel for
        for (left_it = 0; left_it < left.size(); ++left_it) {
            if (right[right_it] <= left[left_it]) {
                result[left_it + right_it] = right[right_it];
            }
        }
    }

    printf("total thread num: %d and time on clock: %f and  time on wall:%f\n",thread_count,(double) (clock() - clock_timer) / CLOCKS_PER_SEC,thread_count,omp_get_wtime() - wall_timer);
    return result;
}



int main()
{
    int num = 10000;
    vector<long> v1(num);
    vector<long> v2(num);
    for (long i=0; i<num; ++i){
        v1[i] = rand()% num;
        v2[i] = rand()% num;
    }
    std::sort (v1.begin(), v1.end());
    std::sort(v2.begin(),v2.end());

    for (int j = 1; j < 11; ++j) {
        merge(v1,v2,j);
    }
}
