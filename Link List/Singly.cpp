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

    // destructor
    ~Node()
    {
        int val = this->data;
        cout << "Memory is free for node with Data: " << val << endl;
    }
};

void insertAtHead(Node *&head, int data)
{
    // new node create
    Node *temp = new Node(data);
    temp->next = head;
    head = temp;
}
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
void insertAtTail(Node *&tail, int data)
{
    Node *temp = new Node(data);
    tail->next = temp;
    tail = temp;
}
void insertAtPosition(Node *&tail, Node *&head, int pos, int data)
{
    // insert at start
    if (pos == 1)
    {
        insertAtHead(head, data);
        return;
    }
    Node *temp = head;
    int cnt = 1;
    while (cnt < pos - 1)
    {
        temp = temp->next;
        cnt++;
    }

    // insert at end
    if (temp->next == NULL)
    {
        insertAtTail(tail, data);
        return;
    }

    Node *node = new Node(data);
    node->next = temp->next;
    temp->next = node;
}
void deleteNode(Node *&tail, Node *&head, int pos)
{
    if (pos == 1)
    {
        // delete first Node
        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    else
    {
        // delete middle or last node
        Node *curr = head;
        Node *prev = NULL;
        int cnt = 1;
        while (cnt < pos)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        if (curr->next == NULL)
        {
            tail = prev;
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}
int main()
{
    Node *node1 = new Node(10);
    cout << node1->data << endl;
    cout << node1->next << endl;

    Node *head = node1;
    Node *tail = node1;
    print(head);
    insertAtTail(tail, 9);
    print(head);
    insertAtHead(head, 12);
    print(head);
    insertAtPosition(tail, head, 2, 23);
    print(head);
    insertAtPosition(tail, head, 1, 67);
    print(head);

    cout << "Head: " << head->data << endl;
    cout << "tail: " << tail->data << endl;

    deleteNode(tail, head, 2);
    print(head);
    deleteNode(tail, head, 1);
    print(head);
    deleteNode(tail, head, 3);
    print(head);

    cout << "Head: " << head->data << endl;
    cout << "tail: " << tail->data << endl;
    return 0;
}