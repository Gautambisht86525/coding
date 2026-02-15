#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool inc = true;
        bool dec = true;

        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] > nums[i + 1]) inc = false;
            if (nums[i] < nums[i + 1]) dec = false;
        }

        return inc || dec;
    }
};

int main() {
    Solution obj;

    vector<int> nums1 = {1, 2, 2, 3};
   
    cout << obj.isMonotonic(nums1) << endl;

    return 0;
}
