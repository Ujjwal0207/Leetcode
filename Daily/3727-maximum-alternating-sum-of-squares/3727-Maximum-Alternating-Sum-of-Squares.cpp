class Solution {
public:
    long long maxAlternatingSum(vector<int>& a) {
        long long n = a.size(), sum = 0, i = 0, j = n - 1;
        for (int i = 0; i < n; i++) {
            a[i] = a[i] * a[i];
        }
        sort(a.begin(), a.end());
        vector<long long> ans;
        
        while (i < j) {
            if (i == j) {
                ans.push_back(a[i]);
                break;
            }
            ans.push_back(a[j]);
            ans.push_back(a[i]);
            j--, i++;
        }
        if (n & 1) ans.push_back(a[n/2]);
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) sum += ans[i];
            else sum -= ans[i];
        }
        return sum;
    }
};