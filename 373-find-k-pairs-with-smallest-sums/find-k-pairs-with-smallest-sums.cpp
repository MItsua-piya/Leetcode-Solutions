class Compare {
public:
    bool operator()(vector<int>& a, vector<int>& b) {
        return a[0] > b[0];
    }
};
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& num1, vector<int>& num2, int k) {
        vector<vector<int>>ans;
          if (num1.empty() || num2.empty() || k == 0)
            return ans;
        priority_queue<
    vector<int>,
    vector<vector<int>>,
    Compare
> pq;
 
for(int i=0;i<min((int)num1.size(), k);i++){
 
pq.push({num1[i]+num2[0],i,0});
    
    
}
while(k-- &&!pq.empty()){
    vector<int> curr =pq.top();
    pq.pop();
       int i = curr[1];
            int j = curr[2];

            ans.push_back({num1[i], num2[j]});

            // Push next element in the same row
            if (j + 1 < num2.size()) {
                pq.push({num1[i] + num2[j + 1], i, j + 1});
            }
}
return ans;
    }
};