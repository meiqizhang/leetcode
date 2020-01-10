##二叉树后序遍历非递归算法

    vector<int> postorderTraversal(TreeNode* root)
    {
        vector<int> result;
        stack<TreeNode *> st;
        TreeNode *p = root;

        while (!st.empty() || p != nullptr)
        {
            if (p != nullptr)
            {
                st.push(p);
                result.insert(result.begin(), p->val);
                p = p->right;
            }
            else
            {
                p = st.top(), st.pop();
                p = p->left;
            }
        }

        return result;
    }


后序遍历和先序遍历刚好相反，在`if`表示当前节点不为空，中将节点插入visit头部，然后访问右子树。在`else`中取出栈顶，由于在访问时候插入顺序是插在头部的，所以先访问右子树，再访问左子树