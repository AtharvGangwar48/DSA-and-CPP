// Greedy Interval Problems - Merge Intervals, Min Platforms, Jump Game
#include <bits/stdc++.h>
using namespace std;

// 1. Merge Overlapping Intervals
vector<pair<int,int>> mergeIntervals(vector<pair<int,int>> intervals) {
    sort(intervals.begin(), intervals.end());
    vector<pair<int,int>> res = {intervals[0]};
    for (int i = 1; i < (int)intervals.size(); i++) {
        if (intervals[i].first <= res.back().second)
            res.back().second = max(res.back().second, intervals[i].second);
        else
            res.push_back(intervals[i]);
    }
    return res;
}

// 2. Minimum Platforms (trains)
int minPlatforms(vector<int> arr, vector<int> dep) {
    sort(arr.begin(), arr.end());
    sort(dep.begin(), dep.end());
    int platforms = 1, maxP = 1, i = 1, j = 0;
    while (i < (int)arr.size() && j < (int)dep.size()) {
        if (arr[i] <= dep[j]) { platforms++; i++; }
        else { platforms--; j++; }
        maxP = max(maxP, platforms);
    }
    return maxP;
}

// 3. Jump Game - can reach last index?
bool canJump(vector<int>& nums) {
    int maxReach = 0;
    for (int i = 0; i < (int)nums.size(); i++) {
        if (i > maxReach) return false;
        maxReach = max(maxReach, i + nums[i]);
    }
    return true;
}

// 4. Jump Game II - min jumps to reach end
int minJumps(vector<int>& nums) {
    int jumps = 0, curEnd = 0, farthest = 0;
    for (int i = 0; i < (int)nums.size() - 1; i++) {
        farthest = max(farthest, i + nums[i]);
        if (i == curEnd) { jumps++; curEnd = farthest; }
    }
    return jumps;
}

// 5. Gas Station - circular tour
int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int total = 0, tank = 0, start = 0;
    for (int i = 0; i < (int)gas.size(); i++) {
        tank += gas[i] - cost[i];
        total += gas[i] - cost[i];
        if (tank < 0) { start = i + 1; tank = 0; }
    }
    return total >= 0 ? start : -1;
}

int main() {
    auto merged = mergeIntervals({{1,3},{2,6},{8,10},{15,18}});
    cout << "Merged: ";
    for (auto& [a,b] : merged) cout << "[" << a << "," << b << "] ";
    cout << "\n";

    cout << "Min Platforms: "
         << minPlatforms({900,940,950,1100,1500,1800}, {910,1200,1120,1130,1900,2000}) << "\n";

    vector<int> nums1 = {2,3,1,1,4};
    cout << "Can Jump: " << canJump(nums1) << "\n";
    cout << "Min Jumps: " << minJumps(nums1) << "\n";

    vector<int> gas = {1,2,3,4,5}, cost = {3,4,5,1,2};
    cout << "Gas Station start: " << canCompleteCircuit(gas, cost) << "\n";
}
