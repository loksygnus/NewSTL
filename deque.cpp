#include <iostream>
#include <deque>

using namespace std;

int main(int argc, char const *argv[])
{
    cout<<"\nThis is Double ended queue example"<<endl;
    deque <int> dq(10);

    for(size_t i = 0; i < dq.size(); i++)
    {
        dq[i] = i * 10;
        cout<<dq[i]<<endl;
    }
    
    dq.push_back(245);
    dq.push_front(42);

    cout<<"\nNew size of dq "<<dq.size()<<endl;
    for(size_t i = 0; i < dq.size(); i++)
    {
        cout<<dq[i]<<endl;
    }

    return 0;
}
