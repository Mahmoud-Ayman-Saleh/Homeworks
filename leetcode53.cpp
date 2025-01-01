#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <limits>
#include <random>
#include <cstring>

using namespace std;
const int MAX = 100000 + 1;
int memory[MAX];
vector<int> arr;

class Solution
{
private:
    int dp(int idx)
    {
        if (idx == arr.size()) return 0;

        auto &ans = memory[idx];
        if (ans != -1) return ans;

        int choice1 = arr[idx] + dp(idx + 1); // take it
        int choice2 = arr[idx]; // leave it

        ans = max(choice1, choice2);
        return ans;
    }
public:
    int maxSubArray_recursive(vector<int>& nums)
    {
        arr = nums;
        memset(memory, -1, sizeof(memory));
        int ans = arr[0];
        for (int i = 0; i < arr.size(); i++)
        {
            ans = max(ans, dp(i));
        }
        return ans;
    }

    int maxSubArray_non_recursive(vector<int>& nums)
    {
        int cur_sum = nums[0];
        int ans = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            cur_sum = max(nums[i], cur_sum + nums[i]);
            ans = max(ans, cur_sum);
        }

        return ans;
    }
};

int main()
{
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    Solution s;
    cout << s.maxSubArray_recursive(v) << endl;
    cout << s.maxSubArray_non_recursive(v) << endl;
}