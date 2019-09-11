#include <iostream>
#include<string>
#include <functional>
#include "person.h"

using namespace std;

void haha(string str){
    cout<<str<<endl;
}

void hello(){
    typedef std::function<void(string)> Func;
    Person p;
    p.test();
    Func f = std::bind(&Person::say, &p, std::placeholders::_1);
    f("hello");
    f = std::bind(&Person::sayhi, std::placeholders::_1);
    f("say hi");
    f = Person();
    f("Person");
    f = haha;
    f("haha");
    f = &haha;
    f("haha2");
    f = [](string str){
        cout<<str<<endl;
    };
    f("lambda");

}
