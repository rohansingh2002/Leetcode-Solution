class Solution {
public:
    int balancedStringSplit(string s) {
        int countl=0;
        int countr=0;
        int ans=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='L'){
                countl++;
            }
            if(s[i]=='R'){
                countr++;
            }
            if(countl==countr){
                ans+=1;
            }
        }
        return ans;
    }
};