class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<pair<int,int>> arr;
        arr.reserve(n);

        for (int i = 0; i < n; i++)
            arr.push_back({nums[i], i});

        sort(arr.begin(), arr.end());

        vector<int> val(n), pos(n);
        for (int i = 0; i < n; i++) {
            val[i] = arr[i].first;
            pos[arr[i].second] = i;
        }

        // Component id in sorted order
        vector<int> comp(n);
        for (int i = 1; i < n; i++) {
            comp[i] = comp[i - 1];
            if (val[i] - val[i - 1] > maxDiff)
                comp[i]++;
        }

        // far[i] = furthest index reachable in one edge
        vector<int> far(n);
        int r = 0;
        for (int l = 0; l < n; l++) {
            while (r + 1 < n && val[r + 1] - val[l] <= maxDiff)
                r++;
            far[l] = r;
        }

        int LOG = 1;
        while ((1 << LOG) <= n) LOG++;

        vector<vector<int>> up(LOG, vector<int>(n));

        for (int i = 0; i < n; i++)
            up[0][i] = far[i];

        for (int k = 1; k < LOG; k++) {
            for (int i = 0; i < n; i++) {
                up[k][i] = up[k - 1][up[k - 1][i]];
            }
        }

        vector<int> ans;
        ans.reserve(queries.size());

        for (auto &q : queries) {
            int u = pos[q[0]];
            int v = pos[q[1]];

            if (u > v) swap(u, v);

            if (comp[u] != comp[v]) {
                ans.push_back(-1);
                continue;
            }

            if (u == v) {
                ans.push_back(0);
                continue;
            }

            int cur = u;
            int steps = 0;

            for (int k = LOG - 1; k >= 0; k--) {
                if (up[k][cur] < v) {
                    cur = up[k][cur];
                    steps += (1 << k);
                }
            }

            ans.push_back(steps + 1);
        }

        return ans;
    }
};