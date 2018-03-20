#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("measurement.in", "r", stdin);
    freopen("measurement.out", "w", stdout);

    int n, g;
    cin >> n >> g;
    map<int, pair<int, int>> log;
    map<int, int> cows;
    for (int i = 0; i < n; i++) {
        int day, id;
        string schange;
        cin >> day >> id >> schange;
        int change;
        if (schange[0] == '-') {
            change = -stoi(schange.substr(1));
        } else {
            change = stoi(schange.substr(1));
        }
        log[day] = make_pair(id, change);
        cows[id] = g;
    }
    int days = 0; // = 1
    int maximum = g;
    for (auto x : log) {
        pair<int, int> cow = x.second;
        if (cows[cow.first] == maximum) {
            if (cow.second >= 0) {
                bool found = false;
                for (auto y : cows) {
                    if (y.second == cows[cow.first] && y.first != cow.first) {
                        found = true;
                    }
                }
                if (found) {
                    days++;
                }
                cows[cow.first] += cow.second;
                maximum = cows[cow.first];
            }
            if (cow.second < 0) {
                cows[cow.first] += cow.second;
                bool found = false;
                // new maximum
                for (auto y : cows) {
                    if (y.second >= cows[cow.first] && y.first != cow.first) {
                        maximum = y.second;
                        found = true;
                    }
                }
                if (found) {
                    days++;
                } else {
                    if (cows[cow.first] < g) {
                        maximum = g;
                        days++;
                    } else {
                        maximum = cows[cow.first];
                    }
                }
            }
            //cout << "End of day " << x.first << ". Maximum: " << maximum << "\n";
            continue;
        }
        //this cow was below the maximum;
        cows[cow.first] += cow.second;
        if (cows[cow.first] >= maximum) {
            days++;
            maximum = cows[cow.first];
            //cout << cow.first << " has new max " << maximum << "\n";
        }
        //cout << "End of day " << x.first << ". Maximum: " << maximum << "\n";
    }
    cout << days << "\n";
}


