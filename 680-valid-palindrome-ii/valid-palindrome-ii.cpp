class Solution {
public:
bool isValid(int i,int j,string s){
    while(i<j){
  if(s[i]==s[j]){
        i++;
        j--;
    }else{
        return false;
    }
    }
  
    return true;
}
    bool validPalindrome(string s) {
        int i=0,j=s.size()-1;
        while(i<j){
            if(s[i]==s[j]){
                i++;
                j--;
            }else{
              return  isValid(i,j-1,s)||
                 isValid(i+1,j,s);
            }
        }
        return true;
    }
};