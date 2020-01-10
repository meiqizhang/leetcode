##二叉树中序遍历非递归算法
   
    vector<int> inorderTraversal(TreeNode* root)
    {
        vector<int> result;
        stack<TreeNode *> st;
        TreeNode *p = root;

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
                result.push_back(p->val);
                p = p->right;
            }
        }
        return result;
    }

`if`相当于是左子树遍历，找到左子树的叶子节点，`else`相当于是到了左子树的叶子节点，接着弹出栈顶元素，访问它，右节点入栈，循环访问右子树的左节点
