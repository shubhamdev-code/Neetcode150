class Solution {
public:

    string encode(vector<string>& strs) {
        string x = ""; 
        for(int i = 0; i < strs.size(); i++){
            x += strs[i]; 
            x += ';'; 
        }
        return x; 
    }

    vector<string> decode(string s) {
        vector<string> ans; 
        string x = ""; 
        for(int i = 0; i < s.length(); i++){
            if(s[i] == ';'){
                ans.push_back(x); 
                x =""; 
                continue; 
            }
            x += s[i]; 
        }
        return ans; 
    }
};
