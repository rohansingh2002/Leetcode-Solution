class Solution {
public:
    int atMostK(vector<int>& a, int k) {
        int i = 0,count = 0,res = 0;
        int j = 0;
         while(j<a.size()){
            if(a[j]%2==1) count++;
            if(count > k){
                while(count>k){
                    if(a[i]%2==1) count--;
                    i++;
                }
            }
            res += j-i+1;
            j++;
        }
        return res;
    }
    
    int numberOfSubarrays(vector<int>& a, int k) {
        return atMostK(a,k) - atMostK(a,k-1);
    }
};