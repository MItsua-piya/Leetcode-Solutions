class Solution {
public:
    string removeStars(string s) {
        string ans="";
        ans+=s[0];
        for(int i=1;i<s.length();i++){
         if(s[i]=='*'){
            ans.pop_back();
         }else{
            ans.push_back(s[i]);
         }
        }
        return ans;
    }
};