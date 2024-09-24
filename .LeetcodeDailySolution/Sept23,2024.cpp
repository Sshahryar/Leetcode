const int N = 26;

struct Trie {

    Trie* next[N];
    bool isEnd = 0;

    Trie() { fill(next, next + N, (Trie*)NULL); }

    ~Trie() {
        for (int i = 0; i < N; ++i) {
            if (next[i] != NULL) {
                delete next[i];
            }
        }
    }

    void insert(string& word) {
        Trie* Node = this;
        for (char c : word) {
            int i = c - 'a';
            if (Node->next[i] == NULL)
                Node->next[i] = new Trie();
            Node = Node->next[i];
        }
        Node->isEnd = 1;
    }
    void insert(vector<string>& dictionary) {
        for (auto& word : dictionary)
            insert(word);
    }
};

class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {

        Trie trie;
        trie.insert(dictionary);

        int n = s.size();
        vector<int> dp(n + 1, 0);

        for (int i = n - 1; i >= 0; i--) {

            dp[i] = dp[i + 1] + 1;
            Trie* node = &trie;

            for (int j = i; j < n; j++) {
                if (node->next[s[j] - 'a'] == NULL)
                    break;

                node = node->next[s[j] - 'a'];

                if (node->isEnd)
                    dp[i] = min(dp[i], dp[j + 1]);
            }
        }

        return dp[0];
    }
};
