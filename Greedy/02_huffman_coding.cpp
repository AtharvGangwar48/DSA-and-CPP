// Huffman Coding - Build tree, encode, decode
#include <bits/stdc++.h>
using namespace std;

struct Node {
    char ch; int freq;
    Node *left, *right;
    Node(char c, int f) : ch(c), freq(f), left(nullptr), right(nullptr) {}
};

struct Cmp { bool operator()(Node* a, Node* b) { return a->freq > b->freq; } };

Node* buildTree(vector<pair<char,int>>& freqs) {
    priority_queue<Node*, vector<Node*>, Cmp> pq;
    for (auto& [c, f] : freqs) pq.push(new Node(c, f));
    while (pq.size() > 1) {
        Node* l = pq.top(); pq.pop();
        Node* r = pq.top(); pq.pop();
        Node* p = new Node('\0', l->freq + r->freq);
        p->left = l; p->right = r;
        pq.push(p);
    }
    return pq.top();
}

void buildCodes(Node* root, string code, unordered_map<char,string>& codes) {
    if (!root) return;
    if (!root->left && !root->right) { codes[root->ch] = code; return; }
    buildCodes(root->left,  code + "0", codes);
    buildCodes(root->right, code + "1", codes);
}

string encode(const string& text, unordered_map<char,string>& codes) {
    string result;
    for (char c : text) result += codes[c];
    return result;
}

string decode(const string& bits, Node* root) {
    string result;
    Node* cur = root;
    for (char b : bits) {
        cur = (b == '0') ? cur->left : cur->right;
        if (!cur->left && !cur->right) { result += cur->ch; cur = root; }
    }
    return result;
}

int main() {
    string text = "huffman coding example";
    map<char,int> freq;
    for (char c : text) freq[c]++;

    vector<pair<char,int>> freqs(freq.begin(), freq.end());
    Node* root = buildTree(freqs);

    unordered_map<char,string> codes;
    buildCodes(root, "", codes);

    cout << "Codes:\n";
    for (auto& [c, code] : codes)
        cout << "  '" << c << "': " << code << "\n";

    string encoded = encode(text, codes);
    cout << "\nOriginal bits: " << text.size() * 8 << "\n";
    cout << "Encoded bits:  " << encoded.size() << "\n";
    cout << "Decoded: " << decode(encoded, root) << "\n";
}
