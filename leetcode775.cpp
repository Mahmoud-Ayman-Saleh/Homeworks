#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <limits>
#include <random>
using namespace std;
#define ll long long

vector<int> tmp;


class Solution
{
private:

    ll merge(vector<int> &nums, int l, int mid, int r)
    {
        ll ans = 0;
        for (int i = l, j = mid+1, k = l; k <= r; k++)
        {
            if (i > mid)
            {
                tmp[k] = nums[j];
                j++;
            }
            else if (j > r)
            {
                tmp[k] = nums[i];
                i++;
            }
            if (nums[i] < nums[j])
            {
                tmp[k] = nums[i];
                i++;
            }
            else
            {
                tmp[k] = nums[j];
                j++;
                ans += mid-i+1;
            }
        }

        return ans;
    }

    ll merge_sort(vector<int> &nums, int l, int r)
    {
        int ans = 0;
        if (l < r)
        {
            int mid = l - (l - r) / 2;
            ans += merge_sort(nums, l, mid);
            ans += merge_sort(nums, mid + 1, r);
            ans += merge(nums, l, mid, r);
        }
        return ans;
    }
public:
    bool isIdealPermutation(vector<int>& nums)
    {
        tmp = nums;
        ll local_conversions = 0;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i] > nums[i+1])
            {
                local_conversions++;
            }
        }
        ll global_conversions = merge_sort(nums, 0, nums.size()-1);
        return local_conversions == global_conversions;
    }
};