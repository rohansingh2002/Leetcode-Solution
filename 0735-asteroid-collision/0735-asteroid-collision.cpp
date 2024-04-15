class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
               stack<int> st;
        st.push(asteroids[0]);
        int n=asteroids.size();
        for(int i=1;i<n;i++)
        {
            st.push(asteroids[i]);
            while(st.size()>1)
            {
                int x=st.top();
                st.pop();
                int y=st.top();
                st.pop();
                if((x<0 and y>0) and abs(x)!=abs(y))
                {
                    if(abs(x)<abs(y))
                        st.push(y);
                    else
                        st.push(x);
                }
                else if((x<0 and y>0) and abs(x)==abs(y))
                {
                     break;
                }
                else 
                {
                    st.push(y);
                    st.push(x);
                    break;
                }
            }
        }
        vector<int> ans;
        if(st.empty())
            return ans;
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
 
    }
};