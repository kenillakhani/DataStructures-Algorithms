#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
Node *merge(Node *a, Node *b)
{
    if (a == NULL)
    {
        return b;
    }
    if (b == NULL)
    {
        return a;
    }
    Node *c;
    if (a->data < b->data)
    {
        c = a;
        c->next = merge(a->next, b);
    }
    else
    {
        c = b;
        c->next = merge(a, b->next);
    }
    return c;
}
Node *mergeIterative(Node *a, Node *b)
{
    if (a == NULL)
    {
        return b;
    }
    if (b == NULL)
    {
        return a;
    }

    if (a->data > b->data)
    {
        swap(a, b);
    }

    if(a->next == NULL){
        a->next = b;
        return a;
    }
    Node *curr1 = a;
    Node *next1 = curr1->next;
    Node *curr2 = b;
    Node *next2 = curr2->next;

    while (next1 != NULL && curr2 != NULL)
    {
        if (curr2->data >= curr1->data && curr2->data <= next1->data)
        {
            curr1->next = curr2;
            next2 = curr2->next;
            curr2->next = next1;

            curr1 = curr2;
            curr2 = next2;
        }
        else
        {
            curr1 = next1;
            next1 = next1->next;

            if (next1 == NULL)
            {
                curr1->next = curr2;
                return a;
            }
        }
    }
    return a;
}

int main()
{
    Node *a = new Node(3);
    a->next = new Node(5);
    a->next->next = new Node(7);
    a->next->next->next = new Node(9);


    Node *b = new Node(2);
    b->next = new Node(4);
    b->next->next = new Node(6);
    b->next->next->next = new Node(8);
    b->next->next->next->next = new Node(10);
    b->next->next->next->next->next = new Node(12);



    print(a);
    print(b);

    Node *c = mergeIterative(a, b);

    print(c);

    return 0;
}