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
    int maxSubArray(vector<int>& nums)
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
};