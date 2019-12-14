#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("teamwork.in", "r", stdin);
    freopen("teamwork.out", "w", stdout);

    int n, k;
    cin >> n >> k;

    vector<int> cows;
    //vector<int> groups;
    for (int i = 0; i < n; i++) {
        int skill;
        cin >> skill;
        cows.push_back(skill);
        //groups.push_back(0)
    }
    sort(cows.rbegin(), cows.rend());
    int sum = 0;
    int i = 0;
    while(n > k) {
        sum += cows[i] * k;
        n -= k;
        i++;
    }
    sum += cows[i] * n;
    cout << sum << "\n";
}
