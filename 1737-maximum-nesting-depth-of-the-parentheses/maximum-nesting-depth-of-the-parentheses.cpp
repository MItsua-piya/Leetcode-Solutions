class Solution {
public:
    int maxDepth(string s) {
        int ans=0;
        int count=0;
        
        for(auto a:s){
            if(a=='('){
                count++;
            }
            else if(a==')'){
                count--;
            }
            ans=max(ans,count);
        }
        return ans;
    }
};