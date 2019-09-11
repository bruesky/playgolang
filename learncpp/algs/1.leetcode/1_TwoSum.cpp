//
// Created by Xiangkui Guo on 2019-02-19.
//

#include <iostream>
#include <vector>
using namespace std;

//1. Two Sum
vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> ret{0,0};
    vector<int> temp = nums;
    sort(temp.begin(),temp.end());
    unsigned int l = 0, r = nums.size()-1;
    while (l<r){
        if(temp[l]+temp[r]<target)
            ++l;
        else if(temp[l]+temp[r]>target)
            --r;
        else
            break;
    }

    int i;
    for (i = 0; i < nums.size(); ++i) {
        if(nums[i]==temp[l]||nums[i]==temp[r]){
            ret[0] = i;
            break;
        }
    }

    for (i = nums.size()-1; i >=0 ; --i) {
        if(nums[i]==temp[l]||nums[i]==temp[r]){
            ret[1] =i;
            break;
        }
    }

    return ret;
}

void twoSumTest(){
    vector<int> nums{2, 7, 11, 15};
    vector<int> ret = twoSum(nums,9);
    for(auto&index:ret)
        cout<<index<<endl;
}

