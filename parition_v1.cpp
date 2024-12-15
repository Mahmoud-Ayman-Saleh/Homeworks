#include <iostream>
#include <vector>
#include <cstring>
#include <climits>
#include <cassert>
#include <numeric>	// accumulate
using namespace std;

vector<int> numbers;
int k;
int partition_sum;

// part of the backtrack state
vector<int> cur_partition_sum;

// For printing purposes
vector<vector<int>> partition_values;


class Solution
{
private:
    bool try_parition(int idx)
    {
        if (idx == numbers.size()) return true;

        for (int i = 0; i < k; i++)
        {
            if (cur_partition_sum[i] + numbers[idx] > partition_sum) continue;

            cur_partition_sum[i] += numbers[idx];
            partition_values[i].push_back(numbers[idx]);

            if (try_parition(idx + 1)) return true;

            cur_partition_sum[i] -= numbers[idx];
            partition_values[i].pop_back();
        }
        return false;
    }
public:
    void partition_ksubsets_equalsum(const vector<int> &numbers_, int k_)
    {
        cout << "*********************\n";
        int sum = accumulate(numbers_.begin(), numbers_.end(), 0);
        if (sum % k_ != 0 || (int)numbers_.size() < k_)
        {
            cout << "Impossible1\n";
            return;
        }

        numbers = numbers_;
        k = k_;
        partition_sum = sum / k_;
        cur_partition_sum = vector<int>(k, 0);
        partition_values = vector<vector<int>>(k);

        if (try_parition(0))
        {
            for (int i = 0; i < k; ++i)
            {
                cout << "Partition " << i + 1 << ": ";
                for (int j = 0; j < (int)partition_values[i].size(); j++)
                {
                    cout << partition_values[i][j] << " ";
                }
                cout << "\n";
            }
        }
        else
        {
            cout << "Impossible2\n";
        }
    }
    
};