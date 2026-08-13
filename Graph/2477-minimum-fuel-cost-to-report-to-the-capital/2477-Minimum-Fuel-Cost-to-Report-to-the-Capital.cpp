class Solution {
public:
    long long dfs(int u, int parent, vector<vector<int>>& adj, int seats, long long& fuel) {
        long long people = 1;

        for (int v : adj[u]) {
            if (v == parent)
                continue;

            people += dfs(v, u, adj, seats, fuel);
        }

        if (u != 0) {
            fuel += (people + seats - 1) / seats;
        }

        return people;
    }

    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = roads.size() + 1;

        vector<vector<int>> adj(n);

        for (auto &road : roads) {
            int u = road[0];
            int v = road[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        long long fuel = 0;

        dfs(0, -1, adj, seats, fuel);

        return fuel;
    }
};