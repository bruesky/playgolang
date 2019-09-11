//
// Created by Xiangkui Guo on 2019-06-01.
//
#include <vector>
using namespace std;

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int >> ret;
    ret.push_back({});
    for (int i = 0; i < nums.size(); ++i) {
        int oldSize = ret.size();
        for (int j = 0; j < oldSize; ++j) {
            auto newVec = ret[j];
            newVec.push_back(nums[i]);
            ret.push_back(ret[j]);
        }
    }
    return ret;
}


void subsetsTest(){
    vector<int> nums = {1,2,3};
    subsets(nums);
}

