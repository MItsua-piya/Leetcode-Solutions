class Solution {
public:
    int hIndex(vector<int>& c) {
        int n = c.size();
        vector<int> count(n + 1, 0);
        for(int x:c){
             if(x >= n)
                count[n]++;
            else
                count[x]++;
        }

        int paper=0;
        for(int i=n;i>=0;i--){
         paper+=count[i];
         if(paper>=i) return i;
        }
        return 0;
    }
};