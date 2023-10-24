class Solution {
public:
    void generator(vector<string> &ans, vector<string> &stack, int n, int openp, int closep) {
        if (openp == closep && openp == n) {
            vector<string> temp = stack;
            string concat;
            while (!temp.empty()) {
                concat = temp.back() + concat;
                temp.pop_back();
            }
            ans.push_back(concat);
            return;
        }

        if (openp < n) {
            stack.push_back("(");
            generator(ans, stack, n, openp + 1, closep);
            stack.pop_back();
        }

        if (closep < openp) {
            stack.push_back(")");
            generator(ans, stack, n, openp, closep + 1);
            stack.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans, stack;
        int openp = 0, closep = 0;
        generator(ans, stack, n, openp, closep);
        return ans;
    }
};