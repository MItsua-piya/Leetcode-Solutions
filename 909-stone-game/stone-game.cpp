class Solution {
public:
int help(vector<int>&nums,int right,int left,vector<vector<int>>&dp){
    if(right==left){
       return dp[right][left]= nums[left];
    }
    if(dp[right][left]!=-1){
        return dp[right][left];
    }
    int takeRight=nums[right]-help(nums,right-1,left,dp);
    int takeLeft=nums[left]-help(nums,right,left+1,dp);
    return dp[right][left]= max(takeRight,takeLeft);
}
    bool stoneGame(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return help(nums,nums.size()-1,0,dp)>=0;
    }
};