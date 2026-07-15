class Solution {
public:
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
    int gcdOfOddEvenSums(int n) {
       int a=n*(n+1);
        return gcd(a,n*n);
    }
};