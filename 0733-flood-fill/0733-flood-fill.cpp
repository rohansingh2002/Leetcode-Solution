class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        int old_color = image[sr][sc];
        vector<vector<int>>vis(n,vector<int>(m,0));
        vector<vector<int>>ans = image;
        queue<pair<int,int>>q;
        q.push({sr,sc});
        ans[sr][sc] = color;
        int row[] = {-1, 0, 1, 0};
        int col[] = {0, 1, 0, -1};
        
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            
            for(int i = 0 ; i < 4 ; i++){
                int nrow = r + row[i];
                int ncol = c + col[i];
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] == 0 && ans[nrow][ncol] != color && ans[nrow][ncol] == old_color ){
                    q.push({nrow,ncol});
                    vis[nrow][ncol] = 1;
                    ans[nrow][ncol] = color;
                }
            }
            
        }
        return ans;
        
        
        
    }
};