class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> last_index; 
        int i = 0,ans = 0 ; 
        for(int j = 0; j<s.length(); j++){
            if(last_index.find(s[j]) != last_index.end()){
                i = max(i,last_index[s[j]]+1);
            }
            last_index[s[j]] = j; 
            ans = max(ans,j-i+1);
        }
        return ans;
    }
};
