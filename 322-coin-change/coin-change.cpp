class Solution {
public:
     int help(vector<int>& coins, int amount,vector<int>&dp){

   if (amount == 0)
            return 0;

        int ans=INT_MAX/2;
if(dp[amount]!=-1) return dp[amount];
  for(auto c:coins){
    if(c<=amount){
ans=min(ans,1+help(coins,amount-c,dp));
    }
  }


return dp[amount]=ans;
     }
    int coinChange(vector<int>& coins, int amount) {
        vector<int>dp(amount+1,-1);
        int ans= help(coins,amount,dp);
        if(ans==INT_MAX/2) return -1;
        return ans;
    }
};