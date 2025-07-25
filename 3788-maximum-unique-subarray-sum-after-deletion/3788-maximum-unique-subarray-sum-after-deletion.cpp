class Solution {
public:
    int maxSum(vector<int>& nums) {
        set<int> set(nums.begin(), nums.end());
        int res = INT_MIN, sum = 0;
        for(auto it = set.rbegin(); it != set.rend(); ++it) {
            sum += *it;
            res = max(sum, res);
        }
        return res; 
    }
};