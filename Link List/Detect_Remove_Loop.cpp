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

bool detectLoop(Node *&head)
{
    if (head == NULL || head->next == NULL)
    {
        return false;
    }

    map<Node *, bool> visited;
    Node *temp = head;

    while (temp != NULL)
    {
        if (visited[temp])
        {
            return true;
        }

        visited[temp] = true;
        temp = temp->next;
    }

    return false;
}
Node *floyedDetect(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }

    Node *slow = head;
    Node *fast = head;

    while (fast != NULL && slow != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
        }

        slow = slow->next;

        if (slow == fast)
        {
            return slow;
        }
    }
    return NULL;
}
Node *getStartingNode(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }

    Node *slow = head;
    Node *intersaction = floyedDetect(head);

    while (slow != intersaction)
    {
        slow = slow->next;
        intersaction = intersaction->next;
    }
    return slow;
}

void removeLoop(Node *head)
{
    if (head == NULL)
    {
        return;
    }

    Node *startingNode = getStartingNode(head);

    if (startingNode == NULL)
    {
        return;
    }

    Node *temp = startingNode;
    while (temp->next != startingNode)
    {
        temp = temp->next;
    }
    temp->next = NULL;
}
int main()
{
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(50);
    print(head);
    head->next->next->next->next->next = head->next->next;

    if (detectLoop(head))
        cout << "Loop Found" << endl;
    else
        cout << "No Loop Found" << endl;

    Node *startingNode = getStartingNode(head);
    if (startingNode != NULL)
    {
        cout << "Starting Node of Loop: " << startingNode->data << endl;
    }
    else
    {
        cout << "No Loop Found" << endl;
    }

    removeLoop(head);
    if (detectLoop(head))
        cout << "Loop Found" << endl;
    else
        cout << "No Loop Found" << endl;
    return 0;
}
