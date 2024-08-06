#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>

using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    
    Node(int data) {
        this->data = data;
        left = right = NULL;
    }
};

class compare {
public:
    bool operator()(Node* a, Node* b) {
        return a->data > b->data;
    }
};

void traverse(Node* root, vector<string>& ans, string temp) {
    if(root == NULL)
        return;
    
    if(root->left == NULL && root->right == NULL) {
        ans.push_back(temp);
        return;
    }

    traverse(root->left, ans, temp + "0");
    traverse(root->right, ans, temp + "1");
}

vector<string> HuffmanCodes(string s, vector<int> f, int N) {
    priority_queue<Node*, vector<Node*>, compare> pq;
    
    // Push each character frequency as a node into the priority queue
    for(int i=0; i<N; i++) {
        Node* temp = new Node(f[i]);
        pq.push(temp);
    }

    // Build Huffman tree
    while(pq.size() > 1) {
        Node* left = pq.top();
        pq.pop();
        Node* right = pq.top();
        pq.pop();

        Node* newNode = new Node(left->data + right->data);
        newNode->left = left;
        newNode->right = right;

        pq.push(newNode);
    }

    // Get the root of the Huffman tree
    Node* root = pq.top();

    vector<string> ans;
    string temp = "";
    traverse(root, ans, temp);
    
    return ans; // Return the vector of Huffman codes
}

int main() {
    string s = "abcdef";
    vector<int> f;
    f.push_back(5);
    f.push_back(9);
    f.push_back(12);
    f.push_back(13);
    f.push_back(16);
    f.push_back(45);

    int N = f.size();

    vector<string> ans = HuffmanCodes(s, f, N);

    for(auto x: ans)
        cout << x << " ";
    cout << endl;

    return 0;
}
