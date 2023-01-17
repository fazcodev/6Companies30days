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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode*ansHead = NULL;
        ListNode*prev = ansHead;
        ListNode*ptr = head;
        while(ptr != NULL){
            ListNode*curr = ptr;
            int sum = curr->val;
            while(curr != NULL && sum != 0){
                curr = curr->next;
                if(curr != NULL)sum+=curr->val;
            }
            if(sum == 0){
                if(ansHead == NULL){
                    ptr = curr->next;
                }
                else{
                    prev->next = curr->next;
                    ptr = prev->next;
                }
                
            }
            else{
                if(ansHead == NULL)ansHead = ptr;
                prev = ptr;
                ptr = ptr->next;
            }
        }
        return ansHead;

    }
};
