/*

You are given an m x n binary matrix grid. An island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

The area of an island is the number of cells with a value 1 in the island.

Return the maximum area of an island in grid. If there is no island, return 0.

*/

class Solution {
public:
    int m;
    int n;
    vector<vector<int>> graph;
    int Area = 0;
    
    bool isValidUnseen(int di, int dj){
        return !(di<0||dj<0||di>=m||dj>=n||graph[di][dj] == 0);
    }
    
    void dfs(int i, int j, int& area){
        if(!isValidUnseen(i,j)) 
            return;
        area++;
        graph[i][j] = 0;
        dfs(i-1,j,area);
        dfs(i+1,j,area);
        dfs(i,j+1,area);
        dfs(i,j-1,area);
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        graph = grid;
        m = graph.size();
        n = graph[0].size();
        int area = 0;
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(graph[i][j] == 1){
                    dfs(i,j, area);
                    Area = max(Area, area);
                    area = 0;
                }
            }
        }
        
        return Area;
    }
};

