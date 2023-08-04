class Solution {
public:
     static bool to(pair<int,int> a,pair<int,int> b){
            return a.second>b.second;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> m;
        for(auto i:nums)
            m[i]++;
        vector<pair<int,int>> vec(m.begin(),m.end());
        sort(vec.begin(),vec.end(),to);
        vector<int> ans;
        for(int i=0;i<k;i++)
            ans.push_back(vec[i].first);
        return ans;
    }
};