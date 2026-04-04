// DAA - Greedy: Activity Selection, Fractional Knapsack, Huffman Coding
#include <bits/stdc++.h>
using namespace std;

// Activity Selection - max non-overlapping activities
int activitySelection(vector<pair<int,int>>& acts) {
    sort(acts.begin(), acts.end(), [](auto& a, auto& b){ return a.second < b.second; });
    int count = 1, lastEnd = acts[0].second;
    cout << "Selected: (" << acts[0].first << "," << acts[0].second << ") ";
    for (int i = 1; i < acts.size(); i++) {
        if (acts[i].first >= lastEnd) {
            cout << "(" << acts[i].first << "," << acts[i].second << ") ";
            lastEnd = acts[i].second;
            count++;
        }
    }
    cout << "\n";
    return count;
}

// Fractional Knapsack
double fractionalKnapsack(int W, vector<pair<int,int>>& items) {
    // items: {value, weight}
    sort(items.begin(), items.end(), [](auto& a, auto& b){
        return (double)a.first/a.second > (double)b.first/b.second;
    });
    double total = 0;
    for (auto& [v, w] : items) {
        if (W >= w) { total += v; W -= w; }
        else { total += (double)v * W / w; break; }
    }
    return total;
}

// Huffman Coding
struct HNode {
    char ch; int freq;
    HNode *left, *right;
    HNode(char c, int f) : ch(c), freq(f), left(nullptr), right(nullptr) {}
};

struct Cmp { bool operator()(HNode* a, HNode* b) { return a->freq > b->freq; } };

void printCodes(HNode* root, string code) {
    if (!root) return;
    if (!root->left && !root->right) cout << root->ch << ": " << code << "\n";
    printCodes(root->left, code + "0");
    printCodes(root->right, code + "1");
}

void huffman(vector<pair<char,int>>& freq) {
    priority_queue<HNode*, vector<HNode*>, Cmp> pq;
    for (auto& [c, f] : freq) pq.push(new HNode(c, f));
    while (pq.size() > 1) {
        HNode* l = pq.top(); pq.pop();
        HNode* r = pq.top(); pq.pop();
        HNode* merged = new HNode('\0', l->freq + r->freq);
        merged->left = l; merged->right = r;
        pq.push(merged);
    }
    cout << "Huffman Codes:\n";
    printCodes(pq.top(), "");
}

int main() {
    vector<pair<int,int>> acts = {{1,3},{2,5},{3,9},{6,8},{5,7},{8,11}};
    cout << "Activities selected: " << activitySelection(acts) << "\n\n";

    vector<pair<int,int>> items = {{60,10},{100,20},{120,30}};
    cout << "Fractional Knapsack(W=50): " << fractionalKnapsack(50, items) << "\n\n";

    vector<pair<char,int>> freq = {{'a',5},{'b',9},{'c',12},{'d',13},{'e',16},{'f',45}};
    huffman(freq);
}
