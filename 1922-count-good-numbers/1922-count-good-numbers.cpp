class Solution {
public:
    int mod = 1000000007;
    long long power(long long val,long long pow){ // calculatin pow in log(n) time
        if(pow==0) return 1;
        
        if(pow%2==0){
            return power((val*val)%mod,pow/2)%mod;
        }
        else
            return (val*power((val*val)%mod,pow/2))%mod;
        
    }
    
    int countGoodNumbers(long long n) {
        long long  odd = n/2;
        long long  even = n - odd;

        return (power(5, even) * power(4, odd))%mod;
       
    }
};