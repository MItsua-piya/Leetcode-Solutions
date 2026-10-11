class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>prefix(n);
        prefix[0]=nums[0];
        for(int i=1;i<n;i++){
         prefix[i]=prefix[i-1]+nums[i];
        }
        unordered_map<int ,int>m;
        m[0]=1;
        int count=0;
        for(int i=0;i<n;i++){
      int val=prefix[i]%k;
      if(val<0){
        val=(val+k)%k;
      }
      if( m.find(val)!=m.end()){
        count+=m[val];
      }
      m[val]++;
        }
        return count;
    }
};