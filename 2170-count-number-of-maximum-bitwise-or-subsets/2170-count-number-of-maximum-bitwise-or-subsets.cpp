class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
         int n = nums.size();
        int ans = 0, mx = 0;
        for (int i = 0; i < (1 << n); i++) {
            int cur = 0;
            for (int j = 0; j < n; j++) {
                if ((i >> j) & 1) cur |= nums[j];
            }
            if (cur > mx) {
                mx = cur;
                ans = 1;
            } else if (cur == mx) {
                ans += 1;
            }
        }
        return ans; 
    }
};