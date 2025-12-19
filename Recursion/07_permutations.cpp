// Generate All Permutations
// Use Case: Scheduling, arrangement problems, testing all possibilities

#include <iostream>
#include <vector>
using namespace std;

void backtrack(vector<int>& nums, vector<int>& path, vector<bool>& used, vector<vector<int>>& result) {
    if (path.size() == nums.size()) {
        result.push_back(path);
        return;
    }
    
    for (int i = 0; i < nums.size(); i++) {
        if (used[i]) continue;
        path.push_back(nums[i]);
        used[i] = true;
        backtrack(nums, path, used, result);
        path.pop_back();
        used[i] = false;
    }
}

vector<vector<int>> permutations(vector<int>& nums) {
    vector<vector<int>> result;
    vector<int> path;
    vector<bool> used(nums.size(), false);
    backtrack(nums, path, used, result);
    return result;
}

int main() {
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> result = permutations(nums);
    
    for (auto& perm : result) {
        cout << "[";
        for (int i = 0; i < perm.size(); i++) {
            cout << perm[i];
            if (i < perm.size() - 1) cout << ", ";
        }
        cout << "]" << endl;
    }
    return 0;
}
