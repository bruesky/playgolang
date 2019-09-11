//
// Created by Xiangkui Guo on 2019-01-08.
//

#include "stuct.h"
//struct init

int structtest(){
    st1 s1 = {"Xxxxx"};
    st1 s2{"Qqqqq"};
    cout<< s1.name << " "<< s2.name <<endl;
    st2 ss1 = {.name = "Hhhhh",.age = 9};
    st2 ss2 = {name : "Ddddd", age : 88};
    cout<< ss1.name << " "<< ss1.age<<endl;
    cout<< ss2.name << " "<< ss2.name<<endl;
    st2 ss3{"Jjjj",56};
    cout<< ss3.name << " "<< ss3.name<<endl;

    return 0;
}
