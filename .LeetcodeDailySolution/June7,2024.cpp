class TrieNode {
public:

    TrieNode* children[26] = {};
    string word = "";

};

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {

        TrieNode* root = new TrieNode();

        for (const string& word : dictionary) {

            TrieNode* node = root;

            for (char c : word) {
                if (node->children[c - 'a'] == nullptr) {
                    node->children[c - 'a'] = new TrieNode();
                }
                node = node->children[c - 'a'];
            }
            node->word = word;
        }
        istringstream iss(sentence);
        string ans, token;

        while (getline(iss, token, ' ')) {

            TrieNode* node = root;

            for (char c : token) {
                if (node->children[c - 'a'] == nullptr || !node->word.empty()) {
                    break;
                }
                node = node->children[c - 'a'];
            }
            ans += (node->word.empty() ? token : node->word) + " ";
        }
        ans.pop_back();  
        
        return ans;
    }
};

