class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> frq; 
        for(int i = 0 ; i < nums.size(); i++){
            if(frq.find(target-nums[i]) != frq.end() ) return {frq[target-nums[i]],i}; 
            frq[nums[i]] = i ; 
        }
        return {}; 
    }
};
