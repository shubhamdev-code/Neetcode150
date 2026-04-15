class Solution {
public:
    vector<string> letterCombinations(string digits){         
        if(digits.length() == 0) return vector<string>();

        vector<vector<string>> letter{{},{},{"a","b","c"},{"d","e","f"},{"g","h","i"},{"j","k","l"},{"m","n","o"},{"p","q","r","s"},{"t","u","v"},{"w","x","y","z"}}; 
        vector<string> ans;  int n = digits.length();
        
        for(int i = 0; i<letter[digits[0]-'0'].size(); i++){  
            if(n >= 2)
                for(int j = 0; j<letter[digits[1]-'0'].size(); j++){
                    if(n >= 3)
                        for(int k = 0; k<letter[digits[2]-'0'].size(); k++){
                            if(n == 4)
                                for(int l = 0; l<letter[digits[3]-'0'].size(); l++)
                                    ans.push_back(letter[digits[0]-'0'][i] + letter[digits[1]-'0'][j] + letter[digits[2]-'0'][k]+ letter[digits[3]-'0'][l]); 

                            else ans.push_back(letter[digits[0]-'0'][i] + letter[digits[1]-'0'][j] + letter[digits[2]-'0'][k]); 
                        }        
                    else ans.push_back(letter[digits[0]-'0'][i]+ letter[digits[1]-'0'][j]); 
                }
            else ans.push_back(letter[digits[0]-'0'][i]); 
        }
        return ans; 
    }
};
    