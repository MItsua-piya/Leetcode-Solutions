class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<int> suf(n + 1, 0);

        suf[n] = m;

        int j = m - 1;

        for (int i = n - 1; i >= 0; --i) {
            if (j >= 0 && word1[i] == word2[j]) {
                --j;
            }

            suf[i] = j + 1;
        }

        vector<int> ans;

        int j2 = 0;
        bool usedMismatch = false;

        for (int i = 0; i < n && j2 < m; ++i) {

            if (word1[i] == word2[j2]) {
                ans.push_back(i);
                ++j2;

                if (j2 == m)
                    return ans;
            }

            else if (!usedMismatch && suf[i + 1] <= j2 + 1) {
                usedMismatch = true;

                ans.push_back(i);
                ++j2;

                if (j2 == m)
                    return ans;
            }
        }

        return {};
    }
};