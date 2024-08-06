#include<iostream>
using namespace std;
class TwoStack
{
    public:
        int *arr;
        int size;
        int top1;
        int top2;

        TwoStack(int size)
        {
            this->size = size;
            arr = new int[size];
            top1 = -1;
            top2 = size;

        }

        void push1(int val)
        {
            if(top1 < top2 - 1)
            {
                top1++;
                arr[top1] = val;
            }
            else
            {
                cout<<"Stack Overflow"<<endl;
            }
        }
        int pop1()
        {
            if(top1 >= 0)
            {
                int val = arr[top1];
                top1--;
                return val;
            }
            else
            {
                cout<<"Stack Underflow"<<endl;
            }
        }

        void push2(int val)
        {
            if(top1 < top2 - 1)
            {
                top2--;
                arr[top2] = val;
            }
            else
            {
                cout<<"Stack Overflow"<<endl;
            }
        }

        int pop2()
        {
            if(top2 < size)
            {
                int val = arr[top2];
                top2++;
                return val;
            }
            else
            {
                cout<<"Stack Underflow"<<endl;
            }
        }
};
int main()
{
    TwoStack st(5);

    st.push1(22);
    st.push1(43);
    st.push2(54);

    cout<<st.pop1()<<endl;
    cout<<st.pop2()<<endl;
    
    return 0;
}