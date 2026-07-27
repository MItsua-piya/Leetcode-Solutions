class Solution {
public:
    vector<vector<int>> dp;
    int offset;

    int solve(vector<int>& nums, int i, int sum, int target) {
        if (i == nums.size()) {
            return (sum == target) ? 1 : 0;
        }

        if (dp[i][sum + offset] != -1)
            return dp[i][sum + offset];

        int add = solve(nums, i + 1, sum + nums[i], target);
        int subtract = solve(nums, i + 1, sum - nums[i], target);

        return dp[i][sum + offset] = add + subtract;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int total = 0;
        for (int num : nums)
            total += num;

        // If target is outside the possible range
        if (abs(target) > total)
            return 0;

        offset = total;
        dp.assign(nums.size(), vector<int>(2 * total + 1, -1));

        return solve(nums, 0, 0, target);
    }
};