#include <iostream>
#include <vector>
#include <cstring>
#include <climits>
#include <cassert>
#include <numeric>
using namespace std;
const int MAX = 58+1;
int memory[MAX];





class Solution
{
public:


    int product_sum(int n)
    {
        if (n == 1) return 1;
        auto &ans = memory[n];
        if (ans != -1) return ans;

        ans = n;

        for (int i = 1; i < n; i++)
        {
            ans = max(ans, i * product_sum(n - i));
        }
        return ans;
    }

    int integerBreak(int n)
    {
        if (n == 2 || n == 3) return n -1;
        memset(memory, -1, sizeof(memory));
        return product_sum(n);      
    }
};