#include <iostream>
using namespace std;

/*
int add (int a, int b)
{
    return a + b;
}

float add (float a, float b)
{
    return a + b;
}

template <typename T>
T add(T a, T b)
{
    return a+b;
}*/

template <class T>

class test
{
private:
    /* data */
public:
    T a[2];
    T add();
    test(T x, T y);
    ~test();
};

template <class T>
test<T>::test(T x, T y)
{
    a[0] = x;
    a[1] = y;
}

template <class T>
test<T>::~test()
{
}

template <class T>
T test<T>::add()
{
    return a[0] + a[1]; 
}


int main(int argc, char const *argv[])
{
/*    int a=15, b=7;
    float u=3.5, v=6.4;
    cout <<"int add:"<<add<int>(a, b)<< "float add:"<<add<float>(u, v) << endl; */
    cout <<"\nHellow World\n"<<endl;
    test<int> test_obj(49, 32);
    test<float> test_objflt(23.45, 56.78);

    cout <<"\nint add "<< test_obj.add()<<endl;
    cout <<"\nfloat add "<<test_objflt.add()<<endl;

    return 0;
}
