class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (!dict.count(endWord)) return 0;
        dict.insert(beginWord);                       // beginWord must be a node

        vector<string> words(dict.begin(), dict.end());
        int n = words.size();

        // build undirected adjacency list: O(N^2 * L)
        unordered_map<string, vector<string>> adj;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (oneDiff(words[i], words[j])) {
                    adj[words[i]].push_back(words[j]);
                    adj[words[j]].push_back(words[i]);
                }
            }
        }

        // layered BFS
        int dist = 1;                                 // beginWord counts as 1
        queue<string> q;
        unordered_set<string> visited;
        q.push(beginWord);
        visited.insert(beginWord);

        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                string cur = q.front(); q.pop();
                if (cur == endWord) return dist;
                for (const string& nxt : adj[cur]) {
                    if (visited.insert(nxt).second)   // mark on enqueue
                        q.push(nxt);
                }
            }
            dist++;
        }
        return 0;
    }
private:
    bool oneDiff(const string& a, const string& b) {
        if (a.size() != b.size()) return false;
        int diff = 0;
        for (size_t k = 0; k < a.size(); k++) {
            if (a[k] != b[k] && ++diff > 1) return false;
        }
        return diff == 1;
    }
};
