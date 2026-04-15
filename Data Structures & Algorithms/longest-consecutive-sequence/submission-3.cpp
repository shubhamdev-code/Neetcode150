class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }
        if(nums.size()==1){
            return 1; 
        }
        sort(nums.begin(),nums.end()); 
        int consecutive_cnt = 1 ; int longest_consecutive = 0; 
        for(int i = 1; i<nums.size(); i++){
            if(nums[i] - nums[i-1] == 1){
                consecutive_cnt++; 
            }  
            else if(nums[i] - nums[i-1] > 1){
                consecutive_cnt = 1;                     
            }
            longest_consecutive = max(consecutive_cnt,longest_consecutive); 
        }
        return longest_consecutive;
    }
};
     