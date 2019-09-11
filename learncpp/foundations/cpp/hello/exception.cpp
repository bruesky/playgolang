//
// Created by Xiangkui Guo on 2018-12-29.
//

#include <iostream>
using namespace std;
float division(int x, int y) {
    if( y == 0 ) {
        throw "Attempted to divide by zero!";
    }
    return (x/y);
}

void test1()
{
    try
    {
        char* p = new char[0x7ffffffffffff];  //抛出异常
    }
    catch (exception e)
    {
        cout << e.what() << endl;   //捕获异常，然后程序结束
    }

}

void test2()
{
    int i = 25;
    int j = 0;
    float k = 0;
    try {
        k = division(i, j);
        cout << k << endl;
    }catch (const char* e) {
        cerr << e << endl;
    }

}

union {
    int number;
    char s;
} testUnion;

void test(){
    testUnion.number = 0x12345678;


    char* p = (char*)&testUnion.number;
    printf("%X\n",*(p));
    printf("%X\n",*(p+1));
    printf("%X\n",*(p+2));
    printf("%X\n",*(p+3));
    if(testUnion.s == 0x12){
        printf("big endian\n");
    }else{
        printf("little endian\n");
    }
}

void exceptiontest () {
    test();
}