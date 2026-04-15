class Solution {
public:
    bool isValid(char ch){
        return ch >= 'a' &&  ch <= 'z' || ch >= 'A' && ch <= 'Z' || ch >= '0' && ch <= '9'; 
    }

    bool isPalindrome(string s) {
        int i = 0,  j = s.length()-1; 
        while(i < j){
            while(i < j && !isValid(s[i])) i++; 
            while(j > i && !isValid(s[j])) j--; 
            if(tolower(s[i]) != tolower(s[j]))
                return false; 
            i++; j--; 
        }
        return true; 
    }
};
