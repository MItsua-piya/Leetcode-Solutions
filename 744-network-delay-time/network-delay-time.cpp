class Edge{
    public:
    int v;
    int wt;
    Edge(int v,int wt){
        this->v=v;
        this->wt=wt;
    }
};

class Solution {
public:
int algo(vector<vector<Edge>>&graph, int n, int src,vector<int>&dist){
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
pq.push({0,src});
dist[src]=0;
while(!pq.empty()){
    int u=pq.top().second;
    pq.pop();
    for(auto e:graph[u]){
        if(dist[e.v]>dist[u]+e.wt){
            dist[e.v]=dist[u]+e.wt;
            pq.push({dist[e.v],e.v});
        }
    }

}
  int ans = 0;

for(int i = 1; i <= n; i++) {
    if(dist[i] == INT_MAX)
        return -1;

    ans = max(ans, dist[i]);
}

return ans;
}
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<Edge>>graph(n+1);
        vector<int>dist(n+1,INT_MAX);
        for (auto &e : times) {
    graph[e[0]].push_back(Edge(e[1], e[2]));
}
   return algo(graph,n,k,dist);
    }
};