class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
       map<int,int>mp;
       for(auto it:roads){
           mp[it[0]]++;
           mp[it[1]]++;
       }
      pair<int,int>p[n];
      int i = 0;
      for(auto it : mp){
          p[i].first = it.second;
          p[i].second = it.first;        
       //   cout<<p[i].first<<" "<< p[i].second<<" ";
          i++;

      }
      map<int,int>m;
      int ind = 1;
      sort(p,p+n);
      for(int i = 0; i < n;i++){
        //  cout<<p[i].second<<" "<<p[i].first<<" ";
          m[p[i].second] = ind;
          cout<<m[p[i].second]<<" "<<p[i].second<<" ";
          ind++;
      }
      long long ans = 0;
      for(auto it : roads){
          ans += m[it[0]];
      //    cout<<mp[it[0]];
          ans += m[it[1]];
      //    cout<<mp[it[1]];
          
      }
      return ans;
    }
};