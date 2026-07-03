class Solution {
public:
int sqr(int num){
    int sum=0;
    while(num>0){
        int rem=num%10;
        sum+=rem*rem;
        num=num/10;
    }
    return sum;
}
    bool isHappy(int n) {
        unordered_set<int>seen;
        while(n!=1 && !seen.count(n)){
                seen.insert(n);
            n = sqr(n);
        }
        return n==1;
    }
};