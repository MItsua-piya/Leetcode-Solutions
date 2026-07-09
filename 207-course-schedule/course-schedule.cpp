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
        
    }

bool helper(int src ,vector<bool>&vis,vector<bool>&recPath){
vis[src]=true;
recPath[src]=true;
for(auto v:l[src]){
    if(!vis[v]){
        if(helper(v,vis,recPath)){
            return true;
        }
    }else{
        if(recPath[v]){
            return true;
        }
    }
}
recPath[src]=false;
return false;
}
    bool dfs(){
     vector<bool>vis(v,false);
     vector<bool>recPath(v,false);
     for(int i=0;i<v;i++){
        if(!vis[i]){
            if(helper(i,vis,recPath))
            return true;
        }
     }
     return false;
    }
};

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        Graph g(numCourses);
        for(auto &p :prerequisites){
            g.addEdge(p[1],p[0]);
        }
        if( g.dfs()) return false;
        return true;
    }
};