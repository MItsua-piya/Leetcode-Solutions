class Solution {
public:
    bool checkDivisibility(int n) {
        int copy=n;
        int sum=0;
        int product=1;
        while(copy>0){
            int rem =copy%10;
            sum+=rem;
            product*=rem;
            copy/=10;
        }
          
 return n%(sum+ product) == 0;
    }
};