class Solution {
public:
class info{
    public:
int u;
int cost;
int stop;
info(int u,
int cost,
int stop){
this->u=u;
this->cost=cost;
this->stop=stop;
}
};
    int findCheapestPrice(int V, vector<vector<int>>& flights, int src, int dst, int k) {
        queue<info>q;
        vector<int>dist(V,INT_MAX);
        dist[src]=0;
        q.push(info(src,0,-1));
        while(q.size()>0){
            info curr=q.front();
            q.pop();
            for(int i=0;i<flights.size();i++){
                if(flights[i][0]==curr.u){
                    int v=flights[i][1];
                    int wt=flights[i][2];
                    if(dist[v]>curr.cost+wt&& curr.stop+1<=k){
                        dist[v]=curr.cost+wt;
                        q.push(info(v,dist[v],curr.stop+1));
                    }
                }
            }
        }
        if(dist[dst]==INT_MAX){
            return -1;
        }
        return dist[dst];
    }
};