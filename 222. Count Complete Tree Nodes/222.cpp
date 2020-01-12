/*
Given a complete binary tree, count the number of nodes.

Note:

Definition of a complete binary tree from Wikipedia:
In a complete binary tree every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

Example:

Input:
    1
   / \
  2   3
 / \  /
4  5 6

Output: 6
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
    int getDepth(TreeNode *root)
    {
        int depth = 0;
        while (root != nullptr)
        {
            depth++;
            root = root->left;
        }

        return depth;
    }

    int countNodes(TreeNode* root)
    {
        if (root == nullptr) return 0;

        int depthL = getDepth(root->left);
        int depthR = getDepth(root->right);

        if (depthL == depthR)
        {
            //return pow(2, depthL) + countNodes(root->right);
            return (1 << depthL) + countNodes(root->right);
        }
        else
        {
            //return pow(2, depthR) + countNodes(root->left);
            return (1 << depthR) + countNodes(root->left);
        }
    }
};

int main()
{
    auto sol = new Solution();
    auto root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    root->right->left = new TreeNode(6);

    cout << sol->countNodes(root) << endl;

}