//
// Created by Xiangkui Guo on 2019-05-31.
//


// Definition for a Node.
#include <unordered_map>
#include <queue>
#include <vector>

using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    Node* cloneGraph(Node* node) {
        unordered_map<Node*,Node*>* map = new unordered_map<Node*,Node*>();
        queue<Node*>* q = new queue<Node*>();
        q->push(node);
        map->insert(make_pair(node,new Node(node->val,vector<Node*>())));
        while (!q->empty()){
            Node* h = q->front();
            q->pop();
            for (auto neighbor : h->neighbors) {
                if(map->find(neighbor)==map->end()){
                    map->insert(make_pair(neighbor,new Node(neighbor->val,vector<Node*>())));
                    q->push(neighbor);
                }
                map->at(h)->neighbors.push_back(map->at(neighbor));
            }
        }
        return  map->at(node);
    }
};

