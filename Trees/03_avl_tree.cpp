// AVL Tree - Self-balancing BST with rotations
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data, height;
    Node* left;
    Node* right;
    Node(int val) : data(val), height(1), left(nullptr), right(nullptr) {}
};

int height(Node* n) { return n ? n->height : 0; }
int bf(Node* n) { return n ? height(n->left) - height(n->right) : 0; }
void updateHeight(Node* n) { n->height = 1 + max(height(n->left), height(n->right)); }

Node* rotateRight(Node* y) {
    Node* x = y->left;
    y->left = x->right;
    x->right = y;
    updateHeight(y); updateHeight(x);
    return x;
}

Node* rotateLeft(Node* x) {
    Node* y = x->right;
    x->right = y->left;
    y->left = x;
    updateHeight(x); updateHeight(y);
    return y;
}

Node* balance(Node* node) {
    updateHeight(node);
    int b = bf(node);
    if (b > 1) {
        if (bf(node->left) < 0) node->left = rotateLeft(node->left);
        return rotateRight(node);
    }
    if (b < -1) {
        if (bf(node->right) > 0) node->right = rotateRight(node->right);
        return rotateLeft(node);
    }
    return node;
}

Node* insert(Node* root, int val) {
    if (!root) return new Node(val);
    if (val < root->data) root->left = insert(root->left, val);
    else if (val > root->data) root->right = insert(root->right, val);
    return balance(root);
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << "(h=" << root->height << ") ";
    inorder(root->right);
}

int main() {
    Node* root = nullptr;
    for (int x : {10, 20, 30, 40, 50, 25})
        root = insert(root, x);

    cout << "Inorder (balanced): ";
    inorder(root);
    cout << "\nRoot: " << root->data << ", Height: " << root->height << "\n";
}
