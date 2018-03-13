#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("angry.in", "r", stdin);
    freopen("angry.out", "w", stdout);

    int n, k;
    cin >> n >> k;

    int maximum = -1;
    int minimum = 1000000001;
    vector<int> haybales;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x > maximum) {
            maximum = x;
        }
        if (x < minimum) {
            minimum = x;
        }
    }

    int r = 0;
    r = (maximum - minimum + 1) / (k * 2 + 1);
    cout << r;

}

