//
// Created by Xiangkui Guo on 2019-06-01.
//

#include <vector>
#include <string>
#include <queue>
#include <unordered_map>
using namespace std;

vector<string> topKFrequent(vector<string>& words, int k) {
    unordered_map<string,int> map;
    for(auto& word:words){
        if(map.find(word)==map.end()){
            map[word] = 1;
        } else
            map[word] += 1;

    }

    auto cmp = [&](string left, string right) {
        if(map[left] == map[right])
            return left>right;
        return map[left] < map[right];
    };
    priority_queue<string, vector<string>, decltype(cmp)> q(cmp);

    for(auto it = map.begin(); it!=map.end();it++){
        q.push(it->first);
    }

    vector<string> ret;
    for (int i = 0; i < k; ++i) {
        ret.push_back(q.top());
        q.pop();
    }
    return ret;
}