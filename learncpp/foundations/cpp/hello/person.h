#ifndef PERSON_H
#define PERSON_H
#include <iostream>
#include <string>
using namespace std;

struct Node{
    Node* next;
    void* data;
};

class Person
{
public:
    Person();
    void say(string str);
    static void sayhi(string str);
    void operator()(string str);
    void test();
};

#endif // PERSON_H
