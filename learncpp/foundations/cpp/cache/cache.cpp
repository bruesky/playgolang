//
// Created by Xiangkui Guo on 9/7/19.
//



#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
using namespace std;

struct Node{
    Node* next;
    Node* prev;
    int value;
    int key;
    Node(Node* p, Node* n, int k, int val):prev(p),next(n),key(k),value(val){};
    Node(int k, int val):prev(NULL),next(NULL),key(k),value(val){};
};

class Cache{

protected:
    map<int,Node*> mp; //map the key to the node in the linked list
    int cp;  //capacity
    Node* tail; // double linked list tail pointer
    Node* head; // double linked list head pointer
    virtual void set(int, int) = 0; //set function
    virtual int get(int) = 0; //get function

};

class LRUCache : public Cache{
public:
    int count;
    LRUCache(int capacity){
        this->cp = capacity;
        tail = new Node(-1,-1);
        head = new Node(nullptr,tail,-1,-1);
        tail->prev = head;
        count = 0;
    }

    virtual void set(int k, int v){
        auto ret = mp.find(k);
        if(ret==mp.end()){
            if(count<cp){
                count++;
                auto newNode = new Node(k,v);
                newNode->prev = head;
                newNode->next = head->next;
                head->next->prev = newNode;
                head->next = newNode;
                mp.insert(make_pair(k,newNode));
            } else{
                auto nowNode = tail->prev;
                mp.erase(nowNode->key);
                nowNode->key = k;
                nowNode->value = v;
                mp.insert(make_pair(k,nowNode));
                nowNode->prev->next = nowNode->next;
                nowNode->next->prev = nowNode->prev;
                nowNode->prev = head;
                nowNode->next = head->next;
                head->next->prev = nowNode;
                head->next = nowNode;
            }

        } else{
            auto nowNode = ret->second;
            nowNode->value = v;
            nowNode->prev->next = nowNode->next;
            nowNode->next->prev = nowNode->prev;
            nowNode->prev = head;
            nowNode->next = head->next;
            head->next->prev = nowNode;
            head->next = nowNode;
        }
    }
    virtual int get(int k){
        auto ret = mp.find(k);
        if(ret!=mp.end())
            return ret->second->value;
        else
            return -1;
    }
};


int main() {
    int n, capacity,i;
    cin >> n >> capacity;
    LRUCache l(capacity);
    for(i=0;i<n;i++) {
        string command;
        cin >> command;
        if(command == "get") {
            int key;
            cin >> key;
            cout << l.get(key) << endl;
        }
        else if(command == "set") {
            int key, value;
            cin >> key >> value;
            l.set(key,value);
        }
    }
    return 0;
}
