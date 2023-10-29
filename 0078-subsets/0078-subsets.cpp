class Solution {
public:
    void subset(int i , vector<int>& nums, vector<int>& vec , vector<vector<int>>& ans){
        if(i == nums.size()){
            ans.push_back(vec);
            return ;
        }
        vec.push_back(nums[i]);
        subset(i+1,nums,vec,ans);
        vec.pop_back();
        subset(i+1,nums,vec,ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> vec;
        vector<vector<int>> ans;
        subset(0 , nums, vec,ans);
        return ans;
    }
};