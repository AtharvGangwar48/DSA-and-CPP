#Correct Code
class Solution:
    def countPrimes(self, n: int) -> int:
        if n <= 2:
            return 0
        is_prime = [True] * n
        is_prime[0] = is_prime[1] = False
        p = 2
        while p * p < n:
            if is_prime[p]:
                for multiple in range(p * p, n, p):
                    is_prime[multiple] = False
            p += 1
        return sum(is_prime)

#This Code gives TLE
class Solution:
    def countPrimes(self, n: int) -> int:
        def isPrime(x):
            if x < 2:
                return False
            for i in range(2, int(x**0.5) + 1):
                if x % i == 0:
                    return False
            return True

        count = 0
        for i in range(n):
            if isPrime(i):
                count += 1
        return count
    
#https://leetcode.com/u/Atharv048/
#https://leetcode.com/problems/count-primes/