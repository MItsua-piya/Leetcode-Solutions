// int ans=INT_MIN;
//         for(int i=0;i<nums.size();i++){
           
//             for(int j=0;j<nums.size();j++){
//                  int sum=min(nums[i],nums[j])*abs(i-j);
//                  ans=max(sum,ans);
//             }
//         }
//         return ans;
class Solution {
public:
    int maxArea(vector<int>& nums) {
        int i=0;
        int j=nums.size()-1;
        int ans=INT_MIN;
        while(i<j){
            int sum=min(nums[i],nums[j])*abs(i-j);
            ans=max(ans,sum);
            if(nums[i]<nums[j]){
                i++;
            }else{
                j--;
            }
        
        }
        return ans;
    }
};