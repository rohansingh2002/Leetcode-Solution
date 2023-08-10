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
    bool find_tar(TreeNode* root, int k, map<int,bool>&mp){
        if(root == NULL) return false;
        if(mp.find(k-root->val) != mp.end()){
            return true;
        }
        mp[root->val] = true;
        return find_tar(root->left,k,mp) || find_tar(root->right,k,mp);
        
    }
    bool findTarget(TreeNode* root, int k) {
         map<int,bool>mp;
         
         return find_tar(root, k,mp);
    }
};