class Solution {
public:
    vector<int> concatWithReverse(vector<int>& nums) {
        vector<int>ans;
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            ans.push_back(nums[i]);
            
        }
         for(int i=0;i<nums.size();i++){
             ans.push_back(nums[n-i-1]);
            // ans[i+n]=nums[n-i-1];
        }
        return ans;
    }
};