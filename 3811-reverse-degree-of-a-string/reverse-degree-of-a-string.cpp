class Solution {
public:
    int reverseDegree(string s) {
        int sum=0;
          int pos = 1;
        for(auto a:s){
            int temp=26-(a-'a');
            sum+=temp*pos;
            pos++;
        }
        return sum;
    }
};