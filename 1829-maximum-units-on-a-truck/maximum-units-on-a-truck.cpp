class Solution {
public:
    int maximumUnits(vector<vector<int>>& arr, int truckSize) {

        sort(arr.begin(), arr.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] > b[1];
        });

        int ans = 0;

        for (auto& box : arr) {
            int boxes = min(box[0], truckSize);

            ans += boxes * box[1];
            truckSize -= boxes;

            if (truckSize == 0)
                break;
        }

        return ans;
    }
};