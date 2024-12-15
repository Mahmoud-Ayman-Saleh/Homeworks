// https://leetcode.com/problems/filling-bookcase-shelves/
#include <iostream>
#include <vector>
#include <cstring>
#include <climits>
#include <algorithm>
#include <cassert>
using namespace std;

const int MAX = 1000 + 1;
int memory[MAX];
vector<vector<int>> books;
int shelfWidth;

class Solution
{
public:

    int arrange(int idx)
    {
        if (idx >= books.size()) return 0;

        auto &ret = memory[idx];
        if (ret != -1) return ret;

        ret = INT_MAX;

        int width = 0, height = 0;

        for (int i = idx; i < books.size(); i++)
        {
            width += books[i][0];
            height = max(height, books[i][1]);
            if (width > shelfWidth) break;
            ret = min(ret, height+arrange(i+1));
        }
        return ret;
    }

	int minHeightShelves(vector<vector<int>> &books_, int shelfWidth_)
    {
		books = books_;
		shelfWidth = shelfWidth_;
		memset(memory, -1, sizeof(memory));
		return arrange(0);
	}
};