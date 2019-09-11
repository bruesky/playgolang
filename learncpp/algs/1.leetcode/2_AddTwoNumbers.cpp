//
// Created by Xiangkui Guo on 2019-02-19.
//

#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* head = nullptr;
    ListNode* ret = nullptr;
    int temp = 0;
    int l1v = 0;
    int l2v = 0;
    while(l1||l2||temp!=0){
        l1v = 0;
        l2v = 0;
        if(l1){
            l1v = l1->val;
            l1 = l1->next;
        }

        if(l2){
            l2v = l2->val;
            l2 = l2->next;
        }

        temp = l1v+l2v+temp;

        if(head){
            head->next = new ListNode(temp%10);
            head = head->next;
        }
        else{
            head = new ListNode(temp%10);
            ret = head;
        }
        temp/=10;
    }
    return ret;
}

void addTwoNumbersTest(){
//    Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
//    Output: 7 -> 0 -> 8
//    Explanation: 342 + 465 = 807.
//
    ListNode* l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    ListNode* ret = addTwoNumbers(l1,l2);
    while(ret){
        cout<<ret->val<<endl;
        ret = ret->next;
    }
}

