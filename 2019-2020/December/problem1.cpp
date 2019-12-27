#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int,int> pi;

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (int i = a; i <= b; i++)

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("pump.in", "r", stdin);
    freopen("pump.out", "w", stdout);

    int n, m;
    cin >> n >> m;

    vector<tuple<int, int, int>> adj[n];
    REP(i, 1, m) {
        int a, b, c, f;
        cin >> a >> b >> c >> f;
        adj[a - 1].PB(make_tuple(b - 1, c ,f));
        adj[b - 1].PB(make_tuple(a - 1, c ,f));
    }

    /*REP(i, 1, n) {
        cout << i << ": \n";
        for (auto x : adj[i - 1]) {
            cout << get<0>(x) + 1 << " " << get<1>(x) << " " << get<2>(x) << "\n";
        }
        cout << "\n";
    }*/

    vi cost;
    vi flow;
    REP(i, 1, n) {
        cost.PB(-1);
        flow.PB(-1);
    }
    cost[0] = 0;
    flow[0] = 9999;

    /*function<void(int)> dfs = [&] (int current) -> void {
        for (tuple<int, int, int> edge : adj[current]) {
            int vertex = get<0>(edge);
            int edgecost = get<1>(edge);
            int edgeflow = get<2>(edge);
            //cout << "Current: " << current << " vertex: " << vertex << " edgecost: " << edgecost << " edgeflow: " << edgeflow << "\n";
            //cout << "cost[vertex]: " << cost[vertex] << " cost[current]: " << cost[current] << "\n";
            if (cost[vertex] == -1) {
                cost[vertex] = edgecost + cost[current];
                flow[vertex] = min(edgeflow, flow[current]);
                dfs(vertex);
            } else if (edgecost + cost[current] < cost[vertex] || min(edgeflow, flow[current]) > flow[vertex]) {
                double oldrate = (flow[vertex] * 1.0) / (cost[vertex] * 1.0);
                double newrate = (min(edgeflow, flow[current]) * 1.0) / ((edgecost + cost[current]) * 1.0);
                if (newrate > oldrate) {
                    flow[vertex] = min(edgeflow, flow[current]);
                    cost[vertex] = edgecost + cost[current] < cost[vertex];
                    dfs(vertex);
                }
            }
        }
    };*/

    function<void(int)> dfs = [&] (int current) -> void {
        for (tuple<int, int, int> edge : adj[current]) {
            int vertex = get<0>(edge);
            int edgecost = get<1>(edge);
            int edgeflow = get<2>(edge);
            //cout << "Current: " << current << " vertex: " << vertex << " edgecost: " << edgecost << " edgeflow: " << edgeflow << "\n";
            //cout << "cost[vertex]: " << cost[vertex] << " cost[current]: " << cost[current] << "\n";
            if (cost[vertex] == -1) {
                cost[vertex] = edgecost + cost[current];
                flow[vertex] = min(edgeflow, flow[current]);
                dfs(vertex);
            } else if (edgecost + cost[current] < cost[vertex] || min(edgeflow, flow[current]) > flow[vertex]) {
                flow[vertex] = min(edgeflow, flow[current]);
                cost[vertex] = edgecost + cost[current] < cost[vertex];
                dfs(vertex);
            }
        }
    };

    dfs(0);

    double endrate = (flow[n - 1] * 1.0) / (cost[n - 1] * 1.0);
    //cout << flow[n - 1] << "\n";
    cout << (int) (endrate * 1000000) << "\n";
}
