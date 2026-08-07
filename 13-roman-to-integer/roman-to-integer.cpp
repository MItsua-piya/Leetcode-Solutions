class Solution {
public:
int value(char a){

            if(a=='I'){
                return 1;
            }else if(a=='V'){
                return 5;
            }
            else if(a=='X'){
                return 10;
            }
            else if(a=='L'){
                return 50;
            }
            else if(a=='C'){
                return 100;
            }
            else if(a=='D'){
                return 500;
            }
            else if(a=='M'){
               return 1000;
            }
            return 0;

}
    int romanToInt(string s) {
        int ans=0;
        for(int i=0;i<s.length();i++){
            if(i+1<s.length()&& value(s[i])<value(s[i+1])){
                ans-=value(s[i]);
            }else{
                ans+=value(s[i]);
            }
        }
        return ans;
        }
        
    
};