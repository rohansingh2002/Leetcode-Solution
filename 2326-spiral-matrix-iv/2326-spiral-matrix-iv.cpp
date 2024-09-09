/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        int left = 0, right = n-1;
        int up = 0, down = m-1;
        vector<vector<int>>vec(m,vector<int>(n,-1));
        ListNode* root = head;
        while(left <= right && up <= down && root != NULL){
            for(int i = left; i <= right && root != NULL; i++){
                vec[left][i] = root->val;
                root = root->next;
            }
            up++;
            for(int i = up; i <= down && root != NULL; i++){
                vec[i][right] = root->val;
                root = root->next;
            }
            right--;
            for(int i = right; i >= left && root != NULL; i--){
                vec[down][i] = root->val;
                root = root->next;
            }
            down--;
            for(int i = down; i >= up && root != NULL; i--){
                vec[i][left] = root->val;
                root = root->next;
            }
            left++;
        }
        return vec;
    }
};