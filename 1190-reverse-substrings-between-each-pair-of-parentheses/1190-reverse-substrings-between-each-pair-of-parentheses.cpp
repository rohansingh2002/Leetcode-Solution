class Solution {
public:
    void reverse(string &s,int i,int j){
        while(i<j){
            swap(s[i],s[j]) ;
            i++;
            j--;
        }
    }
    string reverseParentheses(string s) {
        stack<int> st ;
        int n = s.length() , i ;
        i = 0 ;
        while(i<n)
        {
            if(s[i]=='('){
                st.push(i) ;
            }
            else if(s[i]==')')
            {
                int ind = st.top() ;
                st.pop() ;
                reverse(s,ind+1,i-1) ;
                cout<<"s = "<<s<<" " ;
                s.erase(s.begin()+ind) ;
                s.erase(s.begin()+i-1) ;
                i-=2 ;
            }
            i++ ;
        }
        return s ;
    }
};
