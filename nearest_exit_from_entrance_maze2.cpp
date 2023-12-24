
/*You are given an m x n matrix maze (0-indexed) with empty cells (represented as '.') and walls (represented as '+'). You are also given the entrance of the maze, where entrance = [entrancerow, entrancecol] denotes the row and column of the cell you are initially standing at.

In one step, you can move one cell up, down, left, or right. You cannot step into a cell with a wall, and you cannot step outside the maze. Your goal is to find the nearest exit from the entrance. An exit is defined as an empty cell that is at the border of the maze. The entrance does not count as an exit.

Return the number of steps in the shortest path from the entrance to the nearest exit, or -1 if no such path exists.
*/

class Solution {
public:
    int sz1, sz2;
    vector<vector<char>>* mazeRef;
    queue<vector<int>>* quRef;
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        ios_base::sync_with_stdio(false);
        mazeRef = &maze;
        sz1 = maze.size();
        sz2 = maze[0].size();
        queue<vector<int>> qu;
        quRef = &qu;
        maze[entrance[0]][entrance[1]] = '+';
        qu.push({entrance[0],entrance[1],0});
        vector<int> p;
        int steps;
        while(!qu.empty()){
            p = qu.front();
            qu.pop();
            steps = p[2]+1;
            if(isNextStep(p[0]+1, p[1], steps)){
                return steps;
            }
            if(isNextStep(p[0]-1, p[1], steps)){
                return steps;
            }
            if(isNextStep(p[0], p[1]+1, steps)){
                return steps;
            }
            if(isNextStep(p[0], p[1]-1, steps)){
                return steps;
            }
        }
        return -1;
    }
    bool isNextStep(int i, int j, int steps){
        if(i<0||j<0||i>=sz1||j>=sz2)
            return false;
        if((*mazeRef)[i][j]=='+')
            return false;
        if(i==0||j==0||i==sz1-1||j==sz2-1)
            return true;
        
        (*mazeRef)[i][j] = '+';
        quRef->push({i,j, steps});
        
        return false;
    }
};
