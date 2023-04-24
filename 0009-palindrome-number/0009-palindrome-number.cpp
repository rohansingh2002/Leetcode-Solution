class Solution {
public:
    bool isPalindrome(int x) {
       long long signed int n=x;
       long long signed int ans=0;
        if(n<0){
            return false;
        }
        while(n>0){
            long long signed int rem=n%10;
            ans=ans*10+rem;
            n=n/10;
        }
        if(ans==x){
            return true;
        }
        return false;
        
    }
};