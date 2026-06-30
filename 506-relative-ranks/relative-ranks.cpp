class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<string>ans(score.size());
      priority_queue<
    pair<int,int>
> pq;
        for(int i=0;i<score.size();i++){
            pq.push({score[i],i});
        }
        int rank=1;
        while(!pq.empty()){
            auto e =pq.top();
            pq.pop();
            
            if(rank==1){
                ans[e.second]="Gold Medal";
            }
             else if(rank==2){
                ans[e.second]="Silver Medal";
            }
            else if(rank==3){
                ans[e.second]="Bronze Medal";
            }
            else{
                ans[e.second]=to_string(rank);
            }
            rank++;
        }
        return ans;

    }
};