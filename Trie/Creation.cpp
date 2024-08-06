#include<iostream>
using namespace std;

class TrieNode{
    public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char ch)
    {
        this->data = ch;
        for(int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie{
    public:
    TrieNode* root;

    Trie()
    {
        root = new TrieNode('\0');
    }

    void insertUtil(TrieNode* root, string word)
    {
        if(word.size() == 0)
        {
            root->isTerminal = true;
            return;
        }

        int index = word[0] - 'A';
        TrieNode* child;
        if(root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        insertUtil(child, word.substr(1));
    }
    void insertWord(string word)
    {
        insertUtil(root, word);
    }

    bool searchUtil(TrieNode* root, string word)
    {
        if(word.size() == 0)
        {
            return root->isTerminal;
        }

        int index = word[0] - 'A';
        if(root->children[index] == NULL)
        {
            return false;
        }

        return searchUtil(root->children[index], word.substr(1));
    }
    bool searchWord(string word)
    {
        return searchUtil(root, word);
    }

    void removeUtil(TrieNode* root, string word)
    {
        if(word.size() == 0)
        {
            root->isTerminal = false;
            return;
        }

        int index = word[0] - 'A';
        if(root->children[index] == NULL)
        {
            return;
        }

        removeUtil(root->children[index], word.substr(1));

        if(root->children[index]->isTerminal == false)
        {
            for(int i = 0; i < 26; i++)
            {
                if(root->children[index]->children[i] != NULL)
                {
                    return;
                }
            }
            delete root->children[index];
            root->children[index] = NULL;
        }
    }
    void removeWord(string word)
    {
        removeUtil(root, word);
    }

    bool prefixUtil(TrieNode* root, string word)
    {
        if(word.size() == 0)
        {
            return true;
        }

        int index = word[0] - 'A';
        if(root->children[index] == NULL)
        {
            return false;
        }

        return prefixUtil(root->children[index], word.substr(1));
    }
    bool prefixWord(string word)
    {
        return prefixUtil(root, word);
    }
};
int main()
{
    Trie *t = new Trie();

    t->insertWord("APPLE");
    t->insertWord("BANANA");
    t->insertWord("MANGO");

    cout<<t->searchWord("APPLE")<<endl;
    cout<<t->searchWord("BANAN")<<endl;
    return 0;
}
