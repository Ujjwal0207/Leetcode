class Solution {
public:
    unordered_map<long long, int> mp;
    int ans = 0;

    void dfs(TreeNode* root, long long sum, int target) {
        if (!root) return;

        sum += root->val;

        if (mp.count(sum - target))
            ans += mp[sum - target];

        mp[sum]++;

        dfs(root->left, sum, target);
        dfs(root->right, sum, target);

        mp[sum]--;
    }

    int pathSum(TreeNode* root, int targetSum) {
        mp[0] = 1;
        dfs(root, 0, targetSum);
        return ans;
    }
};