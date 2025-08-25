class Solution {
public:
    int longestSubarray(vector<int>& nums) {
       int n=nums.size(),count{},prev{},maxu{};
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                maxu=max(maxu,prev+count);
                prev=count;
                count=0;
            }
            else count++;
        }
        maxu=max(maxu,prev+count);
        if(count==n) return count-1;
        return maxu; 
    }
};