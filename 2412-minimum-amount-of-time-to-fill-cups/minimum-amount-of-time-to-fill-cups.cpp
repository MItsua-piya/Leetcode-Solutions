class Solution {
public:
    int fillCups(vector<int>& amount) {
        priority_queue<int>pq;
        int time=0;
        for(auto a:amount){
            if(a > 0)
                pq.push(a);
        
        }
        while(pq.size()>1){
            int x=pq.top();
            pq.pop();
             int y=pq.top();
            pq.pop();
            x--;
            y--;
            time++;
            if(x>0) pq.push(x);
            if(y>0) pq.push(y);
        }
        if(!pq.empty()){
            time+=pq.top();
        }
        return time;
    }
};