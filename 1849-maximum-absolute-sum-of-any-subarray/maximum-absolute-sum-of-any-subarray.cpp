class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int currMax=0,currMin=0,maxSum=0,minSum=0;
        for(int i=0;i<nums.size();i++){
            currMax=max(nums[i],currMax+nums[i]);
            // maxSum=max(maxSum+nums[i],nums[i]);
            currMin=min(nums[i],currMin+nums[i]);
            // minSum=min(minSum+nums[i],nums[i]);
            maxSum = max(maxSum, currMax);
minSum = min(minSum, currMin);

        }
        return max(abs(maxSum),abs(minSum));
    }
};