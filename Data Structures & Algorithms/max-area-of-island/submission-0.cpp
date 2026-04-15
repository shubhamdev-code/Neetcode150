class Solution {
public:
    void dfs(int i, int j , vector<vector<int>>& grid, int& ans, int& curr_area){
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 0) return ; 

        grid[i][j]= 0; 

        curr_area++; 
        dfs(i+1,j,grid,ans,curr_area); 
        dfs(i-1,j,grid,ans,curr_area); 
        dfs(i,j+1,grid,ans,curr_area); 
        dfs(i,j-1,grid,ans,curr_area); 
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0 ; 
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j< grid[0].size(); j++){
                if(grid[i][j]){
                    int curr_area = 0; 
                    dfs(i,j,grid,ans,curr_area);
                    ans= max(ans,curr_area); 
                }
            }
        }
        return ans; 
    }
};