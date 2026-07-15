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
bool detect(int src,int par,vector<bool>&vis,vector<bool>&rec){
vis[src]=true;
rec[src]=true;
for(auto s:l[src]){
    if(!vis[s]){
        if (detect(s, src, vis, rec))
        return true;
    }else{
        if(rec[s]){
            return true;
        }
    }
  
}
rec[src]=false;

  return false;
};
bool dfs(){
    vector<bool>vis(v,false);
   vector<bool>rec(v,false);
    for(int i=0;i<v;i++){
        if(!vis[i]){
            if(detect(i,-1,vis,rec)){
                return true;
            };
        }
    }
    return false;
}
};

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        Graph g(numCourses);
        for(auto p:prerequisites){
        
                g.addEdge(p[0],p[1]);}
           
        return !g.dfs();
    }
};