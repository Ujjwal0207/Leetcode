class Solution {
public:
    int helper(vector<int>& nums, int L, int M) {
        int n = nums.size();

        vector<int> pre(n + 1, 0);

        for (int i = 0; i < n; i++)
            pre[i + 1] = pre[i] + nums[i];

        int ans = 0;
        int bestL = 0;

        for (int i = L + M; i <= n; i++) {
            bestL = max(bestL, pre[i - M] - pre[i - M - L]);

            int second = pre[i] - pre[i - M];

            ans = max(ans, bestL + second);
        }

        return ans;
    }

    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        return max(helper(nums, firstLen, secondLen),
                   helper(nums, secondLen, firstLen));
    }
};