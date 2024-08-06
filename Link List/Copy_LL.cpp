#include <iostream>
#include <map>

using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *random;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->random = NULL;
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
Node *copyList(Node *head)
{
    Node *cloneHead = NULL;
    Node *cloneTail = NULL;

    Node *temp = head;
    while (temp != NULL)
    {
        insertAtTail(cloneHead, cloneTail, temp->data);
        temp = temp->next;
    }

    unordered_map<Node *, Node *> oldToNew;

    Node *original = head;
    Node *clone = cloneHead;
    while (original != NULL)
    {
        oldToNew[original] = clone;
        original = original->next;
        clone = clone->next;
    }

    original = head;
    clone = cloneHead;

    while (original != NULL)
    {
        clone->random = oldToNew[original->random];
        original = original->next;
        clone = clone->next;
    }
    return cloneHead;
}
Node *copyList2(Node *head)
{
    Node *cloneHead = NULL;
    Node *cloneTail = NULL;

    Node *temp = head;
    while (temp != NULL)
    {
        insertAtTail(cloneHead, cloneTail, temp->data);
        temp = temp->next;
    }

    Node *original = head;
    Node *clone = cloneHead;

    while (original != NULL)
    {
        Node *temp = original->next;
        original->next = clone;
        original = temp;

        temp = clone->next;
        clone->next = original;
        clone = temp;
    }

    temp = head;
    while (temp != NULL)
    {
        if (temp->next != NULL)
        {
            temp->next->random = temp->random ? temp->random->next : temp->random;
        }
        temp = temp->next->next;
    }

    original = head;
    clone = head->next;

    while (original != NULL && clone != NULL)
    {

        original->next = clone->next;
        original = original->next;

        if (original != NULL)
        {
            clone->next = original->next;
        }
        clone = clone->next;
    }

    return cloneHead;
}
int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    head->random = head->next->next;
    head->next->random = head;
    head->next->next->random = head->next->next->next->next;
    head->next->next->next->random = head->next->next;
    head->next->next->next->next->random = head->next;
    print(head);

    // Node *clone = copyList(head);
    Node *clone = copyList2(head);
    print(clone);

    return 0;
}