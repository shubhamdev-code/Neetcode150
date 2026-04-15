class KthLargest {
public:
    priority_queue<int, vector<int>,greater<int>> min_heap; 
    int max_sz;
    KthLargest(int k, vector<int>& nums) {
        max_sz = k; 
        for(int i = 0; i < nums.size(); i++) min_heap.push(nums[i]); 
    }
    
    int add(int val) {
        min_heap.push(val);
        while(min_heap.size() > max_sz){
            min_heap.pop(); 
        }
        return min_heap.top(); 
    }
};