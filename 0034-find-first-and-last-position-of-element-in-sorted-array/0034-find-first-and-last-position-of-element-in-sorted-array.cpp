class Solution {
public:
    int lowerbond(vector<int>& arr, int n, int x){
    int low = 0;
    int high = n-1;
    int ans = n;
    while(low <= high){
        int mid = (low+high)/2;
        if(arr[mid] == x){
            ans = mid;
            high = mid-1;
        }
        else if(arr[mid] > x){
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
        return ans;
    }

    int upperbond(vector<int>& arr, int n, int x){
        int low = 0;
        int high = n-1;
        int ans = n;
        while(low <= high){
            int mid = (low+high)/2;
            if(arr[mid] == x){
                ans = mid;
                low = mid+1;
            }
            else if(arr[mid] > x){
                high = mid - 1;
            }
            else{
               low = mid+1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int lb = lowerbond(nums,n,target);
        if(lb == n || nums[lb] != target) return {-1,-1};
        return {lb,upperbond(nums,n,target)};
    }
};