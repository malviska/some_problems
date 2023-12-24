class Solution {
public:
    bool isValidUnseen(int di, int dj){
        return (di >= 0)&&(di < m)&&(dj >= 0)&&(dj < n)&&(graph[di][dj] == 1);
    }
    
    void dfs(int i, int j, int& area, vector<vector<int>>& grid){
        vector<vector<int>> dir = {{0,1},{1,0},{-1,0},{0,-1}};
        for(int k = 0; k<4; k++){
            int di = i + dir[k][0];
            int dj = j + dir[k][1];
            if(isValidUnseen(di,dj)){
                grid[di][dj] = 0;
                area++;
                dfs(di, dj, area);
            }
        }
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int Area = 0;
        int m = grid.size();
        int n = grid[0].size();
        int area = 0;
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j] == 1){
                    grid[i][j] = 0;
                    area++;
                    dfs(i,j,area, grid,m,n);
                    Area = max(Area, area);
                    area = 0;
                }
            }
        }
        
        return Area;
    }
};
