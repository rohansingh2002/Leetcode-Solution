class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count1=0;
        int maxi=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                count1++;
            }
            else{
                maxi=max(maxi,count1);
                count1=0;
            }
        }
        if(nums[nums.size()-1]==1){
            maxi=max(maxi,count1);
        }
        return maxi;
    }
};