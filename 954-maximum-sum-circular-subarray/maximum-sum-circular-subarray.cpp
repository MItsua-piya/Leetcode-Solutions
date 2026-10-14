class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
int MaxSum=INT_MIN,currMin=0,currMax=0,totalsum=0,MinSum=INT_MAX;
for(auto n:nums){
    totalsum+=n;
}
for (int j = 0; j <  n; j++) {
    int i = j % n;
    currMin=min(nums[i],currMin+nums[i]);
    currMax=max(nums[i],currMax+nums[i]);
MaxSum=max(currMax,MaxSum);
MinSum=min(MinSum,currMin);
   
}
if(MaxSum<0){
return MaxSum;
}
return max(MaxSum,totalsum-MinSum);
    }
};