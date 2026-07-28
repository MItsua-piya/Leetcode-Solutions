class Solution {
public:

int help(vector<int>& nums, int target,int sum,int idx,vector<vector<int>>&dp, int offset){
if(idx == nums.size()){
    return sum == target;
}
  if (dp[idx][sum + offset] != -1)
            return dp[idx][sum + offset];
     int plus = help(nums, target, sum + nums[idx], idx + 1, dp, offset);
        int minus = help(nums, target, sum - nums[idx], idx + 1, dp, offset);
       return dp[idx][sum + offset]= plus+minus;
}
    int findTargetSumWays(vector<int>& nums, int target) {
   int total=0;
   for(auto x:nums){
    total+=x;
   }
        vector<vector<int>> dp(nums.size(),
                               vector<int>(2 * total + 1, -1));
        return help(nums,target,0,0,dp,total);

    }
};