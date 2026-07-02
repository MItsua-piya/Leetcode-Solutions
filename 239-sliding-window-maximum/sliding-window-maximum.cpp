class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>ans;
        priority_queue<pair<int,int>>pq;
        for(int i=0;i<k;i++){
            pq.push({nums[i],i});
        }
        
            ans.push_back(pq.top().first);
       
        for(int j=k;j<nums.size();j++){
           
            while(!pq.empty() && pq.top().second<=(j-k)){
                pq.pop();
            }
                  pq.push({nums[j],j});
            ans.push_back(pq.top().first);
       
        }
        return ans;
    }
};