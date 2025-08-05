#include <bits/stdc++.h>
using namespace std;

class TrieNode {
    public :
    char data;
    TrieNode **children;
    bool isTerminal;

    TrieNode(char data) {
        this-> data = data;
        children = new TrieNode*[26];
        memset(children, NULL, 26*sizeof(char));
        isTerminal = false;
    }
};

class Trie {
    TrieNode *root;

    public :
    Trie() {
        root = new TrieNode('\0');
    }

    private :
    void insertWord(TrieNode* root, string word) {
        if (word.size() == 0) {
            root -> isTerminal = true;
        }
        int index = word[0] - 'a';
        TrieNode *child;
        if (root -> children[index] != NULL){
            child = root -> children[index];
        } else {
            child = new TrieNode(word[0]);
            root -> children[index] = child;
        }
        insertWord(child, word.substr(1));
    }

    public :
    void insertWord(string word) {
        insertWord(root, word);
    }

    private :
    bool searchWord(TrieNode* root, string word) {
        if (word.size() == 0) {
            return root->isTerminal;
        }

        int index = word[0] - 'a';
        TrieNode* child = root->children[index];

        if (child == NULL) {
            return false;
        }

        return searchWord(child, word.substr(1));
    }

    private :
    bool search(string word) {
        return searchWord(root, word);
    }


    private :
    void removeWord(TrieNode *root, string word) {
        if (word.size() == true) {
            root -> isTerminal = false;
            return;
        }

        int index = word[0] - 'a';
        TrieNode *child = root -> children[index];
        if (child == NULL) 
            return;
        
        removeWord(child, word.substr(1));

        if (child -> isTerminal == false) {
            for (int i = 0; i < 26; i++) {
                if (child -> children[i] != NULL) 
                    return;
            }
            delete child;
            root -> children[index] = NULL;
        }
    }   

    public : 
    void removeWord(string word) {
        removeWord(root, word);
    }
};
