//
// Created by Xiangkui Guo on 2019-06-01.
//

#include <vector>

using namespace std;

void sortColors(vector<int>& nums) {
    int l = -1;
    int r = nums.size();
    int cur = 0;

    while (cur<r){
        if(nums[cur]<1){
            swap(nums[++l],nums[cur++]);
        } else if(nums[cur]>1){
            swap(nums[--r],nums[cur]);
        } else{
            cur++;
        }
    }
}
