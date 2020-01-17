/*
Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

Example:

Given the sorted linked list: [-10,-3,0,5,9],

One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:

     0
    / \
  -3   9
  /   /
-10  5
*/
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    
    void print(ListNode *head)
    {
        while (head != nullptr)
        {
            cout << head->val << " ";
            head = head->next;
        }
        cout << endl;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        if (head == nullptr) return nullptr;
        if (head->next == nullptr) return new TreeNode(head->val);

        ListNode *fast = head->next->next;
        ListNode *slow = head;

        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *mid = slow->next;
        ListNode *right = slow->next->next;
        ListNode *left = head;

        slow->next = nullptr;

        TreeNode *node = new TreeNode(mid->val);
        node->left = sortedListToBST(left);
        node->right = sortedListToBST(right);

        return node;
    }

    vector<int> postOrder(TreeNode *root)
    {
        vector<int> result;
        if (root == nullptr)
        {
            return result;
        }

        using StackNode = pair<TreeNode *, bool>;
        stack<StackNode> st;
        StackNode p = make_pair(root, false);

        while (!st.empty() || p.first != nullptr)
        {
            if (p.first != nullptr)
            {
                st.push(p);
                p = make_pair(p.first->left, false);
            }
            else
            {
                auto &top = st.top();
                if (!top.second && top.first->right != nullptr)
                {
                    top.second = true;
                    p = make_pair(top.first->right, false);
                }
                else
                {
                    result.push_back(top.first->val);
                    st.pop();
                }
            }
        }

        return result;
    }
};

int main()
{
    auto sol = new Solution();
    auto head = new ListNode(-10);
    head->next = new ListNode(-3);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(5);
    head->next->next->next->next = new ListNode(9);

    auto root = sol->sortedListToBST(head);
    auto result = sol->postOrder(root);

    for (auto n : result)
    {
        cout << n << " ";
    }
    cout << endl;
}