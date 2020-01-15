#include <vector>
#include <iostream>
#include <queue>
#include <functional>

using namespace std;

/*
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

Example:

Input:
[
1->4->5,
1->3->4,
2->6
]
Output: 1->1->2->3->4->4->5->6
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    ListNode *head = new ListNode(0);
public:

    void print(ListNode *p)
    {
        while (p != nullptr)
        {
            cout << p->val << " ";
            p = p->next;
        }
        cout << endl;
    }

    ListNode *mergeTwoLists(ListNode *p, ListNode *q)
    {
        if (p == nullptr) return q;
        if (q == nullptr) return p;

        head->next = nullptr;

        ListNode *h = head;

        while (p != nullptr && q != nullptr)
        {
            if (p->val < q->val)
            {
                h->next = p;
                p = p->next;
            }
            else
            {
                h->next = q;
                q = q->next;
            }
            h = h->next;
        }

        if (p != nullptr)
        {
            h->next = p;
        }
        if (q != nullptr)
        {
            h->next = q;
        }

        return head->next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        if (lists.size() == 0) return nullptr;
        if (lists.size() == 1) return lists[0];

        if (lists.size() % 2) // ÆæÊý²¹Æë
        {
            lists.push_back(nullptr);
        }

        int step = 1;
        vector<ListNode *> li;
        for (int i = 0; i < lists.size() - 1; i +=2)
        {
            li.push_back(mergeTwoLists(lists[i], lists[i + 1]));
        }

        return mergeKLists(li);
    }
};

int main()
{
    auto sol = new Solution();
    vector<ListNode *> lists;
    for (int i = 0; i < 10; i++)
    {
        lists.push_back(new ListNode(i));
    }
    sol->print(sol->mergeKLists(lists));
}