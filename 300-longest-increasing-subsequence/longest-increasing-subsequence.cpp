class Solution {
public:
int help(vector<int>&nums,int i,int n,int prev,vector<vector<int>>&dp){
if(i==n){
    return 0 ;
}
if(dp[i][prev+1]!=-1){
    return dp[i][prev+1];
}
// int take=1+help(nums,i+1,n,prev);
int take=0;
if (prev == -1 || nums[i] > nums[prev]){
            take = 1 + help(nums, i + 1, n,i,dp);}
int nottake=help(nums,i+1,n,prev,dp);
        return dp[i][prev+1]= max(take, nottake);
}

    int lengthOfLIS(vector<int>& nums) {
      vector<vector<int>> dp(nums.size(), vector<int>(nums.size() + 1, -1));
        
         return  help(nums,0,nums.size(),-1,dp);
    }
};