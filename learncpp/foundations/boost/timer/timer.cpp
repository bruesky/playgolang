//
// Created by Xiangkui Guo on 2019-02-13.
//

#include <iostream>
#include <boost/timer.hpp>
using namespace std;
using namespace boost;
int main()
{
    timer t;
    cout << "max timespan:"
        << t.elapsed_max()/3600 << "h"<<endl;

    cout << "min timespan:"
         << t.elapsed_min() << "s"<<endl;

    cout << "now time elapsed:"
         << t.elapsed() << "s"<<endl;

    return 0;
}