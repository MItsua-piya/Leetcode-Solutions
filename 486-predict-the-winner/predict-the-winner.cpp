class Solution {
public:
int help(vector<int>& nums,int left,int right,int n,vector<vector<int>>&dp){
    if(left==right){
        dp[left][right]= nums[left];
    }
    if (dp[left][right] != -1)
            return dp[left][right];
    int RightChoice=nums[right]-help(nums,left,right-1,n,dp);
     int leftChoice=nums[left]-help(nums,left+1,right,n,dp);
return dp[left][right]= max(RightChoice,leftChoice);
}
    bool predictTheWinner(vector<int>& nums) {
      
        
        int n=nums.size();
          vector<vector<int>>dp(n,vector<int>(n,-1));
       return help(nums,0,n-1,n,dp)>=0;
       
    }
};