class Graph{
    int V;
    list<int>*l;
    public:
    Graph(int V){
        this->V=V;
        l=new list<int>[V];
    }

    void addEdge(int u,int v){
        l[u].push_back(v);
        l[v].push_back(u);
    }

    bool hasPath(int src,int des,vector<bool>&vis){
    if(src==des) return true;
    vis[src]=true;
    for(auto &s :l[src]){
     if(!vis[s]){
     
       if(hasPath(s, des, vis))
    return true;
     }
    }
    return false;
    }
};

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<bool>vis(n,false);
        Graph g(n);
        for(auto & k:edges){
            g.addEdge(k[0],k[1]);
        }
        return g.hasPath(source,destination,vis);
    }
};