//
// Created by Xiangkui Guo on 2018-12-29.
//

#include "ioexample.h"

#include <fstream>
#include <iostream>
using namespace std;

void iotest () {
    char input[75];
    ofstream os;
    os.open("testout.txt");
    cout <<"Writing to a text file:" << endl;
    cout << "Please Enter your name: ";
    cin.getline(input, 100);
    os << input << endl;
    cout << "Please Enter your age: ";
    cin >> input;
    cin.ignore();
    os << input << endl;
    os.close();
    ifstream is;
    string line;
    is.open("testout.txt");
    cout << "Reading from a text file:" << endl;
    while (getline (is,line))
    {
        cout << line << endl;
    }
    is.close();
}
