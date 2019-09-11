//
// Created by Xiangkui Guo on 2018-12-29.
//

#include <iostream>
using namespace std;
template<class T> T add(T &a,T &b)
{
    T result = a+b;
    return result;

}

template<class X,class Y> void fun(X a,Y b)
{
    std::cout << "Value of a is : " <<a<< std::endl;
    std::cout << "Value of b is : " <<b<< std::endl;
}

template<class X> void fun(X a)
{
    std::cout << "Value of a is : " <<a<< std::endl;
}

template<class T1, class T2>
class A
{
    T1 a;
    T2 b;
public:
    A(T1 x,T2 y)
    {
        a = x;
        b = y;
    }
    void display()
    {
        std::cout << "Values of a and b are : " << a<<" ,"<<b<<std::endl;
    }
};


template<class T>
class Base{
private:
    static int count;
protected:
    Base() {
        ++Base<T>::count;
    }
    Base(Base<T> const&) {
        ++Base<T>::count;
    }
    ~Base() {
        --Base<T>::count;
    }

public:
    static int liveCount() {
        return Base<T>::count;
    }

public:
    virtual void haha(){
        cout<<"Base Haha "<<endl;
    }
};

template<class T>
int Base<T>::count = 0;

template<class T>
class D : public Base<D<T>>{
public:
    virtual void haha(){
        cout<<"D Haha "<<endl;
    }
};



int main()
{
    int i =2;
    int j =3;
    float m = 2.3;
    float n = 1.2;
    cout<<"Addition of i and j is :"<<add(i,j);
    cout<<'\n';
    cout<<"Addition of m and n is :"<<add(m,n);
    cout<<'\n';

    fun(15,12.3);
    fun(11);

    A<int,float> d(5,6.5);
    d.display();

    cout<<"The count of D<int> is "<< D<int>::liveCount()<<endl;
    D<int>* pD = new D<int>();
    pD->haha();
    cout<<"The count of D<int> is "<< D<int>::liveCount()<<endl;
    Base<D<float>>* pB = new D<float>();
    pB->haha();
    cout<<"The count of D<float> is "<< D<float>::liveCount()<<endl;

    return 0;
}