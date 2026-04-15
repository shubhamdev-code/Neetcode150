class Solution {
public:
    void permuted(int in,vector<int> nums,vector<vector<int>>& ans){
        if(in == nums.size()){
            ans.push_back(nums); 
            return ; 
        }
        for(int i = in; i<nums.size(); i++){
            swap(nums[in],nums[i]); 
            permuted(in + 1,nums, ans);
            swap(nums[in],nums[i]); 
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans; 
        permuted(0,nums,ans); 
        return ans;
    }
};

    