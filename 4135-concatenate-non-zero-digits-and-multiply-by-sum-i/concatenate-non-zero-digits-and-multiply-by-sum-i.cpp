class Solution {
public:

    long long sumAndMultiply(int n) {
          if (n == 0) return 0;
        long long  sum=0;
        string s="";
        while(n>0){
            long long rem =n%10;
            if(rem!=0){
             s+= to_string(rem);
            }
            sum+=rem;
            n=n/10;
        }
          reverse(s.begin(), s.end());
        long long num = stoll(s);
        if (s.empty()) return 0;
         return num*sum;
    }
};