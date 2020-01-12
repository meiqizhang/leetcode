/*
Given a binary search tree (BST) with duplicates, find all the mode(s) (the most frequently occurred element) in the given BST.

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than or equal to the node's key.
The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
Both the left and right subtrees must also be binary search trees.


For example:
Given BST [1,null,2,2],

1
 \
  2
 /
2

*/

#include <queue>
#include <vector>
#include <stack>
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
    //÷––Ú±È¿˙”––Ú
    vector<int> findMode(TreeNode* root)
    {
        vector<int> result;
        stack<TreeNode *> st;
        TreeNode *p = root;

        int curVal = 0xffffffff;
        int curFreq = 0;
        int maxFreq = 0;

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
                if (p->val == curVal)
                {
                    curFreq++;
                }
                else
                {
                    curFreq = 1;
                }

                if (curFreq == maxFreq)
                {
                    result.push_back(p->val);
                }
                else if (curFreq > maxFreq)
                {
                    result.clear();
                    result.push_back(p->val);
                    maxFreq = curFreq;
                }

                curVal = p->val;
                p = p->right;
            }
        }

        return result;
    }
};

int main()
{
    auto sol = new Solution();
    auto root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(2);

    auto result = sol->findMode(root);
    for (auto res : result)
    {
        cout << res << " ";
    }
    cout << endl;
}