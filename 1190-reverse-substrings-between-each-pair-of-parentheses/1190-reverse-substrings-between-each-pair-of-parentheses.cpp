class Solution {
public:
    string reverseParentheses(string s) {
        int i = 0; 
        int n = s.size();
        stack<char>st;
        while(i < n){
            if(s[i] == ')'){
                string str;
                while(st.top() != '('){
                    str += st.top();
                    st.pop();
                }
                st.pop();
                int j = 0;
                while(j < str.size()){
                    st.push(str[j]);
                    j++;
                }
            }
            else{
                st.push(s[i]);
            }
            i++;
        }
        string ans="";
        while(!st.empty()){
            char ss = st.top();
            ans += ss;
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};