class WordDictionary {
private:
    struct Node {
        Node* links[26];
        bool flag;

        Node() {
            flag = false;
            for (int i = 0; i < 26; i++) {
                links[i] = nullptr;
            }
        }

        bool contains_key(char ch) {
            return links[ch - 'a'] != nullptr;
        }

        void put(char ch, Node* node) {
            links[ch - 'a'] = node;
        }

        Node* get(char ch) {
            return links[ch - 'a'];
        }

        void set_end() {
            flag = true;
        }

        bool is_end() {
            return flag;
        }
    };

    Node* root;

    bool dfs(int index, string& word, Node* node) {
        if (!node) return false;
        if (index == word.size()) return node->is_end();

        char ch = word[index];
        if (ch == '.') {
            for (int i = 0; i < 26; i++) {
                if (node->contains_key('a' + i)) {
                    if (dfs(index + 1, word, node->get('a' + i))) {
                        return true;
                    }
                }
            }
            return false;
        } else {
            if (!node->contains_key(ch)) return false;
            return dfs(index + 1, word, node->get(ch));
        }
    }

public:
    WordDictionary() {
        root = new Node();
    }

    void addWord(string word) {
        Node* node = root;
        for (char ch : word) {
            if (!node->contains_key(ch)) {
                node->put(ch, new Node());
            }
            node = node->get(ch);
        }
        node->set_end();
    }

    bool search(string word) {
        return dfs(0, word, root);
    }
};
