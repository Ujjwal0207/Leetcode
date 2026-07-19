class Solution {
public:
    const int MOD = 1e9 + 7;
    int n;
    vector<int> memo;

    int solve(int i, string &s, int k) {
        if (i == n) return 1;
        if (s[i] == '0') return 0;
        if (memo[i] != -1) return memo[i];

        long long num = 0;
        int ways = 0;

        for (int j = i; j < n; ++j) {
            num = num * 10 + (s[j] - '0');
            if (num > k) break;
            ways = (ways + solve(j + 1, s, k)) % MOD;
        }

        return memo[i] = ways;
    }

    int numberOfArrays(string s, int k) {
        n = s.size();
        memo = vector<int>(n, -1);
        return solve(0, s, k);
    }
};
