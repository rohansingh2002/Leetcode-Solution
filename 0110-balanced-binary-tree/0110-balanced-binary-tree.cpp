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
    bool isBalanced(TreeNode* root) {
      bool bal=true;
      int t=balance(root,bal);
      return bal;  
    }
    int balance(TreeNode* root,bool &bal){
        if(root==NULL) return 0;
         if(root -> left == NULL && root -> right == NULL) return 1;
        
        int l=balance(root->left,bal);
        int r=balance(root->right,bal);
        if(abs(l-r)>1){
            bal=false;
        }
        return 1 + max(l,r);
    }
};