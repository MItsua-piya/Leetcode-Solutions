class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s1(nums1.begin(), nums1.end());
        unordered_set<int> s2(nums2.begin(), nums2.end());
        vector<int>ans1;
          vector<int>ans2;
        for(auto n:s1){
            if(!s2.count(n)){
                ans1.push_back(n);
            }
        }
         for(auto n:s2){
            if(!s1.count(n)){
                ans2.push_back(n);
            }
        }
        return {ans1,ans2};
    }
};