class Solution {
public:
vector<vector<int>> allPaths;
int n;
void dfs(int node, vector<int> &currentPath, vector<vector<int>> &graph){
if (node == n-1){
            allPaths.push_back(currentPath);
            return;
        }
        for (int neighbour : graph[node]){
            currentPath.push_back(neighbour);
            dfs(neighbour, currentPath, graph);
            currentPath.pop_back();
        }
} 
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        n = graph.size();
        vector<int> currentPath;
        currentPath.push_back(0);
        dfs(0, currentPath, graph);
        return allPaths;

        

        
    }
};