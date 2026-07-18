class Solution {
public:
    long long maximumValue(int n, int s, int m) {
        if (n == 1) return s;
        long long k = n / 2;
        return s + k * 1LL * m - (k - 1);
    }
};