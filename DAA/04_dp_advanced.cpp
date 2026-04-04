// DAA - DP Advanced: Matrix Chain Multiplication, Edit Distance, Floyd-Warshall
#include <bits/stdc++.h>
using namespace std;

// Matrix Chain Multiplication - O(n^3)
int matrixChain(vector<int>& dims) {
    int n = dims.size() - 1;
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int len = 2; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k < j; k++)
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + dims[i]*dims[k+1]*dims[j+1]);
        }
    }
    return dp[0][n-1];
}

// Edit Distance (Levenshtein)
int editDistance(string& a, string& b) {
    int m = a.size(), n = b.size();
    vector<vector<int>> dp(m+1, vector<int>(n+1));
    for (int i = 0; i <= m; i++) dp[i][0] = i;
    for (int j = 0; j <= n; j++) dp[0][j] = j;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            dp[i][j] = (a[i-1] == b[j-1]) ? dp[i-1][j-1]
                       : 1 + min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
    return dp[m][n];
}

// Floyd-Warshall All-Pairs Shortest Path
const int INF = 1e9;
void floydWarshall(vector<vector<int>>& dist) {
    int n = dist.size();
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (dist[i][k] != INF && dist[k][j] != INF)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
}

int main() {
    vector<int> dims = {10, 30, 5, 60};
    cout << "Matrix Chain Min Ops: " << matrixChain(dims) << "\n";

    string a = "sunday", b = "saturday";
    cout << "Edit Distance: " << editDistance(a, b) << "\n";

    int n = 4;
    vector<vector<int>> dist = {
        {0,   3,   INF, 7},
        {8,   0,   2,   INF},
        {5,   INF, 0,   1},
        {2,   INF, INF, 0}
    };
    floydWarshall(dist);
    cout << "Floyd-Warshall (0->3): " << dist[0][3] << "\n";
    cout << "Floyd-Warshall (1->3): " << dist[1][3] << "\n";
}
