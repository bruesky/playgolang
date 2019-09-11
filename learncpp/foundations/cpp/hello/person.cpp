#include "person.h"

Person::Person()
{

}

void Person::say(string str){
    cout<<str<<endl;
}

void Person::sayhi(string str){
    cout<<str<<endl;
}

void Person::operator()(string str){
    cout<<str<<endl;
}

void Person::test(){
    std::cout << "Hello, World!" << std::endl;
        Node* head = nullptr;
        Node* now = nullptr;
        int i = 0;
        while (i < 999){
            Node* node = new Node;
            node->next = nullptr;
            node->data = new int(i);
            if(head == nullptr){
                head = node;
            } else{
                now->next = node;
            }
            now = node;
            i++;
        }

        cout<<"after init linked list"<<endl;
        Node* temp = head;
        while(temp){
            cout<< *(int*)temp->data<<endl;
            temp = temp->next;
        }

        // reverse logic
        Node* before = nullptr;
        Node* nowNode = head;
        Node* next = nullptr;
        while (nowNode){
            next = nowNode->next;
            nowNode->next = before;
            before = nowNode;
            nowNode = next;
        }
        head = before;
        cout<<"after reverse linked list"<<endl;
        temp = head;
        while(temp){
            cout<< *(int*)temp->data<<endl;
            temp = temp->next;
        }

}
