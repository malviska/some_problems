class Solution {
public:
    void dfs(vector<vector<int>>& graph, vector<bool>& seen, int src){
        for(int i = 0; i<graph[src].size(); i++){
            if(!seen[graph[src][i]]){
                seen[graph[src][i]] = true;
                dfs(graph, seen, graph[src][i]);
            }
        }
    }


    int countComponents(int n, vector<vector<int>>& edges) {
		int components = 0;
        if(n == 1){
            return 1;
        }
        vector<bool> seen(n, false);
        vector<vector<int>> graph(n);
        for(int i = 0; i < edges.size(); i++){
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
		for(int j = 0; j<seen.size(); j++){
            if(!seen[j]){
                components++;
                seen[j] = true;
                dfs(graph, seen, j);
            }
		}
        
       return components; 
    }
};

