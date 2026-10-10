class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        vector<int>leftSum(nums.size()),rightSum(nums.size()),ans(nums.size());
        leftSum[0]=0;
        
        for(int i=0;i<nums.size()-1;i++){
            leftSum[i+1]=nums[i]+leftSum[i];
        }
        rightSum[nums.size()-1]=0;
         for(int i=nums.size()-2;i>=0;i--){
            rightSum[i]=nums[i+1]+rightSum[i+1];
        }
 for(int i=0;i<nums.size();i++){
    ans[i]=abs(leftSum[i]-rightSum[i]);
 }
 return ans;
    }
};