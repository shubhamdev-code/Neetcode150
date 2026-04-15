class Solution {
private : 
    bool farthestIndex(vector<vector<char>>& board, int i, int j, string word, int in){
        if(in == word.length()) return true; 
        if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || in > word.length() || word[in] != board[i][j] || board[i][j] == '0') return false; 
        
        if(board[i][j] == word[in] && board[i][j] != '0'){
            in++; 
        }
        char ch = board[i][j]; 
        board[i][j] = '0';

        bool ans = farthestIndex(board,i-1,j,word,in) || farthestIndex(board,i+1,j,word,in) || farthestIndex(board,i,j-1,word,in) ||farthestIndex(board,i,j+1,word,in); 
        board[i][j] = ch; 
        return ans; 
    }    
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0; i<board.size(); i++){
            for(int j = 0; j<board[i].size(); j++){
                if(board[i][j] == word[0] && farthestIndex(board,i,j,word,0)){
                    return true; 
                }
            }
        }
        return false; 
    }
};