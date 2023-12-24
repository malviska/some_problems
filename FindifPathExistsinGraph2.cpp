/*
There is a bi-directional graph with n vertices, where each vertex is labeled from 0 to n - 1 (inclusive). The edges in the graph are represented as a 2D integer array edges, where each edges[i] = [ui, vi] denotes a bi-directional edge between vertex ui and vertex vi. Every vertex pair is connected by at most one edge, and no vertex has an edge to itself.

You want to determine if there is a valid path that exists from vertex source to vertex destination.

Given edges and the integers n, source, and destination, return true if there is a valid path from source to destination, or false otherwise.
*/



class Solution {
public:
    
    bool hasPath = false;
    
    void dfs(vector<vector<int>>& graph, int node, int dest, vector<int>& seen){
        for(int i = 0; i< graph[node].size(); i++){
            int nd = graph[node][i];
            if(nd == dest){
                hasPath = true;
                return;
            }
            if(!seen[nd]){
                seen[nd] = true;
                dfs(graph, nd, dest, seen);
            }
        }
    }
    
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if(n == 1)
            return true;
        vector<int> seen(n, false);
        vector<vector<int>> graph(n);
        for(int i = 0; i< edges.size(); i++){
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        dfs(graph, source, destination, seen);
        
        return hasPath;
    }
};
