class Solution {
public:
    long long finishTime(int n, vector<vector<int>>& edges, vector<int>& baseTime) {
        vector<int> parent(n, -1);
        vector<int> childrenCount(n, 0);

        for(auto &e : edges) {
            int u = e[0];
            int v = e[1];

            parent[v] = u;
            childrenCount[u]++;
        }

        vector<int> processedChildren(n, 0);

        vector<long long> earliest(n, LLONG_MAX);
        vector<long long> latest(n, 0);
        vector<long long> finish(n, 0);

        queue<int> q;

        for(int i = 0; i < n; i++) {

            if(childrenCount[i] == 0) {

                finish[i] = baseTime[i];
                q.push(i);
            }
        }

        while(!q.empty()) {

            int u = q.front();
            q.pop();

            if(u == 0)
                continue;

            int p = parent[u];

            earliest[p] = min(earliest[p], finish[u]);
            latest[p] = max(latest[p], finish[u]);

            processedChildren[p]++;

            if(processedChildren[p] == childrenCount[p]) {

                long long ownDuration =
                    (latest[p] - earliest[p]) + baseTime[p];

                finish[p] = latest[p] + ownDuration;

                q.push(p);
            }
        }

        return finish[0];
    }
};