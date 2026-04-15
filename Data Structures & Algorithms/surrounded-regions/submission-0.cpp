class Solution {
public:
    void dfs(int i, int j, vector<vector<int>>& vis, vector<vector<char>>& board) {
        if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || vis[i][j] == 1 || board[i][j] != 'O')
            return;

        vis[i][j] = 1;
        dfs(i + 1, j, vis, board);
        dfs(i - 1, j, vis, board);
        dfs(i, j + 1, vis, board);
        dfs(i, j - 1, vis, board);
    }

    void solve(vector<vector<char>>& board) {
        vector<vector<int>> vis(board.size(), vector<int>(board[0].size(), 0));

        for(int i = 0; i < board.size(); i++) {
            if(board[i][0] == 'O') dfs(i, 0, vis, board);
            if(board[i][board[0].size() - 1] == 'O') dfs(i, board[0].size() - 1, vis, board);
        }

        for(int i = 0; i < board[0].size(); i++) {
            if(board[0][i] == 'O') dfs(0, i, vis, board);
            if(board[board.size() - 1][i] == 'O') dfs(board.size() - 1, i, vis, board);
        }

        for(int i = 1; i < board.size(); i++) {
            for(int j = 1; j < board[0].size(); j++) {
                if(!vis[i][j] && board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
    }
};