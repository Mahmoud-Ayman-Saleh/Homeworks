#include <iostream>
#include <vector>
#include <cstring>
#include <climits>
#include <algorithm>
using namespace std;

const int MAX = 1000 + 1;
int memory[MAX];
vector<vector<int>> books;
int shelfWidth;

class Solution
{
public:

    int answer(int idx)
    {
        if (idx < 0) return 0; // No books left to place
        return memory[idx];
    }

    int minHeightShelves(vector<vector<int>> &books, int shelfWidth)
    {
        memset(memory, -1, sizeof(memory));
        for (int i = 0; i < books.size(); i++)
        {
            int width = 0, height = 0;
            int ans = INT_MAX;
            for (int j = i; j >= 0; j--)
            {
                width += books[j][0]; // Add book width
                height = max(height, books[j][1]); // Update the height for the current shelf
                if (width > shelfWidth) break; // Exceeded the shelf width
                ans = min(ans, height + answer(j-1));
            }
            memory[i] = ans;
        }
        return memory[books.size()-1];
    }
};
