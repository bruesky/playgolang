//
// Created by Xiangkui Guo on 2/16/20.
//

#include <omp.h>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int findFirstGE(const vector<long>& array, int target);
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
        int index = findFirstGE(right,left[left_it]);
        result[left_it + right_it] = left[left_it];
    }

    #pragma omp parallel for
    for (right_it = 0; right_it < right.size();right_it++){
        int index = findFirstGE(left,right[right_it]);
        result[left_it + right_it] = right[right_it];
    }

    printf("total thread num: %d and time on clock: %f and  time on wall:%f\n",thread_count,(double) (clock() - clock_timer) / CLOCKS_PER_SEC,thread_count,omp_get_wtime() - wall_timer);
    return result;
}

int findFirstGE(const vector<long>& array, int target) // satisfy condition: array[?] >= target  and the first one
{
    int start = 0, end = array.size() - 1;
    while (start <= end) {
        int mid = (start + end) / 2;
        if (array[mid] < target)
            start = mid + 1;
        else if (array[mid] >= target)
            end = mid - 1;
    }
    if (end == array.size() - 1)
        return -1;
    return end + 1;
}


int main()
{
    int num = 10000000;
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
