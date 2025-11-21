class Solution {
public:
    bool isPowerOfTwo(int n) {
        long long ans = 1;
        for (int i=0;i<=30;i++){
            if(ans == n){
                return 1;
            }
            else{
                ans = ans * 2;
            }
        }
        return 0;
    }
};

// Visit: https://leetcode.com/problems/power-of-two/description/
// My Profile: https://leetcode.com/u/Atharv048/