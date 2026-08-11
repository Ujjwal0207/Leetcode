class Solution {
public:
    bool dfs(unordered_map<int, vector<int>>& adj, vector<bool>& visited, int src, int tgt) {
        visited[src] = true;

        if (src == tgt) {
            return true;
        }

        for (int adjNode : adj[src]) {
            if (!visited[adjNode]) {
                if (dfs(adj, visited, adjNode, tgt)) {
                    return true;
                }
            }
        }

        return false;
    }

    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> adj;

        for (auto& edge : prerequisites) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v); // u --> v
        }

        vector<bool> result;
        for (auto& query : queries) {
            vector<bool> visited(numCourses, false);
            int source = query[0];
            int target = query[1];

            result.push_back(dfs(adj, visited, source, target));
        }

        return result;
    }
};
