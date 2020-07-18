#include<iostream>
#include<unordered_map>
#include<vector>
#include<queue>
#define pb push_back
using namespace std;

class Kahns_Algorithm {
public:
    void TopologicalOrdering(vector<vector<int> >&edges, int vertices) {
        vector<int> TopologicalOrder;
        // if (vertices == 0)    // if the number of vertices is 0.
        //     return TopologicalOrder;
        unordered_map<int, vector<int> > adj; // adjacency list
        unordered_map<int, int> indegree;    // store indegree of all vertices
        for (int i = 1; i <= vertices; i++) {
            indegree[i] = 0;
            adj[i] = vector<int>();
        }
        for (auto edge : edges) {
            int src = edge[0], dest = edge[1];
            indegree[dest] += 1;
            adj[src].push_back(dest);
        }
        vector<int> sources;
        for (int i = 1; i <= vertices; i++) {
            if (indegree[i] == 0) {
                sources.pb(i);
            }
        }
        PrintAllOrderings(adj, indegree, sources, TopologicalOrder);
    }
    void PrintAllOrderings( unordered_map<int, vector<int> > adj, unordered_map<int, int> indegree, vector<int>sources, vector<int>TopologicalOrder ) {
        for (int source : sources) {
            TopologicalOrder.push_back(source);
            vector<int> newsources = sources;

            // changes made in this recursive call. Will be mend later. That's what backtracking does.
            newsources.erase(find(sources.begin(), sources.end(), source));
            for (int child : adj[source]) {
                indegree[child]--;
                if (indegree[child] == 0) {
                    newsources.push_back(child);
                }
            }
            PrintAllOrderings(adj, indegree, newsources, TopologicalOrder);

            // backtrack and remove the source from the list maintained. and also recover the changes made to indegree.
            TopologicalOrder.erase(find(TopologicalOrder.begin(), TopologicalOrder.end(), source));
            for (auto child : adj[source])
                indegree[child]++;
        }
        if (TopologicalOrder.size() == indegree.size()) {
            for (int num : TopologicalOrder) {
                cerr << num << " ";
            }
            cerr << endl;
        }

    }
};


int main() {
    int n, m; cin >> n >> m;
    vector<vector<int> > edges;
    for (int i = 1; i <= m; i++) {
        int a, b; cin >> a >> b;
        edges.push_back(vector<int> {a, b});
    }
    Kahns_Algorithm k;
    k.TopologicalOrdering(edges, n);
}
