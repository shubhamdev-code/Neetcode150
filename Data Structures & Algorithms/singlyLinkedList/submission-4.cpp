#include <vector>
using namespace std;

// Singly Linked List Node
class ListNode {
public:
    int val; 
    ListNode* next; 

    ListNode(int val) {
        this->val = val; 
        next = nullptr; 
    }
};

class LinkedList {
private:
    ListNode* head;
    ListNode* tail;

public:
    LinkedList() {
        head = new ListNode(-1); // Dummy head
        tail = head;
    }

    int get(int index) {
        ListNode* curr = head->next;
        int i = 0;
        while (curr != nullptr) {
            if (i == index) {
                return curr->val;
            }
            i++;
            curr = curr->next;
        }
        return -1; // Index out of range
    }

    void insertHead(int val) {
        ListNode* newNode = new ListNode(val);
        newNode->next = head->next;
        head->next = newNode;
        if (newNode->next == nullptr) {
            tail = newNode;
        }
    }

    void insertTail(int val) {
        tail->next = new ListNode(val);
        tail = tail->next;
    }

    bool remove(int index) {
        int i = 0;
        ListNode* curr = head;
        while (i < index && curr != nullptr) {
            i++;
            curr = curr->next;
        }

        if (curr != nullptr && curr->next != nullptr) {
            if (curr->next == tail) {
                tail = curr;
            }
            ListNode* toDelete = curr->next;
            curr->next = curr->next->next;
            delete toDelete;
            return true;
        }
        return false;
    }

    vector<int> getValues() {
        vector<int> res;
        ListNode* curr = head->next;
        while (curr != nullptr) {
            res.push_back(curr->val);
            curr = curr->next;
        }
        return res;
    }
};
