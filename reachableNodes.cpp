/*
There is an undirected tree with n nodes labeled from 0 to n - 1 and n - 1 edges.

You are given a 2D integer array edges of length n - 1 where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the tree. You are also given an integer array restricted which represents restricted nodes.

Return the maximum number of nodes you can reach from node 0 without visiting a restricted node.

Note that node 0 will not be a restricted node.
*/


class Solution {
public:
    int dfs(vector<vector<int>>& graph, vector<int>& seen, int src){
        if(seen[src])
            return 0;
        seen[src] = true;
        int ans = 1;
        for(int i = 0; i<graph[src].size(); i++){
            ans += dfs(graph, seen, graph[src][i]);
        }
        
        return ans;
    }
    
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        vector<vector<int>> graph(n);
        vector<int> seen(n, false);
        for(int i = 0; i<restricted.size(); i++){
            seen[restricted[i]] = true;
        }
        for(int i = 0; i<edges.size(); i++){
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        int ans = 0;
        
        return ans + dfs(graph, seen, 0);
    }
};
