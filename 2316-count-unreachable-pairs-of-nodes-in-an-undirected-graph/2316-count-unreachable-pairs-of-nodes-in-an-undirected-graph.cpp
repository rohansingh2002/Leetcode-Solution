class Solution {
public:
   vector<int>v;
    int ans;
    void dfs(vector<vector<int>>&mp ,vector<bool>&vis,int m){
        if(vis[m]==true)return;
        vis[m]=true;
        ans++;
        for(auto i:mp[m]){
            if(!vis[i]){    
                dfs(mp,vis,i);
            }
        }
    }
    void makeConnected(int n, vector<vector<int>>& connections) {
        int s=connections.size();
        vector<vector<int>>mp(n);
        for(int i=0;i<s;i++){
            mp[connections[i][0]].push_back(connections[i][1]);
            mp[connections[i][1]].push_back(connections[i][0]);
        }
        vector<bool>vis(n,false);
        for(int i=0;i<n;i++) {
            if(!vis[i]){
                ans=0;
                dfs(mp,vis,i);
                v.push_back(ans);
            }
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        makeConnected(n,edges);
        int m=v.size();
        if(m==1)return 0;
        long long sol=v[0],res=0;
        for(int i=1;i<m;i++){
            res+=(long long)v[i]*sol;
            sol+=v[i];
        }
        return res;
    }
};