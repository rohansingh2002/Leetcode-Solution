/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == NULL) return {};
        vector<vector<int>>ans;
        queue<TreeNode*>q;
        q.push(root);
        TreeNode *temp;
        while(!q.empty()){
          int sz = q.size();
          vector<int>v;
          for(int i = 0; i < sz; i++){
             temp = q.front();
             v.push_back(temp->val);
             q.pop();
             if(temp->left){
                 q.push(temp->left);
             }
             if(temp->right){
                 q.push(temp->right);
             }
          }
          ans.push_back(v);     
        }
        return ans;

    }
};

