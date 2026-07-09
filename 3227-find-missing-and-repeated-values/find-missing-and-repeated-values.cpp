class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {

        long long n = grid.size();
        long long N = n * n;

        long long expectedSum = N * (N + 1) / 2;
        long long expectedSq = N * (N + 1) * (2 * N + 1) / 6;

        long long actualSum = 0;
        long long actualSq = 0;

        for (auto &row : grid) {
            for (int x : row) {
                actualSum += x;
                actualSq += 1LL * x * x;
            }
        }

        long long A = actualSum - expectedSum;          // x - y
        long long B = (actualSq - expectedSq) / A;      // x + y

        long long repeated = (A + B) / 2;
        long long missing = repeated - A;

        return {(int)repeated, (int)missing};
    }
};