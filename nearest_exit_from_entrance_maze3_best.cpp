/*You are given an m x n matrix maze (0-indexed) with empty cells (represented as '.') and walls (represented as '+'). You are also given the entrance of the maze, where entrance = [entrancerow, entrancecol] denotes the row and column of the cell you are initially standing at.

In one step, you can move one cell up, down, left, or right. You cannot step into a cell with a wall, and you cannot step outside the maze. Your goal is to find the nearest exit from the entrance. An exit is defined as an empty cell that is at the border of the maze. The entrance does not count as an exit.

Return the number of steps in the shortest path from the entrance to the nearest exit, or -1 if no such path exists.
*/

class Solution {
public:
    int sz1, sz2;
    vector<vector<char>>* mazeRef;
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        ios_base::sync_with_stdio(false);
        mazeRef = &maze;
        sz1 = maze.size();
        sz2 = maze[0].size();
        queue<pair<int,int>> qu;
        maze[entrance[0]][entrance[1]] = '+';
        qu.push({entrance[0],entrance[1]});
        pair<int,int> p;
        int steps = 1;
        while(!qu.empty()){
            queue<pair<int,int>> qnu;
            while(!qu.empty()){
                p = qu.front();
                qu.pop();
                if(isNextStep(p.first+1, p.second, qnu)){
                    return steps;
                }
                if(isNextStep(p.first-1, p.second, qnu)){
                    return steps;
                }
                if(isNextStep(p.first, p.second+1, qnu)){
                    return steps;
                }
                if(isNextStep(p.first, p.second-1, qnu)){
                    return steps;
                }
            }
            steps++;
            swap(qu,qnu);
        }
        return -1;
    }
    bool isNextStep(int i, int j, queue<pair<int,int>>& qnu){
        if(i<0||j<0||i>=sz1||j>=sz2)
            return false;
        if((*mazeRef)[i][j]=='+')
            return false;
        if(i==0||j==0||i==sz1-1||j==sz2-1)
            return true;
        
        (*mazeRef)[i][j] = '+';
        qnu.push({i,j});
        
        return false;
    }
};



// 84ms
//48.9 MB
