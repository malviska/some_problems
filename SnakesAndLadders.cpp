/*
You are given an n x n integer matrix board where the cells are labeled from 1 to n2 in a Boustrophedon style starting from the bottom left of the board (i.e. board[n - 1][0]) and alternating direction each row.

You start on square 1 of the board. In each move, starting from square curr, do the following:

    Choose a destination square next with a label in the range [curr + 1, min(curr + 6, n2)].
        This choice simulates the result of a standard 6-sided die roll: i.e., there are always at most 6 destinations, regardless of the size of the board.
    If next has a snake or ladder, you must move to the destination of that snake or ladder. Otherwise, you move to next.
    The game ends when you reach the square n2.

A board square on row r and column c has a snake or ladder if board[r][c] != -1. The destination of that snake or ladder is board[r][c]. Squares 1 and n2 do not have a snake or ladder.

Note that you only take a snake or ladder at most once per move. If the destination to a snake or ladder is the start of another snake or ladder, you do not follow the subsequent snake or ladder.

    For example, suppose the board is [[-1,4],[-1,3]], and on the first move, your destination square is 2. You follow the ladder to square 3, but do not follow the subsequent ladder to 4.

Return the least number of moves required to reach the square n2. If it is not possible to reach the square, return -1.

*/

class Solution {
public:
    void addEdges(vector<int>& edges, int node, int size){
        int k = 1;
        int value = node + k;
        while(value<min(node+6, size)+1){
            edges.push_back(value);
            k++;
            value = node + k;
        }
    }
    unordered_map<int, vector<int>> mkGraph(vector<vector<int>>& board){
        unordered_map<int,vector<int>> graph;
        int size = board.size()*board.size();
        int node = 0;
        int switcher = 0;
        if(board.size() % 2 == 1)
            switcher = 1;
        for (int i = board.size() - 1; i>-1; i--){
            if(i%2==switcher){
                for(int j = board[0].size() -1; j>-1; j--){
                    vector<int> edges;
                    edges.push_back(board[i][j]);
                    addEdges(edges, ++node, size);
                    graph[node] = edges;
                }
            }else{
                for(int j = 0; j<board[0].size(); j++){
                    vector<int> edges;
                    edges.push_back(board[i][j]);
                    addEdges(edges, ++node, size);
                    graph[node] = edges;
                }
            }

        }
        return graph;
    }

    int snakesAndLadders(vector<vector<int>>& board) {
        unordered_map<int, vector<int>> graph = mkGraph(board);
        int size = board.size()*board.size();
        vector<pair<bool,bool>> seen(size+1, {false, false});
        queue<array<int,2>> qu;
        qu.push({1,0});
        seen[1].second = true;
        while(!qu.empty()){
            array<int,2> turn = qu.front();
            if(turn[0] == size){
                return turn[1];
            }
            qu.pop();
            int node = turn[0], steps = turn[1];
            vector<int> values = graph[node];
            for(int i = 1; i < values.size(); i++){
                if(seen[values[i]].second){
                    continue;
                }
                seen[values[i]].second = true;
                if(graph[values[i]][0] != -1){
                    if(seen[graph[values[i]][0]].first){
                        continue;
                    }
                    qu.push({graph[values[i]][0], steps+1});
                    seen[graph[values[i]][0]].first = true;
                    continue;
                }
                qu.push({values[i], steps+1});
            }

        }

        return -1;

    }
};


















