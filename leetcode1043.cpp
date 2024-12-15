#include <iostream>
#include <vector>
#include <cstring>
#include <climits>
#include <algorithm>
using namespace std;

const int MAX = 500+1;
int memory[MAX];

vector<int> arr;
int k;


class Solution
{
public:

    int dp(int idx)
    {
        if (idx >= arr.size()) return 0;
        
        auto &ret = memory[idx];
        if (ret != -1) return ret;
        ret = INT_MIN;
        int max_element = 0;

        for (int end_idx = idx; end_idx < idx + k; end_idx++)
        {
            if (end_idx >= arr.size()) break;
            max_element = max(max_element, arr[end_idx]);
            int len = end_idx - idx + 1;
            ret = max(ret, len*max_element + dp(end_idx+1));
        }
        return ret;
    }

    int maxSumAfterPartitioning(vector<int>& _arr, int _k)
    {
        arr = _arr;
        k = _k;
        memset(memory, -1, sizeof(memory));
        return dp(0);
    }
};