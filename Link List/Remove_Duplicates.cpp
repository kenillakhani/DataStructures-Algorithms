#include <iostream>
#include <map>
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

Node *sorted(Node *&head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    Node *curr = head;
    while (curr != NULL && curr->next != NULL)
    {
        if (curr->data == curr->next->data)
        {
            Node *temp = curr->next;
            curr->next = temp->next;
            delete temp;
        }
        else
        {
            curr = curr->next;
        }
    }
    return head;
}
Node *unsorted(Node *&head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    map<int, bool> visited;
    Node *curr = head;
    Node *prev = NULL;
    while (curr != NULL)
    {
        if (visited[curr->data])
        {

            Node *temp = curr;
            prev->next = curr->next;
            curr = temp->next;
            delete temp;
        }
        else
        {
            visited[curr->data] = true;
            prev = curr;
            curr = curr->next;
        }
    }
    return head;
}
int main()
{
    Node *head = new Node(50);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(50);
    head->next->next->next->next = new Node(40);
    head->next->next->next->next->next = new Node(50);
    head->next->next->next->next->next->next = new Node(10);

    cout << "Original Linked List:" << endl;
    print(head);

    // sorted(head);
    unsorted(head);
    cout << "Linked List after removing duplicates:" << endl;
    print(head);

    return 0;
}
