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
bool cycleHelper(int src,vector<bool>&vis ,vector<bool>&rec){
vis[src]=true;
rec[src]=true;
for(auto s:l[src]){
    if(!vis[s]){
        if(cycleHelper(s,vis,rec)){
            return true;
        };
    }else{
        if(rec[s]){
            return true;
        }
    }
}
rec[src] = false;
return false;
}
bool isCycle(){
vector<bool>vis(v,false);
vector<bool>rec(v,false);
for(int i=0;i<v;i++){
    if(!vis[i]){
       if(cycleHelper(i,vis,rec)){
        return true;
       }
    }
}

return false;
}
void order(int src,stack<int>&s,vector<bool>&vis){
 vis[src]=true;
 for(auto v:l[src]){
    if(!vis[v]){
        order(v,s,vis);
    }
 }
 s.push(src);
}
};

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        Graph g(numCourses);
        for(auto p:prerequisites){
            g.addEdge(p[1],p[0]);
        }
        vector<int>ans;
        stack<int>s;
        vector<bool>vis(numCourses,false);
        if(!g.isCycle()){
            for(int i=0;i<numCourses;i++){
                if(!vis[i]){
                    g.order(i,s,vis);
                }
           
            }
          
        }
        if(!s.empty()){
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        }
        return ans;
    }
};