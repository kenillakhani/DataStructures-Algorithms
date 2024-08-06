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
    ~Node()
    {
        cout << "Delete node with value: " << this->data << endl;
    }
};
void insertNode(Node *&tail, int data, int ele)
{
    if (tail == NULL)
    {
        Node *node = new Node(data);
        tail = node;
        node->next = node;
    }
    else
    {
        Node *curr = tail;
        while (curr->data != ele)
        {
            curr = curr->next;
        }
        Node *temp = new Node(data);
        temp->next = curr->next;
        curr->next = temp;
    }
}
void print(Node *tail)
{
    Node *temp = tail;
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != tail);

    cout << endl;
}
void deleteNode(Node *&tail, int data)
{
    if (tail == NULL)
    {
        cout << "List is Empty." << endl;
    }
    else
    {
        Node *prev = tail;
        Node *curr = tail->next;

        while (curr->data != data)
        {
            prev = curr;
            curr = curr->next;
        }

        prev->next = curr->next;
        if (curr == prev)
        {
            tail = NULL;
        }
        else if (tail == curr)
        {
            tail = prev;
        }

        curr->next = NULL;
        delete curr;
    }
}
int main()
{
    Node *tail = NULL;
    insertNode(tail, 3, 5);
    print(tail);

    insertNode(tail, 5, 3);
    print(tail);

    insertNode(tail, 7, 5);
    print(tail);

    insertNode(tail, 6, 5);
    print(tail);

    deleteNode(tail, 7);
    print(tail);
    
    return 0;
}