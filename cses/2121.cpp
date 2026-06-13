#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct MinCostMaxFlow {  // TC: F*E*log(V), where F = max flow pushed through
    struct Edge {
        int to;
        ll cap, flow;
        ll cost;
        int rev; // Index of the reverse edge
    };

    int n;
    vector<vector<Edge>> adj;
    const ll inf_cost = numeric_limits<ll>::max() / 2;
    const ll inf_flow = numeric_limits<ll>::max() / 2;

    MinCostMaxFlow(int n) : n(n), adj(n) {}

    void add_edge(int from, int to, ll cost, ll cap) {
        adj[from].push_back({to, cap, 0, cost, (int)adj[to].size()});
        adj[to].push_back({from, 0, 0, -cost, (int)adj[from].size() - 1});
    }

    // Returns a pair: {minimum cost, maximum flow}
    pair<ll, ll> solve(int s, int t) {
        ll total_flow = 0;
        ll total_cost = 0;
        
        vector<ll> pot(n, 0), dist(n);
        vector<int> parent_node(n), parent_edge(n);

        while (true) {
            fill(dist.begin(), dist.end(), inf_cost);
            priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
            
            dist[s] = 0;
            pq.push({0, s});

            while (!pq.empty()) {
                auto [d, u] = pq.top();
                pq.pop();

                if (d > dist[u]) continue;

                for (int i = 0; i < adj[u].size(); i++) {
                    Edge& e = adj[u][i];
                    if (e.cap - e.flow > 0 && dist[e.to] > dist[u] + e.cost + pot[u] - pot[e.to]) {
                        dist[e.to] = dist[u] + e.cost + pot[u] - pot[e.to];
                        parent_node[e.to] = u;
                        parent_edge[e.to] = i;
                        pq.push({dist[e.to], e.to});
                    }
                }
            }

            if (dist[t] == inf_cost) break;

            for (int i = 0; i < n; i++) {
                if (dist[i] != inf_cost) {
                    pot[i] += dist[i];
                }
            }

            ll current_push = inf_flow;
            int curr = t;
            while (curr != s) {
                int p = parent_node[curr];
                int idx = parent_edge[curr];
                current_push = min(current_push, adj[p][idx].cap - adj[p][idx].flow);
                curr = p;
            }

            total_flow += current_push;
            curr = t;
            while (curr != s) {
                int p = parent_node[curr];
                int idx = parent_edge[curr];
                int rev_idx = adj[p][idx].rev;
                
                adj[p][idx].flow += current_push;
                adj[curr][rev_idx].flow -= current_push;
                total_cost += current_push * adj[p][idx].cost;
                
                curr = p;
            }
        }
        return {total_cost, total_flow};
    }
};

int main() {
    int n, m, k; cin >> n >> m >> k;
    MinCostMaxFlow g(n+1);
    while (m--) {
        int i, j, cap, cost; cin >> i >> j >> cap >> cost;
        g.add_edge(i, j, cost, cap);
    }
    g.add_edge(0, 1, 0, k);
    auto [cost, flow] = g.solve(0, n);
    if (flow < k) {
        cout << -1 << endl;
        return 0;
    }
    cout << cost << endl;
}