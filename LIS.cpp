#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
vector<int> numList;
const int MAX = 2500+1;
int memory[MAX][MAX];



class Solution
{
public:

    int lis(int idx, int prev)
    {
        if (idx == numList.size()) return 0;

        auto &ans = memory[idx][prev];
        if (ans != -1) return ans;

        int leave = lis(idx + 1, prev);
        int pick = 0;

        if (prev >= numList.size() || numList[prev] < numList[idx])
        {
            pick = 1 + lis(idx+1, idx);
        }
        ans = max(leave, pick);
        return ans;
    }

    int lengthOfLIS(vector<int>& nums)
    {
        numList = nums;
        memset(memory, -1, sizeof(memory));
        return lis(0, numList.size());
    }
};