/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.

Your algorithm's runtime complexity must be in the order of O(log n).

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
*/

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target)
    {
        if (nums.size() < 1) return -1;

        int low = 0;
        int high = nums.size() - 1;

        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (nums[mid] == target) return mid;

            if (nums[mid] >= nums[low]) // low->mid”––Ú
            { 
                if (nums[low] <= target && target <= nums[mid]) //low->target->mid->high
                {
                    high = mid - 1;
                }
                else
                {
                    low = mid + 1;
                }
            }
            else // mid->high
            {
                if (nums[mid] <= target && target <= nums[high]) //mid->target->high
                {
                    low = mid + 1;
                }
                else
                {
                    high = mid - 1;
                }
            }
        }
        return -1;
    }
};

int main()
{
    auto sol = new Solution();
    vector<int>nums{ 4,5,6,7,0,1,2 };
    for (auto n : nums)
    {
        cout << sol->search(nums, n) << endl;
    }
}