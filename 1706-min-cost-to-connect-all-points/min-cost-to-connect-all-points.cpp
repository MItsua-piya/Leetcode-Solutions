class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int V=points.size();
        vector<bool>MST(V,false);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        int src=0;
        int cost=0;
        pq.push({0,src});
        while(pq.size()>0){
            int wt=pq.top().first;
             int u=pq.top().second;
         
             pq.pop();
             if(!MST[u]){
                MST[u]=true;
                    cost+=wt;

                for (int v = 0; v < V; v++) {
    if (u != v && !MST[v]) {
        int currwt = abs(points[u][0] - points[v][0]) +
                     abs(points[u][1] - points[v][1]);
        pq.push({currwt, v});
    
}
             }
             }
            
        }
        return cost;
    }
};