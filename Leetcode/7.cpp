class Solution {
public:
    long long reverse(long long num) {
    long long reversed_num = 0;
    bool is_negative = num < 0;
    if (is_negative) {
        num = -num;
    }
    while (num != 0) {
        int digit = num % 10;
        reversed_num = reversed_num * 10 + digit;
        num /= 10;
    }
    if (is_negative) {
        reversed_num = -reversed_num;
    }
    return reversed_num;
}
};

// Visit: https://leetcode.com/problems/reverse-integer/description/
// My Profile: https://leetcode.com/u/Atharv048/