// Trie - Insert, Search, StartsWith (Prefix)
#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
    TrieNode* children[26] = {};
    bool isEnd = false;
};

class Trie {
    TrieNode* root;
public:
    Trie() : root(new TrieNode()) {}

    void insert(const string& word) {
        TrieNode* cur = root;
        for (char c : word) {
            int i = c - 'a';
            if (!cur->children[i]) cur->children[i] = new TrieNode();
            cur = cur->children[i];
        }
        cur->isEnd = true;
    }

    bool search(const string& word) {
        TrieNode* cur = root;
        for (char c : word) {
            int i = c - 'a';
            if (!cur->children[i]) return false;
            cur = cur->children[i];
        }
        return cur->isEnd;
    }

    bool startsWith(const string& prefix) {
        TrieNode* cur = root;
        for (char c : prefix) {
            int i = c - 'a';
            if (!cur->children[i]) return false;
            cur = cur->children[i];
        }
        return true;
    }
};

int main() {
    Trie t;
    for (const string& w : {"apple", "app", "apt", "bat", "ball"})
        t.insert(w);

    cout << "search(apple): " << t.search("apple") << "\n";
    cout << "search(ap):    " << t.search("ap") << "\n";
    cout << "startsWith(ap):" << t.startsWith("ap") << "\n";
    cout << "startsWith(ba):" << t.startsWith("ba") << "\n";
    cout << "startsWith(bc):" << t.startsWith("bc") << "\n";
}
