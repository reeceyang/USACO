/*
ID: reeceya1
LANG: C++11
TASK: combo
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("combo.in", "r", stdin);
    freopen("combo.out", "w", stdout);

    int n;
    cin >> n;
    int a, b, c; // fj
    cin >> a >> b >> c;
    int d, e, f; // master
    cin >> d >> e >> f;

    vector<tuple<int, int, int>> combos;
    // Possible combinations from FJ
    for (int i = a - 2; i <= a + 2; i++) {
        for (int j = b - 2; j <= b + 2; j++) {
            for (int k = c  - 2; k <= c + 2; k++) {
                combos.push_back(make_tuple((i + n) % n, (j + n) % n, (k + n) % n));
            }
        }
    }
    // Possible combinations from master
    for (int i = d - 2; i <= d + 2; i++) {
        for (int j = e - 2; j <= e + 2; j++) {
            for (int k = f  - 2; k <= f + 2; k++) {
                combos.push_back(make_tuple((i + n) % n, (j + n) % n, (k + n) % n));
            }
        }
    }
    // Delete duplicates
    for (int i = 0; i < combos.size(); i++) {
        for (int j = i + 1; j < combos.size(); j++) {
            if (combos[i] == combos[j]) {
                combos.erase(combos.begin() + j);
                j--;
            }
        }
    }
    cout << combos.size() << "\n";
}

