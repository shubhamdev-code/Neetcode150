class Solution {
public:
    string minWindow(string s, string t) {
                if(s.length() < t.length() || t == "") return ""; 
        if(s==t) return s; 

        unordered_map<char,int> req_frq;
        for(int i = 0; i  < t.length(); i++){
            req_frq[t[i]]++; 
        }

        int req_len = req_frq.size(), curr_len = 0, i = 0; 
        unordered_map<char,int> curr_frq; vector<int> x = {0,0}; int ans = s.length(); bool flag = false; 
        for(int j = 0; j < s.length(); j++){
            curr_frq[s[j]]++; 

            if(req_frq.find(s[j]) != req_frq.end() && curr_frq[s[j]] == req_frq[s[j]]) curr_len++; 


            while(curr_len == req_len){
                flag = true; 
                curr_frq[s[i]]--; 
                if(j - i + 1 < ans){
                    ans = min(ans,j-i+1); 
                    x[0] = i; x[1] = j-i+1; 
                }
          
                if(req_frq.find(s[i]) != req_frq.end() && curr_frq[s[i]] < req_frq[s[i]]){
                    curr_len--; 
                } 
                i++; 
            }    
        }
        return flag ? s.substr(x[0],ans) : ""; 

    }
};
