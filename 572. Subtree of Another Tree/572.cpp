/*
Given two non-empty binary trees s and t, check whether tree t has exactly the same structure and node values with a subtree of s. A subtree of s is a tree consists of a node in s and all of this node's descendants. The tree s could also be considered as a subtree of itself.

Example 1:
Given tree s:

    3
   / \
  4   5
 / \
1   2
Given tree t:
  4
 / \
1   2
Return true, because t has the same structure and node values with a subtree of s.
Example 2:
Given tree s:

      3
     / \
    4   5
   / \
  1   2
 /
0
Given tree t:
  4
 / \
1   2
Return false.
*/

#include <memory>
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
    bool isSameTree(TreeNode *s, TreeNode *t)
    {
        if (s == nullptr && t == nullptr) return true;
        if (s != nullptr && t == nullptr) return false;
        if (s == nullptr && t != nullptr) return false;

        return s->val == t->val && isSameTree(s->left, t->left) && isSameTree(s->right, t->right);

    }
    bool isSubtree(TreeNode* s, TreeNode* t)
    {
        if (s == nullptr && t == nullptr) return true;
        if (s == nullptr && t != nullptr) return false;
        if (s != nullptr && t == nullptr) return false;

        if (s->val != t->val)
        {
            return isSubtree(s->left, t) || this->isSubtree(s->right, t);
        }
        else
        {
            return isSameTree(s, t) || isSubtree(s->left, t) || isSubtree(s->right, t);
        }
    }
};

int main()
{
    unique_ptr<Solution> sol(new Solution);
    unique_ptr<TreeNode> s(new TreeNode(3));
    s->left = new TreeNode(4);
    s->right = new TreeNode(5);

    s->left->left = new TreeNode(1);
    s->left->right = new TreeNode(2);

    unique_ptr<TreeNode> t(new TreeNode(4));
    t->left = new TreeNode(1);
    t->right = new TreeNode(2);

    /*unique_ptr<TreeNode> s(new TreeNode(3));
    s->left = new TreeNode(4);
    s->left->left = new TreeNode(1);

    s->right = new TreeNode(5);
    s->right->left = new TreeNode(2);

    unique_ptr<TreeNode> t(new TreeNode(3));
    t->left = new TreeNode(1);
    t->right = new TreeNode(2);*/

    /*unique_ptr<TreeNode> s(new TreeNode(1));
    s->left = new TreeNode(1);

    unique_ptr<TreeNode> t(new TreeNode(1));*/

    cout << sol->isSubtree(s.get(), t.get()) << endl;
}