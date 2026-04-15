class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> max_heap; 
        for(int i = 0; i<nums.size(); i++){
            max_heap.push(nums[i]); 
        }
        
        int ans = max_heap.top(); 
        while(k--){
            ans = max_heap.top(); 
            max_heap.pop(); 
        }
        return ans; 
    }
};