/*
ID: reeceya1
LANG: C++11
TASK: barn1
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("barn1.in", "r", stdin);
    freopen("barn1.out", "w", stdout);

    int maxBoards, totalStalls, cows;
    cin >> maxBoards, totalStalls, cows;

    vector<int> cowStalls;
    for (int i = 0; i < cows; i++) {
        int stall;
        cin >> stall;
        cowStalls.push_back(stall);
    }

    sort(cowStalls.begin(), cowStalls.end());

    int minBlocked = totalStalls;
}
