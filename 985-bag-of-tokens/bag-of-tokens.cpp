class Solution {
public:
    int bagOfTokensScore(vector<int>& token, int power) {
        int left=0;
        int right=token.size()-1;
        int score=0;
        int maxScore=0;
        sort(token.begin(), token.end());
        while (left<=right){
            
                if(power>=token[left]){
                    power-=token[left];
                    score++;
                    left++;
                    maxScore = max(maxScore, score);
                }else if (score>0){
                    score--;
                    power+=token[right];
                    right--;
                }else{
                    break;
                }
            
        }
        return maxScore;
           }
};