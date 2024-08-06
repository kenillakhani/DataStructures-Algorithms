#include<iostream>
#include<queue>
using namespace std;
int main()
{
    deque<int> q;

    q.push_back(10);
    q.push_back(20);
    q.push_front(30);
    
    cout<<q.front()<<endl;
    cout<<q.back()<<endl;

    q.pop_front();
    cout<<"After pop front: "<<q.front()<<endl;
    q.pop_back();
    cout<<"After pop back: "<<q.back()<<endl;

    return 0;
}