#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("notlast.in", "r", stdin);
    freopen("notlast.out", "w", stdout);

    int n;
    cin >> n;

    map<string, int> cows;
    for (int i = 0; i < n; i++) {
        string name;
        int milk;
        cin >> name >> milk;
        cows[name];
        cows[name] += milk;
    }

    int minimum = 99999;
    string name = "";
    for (auto cow : cows) {
        if (cow.second == minimum) {
            if (cows.size() < 7) {
                name = "Tie";
            }
        }
        if (cow.second < minimum) {
            minimum = cow.second;
            name = cow.first;
        }
    }

    int secondMin = 99999;
    if (name != "Tie" && cows.size() >= 7) {
        for (auto cow : cows) {
            if (cow.second < secondMin && cow.second > minimum) {
                secondMin = cow.second;
                name = cow.first;
            }
        }
    }
    if (name == "" || (secondMin == 99999 && cows.size() == 7)) {
        name = "Tie";
    }
    cout << name << "\n";
}

