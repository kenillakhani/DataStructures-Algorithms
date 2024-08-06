#include<iostream>
#include<queue>

using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
Node* insertIntoBST(Node* root,int data)
{
    if(root == NULL)
    {
        root = new Node(data);
        return root;
    }
    if(data <= root->data)
    {
        root->left = insertIntoBST(root->left,data);
    }
    else
    {
        root->right = insertIntoBST(root->right,data);
    }
    return root;

}
void levelOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();
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
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}
void inorder(Node* root)
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void preorder(Node* root)
{
    if(root==NULL)
    {
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(Node* root)
{
    if(root==NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
void takeInput(Node* &root)
{
    int data;
    cin>>data;

    while(data != -1)
    {
        root = insertIntoBST(root,data);
        cin>>data;
    }
}
Node* minVal(Node* root)
{
    Node* temp = root;
    while(temp->left != NULL)
    {
        temp = temp->left;
    }   
    return temp;
}
Node* maxVal(Node* root)
{
    Node* temp = root;
    while(temp->right != NULL)
    {
        temp = temp->right;
    }   
    return temp;
}
Node* deletefromBST(Node* root,int val)
{
    if(root == NULL)
    {
        return root;
    }
    if(val < root->data)
    {
        root->left = deletefromBST(root->left,val);
        return root;
    }
    else if(val > root->data)
    {
        root->right = deletefromBST(root->right,val);
        return root;
    }
    else
    {
        if(root->left == NULL)
        {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if(root->right == NULL)
        {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        Node* temp = minVal(root->right);
        root->data = temp->data;
        root->right = deletefromBST(root->right,temp->data);
        return root;
    }
}
int main()
{
    Node * root = NULL;

    cout<<"Enter data to create BST: ";
    takeInput(root);

    cout<<"Level Order Traversal of BST: "<<endl;
    levelOrderTraversal(root);
    cout<<endl;

    cout<<"Inorder Traversal of BST: "<<endl;
    inorder(root);
    cout<<endl;

    cout<<"Preorder Traversal of BST: "<<endl;
    preorder(root);
    cout<<endl; 

    cout<<"Postorder Traversal of BST: "<<endl;
    postorder(root);
    cout<<endl;

    cout<<"Minimum value in BST: "<<minVal(root)->data<<endl;
    cout<<"Maximum value in BST: "<<maxVal(root)->data<<endl;

    cout<<"Enter value to delete from BST: ";
    int val;
    cin>>val;
    root = deletefromBST(root,val);
    
    cout<<"Level Order Traversal of BST after deletion: "<<endl;
    levelOrderTraversal(root);
    cout<<endl;



    return 0;
}