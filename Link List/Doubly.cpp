#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
    ~Node()
    {
        cout << "Delete node with value: " << this->data << endl;
    }
};
void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int getLength(Node *head)
{
    int len = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    return len;
}
void insertAtHead(Node *&head, Node *&tail, int data)
{
    if (head == NULL)
    {
        Node *temp = new Node(data);
        head = temp;
        tail = temp;
    }
    else
    {
        Node *temp = new Node(data);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}
void insertAtTail(Node *&head, Node *&tail, int data)
{
    if (tail == NULL)
    {
        Node *temp = new Node(data);
        head = temp;
        tail = temp;
    }
    else
    {
        Node *temp = new Node(data);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}
void insertAtPosition(Node *&tail, Node *&head, int pos, int data)
{
    // insert at start
    if (pos == 1)
    {
        insertAtHead(head, tail, data);
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
        insertAtTail(head, tail, data);
        return;
    }

    Node *node = new Node(data);
    node->next = temp->next;
    temp->next->prev = node;
    temp->next = node;
    node->prev = temp;
}
void deleteNode(Node *&tail, Node *&head, int pos)
{
    if (pos == 1)
    {
        // delete first Node
        Node *temp = head;
        temp->next->prev = NULL;
        head = temp->next;
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
        curr->prev = NULL;
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}
int main()
{
    // Node *node1 = new Node(10);
    Node *head = NULL;
    Node *tail = NULL;

    print(head);
    cout << "Length: " << getLength(head) << endl;

    insertAtHead(head, tail, 23);
    print(head);
    insertAtTail(head, tail, 34);
    print(head);

    insertAtPosition(tail, head, 2, 78);
    print(head);

    insertAtPosition(tail, head, 1, 8);
    print(head);

    insertAtPosition(tail, head, 5, 88);
    print(head);

    deleteNode(tail, head, 1);
    print(head);

    deleteNode(tail, head, 4);
    print(head);

    deleteNode(tail, head, 2);
    print(head);
    return 0;
}