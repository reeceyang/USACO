#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("lemonade.in", "r", stdin);
    freopen("lemonade.out", "w", stdout);

    int n;
    cin >> n;

    vector<int> cows;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cows.push_back(x);
    }

    sort(cows.rbegin(), cows.rend());
    int minCows = 0;
    for (int i = 0; i < n; i++) {
        if (cows[i] >= i) {
            minCows++;
        } else {
            break;
        }
    }

    cout << minCows << "\n";
}
