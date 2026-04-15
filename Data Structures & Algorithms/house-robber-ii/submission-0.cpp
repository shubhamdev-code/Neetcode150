class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0]; 
        else if(nums.size() == 2) return max(nums[0],nums[1]); 
        else if(nums.size() == 3) return max(max(nums[0],nums[2]),nums[1]); 

        int a = nums[0] , b= max(nums[0],nums[1]), ans1 = 0, ans2 = 0 ; 
        for(int i =2; i<nums.size()-1; i++){
            ans1 = max(b, a + nums[i]); 
            a = b; 
            b = ans1; 
        }   

        a = nums[1] , b = max(nums[1],nums[2]); 
        for(int i = 3; i< nums.size(); i++){
            ans2 = max(b, a + nums[i]); 
            a  = b; 
            b= ans2; 
        }   
        return max(ans1, ans2);  
    }
};
