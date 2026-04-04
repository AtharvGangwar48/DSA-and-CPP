// Greedy Basics - Activity Selection, Job Sequencing, Fractional Knapsack
#include <bits/stdc++.h>
using namespace std;

// 1. Activity Selection - max non-overlapping intervals
void activitySelection(vector<pair<int,int>> acts) {
    sort(acts.begin(), acts.end(), [](auto& a, auto& b){ return a.second < b.second; });
    int lastEnd = acts[0].second;
    cout << "Activities: (" << acts[0].first << "," << acts[0].second << ") ";
    for (int i = 1; i < (int)acts.size(); i++) {
        if (acts[i].first >= lastEnd) {
            cout << "(" << acts[i].first << "," << acts[i].second << ") ";
            lastEnd = acts[i].second;
        }
    }
    cout << "\n";
}

// 2. Job Sequencing with Deadlines - maximize profit
void jobSequencing(vector<tuple<int,int,int>> jobs) {
    // {profit, deadline, id}
    sort(jobs.begin(), jobs.end(), greater<>());
    int maxD = 0;
    for (auto& [p, d, id] : jobs) maxD = max(maxD, d);
    vector<int> slot(maxD + 1, -1);
    int totalProfit = 0;
    cout << "Jobs scheduled: ";
    for (auto& [p, d, id] : jobs) {
        for (int j = d; j >= 1; j--) {
            if (slot[j] == -1) {
                slot[j] = id;
                totalProfit += p;
                cout << "J" << id << " ";
                break;
            }
        }
    }
    cout << "| Profit: " << totalProfit << "\n";
}

// 3. Fractional Knapsack
double fractionalKnapsack(int W, vector<pair<int,int>> items) {
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

int main() {
    activitySelection({{1,3},{2,5},{3,9},{6,8},{5,7},{8,11}});

    // {profit, deadline, id}
    jobSequencing({{100,2,1},{19,1,2},{27,2,3},{25,1,4},{15,3,5}});

    cout << "Fractional Knapsack: "
         << fractionalKnapsack(50, {{60,10},{100,20},{120,30}}) << "\n";
}
