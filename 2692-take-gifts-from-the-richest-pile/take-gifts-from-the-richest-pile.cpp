class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int>pq;
        long long sum=0;
        for(auto gift:gifts){
            pq.push(gift);
        }
        while(k>0){
            int temp=pq.top();
            pq.pop();
            pq.push(sqrt(temp));
            k--;

        }
        while(!pq.empty()){
            int temp =pq.top();
            sum+=temp;
            pq.pop();
        }
        return sum;
    }
};