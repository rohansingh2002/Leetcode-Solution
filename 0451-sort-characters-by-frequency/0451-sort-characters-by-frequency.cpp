class Solution {
public:
    string frequencySort(string s) {
      map<char,int> mp;
        for(auto a:s){
            mp[a]++;
        }
        priority_queue<pair<int, char> > pq;
        for(auto a:s){
            pq.push(make_pair(mp[a],a));
        }
        string  ans="";
        while(!pq.empty()){
            ans+=pq.top().second;
            pq.pop();
        }
        return ans;  
    }
};