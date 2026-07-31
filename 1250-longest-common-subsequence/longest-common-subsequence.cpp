class Solution {
public:
// int help(string t1, string t2,vector<vector<int>>&dp){
//     int n=t1.size();
//     int m=t2.size();
//     if(n==0||m==0){
//         return 0;
//     }
//     if(dp[n][m]!=-1){
//         return dp[n][m];
//     }
//     if(t1[n-1]==t2[m-1]){
//         dp[n][m]= 1+help(t1.substr(0,n-1),t2.substr(0,m-1),dp);
//     }else{
//         int ans1=help(t1.substr(0,n-1),t2,dp);
//         int ans2=help(t1,t2.substr(0,m-1),dp);
//        dp[n][m]= max(ans1,ans2);
//     }
//     return dp[n][m];
// }
    int longestCommonSubsequence(string t1, string t2) {
           int n=t1.size();
    int m=t2.size();
      vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
    for(int i=0;i<n+1;i++){
        dp[i][0]=0;
    }
    for(int i=0;i<m+1;i++){
        dp[0][i]=0;
    }
  
    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            if(t1[i-1]==t2[j-1]){
        dp[i][j]= 1+dp[i-1][j-1];
    }else{
        int ans1=dp[i-1][j];
        int ans2=dp[i][j-1];
       dp[i][j]= max(ans1,ans2);
    } 
        }
    }
       return dp[n][m];
    }
};