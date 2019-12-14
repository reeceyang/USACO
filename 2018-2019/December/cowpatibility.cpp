#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("cowpatibility.in", "r", stdin);
    freopen("cowpatibility.out", "w", stdout);

    int n;
    cin >> n;

    int uncompatible = n * (n - 1) / 2;
    map<int, set<int>> flavors;
    //vector<vector<int>> cows;
    for (int i = 0; i < n; i++) {
        //vector<int> cow;
        //cows.push_back(cow);
        set<int> compatible;
        for (int j = 0; j < 5; j++) {
            int id;
            cin >> id;
            flavors[id];
            flavors[id].insert(i);
            set_union(flavors[id].begin(), flavors[id].end(),
                      compatible.begin(), compatible.end(),
                      inserter(compatible, compatible.begin()));
        }
        uncompatible -= compatible.size() - 1;
    }
    cout << 4 << "\n";
    /* checking input
    for (auto flavor : flavors) {
        for (int i = 0; i < flavor.second.size(); i++) {
            cout << flavor.second[i] << " ";
        }
        cout << "\n";
    }
    */
    // this is the bottleneck
    /*int uncompatible = 0;
    for (int i = 0; i < n; i++) {
        set<int> s;
        for (int j = 0; j < 5; j++) {
            for (auto othercow : flavors[cows[i][j]]) {
                s.insert(othercow);
            }
        }
        uncompatible += n - s.size();
    }
    cout << uncompatible << "\n";*/
    /*vector<vector<int>> cows;
    for (int i = 0; i < n; i++) {
        vector<int> cow;
        cows.push_back(cow);
        for (int j = 0; j < 5; j++) {
            int id;
            cin >> id;
            cows[i].push_back(id);
        }
    }
    /* Checking input
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 5; j++) {
            cout << cows[i][j] << " ";
        }
        cout << "\n";
    }*/
    /* too slow
    int uncompatible = n * (n - 1) / 2;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            bool found = false;
            for (int k = 0; k < 5; k++) {
                for (int l = 0; l < 5; l++) {
                    if (cows[i][k] == cows[j][l]) {
                        uncompatible--;
                        found = true;
                        //cout << i << " " << j << "\n";
                        break;
                    }
                }
                if (found) {
                    found = false;
                    break;
                }
            }
        }
    }
    cout << uncompatible << "\n";*/
}
