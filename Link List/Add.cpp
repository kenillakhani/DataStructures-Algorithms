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
Node *reverse(Node *head)
{
    Node *prev = NULL;
    Node *curr = head;
    Node *next;
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
void insertAtTail(Node *&head, Node *&tail, int val)
{
    Node *temp = new Node(val);
    if (head == NULL)
    {
        head = temp;
        tail = temp;
    }
    else
    {
        tail->next = temp;
        tail = temp;
    }
}
Node *add(Node *a, Node *b)
{
    int carry = 0;
    Node *ansHead = NULL;
    Node *ansTail = NULL;

    while(a!=NULL || b!=NULL || carry!=0){
        int val1 = 0;
        if(a!=NULL){
            val1 = a->data;
            a = a->next;
        }
        int val2 = 0;
        if(b!=NULL){
            val2 = b->data;
            b = b->next;
        }
        int sum = val1 + val2 + carry;
        int digit = sum % 10;

        insertAtTail(ansHead, ansTail, digit);
        carry = sum / 10;

    }

    return ansHead;
}
Node *addTwo(Node *a, Node *b)
{
    a = reverse(a);
    b = reverse(b);

    Node *ans = add(a, b);

    ans = reverse(ans);
    return ans;
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

    cout<<"One:";
    print(a);
    cout<<"Two: ";
    print(b);

    Node *c = addTwo(a, b);

    cout<<"ANS: ";
    print(c);

    return 0;
}