class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>> anagrams; 
        for(int i =0 ; i < strs.size(); i++){
            string x = strs[i]; 
            sort(x.begin(),x.end()); 
            anagrams[x].push_back(strs[i]); 
        }

        vector<vector<string>> ans; 
        for(auto i : anagrams){
            ans.push_back(i.second); 
        }
        return ans; 
    }
};
