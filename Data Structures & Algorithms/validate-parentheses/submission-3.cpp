class Solution {
public:
    bool isValid(string s) {
        if(s.length() % 2 == 1) return false; 

        stack<char> tmp; 
        for(int i =0 ; i < s.length(); i++){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{')
                tmp.push(s[i]); 
            else if(!tmp.empty() && (s[i] == ')' && tmp.top() == '(' || s[i] == '}' && tmp.top() == '{' || s[i] == ']' && tmp.top() == '[')){
                tmp.pop(); 
            } else{
                return false; 
            }
        }
        return tmp.empty(); 
    }
};
