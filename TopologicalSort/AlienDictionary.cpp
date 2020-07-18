#include<iostream>
#include<unordered_map>
#include<vector>
#include<queue>
using namespace std;

class Alien_Dictionary {
public:
    vector<char> finduniquechars(int count[]) {
        vector<char> unique;
        for (int i = 0; i < 26; i++) {
            if (count[i] != 0)
                unique.push_back(i + 'a');
        }
        return unique;
    }
    string TopologicalOrdering(vector<string>&words) {
        string dictionaryorder = "";
        int count[26] = {0};
        for (string w : words) {
            for (char ch : w)
                count[ch - 'a']++;
        }
        vector<char> totalchars = finduniquechars(count);
        unordered_map<int, vector<char> > adj; // adjacency list
        unordered_map<int, int> indegree;    // store indegree of all vertices.

        for (char x : totalchars) {
            indegree[x] = 0;
            adj[x] = vector<char>();
        }
        for (int i = 1; i < words.size(); i++) {
            string second = words[i], first = words[i - 1];
            for (int i = 0; i < min(first.length(), second.length()); i++) {
                if (first[i] != second[i]) {
                    indegree[second[i]]++;
                    adj[first[i]].push_back(second[i]);
                    break;
                }
            }
        }
        queue<char> q;  // helps in implementing BFS logic.
        // push all source vertices (with indegree 0) into the queue.
        for (char i : totalchars) {
            if (indegree[i] == 0)
                q.push(i);
        }

        while (!q.empty()) {
            char curr = q.front();
            dictionaryorder += curr;
            q.pop();
            for (auto child : adj[curr]) {
                indegree[child] -= 1;
                if (indegree[child] == 0) {
                    q.push(child);
                }
            }
        }

        return dictionaryorder;
    }
};

int main() {
    int n; cin >> n;
    vector<string> words;
    for (int i = 0; i < n; i++) {
        string x; cin >> x;
        words.push_back(x);
    }
    Alien_Dictionary ad;
    cout << ad.TopologicalOrdering(words) << endl;
}


