int subtractProductAndSum(int n) {
    int sum=0;
    int product=1;
    if(n==0){
        return 0;
    }
    else{
        while(n!=0){
            int digit = n%10;
            sum = sum + digit;
            product = product * digit;
            n=n/10;
        }
        return product-sum;
    }
}

// Visit: https://leetcode.com/problems/subtract-the-product-and-sum-of-digits-of-an-integer/description/
// My Profile: https://leetcode.com/u/Atharv048/