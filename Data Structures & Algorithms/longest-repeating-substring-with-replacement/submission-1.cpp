class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> frq; int ans = k ; 

        int mx_frq = 1, j = 0 ; 
        for(int i = 0; i < s.length(); i++){
            frq[s[i]]++; 
            mx_frq = max(mx_frq,frq[s[i]]); 
            while((i -j +1) - mx_frq > k){
                frq[s[j]]--;
                j++; 
            } 
            ans = max(ans, i-j+1); 
        }
        return ans; 
    }
};
