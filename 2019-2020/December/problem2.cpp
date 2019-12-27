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
    freopen("milkvisits.in", "r", stdin);
    freopen("milkvisits.out", "w", stdout);

    int n, m;
    cin >> n >> m;

    vi t;
    REP(i, 1, n) {
        int ti;
        cin >> ti;
        t.PB(ti);
    }

    vi adj[n];
    REP(i, 1, n - 1) {
        int x, y;
        cin >> x >> y;
        adj[x - 1].PB(y - 1);
        adj[y - 1].PB(x - 1);
    }

    /*REP(i, 1, n) {
        cout << i << ": ";
        for (auto x : adj[i - 1]) {
            cout << x + 1 << " ";
        }
        cout << "\n";
    }*/

    vi previousNode;
    REP(i, 1, n) {
        previousNode.PB(-1);
    }
    int target;
    function<void(int, int)> dfs = [&] (int current, int previous) -> void {
        for (auto vertex : adj[current]) {
            if (vertex != previous) {
                previousNode[vertex] = current;
                if (vertex == target) {
                    return;
                }
                dfs(vertex, current);
            }
        }
    };

    REP(i, 1, m) {
        int a, b, c;
        cin >> a >> b >> c;
        bool foundCow = false;
        target = b - 1;
        dfs(a - 1, a - 1);

        /*REP(i, 1, n) {
            cout << previousNode[i - 1] << " ";
        }
        cout << "\n";*/

        int currentNode = b - 1;
        while (currentNode != a - 1) {
            if (t[currentNode] == c) {
                foundCow = true;
                break;
            }
            currentNode = previousNode[currentNode];
        }
        if (foundCow || (t[b - 1] == c && a == b)) {
            cout << "1";
        } else {
            cout << "0";
        }
    }

    /*REP(i, 1, m) {
        int a, b, c;
        cin >> a >> b >> c;
        bool foundCow = false;
        int currentNode = a - 1;
        if (t[currentNode] == c) {
            foundCow = true;
        } else {
            while (currentNode != b - 1) {
                if (t[currentNode] == c) {
                    foundCow = true;
                    break;
                }
                if (previousNode[currentNode] == -1) {
                    break;
                }
                currentNode = previousNode[currentNode];
            }
        }
        if (foundCow) {
            cout << "1";
        } else {
            // start from the other endpoint
            currentNode = b - 1;
            while (currentNode != a - 1) {
                if (t[currentNode] == c) {
                    foundCow = true;
                    break;
                }
                currentNode = previousNode[currentNode];
            }

            if (foundCow) {
                cout << "1";
            } else {
                cout << "0";
            }
        }
    }*/
    cout << "\n";
}
