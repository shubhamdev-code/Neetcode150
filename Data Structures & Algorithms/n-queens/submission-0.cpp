class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans; 
        
        vector<bool> occupied_cols(n); 
        vector<bool> occupied_ldiags(2*n-1); 
        vector<bool> occupied_rdiags(2*n-1); 
        
        vector<string> board(n,string(n,'.'));
        auto can_fill = [&](int row,int col){
            return !(occupied_cols[col] || occupied_ldiags[col-row+n-1] || occupied_rdiags[row+col]); 
        };
        
        auto fill = [&](int row, int col){
            occupied_cols[col] = true; 
            occupied_ldiags[col-row+n-1] = true; 
            occupied_rdiags[row+col] = true; 
            board[row][col] = 'Q';
        };
        
        auto clear = [&](int row, int col){
            occupied_cols[col] = false; 
            occupied_ldiags[col-row+n-1] = false; 
            occupied_rdiags[row+col] = false; 
            board[row][col] = '.';
        };
        
        function<void(int)> solve = [&](int row){
            if(row >= n){
                ans.push_back(board); 
            }
            else{
                for(int col = 0 ; col < n; col++){
                    if(can_fill(row,col)){
                        fill(row,col); 
                        solve(row+1); 
                        clear(row,col); 
                    }
                }
            }
        };
        solve(0); 
        return ans; 
    }
};