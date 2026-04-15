class Solution {
    struct Node {
        Node* links[26];
        bool flag = false;

        bool contains_key(char ch) {
            return links[ch - 'a'] != nullptr;
        }

        void put(char ch, Node* node) {
            links[ch - 'a'] = node;
        }

        Node* get(char ch) {
            return links[ch - 'a'];
        }
    };

    Node* root;

public:
    Solution() {
        root = new Node();
    }

    void insert(string word) {
        Node* node = root;
        for (int i = 0; i < word.length(); i++) {
            if (!node->contains_key(word[i])) {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        node->flag = true;
    }

    void dfs(vector<vector<char>>& board, int i, int j, Node* node, string& currentWord, vector<string>& result) {
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] == '*') {
            return;
        }

        char ch = board[i][j];
        if (!node->contains_key(ch)) {
            return;
        }

        currentWord.push_back(ch);
        node = node->get(ch);

        if (node->flag) {
            result.push_back(currentWord);
            node->flag = false; 
        }

        board[i][j] = '*'; 

        dfs(board, i + 1, j, node, currentWord, result);
        dfs(board, i - 1, j, node, currentWord, result);
        dfs(board, i, j + 1, node, currentWord, result);
        dfs(board, i, j - 1, node, currentWord, result);

        board[i][j] = ch; 

        currentWord.pop_back(); 
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Solution trie;
        vector<string> ans;

        for(int i = 0; i <words.size(); i++){
            trie.insert(words[i]);
        }

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                string word = "";
                dfs(board, i, j, trie.root, word, ans);
            }
        }

        return ans;
    }
};