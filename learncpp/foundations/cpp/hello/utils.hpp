//
// Created by Xiangkui Guo on 2018/12/12.
//

#ifndef PAT_UTILS_H
#define PAT_UTILS_H

#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>

using namespace std;

namespace utils{
    typedef std::function<void(vector<int>&)> funcType;

    void swap(vector<int>& vec,int i , int j){
        int temp = vec[i];
        vec[i] = vec[j];
        vec[j] = temp;
    }

    vector<int> generateRandomArray(int maxSize, int maxValue){
        vector<int> vec;
        srand(time(nullptr));
        int num = rand()%maxSize+1;
        for (int i = 0; i < num; ++i) {
            vec.push_back(rand()%(2*maxValue+1)-maxValue);
        }
        return vec;
    }

    vector<int> copyArray(vector<int> src){
        vector<int> vec;
        for (auto num : src) {
            vec.push_back(num);
        }
        return vec;
    }

    void verify(funcType fun){
        bool bPass = true;
        for (int j = 0; j < 100; ++j) {
            auto vec = generateRandomArray(100,200);
            auto vec2 = copyArray(vec);
            sort(vec.begin(),vec.end());
            fun(vec2);

            for (int i = 0; i < vec.size(); ++i) {
                if (vec[i]!=vec2[i]){
                    bPass = false;
                    break;
                }
            }

            if(!bPass)
                break;

        }

        auto vec = generateRandomArray(100,200);
        fun(vec);
        for (auto&num:vec) {
            cout<<num<<" ";
        }
        cout<<endl;
        string outStr = bPass?"Sort Suc !!!":"Sort Fail !!!";
        cout<< outStr << endl;
    }

}


#endif //PAT_UTILS_H
