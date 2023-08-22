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
private:
    ListNode* findMid(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* merge(ListNode* left , ListNode* right){
        if(left==NULL) return right;
        if(right==NULL) return left;

        ListNode*ans = new ListNode(-1); //dummy node to add merging list elements
        ListNode*temp = ans;

        while(left != NULL && right!=NULL){
            if(left->val < right->val){
                temp->next = left;
                temp = left;
                left = left->next;
            }
            else{
                temp->next = right;
                temp = right;
                right = right->next;
            }
        }
        while(left!=NULL){
            temp->next = left;
            temp = left;
            left = left->next;
        }
        while(right!=NULL){
            temp->next = right;
            temp = right;
            right = right->next;
        }
        return ans->next; //return part after dummy node containing -1!
    }
public:
    ListNode* sortList(ListNode* head) {
    //base case
    if(head==NULL || head->next == NULL){
        return head;
    }   
    ListNode* mid = findMid(head);
    ListNode* left = head;
    ListNode* right = mid->next;
    mid->next = NULL;

    //recursive calls to sort both halves
    left = sortList(left);
    right = sortList(right); 

    //merge both left and right
    ListNode*result = merge(left,right);
    return result;
    }
};