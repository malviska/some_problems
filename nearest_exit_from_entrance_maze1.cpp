/* You are given an m x n matrix maze (0-indexed) with empty cells (represented as '.') and walls (represented as '+'). You are also given the entrance of the maze, where entrance = [entrancerow, entrancecol] denotes the row and column of the cell you are initially standing at.

In one step, you can move one cell up, down, left, or right. You cannot step into a cell with a wall, and you cannot step outside the maze. Your goal is to find the nearest exit from the entrance. An exit is defined as an empty cell that is at the border of the maze. The entrance does not count as an exit.

Return the number of steps in the shortest path from the entrance to the nearest exit, or -1 if no such path exists.

*/

class Solution {
public:
    int sz1, sz2;
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        sz1 = maze.size();
        sz2 = maze[0].size();
        queue<vector<int>> qu;
        maze[entrance[0]][entrance[1]] = '+';
        qu.push({entrance[0], entrance[1], 0});
        vector<int> val;
        vector<vector<int>> dir = {{1,0},{0,1},{-1,0},{0,-1}};
        while(!qu.empty()){
            val = qu.front();
            qu.pop();
            for(int k = 0; k<4; k++){
                vector<int> coord = {val[0]+dir[k][0], val[1]+dir[k][1], val[2]+1};
                if(isValid(coord) && maze[coord[0]][coord[1]] != '+'){
                    if(isBorder(coord)){
                        return coord[2];
                    }
                    qu.push(coord);
                    maze[coord[0]][coord[1]] = '+';
                }
            }
        }
        
        return -1;
    }
    bool isValid(vector<int> val){
        if(val[0]<0||val[1]<0||val[0]>=sz1||val[1]>=sz2){
            return false;
        }
        
        return true;
    }
    
    bool isBorder(vector<int> val){
        if(val[0]==0||val[0]==sz1-1||val[1]==0||val[1]==sz2-1)
            return true;
        return false;
    }
};
