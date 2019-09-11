#include <iostream>
#include "utils.hpp"
using namespace std;
extern void hello();
extern void lltest();
extern void iotest();

void bubbleSort(vector<int>& vec){
    if(vec.size()<2)
        return;
    int temp;
    for (int e = vec.size()-1; e > 0; --e) {
        for (int i = 0; i < e; ++i) {
            if(vec[i] > vec[i+1]){
//                temp = vec[i];
//                vec[i] = vec[i+1];
//                vec[i+1] = temp;
                utils::swap(vec,i,i+1);
            }
        }
    }
}



int main()
{
    utils::verify(bubbleSort);

//    hello();
//    iotest();
    return 0;
}
