#include <iostream>
#include <queue>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *rigth;

    node(int val)
    {
        data = val;
        left = NULL;
        rigth = NULL;
    }
};
node *buildTree(node *root)
{
    int data;
    cout << "Enter data: " << endl;
    cin >> data;
    if (data == -1)
    {
        return NULL;
    }

    root = new node(data);
    cout << "Enter the data for left child: " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter the data for right child: " << data << endl;
    root->rigth = buildTree(root->rigth);
    return root;
}
void levelOrderTraversal(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
    
        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";

            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->rigth)
            {
                q.push(temp->rigth);
            }
        }
    }
}
void countLeaf(node* root,int& count)
{
    if(root==NULL)
    {
        return;
    }
    countLeaf(root->left,count);
    if(root->left == NULL && root->rigth == NULL)
        count++;
    countLeaf(root->rigth,count);

}
void inorder(node* root)
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->rigth);
}
void preorder(node* root)
{
    if(root==NULL)
    {
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->rigth);
}
void postorder(node* root)
{
    if(root==NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->rigth);
    cout<<root->data<<" ";
}
node* buildFromLevelOrder(node* root)
{
    queue<node*> q;
    cout<<"Enter the data for root: "<<endl;
    int data;
    cin>>data;
    if(data==-1)
    {
        return NULL;
    }
    root = new node(data);
    q.push(root);

    while(!q.empty())
    {
        node* temp = q.front();
        q.pop();

        cout<<"Enter the data for left child of: "<<temp->data<<endl;
        int leftdata;
        cin>>leftdata;
        if(data!=-1)
        {
            temp->left = new node(data);
            q.push(temp->left);
        }

        cout<<"Enter the data for right child of: "<<temp->data<<endl;
        int rightdata;
        cin>>rightdata;
        if(data!=-1)
        {
            temp->rigth = new node(data);
            q.push(temp->rigth);
        }
    }
}
int main()
{
    node *root = NULL;

    //  1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1
    // root = buildFromLevelOrder(root);

    root = buildTree(root);

    cout << "Level Order Traversal: " << endl;
    levelOrderTraversal(root);
    cout<<endl;
    cout << "Inorder Traversal: " << endl;
    inorder(root);
    cout<<endl;
    cout << "Preorder Traversal: " << endl;
    preorder(root);
    cout<<endl;
    cout << "Postorder Traversal: " << endl;
    postorder(root);
    cout<<endl;
    cout<<endl;

    int cnt=0;
    countLeaf(root,cnt);
    cout<<"Total leafnode: "<<cnt<<endl;
    cout << endl;
    return 0;
}