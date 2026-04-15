class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < board.size(); i++){
            for(int j = 0 ; j < board[0].size(); j++){
                if(board[i][j] =='.') board[i][j] = '0'; 
            }
        }
        

        for(int i = 0; i < 9; i++){
            vector<int> frq(10,0); 
            for(int j =0 ; j < 9; j++){
                frq[board[i][j]-'0']++; 
                if(board[i][j] != '0' && frq[board[i][j] - '0'] > 1){
                    cout<<"0"; 
                    return false; 
                }
            }
        }

        for(int i = 0; i < 9; i++){
            vector<int> frq(10,0); 
            for(int j = 0 ; j < 9; j++){
                frq[board[j][i]-'0']++; 
                if(board[j][i] != '0' && frq[board[j][i] - '0'] > 1){
                    cout<<"1"; 
                    return false; 
                } 
            }
        }

        int i = 0; int j = 0; vector<int> frq(10,0); 
        while(i < 9){
            for(int j = 0; j < 9; j++){
                frq[board[i][j]-'0']++; 
                frq[board[i+1][j]-'0']++; 
                frq[board[i+2][j]-'0']++;

                if(j == 2|| j == 5 || j == 8){
                    for(int k = 1; k <=9; k++){
                        if(frq[k] >1 ){
                            cout<<"2"; 
                            return false; 
                        } 
                    }

                    for(int k = 1; k <= 9 ; k++) frq[k] = 0;
                } 
            }
            i += 3; 
        }
        return true; 
    }
};
