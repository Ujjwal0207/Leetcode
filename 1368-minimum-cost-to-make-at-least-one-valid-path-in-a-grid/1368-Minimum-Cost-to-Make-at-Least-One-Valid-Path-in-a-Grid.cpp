class Solution {
public:
    vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq; //min-heap of int
        vector<vector<int>> result(m, vector<int>(n, INT_MAX));

        pq.push({0,0,0});
        result[0][0] = 0;

        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();

            int curr_cost = curr[0];
            int i         = curr[1];
            int j         = curr[2];

            if(result[i][j] < curr_cost) {
                continue;
                }


            for(int idx=0;idx<=3;idx++){
                int i_ = i + dir[idx][0];
                int j_ = j + dir[idx][1];

                if(i_ >= 0 && j_ >= 0 && i_ < m && j_ < n){
                    int next_cost = curr_cost + (grid[i][j]-1 != idx ? 1:0);

                    if(next_cost < result[i_][j_]) {
                        result[i_][j_] = next_cost;
                        pq.push({next_cost, i_, j_});
                    }
                }
            }
        }
        return result[m-1][n-1];
    }
};