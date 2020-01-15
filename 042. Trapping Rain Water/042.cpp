/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.


The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped. Thanks Marcos for contributing this image!

Example:

Input: [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
*/

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    inline int min(int a, int b)
    {
        return a < b ? a : b;
    }

    int calcTrap(vector<int> height, int start, int end)
    {
        if (end - start < 2) return 0;

        int idx1 = -1;
        int idx2 = -1;

        int min1 = -1;
        int min2 = -1;

        for (int i = start; i <= end; i++)
        {
            if (height[i] >= min1)
            {
                min2 = min1;
                idx2 = idx1;

                idx1 = i;
                min1 = height[i];
            }
            else if (height[i] >= min2)
            {
                idx2 = i;
                min2 = height[i];
            }
        }

        if (idx1 > idx2)
        {
            idx1 ^= idx2 ^= idx1 ^= idx2;
        }

        int area = 0;
        int minH = min(height[idx1], height[idx2]);

        for (int i = idx1 ; i < idx2; i++)
        {
            if (minH > height[i])
                area += minH - height[i];
        }

        //printf("[%d, %d]=%d  ", height[idx1], height[idx2], area);
        printf("[%d, %d]=%d\n", idx1, idx2, area);

        return area + calcTrap(height, start, idx1) + calcTrap(height, idx2, end);
    }

    int trap(vector<int>& height)
    {
        return calcTrap(height, 0, height.size() - 1);
    }
};

int main()
{
    auto sol = new Solution();
    cout << sol->trap(vector<int>{6, 4, 2, 0, 3, 2, 0, 3, 1, 4, 5, 3, 2, 7, 5, 3, 0, 1, 2, 1, 3, 4, 6, 8, 1, 3}) << endl;
    cout << sol->trap(vector<int>{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1}) << endl;
}