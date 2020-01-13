/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).

Find the minimum element.

You may assume no duplicate exists in the array.

Example 1:

Input: [3,4,5,1,2]
Output: 1
Example 2:

Input: [4,5,6,7,0,1,2]
Output: 0
*/

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums)
    {
        if (nums.size() < 1) return -1;
        if (nums.size() == 1) return nums[0];

        int low = 0;
        int high = nums.size() - 1;

        while (low < high)
        {
            int mid = (low + high) / 2;
            printf("[%d, %d]=%d\n", nums[low], nums[high], nums[mid]);

            if (nums[low] < nums[high])
            {
                return nums[low];
            }

            if (nums[mid] >= nums[low])//左端有序，旋转点在右端
            {
                low = mid + 1;
            }
            else
            {
                high = mid;
            }
        }

        return nums[low];
    }
};

int main()
{
    auto sol = new Solution();
    vector<int> nums{5,6,7,8,9,1,2,3,4};
    //vector<int> nums{ 3, 1, 2 };

    cout << sol->findMin(nums) << endl;
}