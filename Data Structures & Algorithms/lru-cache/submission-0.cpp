class LRUCache {
public:
    class Node{
        public : 
            int key; 
            int val; 
            Node* next;
            Node* prev; 

            Node(int key, int val){
                this->key = key; 
                this->val = val; 
            }
    };
    Node* head = new Node(-1,-1); 
    Node* tail = new Node(-1,-1); 
    int cap; 
    unordered_map<int,Node*> mp; 

    LRUCache(int capacity) {
        cap = capacity; 
        head->next = tail; 
        tail->prev = head;     
    }
    
    void addNode(Node* node){
        Node* tmp = head->next; 
        node->next  = tmp; 
        node->prev = head; 

        head->next = node; 
        tmp->prev = node; 
    }

    void deleteNode(Node* node){
        Node* prv = node->prev; 
        Node* nxt = node->next; 

        prv->next = nxt; 
        nxt->prev = prv;  
    }


    int get(int key) {
        if(mp.find(key) != mp.end()){
            Node* node = mp[key];
            int ans = node->val ; 

            mp.erase(key); 
            deleteNode(node); 
            addNode(node); 

            mp[key] = head->next; 
            return ans; 
        }
        return - 1; 
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            Node* curr = mp[key]; 
            mp.erase(key); 
            deleteNode(curr); 
        }

        if(mp.size() == cap){
            mp.erase(tail->prev->key); 
            deleteNode(tail->prev); 
        }

        addNode(new Node(key,value)); 
        mp[key] = head->next; 
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */