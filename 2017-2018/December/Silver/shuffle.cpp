#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("shuffle.in", "r", stdin);
    freopen("shuffle.out", "w", stdout);

    int n;
    cin >> n;

    vector<int> positions;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        positions.push_back(x - 1); // switch to 0 based index
    }

    int p = 0;
    vector<int> cycles;
    for (int i = 0; i < n; i++) {
        int index = distance(positions.begin(), find(positions.begin(), positions.end(), i));
        int nindex = index;
        vector<int> temp = {i};
        bool works = true;
        do {
            if (find(cycles.begin(), cycles.end(), nindex) != cycles.end()) {
                break;
            }
            temp.push_back(nindex);
            nindex = distance(positions.begin(), find(positions.begin(), positions.end(), nindex));
            if (nindex == n) {
                works = false;
                break;
            }
        } while (nindex != index);
        if (works) {
            cycles.reserve(cycles.size() + temp.size());
            cycles.insert(cycles.end(), temp.begin(), temp.end());
            p++;
        }
        /*for (int x : temp) {
            cout << x << "\n";
        }*/
    }
    /*for (int i : cycles) {
        cout << i << "\n";
    }*/
    cout << p << "\n";
}


