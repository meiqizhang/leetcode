/*
Given a binary search tree with non-negative values, find the minimum absolute difference between values of any two nodes.

Example:

Input:

1
 \
  3
 /
2

Output:
1

Explanation:
The minimum absolute difference is 1, which is the difference between 2 and 1 (or between 2 and 3).


Note: There are at least two nodes in this BST.
*/

#include <stack>
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution{
public:
    int getMinimumDifference(TreeNode* root)
    {
        if (root == nullptr) return 0;

        stack<TreeNode *> st;
        TreeNode *p = root;
        int minDiff = 0x7FFFFFFF;
        int lastVal = -1;

        //ÖÐÐò±éÀúÓÐÐò
        while (!st.empty() || p != nullptr)
        {
            if (p != nullptr)
            {
                st.push(p);
                p = p->left;
            }
            else
            {
                p = st.top(), st.pop();
                if (lastVal != -1)
                {
                    int diff = abs(p->val - lastVal);
                    if (diff < minDiff)
                    {
                        minDiff = diff;
                    }
                }
                lastVal = p->val;
                p = p->right;
            }
        }
        return minDiff;
    }
};

int main()
{
    return 0;
}