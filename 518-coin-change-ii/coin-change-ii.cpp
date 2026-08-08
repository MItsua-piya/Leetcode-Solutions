class Solution {
public:
int help(int amount,vector<int>&coins,int i,int n,vector<vector<int>>&dp){
if(i==n  )return 0;
if(amount ==0) return 1;
if(dp[i][amount]!=-1) return dp[i][amount];
int take=0;

if(coins[i]<=amount){
    take=help(amount-coins[i],coins,i,n,dp);
}
int nottake=help(amount,coins,i+1,n,dp);
return dp[i][amount]=take+nottake;
}
    int change(int amount, vector<int>& coins) {
        vector<vector<int>>dp(coins.size(),vector<int>(amount+1,-1));
        return help(amount,coins,0,coins.size(),dp);
    }
};