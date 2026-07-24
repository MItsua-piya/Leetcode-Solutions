class Solution {
public:
int help(int end,int idx,vector<int>& nums,vector<int>& dp){
 if(idx < end) return 0;
if(idx ==end) return nums[idx];

if(dp[idx]!=-1) return dp[idx];
int pick=nums[idx]+help(end,idx-2,nums,dp);
int notpick=help(end,idx-1,nums,dp);
return dp[idx]=max(pick,notpick);

}
    int rob(vector<int>& nums) {
          
        int n=nums.size();
          if (n == 1)
            return nums[0];
        vector<int>dp1(n,-1);
        vector<int>dp2(n,-1);

        return max(help(0,n-2,nums,dp1),help(1,n-1,nums,dp2));
    }
};