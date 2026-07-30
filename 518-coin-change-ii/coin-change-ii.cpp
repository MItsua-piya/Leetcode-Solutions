class Solution {
public:
int help(vector<int>& coins,int n, int amount,vector<vector<int>>&dp){
   if(amount == 0)
    return 1;

if(n < 0)
    return 0;  
    if(dp[n][amount]!=-1) return dp[n][amount];
    // int currcoin=coins[n];

     int notTake = help(coins, n - 1, amount, dp);

        // Take current coin (unlimited times)
        int take = 0;
        if (coins[n] <= amount) {
            take =  help(coins, n, amount - coins[n], dp);
        }

        return dp[n][amount] = take+ notTake;
}
    int change(int amount, vector<int>& coins) {
       vector<vector<int>>dp(coins.size(),vector<int>(amount+1,-1));
    //  if(coins.size()==1 && coins[0]<amount){
    //     return -1;
    //  }
     
     int ans= help(coins,coins.size()-1,amount,dp);
    return ans; 
    }
};