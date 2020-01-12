/*
You are given a binary tree in which each node contains an integer value.

Find the number of paths that sum to a given value.

The path does not need to start or end at the root or a leaf, but it must go downwards (traveling only from parent nodes to child nodes).

The tree has no more than 1,000 nodes and the values are in the range -1,000,000 to 1,000,000.

Example:

root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8

      10
     /  \
    5   -3
   / \    \
  3   2   11
 / \   \
3  -2   1

Return 3. The paths that sum to 8 are:

1.  5 -> 3
2.  5 -> 2 -> 1
3. -3 -> 11
*/

#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    
    int doPathSum(TreeNode *root, int pre, int target)
    {
        if (root == nullptr) return 0;

        pre += root->val;
        int found = 0;
        if (pre == target)
        {
            found = 1;
        }

        return found + doPathSum(root->left, pre, target) + doPathSum(root->right, pre, target);
    }

    int pathSum(TreeNode* root, int sum)
    {
        if(root == nullptr) return 0;
        return doPathSum(root, 0, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
    }
};

int main()
{
    auto sol = new Solution();
    auto root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(-3);

    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(2);

    root->right->right = new TreeNode(11);

    root->left->left->left = new TreeNode(3);
    root->left->left->right = new TreeNode(-2);

    root->left->right->right = new TreeNode(1);

    cout << sol->pathSum(root, 8) << endl;

}