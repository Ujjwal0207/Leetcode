class Solution {
public:
    int totalStrength(vector<int>& strength) {
        const int MOD = 1e9 + 7;
        int n = strength.size();

        vector<int> left(n), right(n);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && strength[st.top()] >= strength[i])
                st.pop();
            left[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        while (!st.empty()) st.pop();

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && strength[st.top()] > strength[i])
                st.pop();
            right[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        vector<long long> pre(n + 1, 0);
        for (int i = 0; i < n; i++)
            pre[i + 1] = (pre[i] + strength[i]) % MOD;

        vector<long long> ppre(n + 2, 0);
        for (int i = 0; i <= n; i++)
            ppre[i + 1] = (ppre[i] + pre[i]) % MOD;

        long long ans = 0;

        for (int i = 0; i < n; i++) {
            int l = left[i];
            int r = right[i];

            long long leftSum = (ppre[i + 1] - ppre[max(0, l + 1)] + MOD) % MOD;
            long long rightSum = (ppre[r + 1] - ppre[i + 1] + MOD) % MOD;

            long long leftCnt = i - l;
            long long rightCnt = r - i;

            long long total =
                (rightSum * leftCnt % MOD - leftSum * rightCnt % MOD + MOD) % MOD;

            ans = (ans + total * strength[i]) % MOD;
        }

        return ans;
    }
};