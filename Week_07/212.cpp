class Trie {
public:
    bool isEnd;
    Trie* next[26];
    string word;
public:
    /** Initialize your data structure here. */
    Trie() {
        isEnd = false;
        for (int i = 0; i < 26; i++)
            next[i] = nullptr;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie* node = this;
        for (char c : word) {
            if (node->next[c-'a'] == nullptr) {
                node->next[c-'a'] = new Trie();
            }
            node = node->next[c-'a'];
        }
        node->isEnd = true;
        node->word = word;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie* node = this;
        for (char c : word) {
            node = node->next[c - 'a'];
            if (node == nullptr) {
                return false;
            }
        }
        return node->isEnd;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie* node = this;
        for (char c : prefix) {
            node = node->next[c-'a'];
            if (node == nullptr) {
                return false;
            }
        }
        return true;
    }
};

class Solution {
public:
    vector<string> ans;
    void dfs(Trie *now, int x, int y, vector<vector<char>> &board)
    {
        if (now->isEnd)
        {
            now->isEnd = 0;
            ans.push_back(now->word);
            return;
        }
        if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size())
            return;
        if (board[x][y] == '#')
            return;
        if (now->next[board[x][y] - 'a'] == nullptr)
            return;
        now = now->next[board[x][y] - 'a'];
        char cur = board[x][y];
        board[x][y] = '#';
        dfs(now, x + 1, y, board);
        dfs(now, x - 1, y, board);
        dfs(now, x, y + 1, board);
        dfs(now, x, y - 1, board);
        board[x][y] = cur;
    }
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
    {
        Trie *root = new Trie();
        for (auto word : words)
        {
            root->insert(word);
        }
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                dfs(root, i, j, board);
            }
        }
        return ans;
    }
};