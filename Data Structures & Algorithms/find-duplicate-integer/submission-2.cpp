class Solution {
public:
    int findDuplicate(vector<int>& nums) {
    
        int tortoise = nums[0];
        int hare = nums[0];

        tortoise = nums[tortoise]; 
        hare = nums[nums[hare]]; 

        while (tortoise != hare) {
            tortoise = nums[tortoise];
            hare = nums[nums[hare]];
        }
        
        tortoise = nums[0]; 
        while(tortoise != hare){
            hare = nums[hare]; 
            tortoise = nums[tortoise];
        }

        return hare; 
    }
};