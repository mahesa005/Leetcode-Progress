// driver.cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0;
        int lastIdx = nums.size() - 1;
        for (int i = 0; i <= lastIdx; i++) {
            if (nums[i] != val) {
                k++;
            }
            else {
                for (int j = lastIdx; j > i; j--) {
                    if (nums[j] != val) {
                        swap(nums[i], nums[j]);
                        k++;
                        lastIdx--;
                        break;
                    }
                }
            }
        }
        return k;
    }
};

int main() {
    Solution sol;

    // Test case 1
    vector<int> nums1 = {3, 2, 2, 3};
    int val1 = 3;
    cout << "Before: ";
    for (int x : nums1) cout << x << ' ';
    cout << "\nRemove value = " << val1 << '\n';

    int k1 = sol.removeElement(nums1, val1);
    sort(nums1.begin(), nums1.begin() + k1);

    cout << "After:  ";
    for (int i = 0; i < k1; i++) cout << nums1[i] << ' ';
    cout << "\nNew length k = " << k1 << "\n\n";

    // Test case 2
    vector<int> nums2 = {0, 1, 2, 2, 3, 0, 4, 2};
    int val2 = 2;
    cout << "Before: ";
    for (int x : nums2) cout << x << ' ';
    cout << "\nRemove value = " << val2 << '\n';

    int k2 = sol.removeElement(nums2, val2);
    sort(nums2.begin(), nums2.begin() + k2);

    cout << "After:  ";
    for (int i = 0; i < k2; i++) cout << nums2[i] << ' ';
    cout << "\nNew length k = " << k2 << "\n";

    return 0;
}
