#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("gates.in", "r", stdin);
    freopen("gates.out", "w", stdout);

    int n;
    cin >> n;
    string s;
    cin >> s;

    int north = 0;
    int east = 0;
    int south = 0;
    int west = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == "N") north++;
        if (s[i] == "E") east++;
        if (s[i] == "S") south++;
        if (s[i] == "W") west++;
    }
}
