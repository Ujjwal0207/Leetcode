class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<int> indegree(n);

        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            indegree[e[1]]++;
        }

        queue<int> q;

        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        vector<set<int>> anc(n);

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v : adj[u]) {
                anc[v].insert(u);

                for (int x : anc[u])
                    anc[v].insert(x);

                indegree[v]--;

                if (indegree[v] == 0)
                    q.push(v);
            }
        }

        vector<vector<int>> ans(n);

        for (int i = 0; i < n; i++) {
            for (int x : anc[i])
                ans[i].push_back(x);
        }

        return ans;
    }
};