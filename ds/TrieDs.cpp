#include <iostream>
using namespace std;

struct TrieNode
{
    TrieNode *children[26];
    bool isendofword;

    TrieNode()
    {
        isendofword = false;
        for (int i = 0; i < 26; i++)
        {
            children[i] = nullptr;
        }
    }
};

class Trie
{

public:
    TrieNode *root;
    Trie(){
        root = new TrieNode();
    }

    void insert(string word){
        TrieNode* node = root;
        for(char ch:word){
            int index = ch - 'a';
            if(!node->children[index]){
                node->children[index]=new TrieNode();
            }
            node = node->children[index];
        }
        node->isendofword = true;
    }

    bool search(string word){
        TrieNode* node = root;
        for(char ch:word){
            int index = ch-'a';
            if(!node->children[index]){
                return false;
            }
            node=node->children[index];
        }
        return node->isendofword;
    }

    bool startswith(string prefix){
        TrieNode* node = root;
        for(char ch:prefix){
            int index = ch-'a';
            if(!node->children[index]) return false;
            node = node->children[index];
        }
        return true;
    }
};

int main()
{
    Trie* trie = new Trie();
    trie->insert("apple");
    cout << trie->search("apple") << endl;   // returns true
    cout << trie->search("app") << endl;     // returns false
    cout << trie->startswith("app") << endl; // returns true
    trie->insert("app");
    cout << trie->search("app") << endl;     // returns true

    delete trie;
    return 0;
}