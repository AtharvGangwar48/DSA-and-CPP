// Binary Search Tree - Search, Insert, Delete, Min, Max, Height
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

Node* insert(Node* root, int val) {
    if (!root) return new Node(val);
    if (val < root->data) root->left = insert(root->left, val);
    else if (val > root->data) root->right = insert(root->right, val);
    return root;
}

bool search(Node* root, int val) {
    if (!root) return false;
    if (root->data == val) return true;
    return val < root->data ? search(root->left, val) : search(root->right, val);
}

Node* minNode(Node* root) {
    while (root->left) root = root->left;
    return root;
}

Node* deleteNode(Node* root, int val) {
    if (!root) return nullptr;
    if (val < root->data) root->left = deleteNode(root->left, val);
    else if (val > root->data) root->right = deleteNode(root->right, val);
    else {
        if (!root->left) return root->right;
        if (!root->right) return root->left;
        Node* succ = minNode(root->right);
        root->data = succ->data;
        root->right = deleteNode(root->right, succ->data);
    }
    return root;
}

int height(Node* root) {
    if (!root) return 0;
    return 1 + max(height(root->left), height(root->right));
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node* root = nullptr;
    for (int x : {5, 3, 7, 1, 4, 6, 8})
        root = insert(root, x);

    cout << "Inorder: "; inorder(root); cout << "\n";
    cout << "Search 4: " << (search(root, 4) ? "Found" : "Not Found") << "\n";
    cout << "Height: " << height(root) << "\n";
    cout << "Min: " << minNode(root)->data << "\n";

    root = deleteNode(root, 3);
    cout << "After deleting 3: "; inorder(root); cout << "\n";
}
