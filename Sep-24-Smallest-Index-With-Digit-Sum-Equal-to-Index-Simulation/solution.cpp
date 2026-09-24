#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        // Fast I/O
        static const auto fast = []() {
            ios_base::sync_with_stdio(false);
            cin.tie(NULL);
            return 0;
        }();
        (void)fast;

        int n = static_cast<int>(nums.size());
        for (int i = 0; i < n; ++i) {
            int digit_sum = 0;
            int temp = nums[i];

            // Extract decimal digits
            while (temp > 0) {
                digit_sum += temp % 10;
                temp /= 10;
            }

            // Smallest index is guaranteed by the left-to-right scan
            if (digit_sum == i) {
                return i;
            }
        }
        return -1;
    }
};
