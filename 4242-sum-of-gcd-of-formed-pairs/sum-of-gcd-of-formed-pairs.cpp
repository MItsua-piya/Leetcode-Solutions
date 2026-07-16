class Solution {
public:
    long long gcdSum(vector<int>& nums) {
           int n = nums.size();

        vector<int> prefixGcd;
        int prefixMax = 0;

        for (int x : nums) {
            prefixMax = max(prefixMax, x);
            prefixGcd.push_back(gcd(x, prefixMax));
        }
        sort(prefixGcd.begin(),prefixGcd.end());
        long long ans = 0;
        int i = 0, j = n - 1;

        while (i < j) {
            ans += gcd(prefixGcd[i], prefixGcd[j]);
            i++;
            j--;
        }

        return ans;
    }
};