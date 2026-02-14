#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        for (int i = 1; i < nums.size(); i++) {
            nums[i] = nums[i - 1] + nums[i];
        }
        return nums;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {1, 2, 3, 4};
    vector<int> result = sol.runningSum(nums);

    for (int x : result) {
        cout << x << " ";
    }

    return 0;
}
