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
Node *findMid(Node *head)
{
    Node *slow = head;
    Node *fast = head->next;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
Node *merge(Node *left, Node *right)
{
    if (left == NULL)
    {
        return right;
    }
    if (right == NULL)
    {
        return left;
    }

    Node *ans = new Node(-1);
    Node *temp = ans;
    while (left != NULL && right != NULL)
    {
        if (left->data < right->data)
        {
            temp->next = left;
            temp = left;
            left = left->next;
        }
        else
        {
            temp->next = right;
            temp = right;
            right = right->next;
        }
    }
    if (left != NULL)
    {
        temp->next = left;
        temp = left;
        left = left->next;
    }
    if (right != NULL)
    {
        temp->next = right;
        temp = right;
        right = right->next;
    }

    return ans->next; // Return head node of the merged linked list.
}
Node *mergeSort(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    Node *mid = findMid(head);

    Node *left = head;
    Node *right = mid->next;
    mid->next = NULL;

    left = mergeSort(left);
    right = mergeSort(right);

    return merge(left, right);
}

int main()
{
    Node *head = new Node(10);
    head->next = new Node(32);
    head->next->next = new Node(12);
    head->next->next->next = new Node(4);
    print(head);

    Node* ans = mergeSort(head);
    print(ans);

    return 0;
}