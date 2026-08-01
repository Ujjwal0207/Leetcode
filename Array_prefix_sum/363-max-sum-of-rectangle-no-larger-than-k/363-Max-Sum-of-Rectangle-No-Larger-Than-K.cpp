class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int m = matrix[0].size();
        int res = INT_MIN;

        for (int left = 0; left < m; ++left) {
            vector<int> rowSum(n, 0);

            for (int right = left; right < m; ++right) {
                for (int i = 0; i < n; ++i)
                    rowSum[i] += matrix[i][right];

                set<int> prefixSums;
                prefixSums.insert(0);
                int currSum = 0;

                for (int sum : rowSum) {
                    currSum += sum;

                    // We want smallest prefix ≥ currSum - k
                    auto it = prefixSums.lower_bound(currSum - k);
                    if (it != prefixSums.end())
                        res = max(res, currSum - *it);

                    prefixSums.insert(currSum);
                }
            }
        }

        return res;
    }
};
