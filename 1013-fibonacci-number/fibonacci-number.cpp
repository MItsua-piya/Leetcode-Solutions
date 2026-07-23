class Solution {
public:
    int fib(int n) {
        if(n==0) return 0;
        if(n==1) return 1;
        int p1=0;
        int p2=1;
        for(int i=2;i<=n;i++){
            int curr=p1+p2;
            p1=p2;
            p2=curr;
        }
        return p2;
    }
};