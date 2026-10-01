class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0,j=1;
        int count=0;
        while(i<nums.size()-1&&j<nums.size()){
            if(nums[i]!=nums[j]){
            // count++;
               nums[i+1]=nums[j];
               i++;
               
            }
            j++;
            
        }
        return i+1;
    }
};