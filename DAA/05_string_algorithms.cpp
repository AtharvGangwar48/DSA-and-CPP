// DAA - String Algorithms: KMP, Rabin-Karp, Z-Algorithm
#include <bits/stdc++.h>
using namespace std;

// KMP Pattern Matching - O(n + m)
vector<int> buildLPS(const string& pat) {
    int m = pat.size();
    vector<int> lps(m, 0);
    for (int i = 1, len = 0; i < m; ) {
        if (pat[i] == pat[len]) lps[i++] = ++len;
        else if (len) len = lps[len-1];
        else lps[i++] = 0;
    }
    return lps;
}

vector<int> kmpSearch(const string& text, const string& pat) {
    vector<int> lps = buildLPS(pat), matches;
    int n = text.size(), m = pat.size();
    for (int i = 0, j = 0; i < n; ) {
        if (text[i] == pat[j]) { i++; j++; }
        if (j == m) { matches.push_back(i - j); j = lps[j-1]; }
        else if (i < n && text[i] != pat[j])
            j ? j = lps[j-1] : i++;
    }
    return matches;
}

// Rabin-Karp - O(n + m) avg
vector<int> rabinKarp(const string& text, const string& pat) {
    const int BASE = 31, MOD = 1e9+7;
    int n = text.size(), m = pat.size();
    vector<int> matches;
    long long ph = 0, th = 0, pw = 1;
    for (int i = 0; i < m-1; i++) pw = pw * BASE % MOD;
    for (int i = 0; i < m; i++) {
        ph = (ph * BASE + pat[i]) % MOD;
        th = (th * BASE + text[i]) % MOD;
    }
    for (int i = 0; i <= n - m; i++) {
        if (ph == th && text.substr(i, m) == pat) matches.push_back(i);
        if (i < n - m)
            th = (BASE * (th - text[i] * pw % MOD + MOD) + text[i+m]) % MOD;
    }
    return matches;
}

// Z-Algorithm - O(n)
vector<int> zFunction(const string& s) {
    int n = s.size();
    vector<int> z(n, 0);
    z[0] = n;
    for (int i = 1, l = 0, r = 0; i < n; i++) {
        if (i < r) z[i] = min(r - i, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i]++;
        if (i + z[i] > r) { l = i; r = i + z[i]; }
    }
    return z;
}

int main() {
    string text = "aabaacaadaabaaba", pat = "aaba";

    auto kmp = kmpSearch(text, pat);
    cout << "KMP matches at: "; for (int i : kmp) cout << i << " "; cout << "\n";

    auto rk = rabinKarp(text, pat);
    cout << "Rabin-Karp at: "; for (int i : rk) cout << i << " "; cout << "\n";

    string combined = pat + "$" + text;
    auto z = zFunction(combined);
    cout << "Z-Algo matches at: ";
    for (int i = pat.size()+1; i < combined.size(); i++)
        if (z[i] == (int)pat.size()) cout << i - pat.size() - 1 << " ";
    cout << "\n";
}
