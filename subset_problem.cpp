#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector<int> numList;
const int MAX_N = 501; // Max N = 500, for safe indexing
const int MAX_T = 2001; // Max Target = 2000
int memory[MAX_N][MAX_T];

class Solution
{
public:
    bool dp(int idx, int remain)
    {
        if (remain < 0) 
        {
            return false; // Sum is exceeded
        }
        if (remain == 0) 
        {
            return true; // Found a subset with the target sum
        }
        if (idx == numList.size()) 
        {
            return false; // End of the list without finding a solution
        }

        // Memoization check
        auto &ret = memory[idx][remain];
        if (ret != -1) 
        {
            return ret;
        }

        // Try leaving the current element or picking it
        ret = dp(idx + 1, remain) || dp(idx + 1, remain - numList[idx]);
        return ret;
    }

    bool subset_sum(vector<int> &values, int target)
    {
        numList = values;
        memset(memory, -1, sizeof(memory)); // Reset memory
        return dp(0, target);
    }
};

int main()
{
    Solution solution;

    // Test case 1: Expected output -> True
    vector<int> values1 = {3, 12, 4, 12, 5, 2};
    int target1 = 9;
    cout << "Test Case 1: " << (solution.subset_sum(values1, target1) ? "True" : "False") << endl;

    // Test case 2: Expected output -> False
    vector<int> values2 = {3, 40, 4, 12, 5, 2};
    int target2 = 30;
    cout << "Test Case 2: " << (solution.subset_sum(values2, target2) ? "True" : "False") << endl;

    // Test case 3: Edge case - sum 0: Expected output -> True (empty subset is valid)
    vector<int> values3 = {1, 2, 3};
    int target3 = 0;
    cout << "Test Case 3: " << (solution.subset_sum(values3, target3) ? "True" : "False") << endl;

    // Test case 4: Edge case - large numbers: Expected output -> False
    vector<int> values4 = {100000000, 100000000, 100000000};
    int target4 = 200000;
    cout << "Test Case 4: " << (solution.subset_sum(values4, target4) ? "True" : "False") << endl;

    return 0;
}
