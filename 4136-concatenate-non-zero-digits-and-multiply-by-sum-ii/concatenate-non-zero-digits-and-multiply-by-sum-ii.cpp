// class Solution {
// public:
//     vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
//          const int MOD = 1e9 + 7;
//         vector<int>vec;
//         vector<int>ans;
//         for( char v:s){
//             vec.push_back(v-'0');
//         }
        
//         for (auto q : queries) {
//     long long sum = 0;
//     long long num = 0;

//     for (int i = q[0]; i <= q[1]; i++) {
//         if (vec[i] != 0) {
//             num = (num * 10 + vec[i]) % MOD;
//             sum += vec[i];
//         }
//     }

//     ans.push_back((num * (sum % MOD)) % MOD);
// }
//         return ans;
//     }
// };

class Solution {
public:
    static const int MOD = 1e9 + 7;

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {

        vector<int> pos;      // original indices of non-zero digits
        vector<int> digit;    // non-zero digits

        // Extract non-zero digits
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != '0') {
                pos.push_back(i);
                digit.push_back(s[i] - '0');
            }
        }

        int m = digit.size();

        // powers of 10
        vector<long long> pow10(m + 1, 1);
        for (int i = 1; i <= m; i++)
            pow10[i] = (pow10[i - 1] * 10) % MOD;

        // prefix sum of digits
        vector<long long> prefSum(m + 1, 0);

        // prefix concatenated number
        vector<long long> prefNum(m + 1, 0);

        for (int i = 0; i < m; i++) {
            prefSum[i + 1] = prefSum[i] + digit[i];

            prefNum[i + 1] =
                (prefNum[i] * 10 + digit[i]) % MOD;
        }

        vector<int> ans;

        for (auto &q : queries) {

            int l = q[0];
            int r = q[1];

            // first non-zero digit inside [l,r]
            int L = lower_bound(pos.begin(), pos.end(), l) - pos.begin();

            // first digit greater than r
            int R = upper_bound(pos.begin(), pos.end(), r) - pos.begin();

            // no non-zero digits
            if (L == R) {
                ans.push_back(0);
                continue;
            }

            long long sum = prefSum[R] - prefSum[L];

            int len = R - L;

            // substring number modulo MOD
            long long num =
                (prefNum[R] -
                 prefNum[L] * pow10[len] % MOD +
                 MOD) % MOD;

            ans.push_back((num * (sum % MOD)) % MOD);
        }

        return ans;
    }
};