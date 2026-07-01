class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
priority_queue<int,vector<int>,greater<int>>pq;
for (int k = 0; k < n * n; k++) {
    int i = k / n;   // row
    int j = k % n;   // column

   pq.push(matrix[i][j]);
}
while(k>1){
    pq.pop();
    k--;
}
return pq.top() ;
    }
};