class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> sum(n + 1, 0); // prefix sum
        for (int i = 0; i < n; ++i) {
            sum[i + 1] = sum[i] + nums[i];
        }

        vector<int> left(n, 0), right(n, 0);
        int total = sum[k] - sum[0];
        for (int i = k; i < n; ++i) {
            int curr = sum[i + 1] - sum[i + 1 - k];
            if (curr > total) {
                left[i] = i + 1 - k;
                total = curr;
            } else {
                left[i] = left[i - 1];
            }
        }

        total = sum[n] - sum[n - k];
        right[n - k] = n - k;
        for (int i = n - k - 1; i >= 0; --i) {
            int curr = sum[i + k] - sum[i];
            if (curr >= total) {
                right[i] = i;
                total = curr;
            } else {
                right[i] = right[i + 1];
            }
        }

        vector<int> res = {-1, -1, -1};
        int maxSum = 0;
        for (int i = k; i <= n - 2 * k; ++i) {
            int l = left[i - 1], r = right[i + k];
            int totalSum = (sum[l + k] - sum[l]) + (sum[i + k] - sum[i]) + (sum[r + k] - sum[r]);
            if (totalSum > maxSum) {
                maxSum = totalSum;
                res = {l, i, r};
            }
        }
        return res;
    }
};