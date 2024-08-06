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
bool checkPalindrome(vector<int> arr)
{
    int start = 0;
    int end = arr.size() - 1;
    while (start < end)
    {
        if (arr[start] != arr[end])
        {
            return false;
        }
        start++;
        end--;
    }
    return true;
}
bool isPaloindrom(Node *head)
{
    vector<int> arr;
    Node *temp = head;
    while (temp != NULL)
    {
        arr.push_back(temp->data);
        temp = temp->next;
    }
    return checkPalindrome(arr);
}
Node *getMid(Node *head)
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

Node *reverse(Node *head)
{
    Node *prev = NULL;
    Node *curr = head;
    Node *next = NULL;
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
bool isPaloindrom2(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return true;
    }

    Node *mid = getMid(head);

    Node *temp = mid->next;
    mid->next = reverse(temp);

    Node *temp1 = head;
    Node *temp2 = mid->next;
    bool flag = true;
    while (temp2 != NULL)
    {
        if (temp1->data != temp2->data)
        {
            flag = false;
            break;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    mid->next = reverse(mid->next);
    return flag;
}

int main()
{
    Node *head = new Node(1);
    head->next = new Node(6);
    head->next->next = new Node(11);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(4);
    head->next->next->next->next->next = new Node(11);
    head->next->next->next->next->next->next = new Node(6);
    head->next->next->next->next->next->next->next = new Node(1);

    print(head);
    if (isPaloindrom2(head))
    {
        cout << "Paloindrom" << endl;
    }
    else
    {
        cout << "Not Paloindrom" << endl;
    }

    return 0;
}