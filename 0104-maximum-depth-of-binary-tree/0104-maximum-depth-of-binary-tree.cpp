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
    int maxDepth(TreeNode* root) {
       int maxi = 0;
       maxDep(root ,maxi);
        return maxi;
    
    }
    int maxDep(TreeNode* root , int& maxi) {
        if(root == NULL) return 0; 
        
       // if(root -> left == NULL && root -> right == NULL) return 1;
         
        int lh = maxDepth(root->left); 
        int rh = maxDepth(root->right); 
        maxi = max(maxi,max(lh,rh)+1);
        return 1 + max(lh , rh); 
    }
};