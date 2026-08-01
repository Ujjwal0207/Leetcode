class Solution {
public:
    int solve(int i, int j, vector<int>& nums) {
        if (i > j) return 0;
        return max(nums[i] - solve(i + 1, j, nums), nums[j] - solve(i, j - 1, nums));
    }

    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        return solve(0, n - 1, nums) >= 0;
    }
};
