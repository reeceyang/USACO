/*
ID: reeceya1
TASK: beads
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("beads.in", "r", stdin);
    freopen("beads.out", "w", stdout);

    int n;
    cin >> n;

    string s;
    cin >> s;

    s = s + s + s;

    int maximum = 0;
    for (int j = n; j < 2 * n; j++) {
        int right = 1;
        int left = 1;
        int i = j;
        char color = s[i];
        while (color == 'w') {
            i++;
            color = s[i];
        }
        i = j;
        while ((s[i + 1] == color || s[i + 1] == 'w') && i < n + i) {
            right++;
            i++;
        }
        i = j;
        color = s[i - 1];
        while (color == 'w') {
            i--;
            color = s[i - 1];
        }
        i = j;
        while ((s[i - 2] == color || s[i - 2] == 'w') && i > i - n) {
            left++;
            i--;
        }
        if (maximum < right + left) {
            maximum = right + left;
        }
    }
    if (maximum > n) {
        maximum = n;
    }
    cout << maximum << "\n";
}

