#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    vector<vector<int>> ans;
    for (int mask = 0; mask < (1 << n); mask++) {
        vector<int> subset;
        bool valid = true;
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                if (i > 0 && nums[i] == nums[i - 1] && !(mask & (1 << (i - 1)))) {
                    valid = false;
                    break;
                }
                subset.push_back(nums[i]);
            }
        }
        if (valid) ans.push_back(subset);
    }
    return ans;
}

int main() {
    vector<int> arr = {1,2,3};
    vector<vector<int>> val = subsetsWithDup(arr);

    for (int i = 0; i < val.size(); i++) {
        for (int j = 0; j < val[i].size(); j++) {
            cout << val[i][j] << " ";
        }
        cout << endl;
    }
}
