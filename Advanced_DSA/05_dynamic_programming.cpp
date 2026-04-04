// Dynamic Programming - Knapsack, LCS, LIS, Coin Change
#include <bits/stdc++.h>
using namespace std;

// 0/1 Knapsack
int knapsack(int W, vector<int>& wt, vector<int>& val) {
    int n = wt.size();
    vector<vector<int>> dp(n+1, vector<int>(W+1, 0));
    for (int i = 1; i <= n; i++)
        for (int w = 0; w <= W; w++) {
            dp[i][w] = dp[i-1][w];
            if (wt[i-1] <= w)
                dp[i][w] = max(dp[i][w], dp[i-1][w-wt[i-1]] + val[i-1]);
        }
    return dp[n][W];
}

// Longest Common Subsequence
int lcs(string& a, string& b) {
    int m = a.size(), n = b.size();
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            dp[i][j] = (a[i-1] == b[j-1]) ? dp[i-1][j-1]+1 : max(dp[i-1][j], dp[i][j-1]);
    return dp[m][n];
}

// Longest Increasing Subsequence (O(n log n))
int lis(vector<int>& arr) {
    vector<int> tails;
    for (int x : arr) {
        auto it = lower_bound(tails.begin(), tails.end(), x);
        if (it == tails.end()) tails.push_back(x);
        else *it = x;
    }
    return tails.size();
}

// Coin Change (min coins)
int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount+1, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i <= amount; i++)
        for (int c : coins)
            if (c <= i && dp[i-c] != INT_MAX)
                dp[i] = min(dp[i], dp[i-c]+1);
    return dp[amount] == INT_MAX ? -1 : dp[amount];
}

int main() {
    vector<int> wt = {1, 3, 4, 5}, val = {1, 4, 5, 7};
    cout << "Knapsack(W=7): " << knapsack(7, wt, val) << "\n";

    string a = "ABCBDAB", b = "BDCAB";
    cout << "LCS: " << lcs(a, b) << "\n";

    vector<int> arr = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << "LIS: " << lis(arr) << "\n";

    vector<int> coins = {1, 5, 6, 9};
    cout << "Coin Change(11): " << coinChange(coins, 11) << "\n";
}
