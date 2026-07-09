class Graph{
    int v;
    list<int>*l;
    public:
    Graph(int v){
        this->v=v;
        l=new list<int>[v+1];
    }
    void addEdge(int u,int v){
        l[u].push_back(v);
          l[v].push_back(u);
    }

  
  bool dfs(int src, int dest, vector<bool>& vis) {
    if (src == dest)
        return true;

    vis[src] = true;

    for (int nbr : l[src]) {
        if (!vis[nbr]) {
            if (dfs(nbr, dest, vis))
                return true;
        }
    }

    return false;
}
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
       Graph g(edges.size() + 1);

for (auto &e : edges) {

    vector<bool> vis(edges.size() + 1, false);

    if (g.dfs(e[0], e[1], vis))
        return {e[0],e[1]};

    g.addEdge(e[0], e[1]);
}
return {};
    }
};