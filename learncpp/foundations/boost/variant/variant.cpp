//
// Created by Xiangkui Guo on 2019-04-01.
//

#include <iostream>
#include <boost/variant.hpp>
using namespace std;
using namespace boost;
int main()
{
    variant< int, std::string > v;
    v = "hello";
    std::cout << v << std::endl;

    std::string& str = boost::get<std::string>(v);
    str += " world! ";
    std::cout << v << std::endl;

    return 0;
}