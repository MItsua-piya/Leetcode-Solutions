class Solution {
public:
int help(int idx,vector<int>& nums,vector<int>& dp){
if(idx ==0) return nums[idx];
if(idx<0) return 0;
if(dp[idx]!=-1) return dp[idx];
int pick=nums[idx]+help(idx-2,nums,dp);
int notpick=help(idx-1,nums,dp);
return dp[idx]=max(pick,notpick);

}
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        return help(n-1,nums,dp);
    }
};