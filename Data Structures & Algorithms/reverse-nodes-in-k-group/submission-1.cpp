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
        ListNode* reverseList(ListNode* head, int k , ListNode* connect , ListNode* prev) {
            if(!head || !head->next) return head; 

            ListNode* currNode = head; 
            ListNode* nextNode = head->next; 
            ListNode* tmp = nullptr; 
            
            currNode->next = connect; int sz = k-1;    

            while(nextNode && sz--){
                tmp = nextNode->next; 
                nextNode->next = currNode; 
                currNode = nextNode; 
                nextNode = tmp; 
            }
            prev->next = currNode; 
            return currNode; 
    }
    
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* newHead = head; 
        
        for(int i = 1; i<k; i++){
            newHead = newHead->next; 
            if(newHead == nullptr){
                return head;  
            }
        }
  
        ListNode* connector = head; ListNode* sentinel = new ListNode(0); 
        while(head != nullptr){
            ListNode* start = head;
            for(int i = 1; i<k; i++){
                head = head->next; 
                if(head == nullptr) return newHead; 
            }
            
            head = head->next; 
            connector = reverseList(start,k,head,sentinel);
            sentinel = start; 
        }
        
        return newHead; 
    }
};