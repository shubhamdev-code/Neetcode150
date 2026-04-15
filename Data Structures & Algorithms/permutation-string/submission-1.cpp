class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length() > s2.length()) return false;
        
        vector<int> freq_s1(26); vector<int> freq_s2(26); 
        for(int i = 0; i<s1.length(); i++){
            freq_s1[s1[i]-'a']++;  
            freq_s2[s2[i]-'a']++;  
        }
        if(freq_s1 == freq_s2) return true;   
        
        int i = 1 , j = s1.length(); 
        while(j < s2.length()){
            freq_s2[s2[i-1]-'a']--; 
            freq_s2[s2[j]-'a']++; 
            if(freq_s1 == freq_s2) return true; 
            i++; j++; 
        }
        return false; 
    }
};
    
