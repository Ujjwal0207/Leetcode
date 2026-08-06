class Solution {
public:
    vector<int> ans;

    void dfs(int num, int len, int n, int k) {
        if (len == n) {
            ans.push_back(num);
            return;
        }

        int last = num % 10;

        if (last + k <= 9) {
            dfs(num * 10 + last + k, len + 1, n, k);
        }

        if (k != 0 && last - k >= 0) {
            dfs(num * 10 + last - k, len + 1, n, k);
        }
    }

    vector<int> numsSameConsecDiff(int n, int k) {
        if (n == 1)
            ans.push_back(0);

        for (int i = 1; i <= 9; i++) {
            dfs(i, 1, n, k);
        }

        return ans;
    }
};