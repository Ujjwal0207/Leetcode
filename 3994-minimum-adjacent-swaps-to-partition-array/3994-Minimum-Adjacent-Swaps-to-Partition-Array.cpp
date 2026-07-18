class Solution {
public:
    int minAdjacentSwaps(vector<int>& nums, int a, int b) {
        const int MOD = 1e9 + 7;
        long long ans = 0;
        long long cnt1 = 0, cnt2 = 0;

        for (int x : nums) {
            if (x < a) {
                ans += cnt1 + cnt2;
            } else if (x <= b) {
                ans += cnt2;
                cnt1++;
            } else {
                cnt2++;
            }
        }

        return ans % MOD;
    }
};