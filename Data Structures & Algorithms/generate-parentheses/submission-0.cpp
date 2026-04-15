class Solution {
private : 
    void dfs(string s, int n , int open_cnt, int closed_cnt, vector<string>& ans){
        if(s.length() == n *2){
            ans.push_back(s); 
            return ; 
        }

        if(open_cnt < n){
            dfs(s+'(', n, open_cnt+1, closed_cnt,ans); 
        }  if(closed_cnt < open_cnt){
            dfs(s + ')', n,open_cnt, closed_cnt+1,ans); 
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans; 
        dfs("",n,0,0,ans); 
        return ans;
    }
};
