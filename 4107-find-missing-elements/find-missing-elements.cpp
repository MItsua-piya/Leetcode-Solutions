class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int mx=*max_element(nums.begin(),nums.end());
        int mn=*min_element(nums.begin(),nums.end());
        // vector<int>ans;
        unordered_set<int> s(nums.begin(), nums.end());
        vector<int> ans;

        for (int i = mn; i <= mx; i++) {
            if (s.find(i) == s.end()) {
                ans.push_back(i);
            }
        }

        return ans;
    }
    
};