class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        
        set<int>s;
        unordered_map<int,int>mp;
        vector<int>ans;
        for(int i = 0; i < arr.size(); i++){
            s.insert(arr[i]);
        }
        int count = 1;
        int val = -1;
        for(auto it:s){
            if(val == it){
                mp[it] = count;
            }else{
                mp[it] = count;
                val = it;
                count++;
            }
            
        }
        for(int  i =0; i < arr.size(); i++){
            ans.push_back(mp[arr[i]]);
        }
        return ans;
    }
};