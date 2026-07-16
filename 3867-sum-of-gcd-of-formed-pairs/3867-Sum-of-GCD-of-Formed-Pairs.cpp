class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        const int n = nums.size();
        vector<int> p(n);
        for (int i = 0, m = 0; i < n; ++i) {
            m = max(m, nums[i]);
            p[i] = gcd(nums[i], m);
        }
        sort(p.begin(), p.end());
        long long r = 0;
        for (int i = 0, j = n - 1; i < j; r += gcd(p[i++], p[j--]))
        ;
        return r;
    }
};