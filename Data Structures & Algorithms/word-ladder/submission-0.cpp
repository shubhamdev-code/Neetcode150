class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(beginWord == endWord) return 0; 
        unordered_set<string> words; bool contains_endWord = false; 
        for(int i = 0; i<wordList.size(); i++){
            if(wordList[i] == endWord){
                contains_endWord = true; 
            }
            words.insert(wordList[i]);
        }
        if(!contains_endWord) return 0; 
        
        queue<string> store; 
        store.push(beginWord); int ans = 1; 
        while(!store.empty()){
            int sz = store.size(); 
            for(int i = 0; i<sz; i++){
                string curr = store.front(); 
                store.pop(); 
                for(int j = 0; j<curr.length(); j++){
                    string temp = curr; 
                    for(char ch = 'a'; ch<='z'; ch++){
                        temp[j] = ch; 
                        if(temp == curr) continue; 
                        if(temp == endWord) return ans + 1;
                        if(words.find(temp) != words.end()){
                            store.push(temp); 
                            words.erase(temp); 
                        }
                    }
                }
            }
            ans++; 
        }
        return 0; 
    }
};
