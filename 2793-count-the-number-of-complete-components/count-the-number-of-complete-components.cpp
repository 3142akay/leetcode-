class Solution {
public:
void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited,
             int& vertexCount, int& edgeCount) {
        
        visited[node] = true;     // Mark current node as visited
        vertexCount++;            // Increment vertex count
        
        // Visit all neighbors
        for(int neighbor : adj[node]) {
            
            // Count edge only once (when current < neighbor)
            // This avoids counting same edge twice in undirected graph
            if(node < neighbor) {
                edgeCount++;
            }
            
            // If neighbor not visited, do DFS
            if(!visited[neighbor]) {
                dfs(neighbor, adj, visited, vertexCount, edgeCount);
            }
        }
    }
    
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto& edge: edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool> visited(n, false);
        int completeCount =0;
        for(int i=0; i<n; i++){
            if(!visited[i]){
                int vertexCount = 0;
                int edgeCount = 0;
                dfs(i, adj, visited, vertexCount, edgeCount);
                int requiredEdges = vertexCount * (vertexCount - 1)/2;
                if(edgeCount == requiredEdges){
                    completeCount++;
                }
            }
        }
        return completeCount++;

        
    }
};