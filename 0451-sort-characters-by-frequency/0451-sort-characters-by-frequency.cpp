class Solution {
public:
    string frequencySort(string s) {
        map<char,int> mpp;
        vector<pair<int,char>> v;
        for(auto it: s) mpp[it]++;
        for(auto it: mpp) {
            v.push_back({ it.second, it.first});
        }
        sort(v.begin(), v.end(), greater<pair<int, char>>());
        string res="";
        for(int i=0; i<v.size(); i++) {
            while(v[i].first--) res+= v[i].second;
        }
        return res;
    }
};