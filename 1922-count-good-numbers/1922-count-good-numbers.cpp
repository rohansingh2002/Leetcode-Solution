class Solution {
public:
    int MOD = 1e9 + 7;
     long long power(int a, long long b) {
        if(b == 0)
            return 1;
        long long x = power(a, b/2);
        if(b % 2 == 0)
            return (x * x) % MOD;
        else
            return (((a * x) % MOD) * x) % MOD;
    }
    
    int countGoodNumbers(long long n) {
        long long  odd = n/2;
        long long  even = n - odd;

        return (power(5, even) * power(4, odd))%MOD;
       
    }
};