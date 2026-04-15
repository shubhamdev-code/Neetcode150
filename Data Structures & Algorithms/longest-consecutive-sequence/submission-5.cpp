class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;

        map<int,int> frq; 
        for(int i = 0; i < nums.size(); i++) frq[nums[i]]++; 

        int len = 1, ans = 1; 
        for(auto i : frq){
            int num = i.first+1; 
            if(frq.find(num) != frq.end()){
                len++; 
                ans = max(len, ans); 
            } else len = 1; 
        }
        return ans;
    }
};
     