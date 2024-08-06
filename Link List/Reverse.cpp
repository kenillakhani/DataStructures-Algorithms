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

Node *reverse(Node *& head)
{

    if(head == NULL || head->next == NULL){
        return head;
    }

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

void recursion(Node *&head, Node *prev, Node *curr)
{
    if (curr == NULL)
    {
        head = prev;
        return;
    }
    Node *next = curr->next;
    curr->next = prev;
    recursion(head, curr, next);
}
Node * reverseRecursion(Node *&head){
    Node *prev = NULL;
    Node *curr = head;
    recursion(head, prev, curr);
    return head;
}

Node* reverseRecursion2(Node *head)
{
    if(head == NULL || head->next == NULL)
    {
        return head;
    }

    Node *chotaHead = reverseRecursion2(head->next);
    head->next->next = head;
    head->next = NULL;

    return chotaHead;
}

int main()
{
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    print(head);

    head = reverse(head);
    print(head);

    // Using Recursion
    head = reverseRecursion(head);
    print(head);

    head = reverseRecursion2(head);
    print(head);

    return 0;
}