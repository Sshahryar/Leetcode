class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {

        int n = deck.size();
        vector<int> result(n);
        deque<int> indices;

        for (int i = 0; i < n; i++) {
            indices.push_back(i);
        }
        sort(deck.begin(), deck.end());

        for (int card : deck) {
            result[indices.front()] = card;
            indices.pop_front();
            if (!indices.empty()) {
                indices.push_back(indices.front());
                indices.pop_front();
            }
        }
        return result;
    }
};
