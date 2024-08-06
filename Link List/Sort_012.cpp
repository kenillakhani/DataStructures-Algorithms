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
Node *sortt(Node *head)
{
    int zeros = 0, ones = 0, twos = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == 0)
        {
            zeros++;
        }
        else if (temp->data == 1)
        {
            ones++;
        }
        else
        {
            twos++;
        }
        temp = temp->next;
    }

    temp = head;
    while (temp != NULL)
    {
        if (zeros > 0)
        {
            temp->data = 0;
            zeros--;
        }
        else if (ones > 0)
        {
            temp->data = 1;
            ones--;
        }
        else
        {
            temp->data = 2;
            twos--;
        }
        temp = temp->next;
    }
    return head;
}
Node *sorttt(Node *head)
{
    Node *zerohead = new Node(-1);
    Node *zerotail = zerohead;
    Node *onehead = new Node(-1);
    Node *onetail = onehead;
    Node *twohead = new Node(-1);
    Node *twotail = twohead;

    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == 0)
        {
            zerotail->next = temp;
            zerotail = zerotail->next;
        }
        else if (temp->data == 1)
        {
            onetail->next = temp;
            onetail = onetail->next;
        }
        else
        {
            twotail->next = temp;
            twotail = twotail->next;
        }
        temp = temp->next;
    }

    zerotail->next = (onehead->next) ? onehead->next : twohead->next;
    onetail->next = twohead->next;
    twohead->next = NULL;

    head = zerohead->next;

    delete zerohead;
    delete onehead;
    delete twohead;

    return head;
}

int main()
{
    Node *head = new Node(1);
    head->next = new Node(0);
    head->next->next = new Node(0);
    head->next->next->next = new Node(2);
    head->next->next->next->next = new Node(1);
    head->next->next->next->next->next = new Node(2);
    head->next->next->next->next->next->next = new Node(1);
    head->next->next->next->next->next->next->next = new Node(0);
    head->next->next->next->next->next->next->next->next = new Node(2);
    print(head);

    // head = sortt(head);
    head = sorttt(head);
    print(head);

    return 0;
}