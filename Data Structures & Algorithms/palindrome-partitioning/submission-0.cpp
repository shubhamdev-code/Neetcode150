class Solution {
public:
    bool checkPalindrome(string s){
        int i = 0 , j =s.length()-1; 
        while(i <= j){
            if(s[i] != s[j]) return false; 
            i++; j--; 
        }
        return true; 
    }


    void solve(vector<vector<string>>& ans, string s, vector<string>& sub_ans, int in ){
        if(in >= s.length()){
            ans.push_back(sub_ans); 
            return ; 
        }

        for(int i = 1; i<=s.length(); i++){
            if(in + i <=s.length()){
                string substring = s.substr(in, i) ;
                if(checkPalindrome(substring)){
                    sub_ans.push_back(substring); 
                    solve(ans,s,sub_ans, in+i);
                    sub_ans.pop_back();
                } 
            }
            else break;
        }
        return ; 
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans ; vector<string> partition; 
        solve(ans, s, partition, 0); 
        return ans; 
    }
};