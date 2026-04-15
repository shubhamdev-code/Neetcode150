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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
                ListNode* sentinel = new ListNode(0); 
        ListNode* newHead = sentinel; 
        int sum = 0 ; 
        
        while(l1 || l2){
            sum /= 10 ; 
            if(l1){
                sum += l1->val; 
                l1 = l1->next; 
            }
            if(l2){
                sum += l2->val;
                l2 = l2->next; 
            }
            sentinel->next = new ListNode(sum % 10); 
            sentinel = sentinel->next; 
            
        }
        if(sum / 10 == 1){
            sentinel->next = new ListNode(1); 
        }
        return newHead->next; 

    }
};
