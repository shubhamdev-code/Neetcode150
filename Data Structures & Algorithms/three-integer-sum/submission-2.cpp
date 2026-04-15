class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end()); 
        vector<vector<int>> ans; 
        for(int i = 0; i<nums.size()-2; i++){
            if(i == 0 || (i > 0 && nums[i] != nums[i-1])){
                int left = i+1, right = nums.size()-1, target = 0-nums[i]; 
                while(left < right){
                    if(nums[left] + nums[right] > target) right--; 
                    else if(nums[left] + nums[right] < target) left++; 
                    else{
                        ans.push_back({-target,nums[left],nums[right]}); 
                        while(left < right && nums[left] == nums[left+1]) left++; 
                        while(right > left && nums[right] == nums[right-1]) right--; 
                        left++; right--; 
                    }
                }
            }
        }
        return ans;
    }
};