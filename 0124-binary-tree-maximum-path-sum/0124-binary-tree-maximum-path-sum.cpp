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
    int maxPathSum(TreeNode* root) {
      int max_path_sum=INT_MIN;
      solve(root,max_path_sum);
      return max_path_sum;// Your code here    
    }
    int solve(TreeNode* root,int & max_path_sum){
        if(root==NULL){
            return 0;
        }
        // if(root -> left == NULL && root ->right == NULL) return root -> val;
        int l=max(0,(solve(root->left,max_path_sum)));
        int h=max(0,(solve(root->right,max_path_sum)));
        max_path_sum=max(max_path_sum,l+h+root->val);
        return root -> val + max(l,h);
    }  
};