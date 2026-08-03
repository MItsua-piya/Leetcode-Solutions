class Solution {
public:
void help(vector<int>& stoneValue,vector<int>&dp){
int n=stoneValue.size();

 for (int i = n - 1; i >= 0; i--) {
            dp[i] = INT_MIN;
            int sum = 0;

            for (int k = 0; k < 3 && i + k < n; k++) {
                sum += stoneValue[i + k];
                dp[i] = max(dp[i], sum - dp[i + k + 1]);
            }
        }
}

    string stoneGameIII(vector<int>& stoneValue) {
        vector<int>dp(stoneValue.size()+1,0);
        help(stoneValue,dp);
        if(dp[0]>0) return "Alice";
        if (dp[0]<0)return "Bob";
        return "Tie";
    }
};