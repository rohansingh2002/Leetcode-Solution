class Solution {
public:
    int longestSubarray(vector<int>& nums) {
         int n = nums.size();
        int maxAnd = 0;
        int len = 0, maxlen = 0;

        for (int i = 0; i < n; i++) {
            maxAnd = max(nums[i], maxAnd);
        }

        for (int i = 0; i < n; i++) {
            if (nums[i] == maxAnd) len++;
            else len = 0;
            maxlen = max(maxlen, len);
        }

        return maxlen;
    }
};