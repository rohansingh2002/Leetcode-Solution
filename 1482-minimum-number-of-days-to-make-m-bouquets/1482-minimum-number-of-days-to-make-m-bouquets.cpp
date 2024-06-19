class Solution {
public:
    int total(vector<int> &nums, int k, int day) {
        int count = 0;
        int b = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] <= day) {
                count++;
                if (count == k) {
                    b++;
                    count = 0;
                }
            } else {
                count = 0;
            }
        }
        
        return b;
    }
    
    int minDays(vector<int> &bloomDay, int m, int k) {
        int left = *min_element(bloomDay.begin(), bloomDay.end());
        int right = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = -1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int v = total(bloomDay, k, mid);
            
            if (v >= m) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        
        return ans;
    }
    
};