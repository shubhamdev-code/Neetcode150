class Solution {
public:
    bool isPalindrome(string s) {
        string a = ""; 
        for(auto i : s){
            if(i >= 'a' && i <='z' || i >= 'A' && i <= 'Z' || i >= '0' && i <= '9') a += tolower(i); 
        }
        string b = a;
        reverse(b.begin(),b.end());  
        return a == b; 

    }
};
