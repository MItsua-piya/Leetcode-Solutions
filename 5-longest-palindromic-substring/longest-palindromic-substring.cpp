class Solution {
public:
   bool isPal(int i, int j, string& s, vector<vector<int>>& dp) {
    if (i >= j) return true;

    if (dp[i][j] != -1)
        return dp[i][j];

    if (s[i] != s[j])
        return dp[i][j] = 0;

    return dp[i][j] = isPal(i + 1, j - 1, s, dp);
}
    string longestPalindrome(string s) {
        int n=s.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
int start=0,maxlen=0;
for(int i=0;i<n;i++){
for(int j=i;j<n;j++){
   if(isPal(i,j,s,dp)){
     int len=j-i+1;
    if(len>maxlen){
        maxlen=len;
        start=i;
    }
   }
}
}
return s.substr(start,maxlen);
    }
};