int hammingWeight(int n) {
    int count=0;
    while(n!=0){
        if(n&1){
            count++;
        }
        n=n>>1;
    }
    return count;
}

// Visit: https://leetcode.com/problems/number-of-1-bits/description/
// My Profile: https://leetcode.com/u/Atharv048/