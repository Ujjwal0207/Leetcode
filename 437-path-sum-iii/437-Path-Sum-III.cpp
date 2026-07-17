class Solution {
public:
    int ans = 0;

    void dfs(TreeNode* root, long long sum, int target) {
        if (!root) return;

        sum += root->val;

        if (sum == target)
            ans++;

        dfs(root->left, sum, target);
        dfs(root->right, sum, target);
    }

    void solve(TreeNode* root, int target) {
        if (!root) return;

        dfs(root, 0, target);

        solve(root->left, target);
        solve(root->right, target);
    }

    int pathSum(TreeNode* root, int targetSum) {
        solve(root, targetSum);
        return ans;
    }
};