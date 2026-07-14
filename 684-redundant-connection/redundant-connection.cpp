class Graph{
int v;
list<int>*l;
public:
Graph(int v){
this->v=v;
l=new list<int>[v];
}
void addEdge(int u,int v){
    l[u].push_back(v);
     l[v].push_back(u);
}
bool bfs(int src,int des){
    vector<bool>vis(v,false);
    vis[src]=true;
    queue<int>q;
    q.push(src);
    while(!q.empty()){
        int curr=q.front();
        q.pop();
         if (curr == des)   
            return true;

        for(auto & c:l[curr]){
            if(!vis[c]){
                vis[c]=true;
                q.push(c);
            }
           
        }
    }
    return false;

}
};


class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        Graph g(edges.size()+1);
        for(auto &n:edges){
           
            if(g.bfs(n[0],n[1])){
                return n;
            }
 g.addEdge(n[0],n[1]);
        }
        return {};
    }
};