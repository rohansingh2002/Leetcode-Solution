class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
          vector<int> res;
          deque<int> dq;
        
        for(int itr = 0; itr < nums.size(); itr++){
            
            if(!dq.empty() && dq.front() == itr-k) dq.pop_front();
            
           
            while(!dq.empty() && nums[dq.back()] < nums[itr]){
                dq.pop_back();
            }
            
            dq.push_back(itr);
            
    
            if(itr >= k-1) res.push_back(nums[dq.front()]);
        }
        
        return res;
    }
};