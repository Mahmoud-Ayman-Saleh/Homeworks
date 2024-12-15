#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm> // Added to use the max function
using namespace std;

vector<int> numbers;
const int MAX = 1000 + 1;
int memory_lds[MAX];
int memory_lis[MAX];

class Solution
{
private:
    int lis(int idx)
    {
        if (idx == numbers.size()) return 0;

        auto &ans = memory_lis[idx];
        if (ans != -1) return ans;

        ans = 0;
        for (int i = idx - 1; i >=0; i--)
        {
            if (numbers[i] < numbers[idx])
            {
                ans = max(ans, lis(i));
            }
        }
        ans = ans + 1;
        return ans;
    }

    int lds(int idx)
    {
        if (idx == numbers.size()) return 0;

        auto &ans = memory_lds[idx];
        if (ans != -1) return ans;

        ans = 0;
        for (int i = idx + 1; i < numbers.size(); i++)
        {
            if (numbers[i] < numbers[idx])
            {
                ans = max(ans, lds(i));
            }
        }
        ans = ans + 1;
        return ans;
    }
public:
    int minimumMountainRemovals(vector<int>& nums)
    {
        numbers = nums;
        int n = numbers.size();
        memset(memory_lis, -1, sizeof(memory_lis));
        memset(memory_lds, -1, sizeof(memory_lds));

        int longest_incerasing_decreasing = 0;

        for (int i = 0; i < n; i++)
        {
            if (lis(i) == 1 || lds(i) == 1) continue;
            int cur = lis(i) + lds(i) - 1;
            longest_incerasing_decreasing = max(cur, longest_incerasing_decreasing);
        }

        return n - longest_incerasing_decreasing;

    }
};

int main()
{
    Solution solution;

    // Test Case 1: nums = [1,3,1]
    vector<int> nums1 = {1, 3, 1};
    cout << "Test Case 1: Expected Output = 0, Actual Output = " << solution.minimumMountainRemovals(nums1) << endl;

    // Test Case 2: nums = [2,1,1,5,6,2,3,1]
    vector<int> nums2 = {2, 1, 1, 5, 6, 2, 3, 1};
    cout << "Test Case 2: Expected Output = 3, Actual Output = " << solution.minimumMountainRemovals(nums2) << endl;

    // Test Case 3: nums = [9,8,1,7,6,5,4,3,2,1]
    vector<int> nums3 = {9, 8, 1, 7, 6, 5, 4, 3, 2, 1};
    cout << "Test Case 3: Expected Output = 0, Actual Output = " << solution.minimumMountainRemovals(nums3) << endl;

    // Test Case 4: nums = [1,2,3,4,3,2,1,0]
    vector<int> nums4 = {1, 2, 3, 4, 3, 2, 1, 0};
    cout << "Test Case 4: Expected Output = 0, Actual Output = " << solution.minimumMountainRemovals(nums4) << endl;

    // Test Case 5: nums = [2, 3, 2, 4, 3, 5, 2]
    vector<int> nums5 = {2, 3, 2, 4, 3, 5, 2};
    cout << "Test Case 5: Expected Output = 2, Actual Output = " << solution.minimumMountainRemovals(nums5) << endl;

    return 0;
}