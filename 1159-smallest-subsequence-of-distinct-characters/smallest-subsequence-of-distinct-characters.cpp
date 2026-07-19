class Solution {
public:
    string smallestSubsequence(string s) {

        vector<int> freq(26, 0);
        vector<bool> vis(26, false);

        // Count frequencies
        for (char c : s)
            freq[c - 'a']++;

        string ans = "";

        // Process characters
        for (char c : s) {

            freq[c - 'a']--;

            if (vis[c - 'a'])
                continue;

            while (!ans.empty() &&
                   ans.back() > c &&
                   freq[ans.back() - 'a'] > 0) {

                vis[ans.back() - 'a'] = false;
                ans.pop_back();
            }

            ans.push_back(c);
            vis[c - 'a'] = true;
        }

        return ans;
    }
};