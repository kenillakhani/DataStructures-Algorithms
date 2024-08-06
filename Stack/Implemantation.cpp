#include <iostream>
using namespace std;
class Stack
{
public:
    int *arr;
    int top;
    int size;

    Stack(int size)
    {
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int val)
    {
        if (top == size - 1)
        {
            cout << "Stack Overflow" << endl;
            return;
        }
        top++;
        arr[top] = val;
    }

    int pop()
    {
        if (top == -1)
        {
            cout << "Stack Underflow" << endl;
            return -1;
        }
        int val = arr[top];
        top--;
        return val;
    }

    int peek()
    {
        if (top == -1)
        {
            cout << "Stack is Empty" << endl;
            return -1;
        }
        return arr[top];
    }

    bool isEmpty()
    {
        return top == -1;
    }
};
int main()
{
    Stack st(5);

    st.push(22);
    st.push(43);
    st.push(54);

    cout << st.pop() << endl;
    cout << st.peek() << endl;

    if(st.isEmpty())
    {
        cout<<"Stack is Empty."<<endl;
    }
    else
    {
        cout<<"Stack is not Empty."<<endl;
    }
    return 0;
}