class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {

        vector<pair<int, int>> v;

        for (int i = 0; i < rocks.size(); i++) {
            int need = capacity[i] - rocks[i];
            v.push_back({need, capacity[i]});
        }

        sort(v.begin(), v.end(), [](const pair<int,int>& x, const pair<int,int>& y) {
            return x.first < y.first;
        });

        int ans = 0;

        for (auto m : v) {
            int need = m.first;

            if (additionalRocks >= need) {
                additionalRocks -= need;
                ans++;
            } else {
                break;
            }
        }

        return ans;
    }
};