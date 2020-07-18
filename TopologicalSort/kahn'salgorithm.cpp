#include<iostream>
#include<unordered_map>
#include<vector>
#include<queue>
using namespace std;

class Kahns_Algorithm {
public:
    static vector<int> TopologicalOrdering(vector<vector<int> >&edges, int vertices) {
        vector<int> TopologicalOrder;
        if (vertices == 0)    // if the number of vertices is 0.
            return TopologicalOrder;
        unordered_map<int, vector<int> > adj; // adjacency list
        unordered_map<int, int> indegree;    // store indegree of all vertices.
        for (int i = 1; i <= vertices; i++) {
            indegree[i] = 0;
            adj[i] = vector<int>();
        }
        for (auto edge : edges) {
            int src = edge[0], dest = edge[1];
            indegree[dest] += 1;
            adj[src].push_back(dest);
        }
        queue<int> q;  // helps in implementing BFS logic.
        // push all source vertices (with indegree 0) into the queue.
        for (int i = 1; i <= vertices; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }
        while (!q.empty()) {
            int curr = q.front();
            TopologicalOrder.push_back(curr);
            q.pop();
            for (auto child : adj[curr]) {
                indegree[child] -= 1;
                if (indegree[child] == 0) {
                    q.push(child);
                }
            }
        }
        if (TopologicalOrder.size() != vertices) {
            cout << "Graph is not a DAG" << endl;
            return vector<int>();
        }
        return TopologicalOrder;
    }
};

int main() {
    int n, m; cin >> n >> m;
    vector<vector<int> > edges;
    for (int i = 1; i <= m; i++) {
        int a, b; cin >> a >> b;
        edges.push_back(vector<int> {a, b});
    }
    vector<int> result = Kahns_Algorithm::TopologicalOrdering(edges, n);
    for (int res : result)
        cerr << res << " ";
    cerr << endl;
}
