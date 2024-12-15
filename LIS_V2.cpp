#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
vector<int> numList;
const int MAX = 2500+1;
int memory[MAX];


class Solution
{

int lis(int i)
{
    int n = numList.size();
    if (i == numList.size()) return 0;

    auto &ans = memory[i];
    if (ans != -1) return ans;

    ans = 0;
    for (int j = i + 1; j < n; j++)
    {
        if (numList[j] > numList[i])
        {
            ans = max(lis(j), ans);
        }
    }
    ans = ans + 1;
    return ans;
}

public:
    int lengthOfLIS(vector<int>& nums)
    {
        numList = nums;
        int n = numList.size();
        memset(memory, -1, sizeof(memory));
        numList.insert(numList.begin(), INT_MIN);
        return lis(0) - 1;
    }
};