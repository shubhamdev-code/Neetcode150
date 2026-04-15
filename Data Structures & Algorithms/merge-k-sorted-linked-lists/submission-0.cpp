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
    ListNode* mergeLists(ListNode* l1, ListNode* l2){
        if(!l1) return l2; 
        else if(!l2) return l1; 
        
        ListNode* start = nullptr; 
        if(l1->val <= l2->val){
            start = l1; 
            l1 = l1->next; 
        }
        else{
            start = l2; 
            l2 = l2->next; 
        }
        
        ListNode* curr = start; 
        while(l1 && l2){
            if(l1->val <= l2->val){
                curr->next = l1; 
                l1 = l1->next; 
            } else{ 
                curr->next = l2; 
                l2 = l2->next;
            }
            curr = curr->next; 
        }
        l1 != nullptr ? curr->next = l1 : curr->next = l2; 
        return start; 
    }
    
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return nullptr; 
        for(int i = 1; i<lists.size(); i++){
            lists[0] = mergeLists(lists[0],lists[i]); 
        }
        return lists[0]; 
    }
};