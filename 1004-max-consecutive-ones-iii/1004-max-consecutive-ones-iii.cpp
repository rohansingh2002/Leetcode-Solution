class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i = 0;
        int j = 0;
        int cnt = 0;
        int n=nums.size();
        while(i<n) {
            if(nums[i]==1) {
                i++;
            }
            else {
                if(k>0) {
                    k--;
                    i++;
                } else {
                    while(nums[j]==1) {
                        j++;
                    }
                    j++;
                    k++;
                }
            }
            cnt = max(cnt, i-j);
        }
        return cnt; // Code here
    }
};