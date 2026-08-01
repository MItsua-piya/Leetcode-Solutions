class Solution {
public:
int help(vector<int>& nums,int left,int right,int n){
    if(left==right){
        return nums[left];
    }
    int RightChoice=nums[right]-help(nums,left,right-1,n);
     int leftChoice=nums[left]-help(nums,left+1,right,n);
return max(RightChoice,leftChoice);
}
    bool predictTheWinner(vector<int>& nums) {
        
        int n=nums.size();
        return help(nums,0,nums.size()-1,n)>=0;
    }
};