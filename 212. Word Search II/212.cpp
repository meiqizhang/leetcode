/*
Given a 2D board and a list of words from the dictionary, find all words in the board.

Each word must be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.

Example:

Input:
board = [
['o','a','a','n'],
['e','t','a','e'],
['i','h','k','r'],
['i','f','l','v']
]
words = ["oath","pea","eat","rain"]

Output: ["eat","oath"]


Note:

All inputs are consist of lowercase letters a-z.
The values of words are distinct.
*/

#include <vector>
#include <string>
#include <iostream>

using namespace std;

struct TrieNode
{
    char ch;
    bool isWord;
    vector<TrieNode *>children;

    TrieNode(char ch = '#')
    {
        this->ch = ch;
        this->isWord = false;
        this->children.resize(127, nullptr);
    }
};

struct TrieTree
{
    TrieNode root;

    void insert(string s)
    {
        TrieNode *p = &root;
        int index = 0;

        while (index < s.size() && p->children[s[index]] != nullptr)
        {
            p = p->children[s[index]];
            index++;
        }

        while (index < s.size())
        {
            p->children[s[index]] = new TrieNode(s[index]);
            p = p->children[s[index]];
            index++;
        }
        p->isWord = true;
    }
};


class Solution
{
    vector<vector<int>> step{ { 0, -1 },{ 1, 0 },{ 0, 1 },{ -1, 0 } };

public:

    void dfs(int r, int c, vector<vector<bool>> &visit, string pre, TrieNode *node, vector<string> &result, vector<vector<char>>& board)
    {
        if (node->isWord)
        {
            result.push_back(pre);
            node->isWord = false;
        }

        int N = board.size();
        int M = board[0].size();

        visit[r][c] = true;
        for (int i = 0; i < 4; i++)
        {
            int x = r + step[i][0];
            int y = c + step[i][1];

            if (x >= 0 && y >= 0 && x < N && y < M && !visit[x][y])
            {
                char ch = board[x][y];

                if (node->children[ch] != nullptr)
                {
                    dfs(x, y, visit, pre + ch, node->children[ch], result, board);
                }
            }
        }
        visit[r][c] = false;
    }

    vector<string> searchTireTree(vector<vector<char>>& board, TrieTree *tree)
    {
        vector<string> result;
        vector<vector<bool>> visit(board.size(), vector<bool>(board[0].size(), false));

        int N = board.size();
        int M = board[0].size();

        for (int r = 0; r < N; r++)
        {
            for (int c = 0; c < M; c++)
            {
                char ch = board[r][c];
                if (tree->root.children[ch] != nullptr)
                {
                    dfs(r, c, visit, string("") + ch, tree->root.children[ch], result, board);
                }
            }
        }
        
        return result;           
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words)
    {
        TrieTree root;
        for (auto word : words)
        {
            root.insert(word);
        }

        return this->searchTireTree(board, &root);
    }
};

int main()
{
    auto sol = new Solution();
    
    /*vector<vector<char>> board{
        {'o','a','a','n'},
        {'e','t','a','e'},
        {'i','h','k','r'},
        {'i','f','l','v'} };

    vector<string> words{ "oath","pea","eat","rain" };
    */

    vector<vector<char>> board{ {'a'} };
    vector<string> words{ "a" };

    /*vector<vector<char>> board{
        { 'b', 'a', 'a', 'b', 'a', 'b' }, 
        { 'a', 'b', 'a', 'a', 'a', 'a' }, 
        { 'a', 'b', 'a', 'a', 'a', 'b' },
        { 'a', 'b', 'a', 'b', 'b', 'a' }, 
        { 'a', 'a', 'b', 'b', 'a', 'b' }, 
        { 'a', 'a', 'b', 'b', 'b', 'a' },
        { 'a', 'a', 'b', 'a', 'a', 'b' }};

    vector<string> words{ "aab", "bbaabaabaaaaabaababaaaaababb", "aabbaaabaaabaabaaaaaabbaaaba", "babaababbbbbbbaabaababaabaaa", "bbbaaabaabbaaababababbbbbaaa", "babbabbbbaabbabaaaaaabbbaaab", "bbbababbbbbbbababbabbbbbabaa", "babababbababaabbbbabbbbabbba", "abbbbbbaabaaabaaababaabbabba", "aabaabababbbbbbababbbababbaa", "aabbbbabbaababaaaabababbaaba", "ababaababaaabbabbaabbaabbaba", "abaabbbaaaaababbbaaaaabbbaab", "aabbabaabaabbabababaaabbbaab", "baaabaaaabbabaaabaabababaaaa", "aaabbabaaaababbabbaabbaabbaa", "aaabaaaaabaabbabaabbbbaabaaa", "abbaabbaaaabbaababababbaabbb", "baabaababbbbaaaabaaabbababbb", "aabaababbaababbaaabaabababab", "abbaaabbaabaabaabbbbaabbbbbb", "aaababaabbaaabbbaaabbabbabab", "bbababbbabbbbabbbbabbbbbabaa", "abbbaabbbaaababbbababbababba", "bbbbbbbabbbababbabaabababaab", "aaaababaabbbbabaaaaabaaaaabb", "bbaaabbbbabbaaabbaabbabbaaba", "aabaabbbbaabaabbabaabababaaa", "abbababbbaababaabbababababbb", "aabbbabbaaaababbbbabbababbbb", "babbbaabababbbbbbbbbaabbabaa" };
    
    */
    auto result = sol->findWords(board, words);

    for (auto res : result)
    {
        cout << res << " ";
    }
    cout << endl;
}