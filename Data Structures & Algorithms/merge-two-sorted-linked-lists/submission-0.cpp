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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1 && !list2) return nullptr; 
        if(!list1) return list2; 
        if(!list2) return list1; 


        ListNode* god; 
        if(list1->val <= list2->val){
            god = list1; 
            list1 = list1->next; 
        }  else{
            god = list2; 
            list2 = list2->next; 
        }
        
        ListNode* curr = god; 
        while(list1 && list2){
            if(curr->val <= list1->val && curr->val <= list2->val){
                if(list1->val <= list2->val ){
                    curr->next = list1; 
                    list1 = list1->next; 
                } else{
                    curr->next = list2; 
                    list2 = list2->next; 
                }
            } else if(curr->val <= list1->val){
                curr->next = list1; 
                list1 = list1->next; 
            } else{
                curr->next = list2; 
                list2 = list2->next; 
            }
            curr = curr->next; 
        }

        if(list1) curr->next = list1; 
        if(list2) curr->next = list2; 
        
        return god; 
    }
};
