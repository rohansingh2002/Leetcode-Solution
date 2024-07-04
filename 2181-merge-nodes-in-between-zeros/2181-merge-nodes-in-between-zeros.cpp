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
    ListNode* mergeNodes(ListNode* head) {
      ListNode* p = new ListNode(0);
        ListNode* cur =  head;
        ListNode* answer = p;
        cur = cur->next;
        int sum = 0;
        while(cur){
           if(cur->val==0){
                answer->next = new ListNode(sum);
                answer = answer->next;
                sum=0;
                cur = cur->next;
            }
             else{
                sum += cur->val;
                cur = cur->next;
            }
        }
        return p->next;  
    }
};