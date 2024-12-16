class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        vector<int>ans = nums;
        int value = 0, mini = INT_MAX;
        int j = 0;
        while(k--){
            for(int i = 0; i < nums.size(); i++){
                if(mini > ans[i]){
                    mini = ans[i];
                    j = i;
                    value = multiplier*mini;
                }
            }
            ans[j] = value;
            mini = INT_MAX;
        }
        return ans;
    }
};