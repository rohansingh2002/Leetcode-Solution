class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
          int freq[10001] = {0};  // frequency array
        int l = 0, r = 0, n = nums.size();
        int sum = 0, maxi = 0;

        while (r < n) {
            int num = nums[r];
            freq[num]++;
            sum += num;

            while (freq[num] > 1) {
                freq[nums[l]]--;
                sum -= nums[l];
                l++;
            }

            maxi = max(maxi, sum);
            r++;
        }

        return maxi;
    }
};