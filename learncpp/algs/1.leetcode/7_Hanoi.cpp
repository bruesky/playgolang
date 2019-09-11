//
// Created by Xiangkui Guo on 2019-06-04.
//

#include "Common.h"
void hanoi(int num, string from,string to, string help){
    if (1==num)
        cout<<"move 1 from "<<from<<" to "<<to<<endl;
    else{
        hanoi(num-1,from,help,to);
        cout<<"move "<<num <<" from "<<from<<" to "<<to<<endl;
        hanoi(num-1,help,to,from);
    }

}

void testHanoi(){
    hanoi(3,"left","right","mid");
}